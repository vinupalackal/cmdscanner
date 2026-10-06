# cmdscan: command namespace discovery

`cmdscan` lists every command in a **namespace** and works out each one's usage, summary, options and arguments from its help text. It writes the result as JSON, JSON Lines and Markdown.

A namespace is a set of commands reached the same way:

| Provider | Namespace | How commands are listed | How help is read |
| --- | --- | --- | --- |
| `busybox` | Applets of a BusyBox binary | `busybox --list` | `busybox <applet> --help` (BusyBox prints usage without running the applet) |
| `toybox` | Applets of a Toybox binary | `toybox` | `toybox help <command>` |
| `path` | Executables in a set of directories | Directory scan (first match in PATH order wins) | `<command> --help`, **only with `--probe`** |
| custom | Anything you describe in a config file | Your list command | Your help command, **only with `--probe`** |

Typical uses on an RDK-B device:

- see exactly which applets and options this device's BusyBox build has (it varies by platform and config);
- seed the Safety Gate's destructive-command list from what is really installed;
- build per-command option allowlists for the runtime's policy checks;
- compare two firmware builds to see which commands or options appeared or disappeared.

## Build

```sh
make                      # vendored cJSON
make CJSON=system         # platform libcjson (RDK-B)
make CC=<cross-gcc> CJSON=system
```

For RDK-B images, the `cmdscan` recipe in the `meta-cpe-agent` layer builds and installs it.

## Usage

```text
cmdscan list -p busybox|toybox|path|<custom> [-b BIN] [-d DIRS] [-c CONFIG] [-f GLOB]...
cmdscan scan -p <provider> -o <prefix> [-b BIN] [-d DIRS] [-c CONFIG] [-f GLOB]... [-t MS]
             [--probe] [--scripts] [--raw] [--jsonl]
cmdscan show -p <provider> [-b BIN] [-c CONFIG] [--probe] <command>
```

| Option | Meaning |
| --- | --- |
| `-p` | Provider: `busybox`, `toybox`, `path`, or a name defined under `providers` in the config |
| `-b PATH` | BusyBox or Toybox binary (default: found on `PATH`) |
| `-d DIRS` | Colon-separated directories for `path` (default: `$PATH`) |
| `-c FILE` | Config file: custom providers, extra risk patterns, never-probe patterns |
| `-f GLOB` | Only commands matching the glob; repeatable (`-f 'if*' -f 'ip*'`) |
| `-t MS` | Help timeout per command (default 3000) |
| `--probe` | For `path` and custom providers, actually run the help command. Without it they are only listed |
| `--scripts` | With `--probe`, also probe shell scripts (ELF binaries only by default) |
| `--raw` | Include the raw help text in the JSON |
| `--jsonl` | Also write `<prefix>.jsonl`, one command per line |

Examples:

```sh
# Every BusyBox applet on this device
cmdscan scan -p busybox -o /tmp/busybox --jsonl

# One command, for a quick look
cmdscan show -p busybox ip

# Native binaries in /usr/sbin and /usr/bin, reading their help
cmdscan scan -p path -d /usr/sbin:/usr/bin --probe -o /tmp/native

# A custom namespace from the config file
cmdscan scan -c /usr/share/cmdscan/cmdscan.example.json -p sbin-tools --probe -o /tmp/sbin
```

## Output

`<prefix>.json` holds the namespace, a summary, the Safety Gate candidates and every command:

```json
{
  "name": "reboot",
  "via": "busybox",
  "risk": "destructive",
  "usage": "reboot [-d DELAY] [-nf]",
  "summary": "Reboot the system",
  "options": [
    { "flag": "-d", "arg": "DELAY", "description": "Delay interval", "source": "both" },
    { "flag": "-n", "description": "Do not sync", "source": "both" },
    { "flag": "-f", "description": "Force (don't go through init)", "source": "both" }
  ],
  "arguments": []
}
```

| Field | Meaning |
| --- | --- |
| `options[].flag` / `long` | Short form (`-a`, or a keyword like `if=` for dd) and long form (`--all`) |
| `options[].arg` | Argument placeholder (`N`, `FILE`, or choices like `notrunc\|noerror\|sync`); `arg_optional` when written `[=ARG]` |
| `options[].alias` | Other spellings of the same option |
| `options[].source` | `usage` (from the usage line), `help` (from the option list) or `both` |
| `arguments[]` | Positional arguments with `optional`, `repeat` (`FILE...`) and `choices` (`start\|stop`) |
| `forms[]` | Extra usage lines, such as `ip` subcommands (`ip route add\|del ...`) |
| `risk` | `destructive`, `state-changing` or `unclassified`, by name (see below) |
| `skipped` | Why a command has no parsed help (not probed, never-probe list, no usage section) |

`<prefix>.md` is the readable version: summary, Safety Gate candidates, a table of all commands, and per-command usage and option tables. `<prefix>.jsonl` has the same command objects, one per line, for `jq`, log pipelines or diffing two firmware builds.

## Risk classification

Risk is decided **by command name only**, as a starting point for review:

- **destructive:** deletes data, erases storage or stops the device (`rm`, `dd`, `mkfs*`, `flash_erase*`, `reboot`, `kill*`, `*factory*`, `*upgrade*` and similar). These are listed as `safety_gate_candidates`.
- **state-changing:** changes configuration or system state (`mount`, `ip`, `iptables*`, `sysctl`, `chmod`, `dmcli`, `syscfg` and similar).
- **unclassified:** everything else. This does **not** mean read-only.

Add platform-specific names in the config file. Always review the candidates before they go into the Safety Gate's blocked list.

## Config file

```json
{
  "providers": [
    { "name": "sbin-tools", "list": ["sh", "-c", "ls /usr/sbin"], "help": ["{name}", "-h"] }
  ],
  "risk": {
    "destructive": ["rdkfwupgrader", "*FactoryReset*"],
    "state_changing": ["psmcli", "syscfg", "sysevent"],
    "replace": false
  },
  "never_probe": ["rdkfwupgrader", "*.sh"]
}
```

- `providers[].list` prints one command name per line. `providers[].help` is the help command; `{name}` is replaced by the command's path, or its name if it is not on `PATH`.
- `risk` patterns are shell globs added to the built-in lists. Set `"replace": true` to use only yours.
- `never_probe` adds to the built-in never-probe list.

## Safety

Running `--help` on an unknown program is not always harmless: a program or script that ignores its arguments simply runs. cmdscan is careful by default:

- **BusyBox and Toybox** are probed by default. BusyBox handles `--help` before the applet runs, and Toybox has a separate `help` applet, so no applet runs.
- **`path` and custom providers are only listed** unless you pass `--probe`.
- **Shell scripts are never probed** unless you also pass `--scripts`.
- **Never-probe list:** commands matching it are never run, whatever the flags. Built-in entries include `reboot`, `halt`, `poweroff`, `init`, `kill*`, `rm`, `dd`, `mkfs*`, `flash*`, `mtd*`, `ubi*`, `*reset*`, `*upgrade*` and `*factory*`.
- **Containment:** every probe runs in its own session with no stdin, `LC_ALL=C`, a timeout (default 3 s), a 64 KB output cap, and a kill of its whole process group afterwards.

Even so, run `--probe` scans on lab devices first.

## Accuracy

The parser understands BusyBox help (usage line, tab-separated option list, keyword options such as `dd if=FILE`, extra usage forms) and GNU-style `--help` (`-a, --all   description`, `--opt[=ARG]`). Help text is free-form, so treat the output as a strong first draft:

- options that appear only inside prose descriptions are not picked up;
- commands with no `--help` support (`echo`, `true`, `test`) are listed with `skipped: "no usage section in help output"`;
- BusyBox builds without `FEATURE_VERBOSE_USAGE` give only the usage line: flags are found but have no descriptions.

Tested against BusyBox 1.36.1 (272 applets, 257 parsed, about 1,200 options) and GNU coreutils.
