/*
 * cmdscan - discover the commands, options and arguments in a command namespace
 *
 * A namespace is a set of commands reachable one way: the applets of a
 * multi-call binary (BusyBox, Toybox), the executables in a set of
 * directories, or any list you describe in a config file. For every command
 * cmdscan captures the help text in a contained child process and parses it
 * into usage, summary, options (short, long, argument, description),
 * positional arguments and extra usage forms (subcommands). It also tags
 * commands by risk so the destructive ones can seed the Safety Gate list.
 *
 *   cmdscan list  -p busybox|toybox|path|<custom> [options]
 *   cmdscan scan  -p busybox|toybox|path|<custom> -o <prefix> [options]
 *   cmdscan show  -p busybox|toybox|path|<custom> <command>
 *
 * Options
 *   -b PATH      binary for busybox/toybox        (default: found on PATH)
 *   -d DIRS      colon-separated dirs for "path"  (default: $PATH)
 *   -c FILE      config: custom providers, risk lists, never-probe patterns
 *   -f GLOB      only commands matching GLOB (repeatable)
 *   -t MS        help timeout per command          (default 3000)
 *   --probe      "path"/custom: actually run "<cmd> --help" (default: list only)
 *   --scripts    with --probe, also probe shell scripts (default: ELF only)
 *   --raw        include raw help text in the JSON
 *   --jsonl      also write <prefix>.jsonl (one command per line)
 *
 * Build: make (vendored cJSON) or make CJSON=system.
 */
#define _GNU_SOURCE
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fnmatch.h>
#include <limits.h>
#include <poll.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#ifdef CJSON_SYSTEM
#include <cjson/cJSON.h>
#else
#include "cJSON.h"
#endif

#define CMDSCAN_VERSION "1.0.0"
#define MAX_CMDS 4096
#define MAX_OPTS 160
#define MAX_POS 24
#define MAX_FORMS 32
#define MAX_PAT 128
#define MAX_ARGV 32
#define HELP_CAP (64 * 1024)

/* ------------------------------------------------------------------ */
/* Utilities                                                           */
/* ------------------------------------------------------------------ */

static void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "cmdscan: ");
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
    exit(2);
}

static void warnx(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "cmdscan: warning: ");
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
}

static char *xstrdup(const char *s)
{
    char *p = strdup(s ? s : "");
    if (!p) die("out of memory");
    return p;
}

static void scopy(char *dst, size_t n, const char *src)
{
    size_t i = 0;
    if (!n) return;
    if (src)
        for (; i + 1 < n && src[i]; i++) dst[i] = src[i];
    dst[i] = 0;
}

static void scopyn(char *dst, size_t n, const char *src, size_t len)
{
    if (!n) return;
    if (len >= n) len = n - 1;
    memcpy(dst, src, len);
    dst[len] = 0;
}

static void sappend(char *dst, size_t n, const char *src)
{
    size_t l = strlen(dst);
    if (l + 1 >= n) return;
    scopy(dst + l, n - l, src);
}

static char *trim(char *s)
{
    while (isspace((unsigned char)*s)) s++;
    char *e = s + strlen(s);
    while (e > s && isspace((unsigned char)e[-1])) *--e = 0;
    return s;
}

static long long now_ms(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

/* ------------------------------------------------------------------ */
/* Running a command in a contained child                              */
/* ------------------------------------------------------------------ */

typedef struct {
    char *out;
    size_t len;
    int rc;
    int timed_out;
} capture_t;

static void capture(char *const argv[], long timeout_ms, capture_t *c)
{
    memset(c, 0, sizeof(*c));
    c->rc = -1;
    c->out = malloc(HELP_CAP + 1);
    if (!c->out) die("out of memory");
    int pfd[2];
    if (pipe2(pfd, O_CLOEXEC) != 0) die("pipe: %s", strerror(errno));
    pid_t pid = fork();
    if (pid < 0) die("fork: %s", strerror(errno));
    if (pid == 0) {
        setsid();
        int dn = open("/dev/null", O_RDONLY);
        if (dn >= 0) { dup2(dn, 0); close(dn); }
        dup2(pfd[1], 1);
        dup2(pfd[1], 2);
        setenv("LC_ALL", "C", 1);
        setenv("COLUMNS", "200", 1);
        setenv("TERM", "dumb", 1);
        signal(SIGPIPE, SIG_DFL);
        execvp(argv[0], argv);
        _exit(127);
    }
    close(pfd[1]);
    fcntl(pfd[0], F_SETFL, fcntl(pfd[0], F_GETFL) | O_NONBLOCK);
    long long t0 = now_ms();
    int open_ = 1, reaped = 0, status = 0, killed = 0;
    while (open_ || !reaped) {
        if (open_) {
            struct pollfd pf = {pfd[0], POLLIN, 0};
            poll(&pf, 1, 20);
            for (;;) {
                char buf[4096];
                ssize_t n = read(pfd[0], buf, sizeof(buf));
                if (n > 0) {
                    size_t room = HELP_CAP - c->len;
                    size_t w = (size_t)n < room ? (size_t)n : room;
                    memcpy(c->out + c->len, buf, w);
                    c->len += w;
                    if (c->len >= HELP_CAP && !killed) { kill(-pid, SIGKILL); killed = 1; }
                    continue;
                }
                if (n == 0) { open_ = 0; close(pfd[0]); }
                break;
            }
        } else {
            poll(NULL, 0, 5);
        }
        if (!reaped && waitpid(pid, &status, WNOHANG) == pid) reaped = 1;
        if (!reaped && !killed && now_ms() - t0 > timeout_ms) {
            c->timed_out = 1;
            kill(-pid, SIGKILL);
            killed = 1;
        }
        if (reaped && open_ && now_ms() - t0 > timeout_ms + 500) { close(pfd[0]); open_ = 0; }
    }
    kill(-pid, SIGKILL); /* anything the command left behind */
    c->out[c->len] = 0;
    if (WIFEXITED(status)) c->rc = WEXITSTATUS(status);
    else if (WIFSIGNALED(status)) c->rc = 128 + WTERMSIG(status);
}

/* ------------------------------------------------------------------ */
/* Data model                                                          */
/* ------------------------------------------------------------------ */

typedef struct {
    char flag[24];   /* short or keyword form: -a, -lc, if=   */
    char lng[64];    /* long form: --all                      */
    char arg[64];    /* argument placeholder: N, FILE         */
    int arg_optional;
    char alias[64];  /* other spellings: -E, --extended       */
    char desc[320];
    char source[8];  /* "help" (option list) or "usage"       */
} opt_t;

typedef struct {
    char name[96];
    int optional, repeat;
} pos_t;

typedef struct {
    char name[96];
    char path[PATH_MAX];
    char via[32];        /* busybox, toybox, path, custom name */
    char kind[16];       /* elf, script, applet, other         */
    char risk[24];
    int probed, help_rc, timed_out;
    char skipped[128];
    char usage[2048];
    char summary[400];
    char forms[MAX_FORMS][400];
    int nforms;
    opt_t opts[MAX_OPTS];
    int nopts;
    pos_t pos[MAX_POS];
    int npos;
    char *raw;
} cmd_t;

typedef struct {
    char name[64];
    char *list_argv[MAX_ARGV + 1];
    char *help_argv[MAX_ARGV + 1];
} custom_t;

typedef struct {
    char *destructive[MAX_PAT];
    int n_destructive;
    char *state[MAX_PAT];
    int n_state;
    char *never_probe[MAX_PAT];
    int n_never;
    custom_t custom[16];
    int n_custom;
} config_t;

static const char *DEF_DESTRUCTIVE[] = {
    "rm", "rmdir", "shred", "wipe", "dd", "truncate", "mkfs", "mkfs.*", "mke2fs", "mkswap", "mkdosfs",
    "fdisk", "sfdisk", "parted", "blkdiscard", "flash_erase*", "flash_lock", "flash_unlock", "flashcp",
    "nandwrite", "mtd", "mtd_debug", "ubiformat", "ubirmvol", "ubimkvol", "ubidetach", "reboot", "halt",
    "poweroff", "shutdown", "init", "telinit", "kill", "killall", "killall5", "pkill", "*_reset*",
    "reset_*", "*reset.sh", "*upgrade*", "*factory*", NULL};
static const char *DEF_STATE[] = {
    "mount", "umount", "swapon", "swapoff", "ifconfig", "ifup", "ifdown", "ip", "route", "iptables*",
    "ip6tables*", "ebtables", "brctl", "vconfig", "tc", "sysctl", "hwclock", "date", "chmod", "chown",
    "chgrp", "mv", "cp", "ln", "touch", "mkdir", "mknod", "mkfifo", "install", "sed", "tee", "patch",
    "crontab", "passwd", "adduser", "addgroup", "deluser", "delgroup", "insmod", "rmmod", "modprobe",
    "udhcpc", "udhcpd", "ntpd", "renice", "nice", "setsid", "chroot", "nvram", "dmcli", "syscfg", NULL};
static const char *DEF_NEVER_PROBE[] = {
    "reboot", "halt", "poweroff", "shutdown", "init", "telinit", "kill*", "pkill", "rm", "rmdir", "dd",
    "mkfs*", "mke2fs", "mkswap", "fdisk", "sfdisk", "flash*", "nand*", "mtd*", "ubi*", "*reset*",
    "*upgrade*", "*factory*", "*reboot*", "shred", "wipe", "blkdiscard", NULL};

static int match_any(char *const *pats, int n, const char *name)
{
    for (int i = 0; i < n; i++)
        if (fnmatch(pats[i], name, 0) == 0) return 1;
    return 0;
}

static int load_list(const cJSON *arr, char **out, int max)
{
    int n = 0;
    const cJSON *it;
    cJSON_ArrayForEach(it, arr) if (cJSON_IsString(it) && n < max) out[n++] = xstrdup(it->valuestring);
    return n;
}

static int load_argv(const cJSON *arr, char **out)
{
    int n = 0;
    const cJSON *it;
    cJSON_ArrayForEach(it, arr) if (cJSON_IsString(it) && n < MAX_ARGV) out[n++] = xstrdup(it->valuestring);
    out[n] = NULL;
    return n;
}

static void load_config(const char *path, config_t *cfg)
{
    memset(cfg, 0, sizeof(*cfg));
    for (int i = 0; DEF_DESTRUCTIVE[i]; i++) cfg->destructive[cfg->n_destructive++] = xstrdup(DEF_DESTRUCTIVE[i]);
    for (int i = 0; DEF_STATE[i]; i++) cfg->state[cfg->n_state++] = xstrdup(DEF_STATE[i]);
    for (int i = 0; DEF_NEVER_PROBE[i]; i++) cfg->never_probe[cfg->n_never++] = xstrdup(DEF_NEVER_PROBE[i]);
    if (!path) return;
    FILE *f = fopen(path, "rb");
    if (!f) die("cannot read %s: %s", path, strerror(errno));
    fseek(f, 0, SEEK_END);
    long n = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *txt = malloc((size_t)n + 1);
    if (!txt) die("out of memory");
    size_t got = fread(txt, 1, (size_t)n, f);
    txt[got] = 0;
    fclose(f);
    cJSON *root = cJSON_Parse(txt);
    if (!root) die("%s: invalid JSON", path);
    const cJSON *a;
    /* "risk": {"destructive": [...], "state_changing": [...], "replace": false} */
    const cJSON *risk = cJSON_GetObjectItemCaseSensitive(root, "risk");
    if (risk) {
        int replace = cJSON_IsTrue(cJSON_GetObjectItemCaseSensitive(risk, "replace"));
        if ((a = cJSON_GetObjectItemCaseSensitive(risk, "destructive"))) {
            if (replace) cfg->n_destructive = 0;
            cfg->n_destructive += load_list(a, cfg->destructive + cfg->n_destructive, MAX_PAT - cfg->n_destructive);
        }
        if ((a = cJSON_GetObjectItemCaseSensitive(risk, "state_changing"))) {
            if (replace) cfg->n_state = 0;
            cfg->n_state += load_list(a, cfg->state + cfg->n_state, MAX_PAT - cfg->n_state);
        }
    }
    if ((a = cJSON_GetObjectItemCaseSensitive(root, "never_probe")))
        cfg->n_never += load_list(a, cfg->never_probe + cfg->n_never, MAX_PAT - cfg->n_never);
    /* "providers": [{"name": "ccsp", "list": ["sh","-c","ls /usr/ccsp"], "help": ["{name}","--help"]}] */
    const cJSON *prov = cJSON_GetObjectItemCaseSensitive(root, "providers");
    const cJSON *p;
    cJSON_ArrayForEach(p, prov) {
        if (cfg->n_custom >= 16) break;
        custom_t *c = &cfg->custom[cfg->n_custom];
        const cJSON *nm = cJSON_GetObjectItemCaseSensitive(p, "name");
        const cJSON *ls = cJSON_GetObjectItemCaseSensitive(p, "list");
        const cJSON *hp = cJSON_GetObjectItemCaseSensitive(p, "help");
        if (!cJSON_IsString(nm) || !cJSON_IsArray(ls) || !cJSON_IsArray(hp)) { warnx("provider entry needs name, list, help"); continue; }
        scopy(c->name, sizeof(c->name), nm->valuestring);
        load_argv(ls, c->list_argv);
        load_argv(hp, c->help_argv);
        cfg->n_custom++;
    }
    cJSON_Delete(root);
    free(txt);
}

/* ------------------------------------------------------------------ */
/* Help-text parser                                                    */
/* ------------------------------------------------------------------ */

static opt_t *find_opt(cmd_t *c, const char *flag, const char *lng)
{
    for (int i = 0; i < c->nopts; i++) {
        if (flag[0] && !strcmp(c->opts[i].flag, flag)) return &c->opts[i];
        if (lng[0] && !strcmp(c->opts[i].lng, lng)) return &c->opts[i];
    }
    return NULL;
}

static opt_t *add_opt(cmd_t *c, const char *flag, const char *lng, const char *arg, int argopt, const char *src)
{
    opt_t *o = find_opt(c, flag, lng);
    if (o) {
        if (!o->lng[0] && lng[0]) scopy(o->lng, sizeof(o->lng), lng);
        if (!o->arg[0] && arg[0]) { scopy(o->arg, sizeof(o->arg), arg); o->arg_optional = argopt; }
        return o;
    }
    if (c->nopts >= MAX_OPTS) return NULL;
    o = &c->opts[c->nopts++];
    memset(o, 0, sizeof(*o));
    scopy(o->flag, sizeof(o->flag), flag);
    scopy(o->lng, sizeof(o->lng), lng);
    scopy(o->arg, sizeof(o->arg), arg);
    o->arg_optional = argopt;
    scopy(o->source, sizeof(o->source), src);
    return o;
}

static void add_pos(cmd_t *c, const char *name, int optional, int repeat)
{
    char n[96];
    scopy(n, sizeof(n), name);
    char *t = trim(n);
    size_t l = strlen(t);
    while (l >= 3 && !strcmp(t + l - 3, "...")) { t[l - 3] = 0; l -= 3; repeat = 1; }
    t = trim(t);
    if (!*t || !strcmp(t, "OPTIONS") || !strcmp(t, "OPTION") || !strcmp(t, "options") || !strcmp(t, "-") ||
        !strcmp(t, "|") || !strcmp(t, "||") || t[0] == '>' || t[0] == '<') return;
    for (int i = 0; i < c->npos; i++)
        if (!strcmp(c->pos[i].name, t)) return;
    if (c->npos >= MAX_POS) return;
    pos_t *p = &c->pos[c->npos++];
    scopy(p->name, sizeof(p->name), t);
    p->optional = optional;
    p->repeat = repeat;
}

/* "-x", "--long", "--long=ARG", "--long[=ARG]", "-x ARG", "-xARG"? -> parts */
static void parse_flag_token(const char *tok, char *flag, size_t fn, char *lng, size_t ln, char *arg, size_t an, int *argopt)
{
    flag[0] = lng[0] = arg[0] = 0;
    *argopt = 0;
    char t[128];
    scopy(t, sizeof(t), tok);
    char *eq = strchr(t, '=');
    char *br = strstr(t, "[=");
    if (br) { *argopt = 1; *br = 0; scopy(arg, an, br + 2); char *e = strchr(arg, ']'); if (e) *e = 0; }
    else if (eq && t[0] == '-' && t[1] == '-') { *eq = 0; scopy(arg, an, eq + 1); }
    if (t[0] == '-' && t[1] == '-') scopy(lng, ln, t);
    else scopy(flag, fn, t);
}

/* Option-list line: "\t-w N\tFormat N columns", "  -a, --all   desc", "\tif=FILE\t\tRead..." */
static int parse_option_line(cmd_t *c, char *line, opt_t **last)
{
    if (!isspace((unsigned char)line[0])) return 0;
    char *s = line;
    while (*s == ' ' || *s == '\t') s++;
    int keyword = 0;
    if (*s != '-') {
        /* keyword option such as if=FILE (dd) */
        char *e = s;
        while (*e && (isalnum((unsigned char)*e) || *e == '_')) e++;
        if (*e != '=' || e == s) return 0;
        keyword = 1;
    }
    if (s[0] == '-' && (s[1] == 0 || isspace((unsigned char)s[1]))) return 0;
    /* split spec / description at a TAB or 2+ spaces */
    char *desc = NULL;
    for (char *p = s; *p; p++) {
        if (*p == '\t' || (p[0] == ' ' && p[1] == ' ')) { *p = 0; desc = p + 1; break; }
    }
    char spec[256];
    scopy(spec, sizeof(spec), s);
    char flag[24] = "", lng[64] = "", arg[64] = "", alias[64] = "";
    int argopt = 0;
    if (keyword) {
        char *eq = strchr(spec, '=');
        scopyn(flag, sizeof(flag), spec, (size_t)(eq - spec + 1));
        scopy(arg, sizeof(arg), eq + 1);
    } else {
        /* tokens separated by ',' or ' ' ; first short -> flag, first long -> lng, words -> arg */
        char *save = NULL;
        for (char *tok = strtok_r(spec, ", ", &save); tok; tok = strtok_r(NULL, ", ", &save)) {
            if (tok[0] == '-') {
                char f[24], l[64], a[64];
                int ao;
                parse_flag_token(tok, f, sizeof(f), l, sizeof(l), a, sizeof(a), &ao);
                if (f[0]) { if (!flag[0]) scopy(flag, sizeof(flag), f); else { if (alias[0]) sappend(alias, sizeof(alias), " "); sappend(alias, sizeof(alias), f); } }
                if (l[0]) { if (!lng[0]) scopy(lng, sizeof(lng), l); else { if (alias[0]) sappend(alias, sizeof(alias), " "); sappend(alias, sizeof(alias), l); } }
                if (a[0] && !arg[0]) { scopy(arg, sizeof(arg), a); argopt = ao; }
            } else if (tok[0] == '[') {
                char a[64];
                scopy(a, sizeof(a), tok + 1);
                char *e = strchr(a, ']');
                if (e) *e = 0;
                if (!arg[0]) { scopy(arg, sizeof(arg), a[0] == '=' ? a + 1 : a); argopt = 1; }
            } else if (!arg[0]) {
                scopy(arg, sizeof(arg), tok);
            } else {
                sappend(arg, sizeof(arg), " ");
                sappend(arg, sizeof(arg), tok);
            }
        }
    }
    if (!flag[0] && !lng[0]) return 0;
    opt_t *o = add_opt(c, flag, lng, arg, argopt, "help");
    if (!o) return 1;
    if (!strcmp(o->source, "usage")) scopy(o->source, sizeof(o->source), "both");
    if (alias[0] && !o->alias[0]) scopy(o->alias, sizeof(o->alias), alias);
    if (desc) {
        char *d = trim(desc);
        if (*d) {
            if (o->desc[0]) sappend(o->desc, sizeof(o->desc), "; ");
            sappend(o->desc, sizeof(o->desc), d);
        }
    }
    *last = o;
    return 1;
}

/* Bracket groups and bare words of a usage line. */
static void parse_usage_body(cmd_t *c, const char *body)
{
    const char *p = body;
    while (*p) {
        while (isspace((unsigned char)*p)) p++;
        if (!*p) break;
        char tok[256];
        int optional = 0, repeat = 0;
        if (*p == '[') {
            int depth = 0;
            const char *s = p;
            do {
                if (*p == '[') depth++;
                else if (*p == ']') depth--;
                p++;
            } while (*p && depth > 0);
            scopyn(tok, sizeof(tok), s + 1, (size_t)(p - s - (depth ? 1 : 2)));
            optional = 1;
            if (!strncmp(p, "...", 3)) { repeat = 1; p += 3; }
        } else {
            const char *s = p;
            int depth = 0;
            while (*p && (depth || !isspace((unsigned char)*p))) {
                if (*p == '{' || *p == '(') depth++;
                else if ((*p == '}' || *p == ')') && depth) depth--;
                p++;
            }
            scopyn(tok, sizeof(tok), s, (size_t)(p - s));
        }
        char *t = trim(tok);
        if (!*t) continue;
        if (t[0] == '-' && t[1] && t[1] != ' ') {
            /* option group: "-abc", "-w WIDTH", "-a|-b", "--long[=X]" */
            char work[256];
            scopy(work, sizeof(work), t);
            char *alt_save = NULL;
            for (char *alt = strtok_r(work, "|", &alt_save); alt; alt = strtok_r(NULL, "|", &alt_save)) {
                alt = trim(alt);
                char *sp = strchr(alt, ' ');
                char argbuf[64] = "";
                if (sp) { *sp = 0; scopy(argbuf, sizeof(argbuf), trim(sp + 1)); }
                if (alt[0] != '-') continue;
                if (alt[1] == '-') {
                    char f[24], l[64], a[64];
                    int ao;
                    parse_flag_token(alt, f, sizeof(f), l, sizeof(l), a, sizeof(a), &ao);
                    add_opt(c, "", l, a[0] ? a : argbuf, ao, "usage");
                } else if (!argbuf[0] && strlen(alt) > 2 && !strchr(alt, '=')) {
                    /* cluster of single-letter flags: -1AaCx */
                    int known_multi = 0;
                    for (int i = 0; i < c->nopts; i++)
                        if (!strcmp(c->opts[i].flag, alt)) known_multi = 1;
                    if (known_multi) continue;
                    for (const char *q = alt + 1; *q; q++) {
                        if (!isalnum((unsigned char)*q)) continue;
                        char f[3] = {'-', *q, 0};
                        add_opt(c, f, "", "", 0, "usage");
                    }
                } else {
                    char f[24];
                    scopyn(f, sizeof(f), alt, strcspn(alt, "="));
                    add_opt(c, f, "", argbuf, 0, "usage");
                }
            }
        } else if (isalpha((unsigned char)t[0]) && strchr(t, '=') && strspn(t, "abcdefghijklmnopqrstuvwxyz_") == (size_t)(strchr(t, '=') - t)) {
            /* keyword options such as dd's "if=FILE" or "ibs=N obs=N/bs=N" */
            char work[256];
            scopy(work, sizeof(work), t);
            char *save = NULL;
            for (char *kw = strtok_r(work, " ", &save); kw; kw = strtok_r(NULL, " ", &save)) {
                char *eq = strchr(kw, '=');
                if (!eq) continue;
                char f[24];
                scopyn(f, sizeof(f), kw, (size_t)(eq - kw + 1));
                add_opt(c, f, "", eq + 1, 0, "usage");
            }
        } else {
            add_pos(c, t, optional, repeat);
        }
    }
}

static void parse_help(cmd_t *c, const char *text)
{
    char *buf = xstrdup(text);
    char *lines[4096];
    int nl = 0;
    for (char *s = buf, *save = NULL, *ln = strtok_r(s, "\n", &save); ln && nl < 4096; ln = strtok_r(NULL, "\n", &save))
        lines[nl++] = ln;
    /* strip \r */
    for (int i = 0; i < nl; i++) { char *r = strchr(lines[i], '\r'); if (r) *r = 0; }

    int u = -1;
    for (int i = 0; i < nl; i++) {
        const char *t = lines[i];
        while (isspace((unsigned char)*t)) t++;
        if (!strncasecmp(t, "usage:", 6)) { u = i; break; }
    }
    int after_usage = 0;
    if (u >= 0) {
        const char *t = lines[u];
        while (isspace((unsigned char)*t)) t++;
        t += 6;
        while (isspace((unsigned char)*t)) t++;
        char usage[2048];
        scopy(usage, sizeof(usage), t);
        int j = u + 1;
        /* Continuation: following lines that look like syntax (indented, or
         * starting with '['), until a blank line, an option line, or prose. */
        while (j < nl && (lines[j][0] == '\t' || lines[j][0] == ' ' || lines[j][0] == '[')) {
            char *s = lines[j];
            while (isspace((unsigned char)*s)) s++;
            if (*s == '-' || !*s) break;
            if (strncasecmp(s, "or:", 3) && !strpbrk(s, "[{|<")) break; /* prose, not syntax */
            if (!strncasecmp(s, "or:", 3)) {
                if (c->nforms < MAX_FORMS) scopy(c->forms[c->nforms++], sizeof(c->forms[0]), trim(s + 3));
            } else {
                sappend(usage, sizeof(usage), " ");
                sappend(usage, sizeof(usage), s);
            }
            j++;
        }
        /* collapse tabs and runs of spaces */
        {
            char *w = usage;
            int sp = 0;
            for (char *r = usage; *r; r++) {
                if (isspace((unsigned char)*r)) { if (!sp && w != usage) *w++ = ' '; sp = 1; }
                else { *w++ = *r; sp = 0; }
            }
            while (w > usage && w[-1] == ' ') w--;
            *w = 0;
        }
        scopy(c->usage, sizeof(c->usage), usage);
        after_usage = j;
        /* body after the command name */
        const char *body = usage;
        size_t nlen = strlen(c->name);
        const char *base = strrchr(c->name, '/');
        if (!strncmp(body, c->name, nlen) && (body[nlen] == 0 || isspace((unsigned char)body[nlen]))) body += nlen;
        else if (base && !strncmp(body, base + 1, strlen(base + 1))) body += strlen(base + 1);
        else { while (*body && !isspace((unsigned char)*body)) body++; }
        parse_usage_body(c, body);
    }

    opt_t *last = NULL;
    for (int i = after_usage; i < nl; i++) {
        char *ln = lines[i];
        char tmp[1024];
        scopy(tmp, sizeof(tmp), ln);
        char *t = trim(tmp);
        if (!*t) { last = NULL; continue; }
        if (parse_option_line(c, ln, &last)) continue;
        if (last && isspace((unsigned char)ln[0])) {
            /* description continuation */
            if (last->desc[0]) sappend(last->desc, sizeof(last->desc), " ");
            sappend(last->desc, sizeof(last->desc), t);
            continue;
        }
        last = NULL;
        if (isspace((unsigned char)ln[0])) continue;
        size_t nlen = strlen(c->name);
        if (!strncmp(t, c->name, nlen) && t[nlen] == ' ') {
            /* an extra usage form, e.g. "ip addr add|del IFADDR dev IFACE" */
            if (c->nforms < MAX_FORMS) scopy(c->forms[c->nforms++], sizeof(c->forms[0]), t);
            continue;
        }
        if (!strncasecmp(t, "busybox v", 9) || !strncasecmp(t, "toybox", 6) || strstr(t, ":=")) continue;
        if (!c->summary[0] && u >= 0 && i > u) scopy(c->summary, sizeof(c->summary), t);
    }
    free(buf);
}

/* ------------------------------------------------------------------ */
/* Providers                                                           */
/* ------------------------------------------------------------------ */

typedef struct {
    const char *provider;
    const char *bin;
    char bin_path[PATH_MAX];
    char version[160];
    const char *dirs;
    long timeout_ms;
    int probe, scripts, raw;
    char *filters[64];
    int nfilters;
    const config_t *cfg;
    const custom_t *custom;
} ctx_t;

static int find_in_path(const char *name, char *out)
{
    if (strchr(name, '/')) { if (access(name, X_OK) == 0) { scopy(out, PATH_MAX, name); return 1; } return 0; }
    const char *path = getenv("PATH");
    if (!path) path = "/bin:/usr/bin:/sbin:/usr/sbin";
    char *dup = xstrdup(path), *save = NULL;
    for (char *d = strtok_r(dup, ":", &save); d; d = strtok_r(NULL, ":", &save)) {
        char p[PATH_MAX];
        snprintf(p, sizeof(p), "%s/%s", d, name);
        if (access(p, X_OK) == 0) { scopy(out, PATH_MAX, p); free(dup); return 1; }
    }
    free(dup);
    return 0;
}

static int keep(const ctx_t *x, const char *name)
{
    if (!x->nfilters) return 1;
    for (int i = 0; i < x->nfilters; i++)
        if (fnmatch(x->filters[i], name, 0) == 0) return 1;
    return 0;
}

static const char *classify(const config_t *cfg, const char *name)
{
    const char *b = strrchr(name, '/');
    b = b ? b + 1 : name;
    if (match_any(cfg->destructive, cfg->n_destructive, b)) return "destructive";
    if (match_any(cfg->state, cfg->n_state, b)) return "state-changing";
    return "unclassified";
}

static int file_kind(const char *path, char *kind, size_t kn)
{
    char hdr[4] = {0};
    int fd = open(path, O_RDONLY);
    if (fd < 0) { scopy(kind, kn, "other"); return 0; }
    ssize_t n = read(fd, hdr, 4);
    close(fd);
    if (n >= 4 && !memcmp(hdr, "\x7f" "ELF", 4)) scopy(kind, kn, "elf");
    else if (n >= 2 && hdr[0] == '#' && hdr[1] == '!') scopy(kind, kn, "script");
    else scopy(kind, kn, "other");
    return 1;
}

static int cmp_cmd(const void *a, const void *b)
{
    return strcmp(((const cmd_t *)a)->name, ((const cmd_t *)b)->name);
}

/* Collect command names. Returns count; fills cmds[].name/path/via/kind. */
static int list_commands(ctx_t *x, cmd_t *cmds)
{
    int n = 0;
    const char *p = x->provider;
    if (!strcmp(p, "busybox") || !strcmp(p, "toybox")) {
        const char *bin = x->bin ? x->bin : p;
        if (!find_in_path(bin, x->bin_path)) die("%s binary not found (use -b PATH)", p);
        capture_t c;
        char *ver_argv[] = {x->bin_path, NULL};
        capture(ver_argv, x->timeout_ms, &c);
        char first[160] = "";
        sscanf(c.out, "%159[^\n]", first);
        scopy(x->version, sizeof(x->version), first);
        char *names = NULL;
        if (!strcmp(p, "busybox")) {
            capture_t l;
            char *list_argv[] = {x->bin_path, "--list", NULL};
            capture(list_argv, x->timeout_ms, &l);
            if (l.rc == 0 && l.len) { names = l.out; free(c.out); }
            else {
                free(l.out);
                char *cd = strstr(c.out, "Currently defined functions:");
                if (!cd) die("cannot list applets from %s", x->bin_path);
                names = c.out;
                memmove(names, cd + 28, strlen(cd + 28) + 1);
            }
        } else {
            names = c.out; /* toybox prints its command list with no arguments */
        }
        char *save = NULL;
        for (char *tok = strtok_r(names, " ,\t\n", &save); tok && n < MAX_CMDS; tok = strtok_r(NULL, " ,\t\n", &save)) {
            if (!keep(x, tok)) continue;
            if (!isalnum((unsigned char)tok[0]) && tok[0] != '[') continue;
            memset(&cmds[n], 0, sizeof(cmd_t));
            scopy(cmds[n].name, sizeof(cmds[n].name), tok);
            scopy(cmds[n].path, sizeof(cmds[n].path), x->bin_path);
            scopy(cmds[n].via, sizeof(cmds[n].via), p);
            scopy(cmds[n].kind, sizeof(cmds[n].kind), "applet");
            n++;
        }
        free(names);
    } else if (!strcmp(p, "path")) {
        const char *dirs = x->dirs ? x->dirs : getenv("PATH");
        if (!dirs) dirs = "/bin:/sbin:/usr/bin:/usr/sbin";
        char *dup = xstrdup(dirs), *save = NULL;
        scopy(x->version, sizeof(x->version), dirs);
        for (char *d = strtok_r(dup, ":", &save); d; d = strtok_r(NULL, ":", &save)) {
            DIR *dir = opendir(d);
            if (!dir) continue;
            struct dirent *de;
            while ((de = readdir(dir)) && n < MAX_CMDS) {
                if (de->d_name[0] == '.') continue;
                if (!keep(x, de->d_name)) continue;
                char full[PATH_MAX];
                snprintf(full, sizeof(full), "%s/%s", d, de->d_name);
                struct stat st;
                if (stat(full, &st) != 0 || !S_ISREG(st.st_mode) || access(full, X_OK) != 0) continue;
                int dupname = 0;
                for (int i = 0; i < n && !dupname; i++) dupname = !strcmp(cmds[i].name, de->d_name);
                if (dupname) continue; /* first in PATH order wins */
                memset(&cmds[n], 0, sizeof(cmd_t));
                scopy(cmds[n].name, sizeof(cmds[n].name), de->d_name);
                scopy(cmds[n].path, sizeof(cmds[n].path), full);
                char real[PATH_MAX];
                const char *via = "path";
                if (realpath(full, real)) {
                    const char *rb = strrchr(real, '/');
                    rb = rb ? rb + 1 : real;
                    if (!strcmp(rb, "busybox")) via = "busybox";
                    else if (!strcmp(rb, "toybox")) via = "toybox";
                }
                scopy(cmds[n].via, sizeof(cmds[n].via), via);
                if (!strcmp(via, "path")) file_kind(full, cmds[n].kind, sizeof(cmds[n].kind));
                else scopy(cmds[n].kind, sizeof(cmds[n].kind), "applet");
                n++;
            }
            closedir(dir);
        }
        free(dup);
    } else if (x->custom) {
        capture_t c;
        capture((char *const *)x->custom->list_argv, x->timeout_ms * 3, &c);
        scopy(x->version, sizeof(x->version), x->custom->name);
        char *save = NULL;
        for (char *tok = strtok_r(c.out, "\n", &save); tok && n < MAX_CMDS; tok = strtok_r(NULL, "\n", &save)) {
            char *t = trim(tok);
            if (!*t || !keep(x, t)) continue;
            memset(&cmds[n], 0, sizeof(cmd_t));
            scopy(cmds[n].name, sizeof(cmds[n].name), t);
            scopy(cmds[n].via, sizeof(cmds[n].via), x->custom->name);
            char found[PATH_MAX];
            if (find_in_path(t, found)) {
                scopy(cmds[n].path, sizeof(cmds[n].path), found);
                file_kind(found, cmds[n].kind, sizeof(cmds[n].kind));
            } else {
                scopy(cmds[n].kind, sizeof(cmds[n].kind), "other");
            }
            n++;
        }
        free(c.out);
    } else {
        die("unknown provider '%s' (busybox, toybox, path, or a provider from -c)", p);
    }
    qsort(cmds, (size_t)n, sizeof(cmd_t), cmp_cmd);
    for (int i = 0; i < n; i++) scopy(cmds[i].risk, sizeof(cmds[i].risk), classify(x->cfg, cmds[i].name));
    return n;
}

static void probe_command(const ctx_t *x, cmd_t *c)
{
    char *argv[MAX_ARGV + 1];
    char bb[] = "--help", help[] = "help";
    int via_multicall = !strcmp(c->via, "busybox") || !strcmp(c->via, "toybox");
    const char *bin = x->bin_path[0] ? x->bin_path : (!strcmp(c->via, "busybox") ? "busybox" : "toybox");
    if (via_multicall) {
        /* BusyBox prints usage for "<applet> --help" without running the
         * applet; Toybox has a separate "help" applet. Both are safe. */
        if (!strcmp(c->via, "busybox")) { argv[0] = (char *)bin; argv[1] = c->name; argv[2] = bb; argv[3] = NULL; }
        else { argv[0] = (char *)bin; argv[1] = help; argv[2] = c->name; argv[3] = NULL; }
    } else {
        if (!x->probe) { scopy(c->skipped, sizeof(c->skipped), "listed only (use --probe to read help)"); return; }
        if (match_any(x->cfg->never_probe, x->cfg->n_never, c->name)) { scopy(c->skipped, sizeof(c->skipped), "on the never-probe list"); return; }
        if (!strcmp(c->kind, "script") && !x->scripts) { scopy(c->skipped, sizeof(c->skipped), "shell script (use --scripts to probe)"); return; }
        if (strcmp(c->kind, "elf") && strcmp(c->kind, "script")) { scopy(c->skipped, sizeof(c->skipped), "not an ELF binary or script"); return; }
        if (x->custom) {
            int k = 0;
            for (int i = 0; x->custom->help_argv[i] && k < MAX_ARGV; i++)
                argv[k++] = !strcmp(x->custom->help_argv[i], "{name}") ? (c->path[0] ? c->path : c->name) : x->custom->help_argv[i];
            argv[k] = NULL;
        } else {
            argv[0] = c->path;
            argv[1] = bb;
            argv[2] = NULL;
        }
    }
    capture_t cap;
    capture(argv, x->timeout_ms, &cap);
    c->probed = 1;
    c->help_rc = cap.rc;
    c->timed_out = cap.timed_out;
    if (cap.len) parse_help(c, cap.out);
    if (x->raw) c->raw = cap.out;
    else free(cap.out);
    if (!c->usage[0] && !c->nopts) {
        if (cap.timed_out) scopy(c->skipped, sizeof(c->skipped), "help timed out");
        else if (!cap.len) scopy(c->skipped, sizeof(c->skipped), "no help output");
        else scopy(c->skipped, sizeof(c->skipped), "no usage section in help output");
    }
}

/* ------------------------------------------------------------------ */
/* Output                                                              */
/* ------------------------------------------------------------------ */

static cJSON *cmd_json(const cmd_t *c)
{
    cJSON *o = cJSON_CreateObject();
    cJSON_AddStringToObject(o, "name", c->name);
    cJSON_AddStringToObject(o, "via", c->via);
    cJSON_AddStringToObject(o, "path", c->path);
    cJSON_AddStringToObject(o, "kind", c->kind);
    cJSON_AddStringToObject(o, "risk", c->risk);
    cJSON_AddBoolToObject(o, "probed", c->probed);
    if (c->probed) cJSON_AddNumberToObject(o, "help_rc", c->help_rc);
    if (c->skipped[0]) cJSON_AddStringToObject(o, "skipped", c->skipped);
    if (c->usage[0]) cJSON_AddStringToObject(o, "usage", c->usage);
    if (c->summary[0]) cJSON_AddStringToObject(o, "summary", c->summary);
    cJSON *opts = cJSON_AddArrayToObject(o, "options");
    for (int i = 0; i < c->nopts; i++) {
        const opt_t *p = &c->opts[i];
        cJSON *j = cJSON_CreateObject();
        if (p->flag[0]) cJSON_AddStringToObject(j, "flag", p->flag);
        if (p->lng[0]) cJSON_AddStringToObject(j, "long", p->lng);
        if (p->arg[0]) cJSON_AddStringToObject(j, "arg", p->arg);
        if (p->arg[0] && p->arg_optional) cJSON_AddBoolToObject(j, "arg_optional", 1);
        if (p->alias[0]) cJSON_AddStringToObject(j, "alias", p->alias);
        if (p->desc[0]) cJSON_AddStringToObject(j, "description", p->desc);
        cJSON_AddStringToObject(j, "source", p->source);
        cJSON_AddItemToArray(opts, j);
    }
    cJSON *args = cJSON_AddArrayToObject(o, "arguments");
    for (int i = 0; i < c->npos; i++) {
        cJSON *j = cJSON_CreateObject();
        cJSON_AddStringToObject(j, "name", c->pos[i].name);
        cJSON_AddBoolToObject(j, "optional", c->pos[i].optional);
        cJSON_AddBoolToObject(j, "repeat", c->pos[i].repeat);
        if (strchr(c->pos[i].name, '|')) {
            cJSON *ch = cJSON_AddArrayToObject(j, "choices");
            char tmp[96];
            scopy(tmp, sizeof(tmp), c->pos[i].name);
            char *s = tmp;
            if (*s == '{') s++;
            char *e = strchr(s, '}');
            if (e) *e = 0;
            char *save = NULL;
            for (char *t = strtok_r(s, "|", &save); t; t = strtok_r(NULL, "|", &save))
                cJSON_AddItemToArray(ch, cJSON_CreateString(t));
        }
        cJSON_AddItemToArray(args, j);
    }
    if (c->nforms) {
        cJSON *f = cJSON_AddArrayToObject(o, "forms");
        for (int i = 0; i < c->nforms; i++) cJSON_AddItemToArray(f, cJSON_CreateString(c->forms[i]));
    }
    if (c->raw) cJSON_AddStringToObject(o, "raw_help", c->raw);
    return o;
}

static void md_cell(FILE *f, const char *s)
{
    for (; *s; s++) {
        if (*s == '|') fputs("\\|", f);
        else if (*s == '\n') fputc(' ', f);
        else fputc(*s, f);
    }
}

static void write_outputs(const ctx_t *x, cmd_t *cmds, int n, const char *prefix, int jsonl)
{
    char path[PATH_MAX];
    time_t now = time(NULL);
    char ts[64];
    strftime(ts, sizeof(ts), "%Y-%m-%dT%H:%M:%S%z", localtime(&now));
    struct utsname un;
    uname(&un);

    int probed = 0, parsed = 0, nd = 0, ns = 0, total_opts = 0;
    for (int i = 0; i < n; i++) {
        probed += cmds[i].probed;
        parsed += cmds[i].usage[0] || cmds[i].nopts;
        nd += !strcmp(cmds[i].risk, "destructive");
        ns += !strcmp(cmds[i].risk, "state-changing");
        total_opts += cmds[i].nopts;
    }

    /* JSON */
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "tool", "cmdscan " CMDSCAN_VERSION);
    cJSON_AddStringToObject(root, "generated", ts);
    cJSON_AddStringToObject(root, "host", un.nodename);
    cJSON_AddStringToObject(root, "kernel", un.release);
    cJSON *ns_ = cJSON_AddObjectToObject(root, "namespace");
    cJSON_AddStringToObject(ns_, "provider", x->provider);
    if (x->bin_path[0]) cJSON_AddStringToObject(ns_, "binary", x->bin_path);
    if (x->version[0]) cJSON_AddStringToObject(ns_, "version", x->version);
    cJSON *sum = cJSON_AddObjectToObject(root, "summary");
    cJSON_AddNumberToObject(sum, "commands", n);
    cJSON_AddNumberToObject(sum, "probed", probed);
    cJSON_AddNumberToObject(sum, "parsed", parsed);
    cJSON_AddNumberToObject(sum, "options", total_opts);
    cJSON_AddNumberToObject(sum, "destructive", nd);
    cJSON_AddNumberToObject(sum, "state_changing", ns);
    cJSON *sg = cJSON_AddArrayToObject(root, "safety_gate_candidates");
    for (int i = 0; i < n; i++)
        if (!strcmp(cmds[i].risk, "destructive")) cJSON_AddItemToArray(sg, cJSON_CreateString(cmds[i].name));
    cJSON *arr = cJSON_AddArrayToObject(root, "commands");
    for (int i = 0; i < n; i++) cJSON_AddItemToArray(arr, cmd_json(&cmds[i]));
    char *txt = cJSON_Print(root);
    snprintf(path, sizeof(path), "%s.json", prefix);
    FILE *f = fopen(path, "w");
    if (!f) die("cannot write %s: %s", path, strerror(errno));
    fputs(txt, f);
    fputc('\n', f);
    fclose(f);
    free(txt);
    cJSON_Delete(root);

    if (jsonl) {
        snprintf(path, sizeof(path), "%s.jsonl", prefix);
        f = fopen(path, "w");
        if (!f) die("cannot write %s: %s", path, strerror(errno));
        for (int i = 0; i < n; i++) {
            cJSON *o = cmd_json(&cmds[i]);
            char *line = cJSON_PrintUnformatted(o);
            fprintf(f, "%s\n", line);
            free(line);
            cJSON_Delete(o);
        }
        fclose(f);
    }

    /* Markdown */
    snprintf(path, sizeof(path), "%s.md", prefix);
    f = fopen(path, "w");
    if (!f) die("cannot write %s: %s", path, strerror(errno));
    fprintf(f, "# Command namespace: %s\n\n", x->provider);
    fprintf(f, "%d commands found, %d with parsed help, %d options in total. **%d destructive** and %d state-changing "
               "commands by name.\n\n",
            n, parsed, total_opts, nd, ns);
    fprintf(f, "- Generated: %s\n- Host: %s, kernel %s\n", ts, un.nodename, un.release);
    if (x->bin_path[0]) fprintf(f, "- Binary: `%s`\n", x->bin_path);
    if (x->version[0]) fprintf(f, "- Version: %s\n", x->version);
    fprintf(f, "\n## Safety Gate candidates\n\nCommands classified destructive by name. Review before adding them to the "
               "blocked list.\n\n");
    int first = 1;
    for (int i = 0; i < n; i++)
        if (!strcmp(cmds[i].risk, "destructive")) { fprintf(f, "%s`%s`", first ? "" : ", ", cmds[i].name); first = 0; }
    fprintf(f, "%s\n\n## Commands\n\n| Command | Risk | Options | Arguments | Summary |\n| --- | --- | --- | --- | --- |\n",
            first ? "None found." : "");
    for (int i = 0; i < n; i++) {
        cmd_t *c = &cmds[i];
        int safe = strspn(c->name, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_.-") == strlen(c->name);
        int detailed = c->usage[0] || c->nopts;
        if (safe && detailed) fprintf(f, "| [%s](#cmd-%s) | %s | %d | ", c->name, c->name, c->risk, c->nopts);
        else { fputs("| `", f); md_cell(f, c->name); fprintf(f, "` | %s | %d | ", c->risk, c->nopts); }
        for (int k = 0; k < c->npos; k++) {
            if (k) fputs(", ", f);
            fputs(c->pos[k].optional ? "[" : "", f);
            md_cell(f, c->pos[k].name);
            fputs(c->pos[k].optional ? "]" : "", f);
            if (c->pos[k].repeat) fputs("...", f);
        }
        fputs(" | ", f);
        md_cell(f, c->summary[0] ? c->summary : (c->skipped[0] ? c->skipped : ""));
        fputs(" |\n", f);
    }
    fprintf(f, "\n## Details\n");
    for (int i = 0; i < n; i++) {
        cmd_t *c = &cmds[i];
        if (!c->usage[0] && !c->nopts) continue;
        fprintf(f, "\n<a id=\"cmd-%s\"></a>\n### %s\n\n", c->name, c->name);
        if (c->summary[0]) fprintf(f, "%s\n\n", c->summary);
        fprintf(f, "Risk: %s. Source: %s.\n\n", c->risk, c->via);
        if (c->usage[0]) fprintf(f, "```text\n%s %s\n", c->name, c->usage + (strncmp(c->usage, c->name, strlen(c->name)) ? 0 : strlen(c->name)));
        for (int k = 0; k < c->nforms; k++) fprintf(f, "%s\n", c->forms[k]);
        if (c->usage[0]) fprintf(f, "```\n\n");
        if (c->nopts) {
            fprintf(f, "| Option | Long | Argument | Description |\n| --- | --- | --- | --- |\n");
            for (int k = 0; k < c->nopts; k++) {
                opt_t *o = &c->opts[k];
                fputs("| ", f);
                md_cell(f, o->flag);
                if (o->alias[0]) { fputs(" (", f); md_cell(f, o->alias); fputs(")", f); }
                fputs(" | ", f);
                md_cell(f, o->lng);
                fputs(" | ", f);
                if (o->arg[0]) { if (o->arg_optional) fputs("[", f); md_cell(f, o->arg); if (o->arg_optional) fputs("]", f); }
                fputs(" | ", f);
                md_cell(f, o->desc);
                fputs(" |\n", f);
            }
        }
    }
    fclose(f);

    printf("%d commands, %d probed, %d parsed, %d options; %d destructive, %d state-changing\n", n, probed, parsed,
           total_opts, nd, ns);
    printf("written: %s.json  %s.md%s%s%s\n", prefix, prefix, jsonl ? "  " : "", jsonl ? prefix : "", jsonl ? ".jsonl" : "");
}

/* ------------------------------------------------------------------ */
/* main                                                                */
/* ------------------------------------------------------------------ */

static void usage(void)
{
    fprintf(stderr,
            "cmdscan %s - list the commands, options and arguments of a command namespace\n\n"
            "  cmdscan list -p busybox|toybox|path|<custom> [-b BIN] [-d DIRS] [-c CONFIG] [-f GLOB]...\n"
            "  cmdscan scan -p <provider> -o <prefix> [-b BIN] [-d DIRS] [-c CONFIG] [-f GLOB]... [-t MS]\n"
            "               [--probe] [--scripts] [--raw] [--jsonl]\n"
            "  cmdscan show -p <provider> [-b BIN] [-c CONFIG] [--probe] <command>\n",
            CMDSCAN_VERSION);
    exit(2);
}

int main(int argc, char **argv)
{
    if (argc < 2) usage();
    const char *sub = argv[1];
    static ctx_t x;
    static config_t cfg;
    const char *cfg_path = NULL, *out = NULL, *one = NULL;
    int jsonl = 0;
    x.provider = NULL;
    x.timeout_ms = 3000;
    for (int i = 2; i < argc; i++) {
        const char *a = argv[i];
        const char *v = i + 1 < argc ? argv[i + 1] : NULL;
        if (!strcmp(a, "-p") && v) { x.provider = v; i++; }
        else if (!strcmp(a, "-b") && v) { x.bin = v; i++; }
        else if (!strcmp(a, "-d") && v) { x.dirs = v; i++; }
        else if (!strcmp(a, "-c") && v) { cfg_path = v; i++; }
        else if (!strcmp(a, "-o") && v) { out = v; i++; }
        else if (!strcmp(a, "-t") && v) { x.timeout_ms = atol(v); i++; }
        else if (!strcmp(a, "-f") && v) { if (x.nfilters < 64) x.filters[x.nfilters++] = (char *)v; i++; }
        else if (!strcmp(a, "--probe")) x.probe = 1;
        else if (!strcmp(a, "--scripts")) x.scripts = 1;
        else if (!strcmp(a, "--raw")) x.raw = 1;
        else if (!strcmp(a, "--jsonl")) jsonl = 1;
        else if (a[0] != '-' && !one) one = a;
        else usage();
    }
    if (!x.provider) usage();
    if (x.timeout_ms < 100) x.timeout_ms = 100;
    load_config(cfg_path, &cfg);
    x.cfg = &cfg;
    if (strcmp(x.provider, "busybox") && strcmp(x.provider, "toybox") && strcmp(x.provider, "path")) {
        for (int i = 0; i < cfg.n_custom; i++)
            if (!strcmp(cfg.custom[i].name, x.provider)) x.custom = &cfg.custom[i];
        if (!x.custom) die("unknown provider '%s'; define it under \"providers\" in a -c config", x.provider);
    }

    cmd_t *cmds = calloc(MAX_CMDS, sizeof(cmd_t));
    if (!cmds) die("out of memory");

    if (!strcmp(sub, "show")) {
        if (!one) usage();
        x.filters[0] = (char *)one;
        x.nfilters = 1;
        x.raw = 1;
    }
    int n = list_commands(&x, cmds);

    if (!strcmp(sub, "list")) {
        printf("%-28s %-10s %-8s %-15s %s\n", "COMMAND", "VIA", "KIND", "RISK", "PATH");
        for (int i = 0; i < n; i++)
            printf("%-28s %-10s %-8s %-15s %s\n", cmds[i].name, cmds[i].via, cmds[i].kind, cmds[i].risk, cmds[i].path);
        printf("\n%d command(s)%s%s\n", n, x.version[0] ? " - " : "", x.version);
        return 0;
    }
    if (!strcmp(sub, "show")) {
        if (!n) die("command '%s' not found in provider %s", one, x.provider);
        x.probe = x.probe || strcmp(cmds[0].via, "path");
        probe_command(&x, &cmds[0]);
        cJSON *o = cmd_json(&cmds[0]);
        char *t = cJSON_Print(o);
        puts(t);
        free(t);
        cJSON_Delete(o);
        return 0;
    }
    if (!strcmp(sub, "scan")) {
        if (!out) usage();
        fprintf(stderr, "cmdscan %s: provider=%s, %d command(s)\n", CMDSCAN_VERSION, x.provider, n);
        for (int i = 0; i < n; i++) {
            probe_command(&x, &cmds[i]);
            if ((i + 1) % 50 == 0) fprintf(stderr, "  %d/%d\n", i + 1, n);
        }
        write_outputs(&x, cmds, n, out, jsonl);
        return 0;
    }
    usage();
    return 2;
}
