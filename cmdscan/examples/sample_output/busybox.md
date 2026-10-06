# Command namespace: busybox

272 commands found, 257 with parsed help, 1199 options in total. **16 destructive** and 38 state-changing commands by name.

- Generated: 2026-10-05T23:36:59-0400
- Host: vm, kernel 6.18.44-fc-v70
- Binary: `/bin/busybox`
- Version: BusyBox v1.36.1 (Ubuntu 1:1.36.1-6ubuntu3.1) multi-call binary.

## Safety Gate candidates

Commands classified destructive by name. Review before adding them to the blocked list.

`blkdiscard`, `dd`, `fdisk`, `halt`, `init`, `kill`, `killall`, `mkdosfs`, `mke2fs`, `mkswap`, `poweroff`, `reboot`, `rm`, `rmdir`, `shred`, `truncate`

## Commands

| Command | Risk | Options | Arguments | Summary |
| --- | --- | --- | --- | --- |
| `[` | unclassified | 0 |  | no usage section in help output |
| `[[` | unclassified | 0 |  | no usage section in help output |
| [acpid](#cmd-acpid) | unclassified | 8 |  | Listen to ACPI events and spawn specific helpers on event arrival |
| [adjtimex](#cmd-adjtimex) | unclassified | 5 |  | Read or set kernel time variables. See adjtimex(2) |
| [ar](#cmd-ar) | unclassified | 2 | x\|p\|t, ARCHIVE, [FILE]... | Extract or list FILEs from an ar archive |
| [arch](#cmd-arch) | unclassified | 0 |  | Print system architecture |
| [arp](#cmd-arp) | unclassified | 9 | [HOSTNAME], [pub], HWADDR, [temp], [netmask MASK], IFACE | Manipulate ARP cache |
| [arping](#cmd-arping) | unclassified | 10 | DST_IP | Send ARP requests/replies |
| `ascii` | unclassified | 0 |  | no usage section in help output |
| [ash](#cmd-ash) | unclassified | 5 |  | Unix shell interpreter |
| [awk](#cmd-awk) | unclassified | 4 | [AWK_PROGRAM], [FILE]... |  |
| [base64](#cmd-base64) | unclassified | 2 | [FILE] | Base64 encode or decode FILE to standard output |
| [basename](#cmd-basename) | unclassified | 2 | FILE, [SUFFIX] | Strip directory path and SUFFIX from FILE |
| [bc](#cmd-bc) | unclassified | 4 | [FILE]... | Arbitrary precision calculator |
| [blkdiscard](#cmd-blkdiscard) | destructive | 3 | DEVICE | Discard sectors on DEVICE |
| [blockdev](#cmd-blockdev) | unclassified | 12 | BLOCKDEV |  |
| [brctl](#cmd-brctl) | state-changing | 0 | COMMAND, [BRIDGE [ARGS]] | Manage ethernet bridges |
| [bunzip2](#cmd-bunzip2) | unclassified | 4 | [FILE]... | Decompress FILEs (or stdin) |
| [busybox](#cmd-busybox) | unclassified | 0 | [function [arguments]]... | Currently defined functions: |
| [bzcat](#cmd-bzcat) | unclassified | 0 | [FILE]... | Decompress to stdout |
| [bzip2](#cmd-bzip2) | unclassified | 15 | [FILE]... | Compress FILEs (or stdin) with bzip2 algorithm |
| [cal](#cmd-cal) | unclassified | 3 | [[MONTH] YEAR] | Display a calendar |
| [cat](#cmd-cat) | unclassified | 6 | [FILE]... | Print FILEs to stdout |
| [chgrp](#cmd-chgrp) | state-changing | 8 | GROUP, FILE... | Change the group membership of FILEs to GROUP |
| [chmod](#cmd-chmod) | state-changing | 4 | MODE[,MODE]..., FILE... | MODE is octal number (bit pattern sstrwxrwxrwx) or [ugoa]{+\|-\|=}[rwxXst] |
| [chown](#cmd-chown) | state-changing | 8 | USER[:[GRP]], FILE... | Change the owner and/or group of FILEs to USER and/or GRP |
| [chpasswd](#cmd-chpasswd) | unclassified | 4 |  | Read user:password from stdin and update /etc/passwd |
| [chroot](#cmd-chroot) | state-changing | 0 | NEWROOT, [PROG ARGS] | Run PROG with root directory set to NEWROOT |
| [chvt](#cmd-chvt) | unclassified | 0 | N | Change the foreground virtual terminal to /dev/ttyN |
| [clear](#cmd-clear) | unclassified | 0 |  | Clear screen |
| [cmp](#cmd-cmp) | unclassified | 3 | FILE1, [FILE2 [SKIP1 [SKIP2]]] | Compare FILE1 with FILE2 (or stdin) |
| [cp](#cmd-cp) | state-changing | 16 | SOURCE, DEST | or: cp [-arPLHpfinlsu] SOURCE... { -t DIRECTORY \| DIRECTORY } |
| [cpio](#cmd-cpio) | unclassified | 14 | [EXTR_FILE]... | Extract (-i) or list (-t) files from a cpio archive, or |
| [crc32](#cmd-crc32) | unclassified | 0 | FILE... | Calculate CRC32 checksum of FILEs |
| [crond](#cmd-crond) | unclassified | 6 |  |  |
| [crontab](#cmd-crontab) | state-changing | 5 | \|[FILE] |  |
| [cttyhack](#cmd-cttyhack) | unclassified | 0 | [PROG ARGS] | Give PROG a controlling tty if possible. |
| [cut](#cmd-cut) | unclassified | 9 | [FILE]... | Print selected fields from FILEs to stdout |
| [date](#cmd-date) | state-changing | 7 | [+FMT], [[-s] TIME] | Display time (using +FMT), or set time |
| [dc](#cmd-dc) | unclassified | 12 | [FILE]... | Tiny RPN calculator. Operations: |
| [dd](#cmd-dd) | destructive | 12 |  | Copy a file with converting and formatting |
| [deallocvt](#cmd-deallocvt) | unclassified | 0 | [N] | Deallocate unused virtual terminal /dev/ttyN |
| [depmod](#cmd-depmod) | unclassified | 2 | [VERSION], [MODFILES]... | Generate modules.dep, alias, and symbols files |
| [devmem](#cmd-devmem) | unclassified | 0 | ADDRESS, [WIDTH [VALUE]] | Read/write from physical address |
| [df](#cmd-df) | unclassified | 9 | [FILESYSTEM]... | Print filesystem usage statistics |
| [diff](#cmd-diff) | unclassified | 15 | FILE1, FILE2 | Compare files line by line and output the differences between them. |
| [dirname](#cmd-dirname) | unclassified | 0 | FILENAME | Strip non-directory suffix from FILENAME |
| [dmesg](#cmd-dmesg) | unclassified | 4 |  | Print or control the kernel ring buffer |
| `dnsdomainname` | unclassified | 0 |  | no usage section in help output |
| [dos2unix](#cmd-dos2unix) | unclassified | 2 | [FILE] | Convert FILE in-place from DOS to Unix format. |
| [dpkg](#cmd-dpkg) | unclassified | 12 | PACKAGE | Install, remove and manage Debian packages |
| [dpkg-deb](#cmd-dpkg-deb) | unclassified | 5 | FILE, [DIR] | Perform actions on Debian packages (.deb) |
| [du](#cmd-du) | unclassified | 12 | [FILE]... | Summarize disk space used for FILEs (or directories) |
| [dumpkmap](#cmd-dumpkmap) | unclassified | 0 | keymap | Print a binary keyboard translation table to stdout |
| [dumpleases](#cmd-dumpleases) | unclassified | 4 |  | Display DHCP leases granted by udhcpd |
| `echo` | unclassified | 0 |  | no usage section in help output |
| [ed](#cmd-ed) | unclassified | 2 | [FILE] |  |
| `egrep` | unclassified | 0 |  | no usage section in help output |
| [env](#cmd-env) | unclassified | 4 | [NAME=VALUE]..., [PROG ARGS] | Print current environment or run PROG after setting up environment |
| [expand](#cmd-expand) | unclassified | 2 | [FILE]... | Convert tabs to spaces, writing to stdout |
| [expr](#cmd-expr) | unclassified | 0 | EXPRESSION | Print the value of EXPRESSION |
| [factor](#cmd-factor) | unclassified | 0 | [NUMBER]... | Print prime factors |
| [fallocate](#cmd-fallocate) | unclassified | 2 | LEN, FILE | Preallocate space for FILE |
| `false` | unclassified | 0 |  | no help output |
| [fatattr](#cmd-fatattr) | unclassified | 6 | FILE... | Change file attributes on FAT filesystem |
| [fdisk](#cmd-fdisk) | destructive | 6 | DISK | Change partition table |
| `fgrep` | unclassified | 0 |  | no usage section in help output |
| [find](#cmd-find) | unclassified | 33 | [PATH]..., [ACTIONS] | Search for files and perform actions on them. |
| [findfs](#cmd-findfs) | unclassified | 0 | LABEL=label, or, UUID=uuid | Find a filesystem device based on a label or UUID |
| [fold](#cmd-fold) | unclassified | 3 | [FILE]... | Wrap input lines in FILEs (or stdin), writing to stdout |
| [free](#cmd-free) | unclassified | 5 |  | Display free and used memory |
| [freeramdisk](#cmd-freeramdisk) | unclassified | 0 | DEVICE | Free all memory used by the specified ramdisk |
| [fsfreeze](#cmd-fsfreeze) | unclassified | 1 | MOUNTPOINT | Flush and halt writes to MOUNTPOINT |
| [fstrim](#cmd-fstrim) | unclassified | 4 | MOUNTPOINT |  |
| [ftpget](#cmd-ftpget) | unclassified | 5 | HOST, [LOCAL_FILE], REMOTE_FILE | Download a file via FTP |
| [ftpput](#cmd-ftpput) | unclassified | 4 | HOST, [REMOTE_FILE], LOCAL_FILE | Upload a file to a FTP server |
| [getopt](#cmd-getopt) | unclassified | 14 | OPTSTRING, PARAMS | Example: |
| [getty](#cmd-getty) | unclassified | 11 | BAUD_RATE[,BAUD_RATE]..., TTY, [TERMTYPE] | Open TTY, prompt for login name, then invoke /bin/login |
| [grep](#cmd-grep) | unclassified | 24 | { PATTERN \| -e PATTERN... \| -f FILE... }, [FILE]... | Search for PATTERN in FILEs (or stdin) |
| [groups](#cmd-groups) | unclassified | 0 | [USER] | Print the groups USER is in |
| [gunzip](#cmd-gunzip) | unclassified | 4 | [FILE]... | Decompress FILEs (or stdin) |
| [gzip](#cmd-gzip) | unclassified | 5 | [FILE]... | Compress FILEs (or stdin) |
| [halt](#cmd-halt) | destructive | 4 |  | Halt the system |
| [head](#cmd-head) | unclassified | 4 | [FILE]... | Print first 10 lines of FILEs (or stdin). |
| [hexdump](#cmd-hexdump) | unclassified | 11 | [FILE]... | Display FILEs (or stdin) in a user specified format |
| [hostid](#cmd-hostid) | unclassified | 0 |  | Print out a unique 32-bit identifier for the machine |
| [hostname](#cmd-hostname) | unclassified | 5 | [HOSTNAME \| -F FILE] | Show or set hostname or DNS domain name |
| [httpd](#cmd-httpd) | unclassified | 12 |  | or httpd -d/-e/-m STRING |
| [hwclock](#cmd-hwclock) | state-changing | 6 |  | Show or set hardware clock (RTC) |
| [i2cdetect](#cmd-i2cdetect) | unclassified | 6 | I2CBUS, [FIRST LAST] | Detect I2C chips |
| [i2cdump](#cmd-i2cdump) | unclassified | 3 | BUS, ADDR, [MODE] | Examine I2C registers |
| [i2cget](#cmd-i2cget) | unclassified | 2 | BUS, CHIP-ADDRESS, [DATA-ADDRESS [MODE]] | Read from I2C/SMBus chip registers |
| [i2cset](#cmd-i2cset) | unclassified | 4 | BUS, CHIP-ADDRESS, DATA-ADDRESS, [VALUE], [MODE] | Set I2C registers |
| [i2ctransfer](#cmd-i2ctransfer) | unclassified | 3 | I2CBUS, { rLENGTH[@ADDR] \| wLENGTH[@ADDR] DATA...}... | Read/write I2C data in one transfer |
| [id](#cmd-id) | unclassified | 5 | [USER] | Print information about USER or the current user |
| [ifconfig](#cmd-ifconfig) | state-changing | 1 | [IFACE], [ADDRESS] | Configure a network interface |
| [ifdown](#cmd-ifdown) | state-changing | 6 | IFACE... |  |
| [ifup](#cmd-ifup) | state-changing | 6 | IFACE... |  |
| [init](#cmd-init) | destructive | 0 |  | Init is the first process started during boot. It never exits. |
| [insmod](#cmd-insmod) | state-changing | 0 | FILE, [SYMBOL=VALUE]... | Load kernel module |
| [ionice](#cmd-ionice) | unclassified | 3 | { -p PID \| PROG ARGS } | Change I/O priority and class |
| [ip](#cmd-ip) | state-changing | 0 | address\|route\|link\|tunnel\|neigh\|rule, [ARGS] |  |
| [ipcalc](#cmd-ipcalc) | unclassified | 6 | ADDRESS[/PREFIX], [NETMASK] | Calculate and display network settings from IP address |
| [kill](#cmd-kill) | destructive | 4 | PID... | Send a signal (default: TERM) to given PIDs |
| [killall](#cmd-killall) | destructive | 5 | PROCESS_NAME... | Send a signal (default: TERM) to given processes |
| [klogd](#cmd-klogd) | unclassified | 2 |  | Log kernel messages to syslog |
| [last](#cmd-last) | unclassified | 0 |  | Show listing of the last users that logged into the system |
| [less](#cmd-less) | unclassified | 10 | [FILE]... | View FILE (or stdin) one screenful at a time |
| [link](#cmd-link) | unclassified | 0 | FILE, LINK | Create hard LINK to FILE |
| `linux32` | unclassified | 0 |  | no usage section in help output |
| `linux64` | unclassified | 0 |  | no usage section in help output |
| `linuxrc` | unclassified | 0 |  | no usage section in help output |
| [ln](#cmd-ln) | state-changing | 8 | TARGET..., LINK\|DIR | Create a link LINK or DIR/TARGET to the specified TARGET(s) |
| [loadfont](#cmd-loadfont) | unclassified | 0 | font | Load a console font from stdin |
| [loadkmap](#cmd-loadkmap) | unclassified | 0 | keymap | Load a binary keyboard translation table from stdin |
| [logger](#cmd-logger) | unclassified | 3 | [MESSAGE] | Write MESSAGE (or stdin) to syslog |
| [login](#cmd-login) | unclassified | 3 | [[-f] USER] | Begin a new session on the system |
| [logname](#cmd-logname) | unclassified | 0 |  | Print the name of the current user |
| [logread](#cmd-logread) | unclassified | 2 |  | Show messages in syslogd's circular buffer |
| [losetup](#cmd-losetup) | unclassified | 4 | {-f\|LOOPDEV}, FILE:, associate, loop, devices |  |
| [ls](#cmd-ls) | unclassified | 31 | [FILE]... | List directory contents |
| [lsmod](#cmd-lsmod) | unclassified | 0 |  | List loaded kernel modules |
| `lsscsi` | unclassified | 0 |  | no usage section in help output |
| [lzcat](#cmd-lzcat) | unclassified | 0 | [FILE]... | Decompress to stdout |
| [lzma](#cmd-lzma) | unclassified | 5 | [FILE]... | Decompress FILEs (or stdin) |
| [lzop](#cmd-lzop) | unclassified | 17 | [FILE]... |  |
| [md5sum](#cmd-md5sum) | unclassified | 3 | [FILE]... | Print or check MD5 checksums |
| [mdev](#cmd-mdev) | unclassified | 5 | { [-s] \| [-df] } | Bare mdev is a kernel hotplug helper. To activate it: |
| [microcom](#cmd-microcom) | unclassified | 4 | TTY | Copy bytes from stdin to TTY and from TTY to stdout |
| [mim](#cmd-mim) | unclassified | 1 | [SHELL_OPTIONS], [TARGET] | Run a script from a Makefile-like specification file |
| [mkdir](#cmd-mkdir) | state-changing | 2 | DIRECTORY... | Create DIRECTORY |
| [mkdosfs](#cmd-mkdosfs) | destructive | 2 | BLOCKDEV, [KBYTES] | Make a FAT32 filesystem |
| [mke2fs](#cmd-mke2fs) | destructive | 7 | BLOCKDEV, [KBYTES] |  |
| [mkfifo](#cmd-mkfifo) | state-changing | 1 | NAME | Create named pipe |
| [mknod](#cmd-mknod) | state-changing | 1 | NAME, TYPE, [MAJOR MINOR] | Create a special file (block, character, or pipe) |
| [mkpasswd](#cmd-mkpasswd) | unclassified | 3 | [PASSWORD], [SALT] | Print crypt(3) hashed PASSWORD |
| [mkswap](#cmd-mkswap) | destructive | 1 | BLOCKDEV, [KBYTES] | Prepare BLOCKDEV to be used as swap partition |
| [mktemp](#cmd-mktemp) | unclassified | 5 | [TEMPLATE] | Create a temporary file with name based on TEMPLATE and print its name. |
| [modinfo](#cmd-modinfo) | unclassified | 7 | MODULE |  |
| [modprobe](#cmd-modprobe) | state-changing | 8 | MODULE, [SYMBOL=VALUE]... |  |
| [more](#cmd-more) | unclassified | 0 | [FILE]... | View FILE (or stdin) one screenful at a time |
| [mount](#cmd-mount) | state-changing | 8 | DEVICE, NODE | Mount a filesystem. Filesystem autodetection requires /proc. |
| [mt](#cmd-mt) | unclassified | 1 | OPCODE, VALUE | Control magnetic tape drive operation |
| [mv](#cmd-mv) | state-changing | 5 | SOURCE, DEST | or: mv [-fin] SOURCE... { -t DIRECTORY \| DIRECTORY } |
| [nameif](#cmd-nameif) | unclassified | 2 | [IFNAME HWADDR]... | Rename network interface while it in the down state. |
| [nbd-client](#cmd-nbd-client) | unclassified | 0 | { [-b BLKSIZE] [-N NAME] [-t SEC] [-p] HOST [PORT] \| -d }, BLOCKDEV | Connect to HOST and provide network block device on BLOCKDEV |
| [nc](#cmd-nc) | unclassified | 7 |  | Open a pipe to IP:PORT or FILE |
| [netstat](#cmd-netstat) | unclassified | 9 |  | Display networking information |
| [nl](#cmd-nl) | unclassified | 5 | [FILE]... | Write FILEs to standard output with line numbers added |
| [nologin](#cmd-nologin) | unclassified | 0 |  | Politely refuse a login |
| [nproc](#cmd-nproc) | unclassified | 2 |  | Print number of available CPUs |
| [nsenter](#cmd-nsenter) | unclassified | 13 | [PROG ARGS] |  |
| [nslookup](#cmd-nslookup) | unclassified | 6 | HOST, [DNS_SERVER] | Query DNS about HOST |
| [nuke](#cmd-nuke) | unclassified | 0 | DIR... | Remove DIRs |
| [od](#cmd-od) | unclassified | 18 | [FILE]... | Print FILEs (or stdin) unambiguously, as octal bytes by default |
| [openvt](#cmd-openvt) | unclassified | 3 | [PROG ARGS] | Start PROG on a new virtual terminal |
| [partprobe](#cmd-partprobe) | unclassified | 0 | DEVICE... | Ask kernel to rescan partition table |
| [passwd](#cmd-passwd) | state-changing | 4 | [USER] | Change USER's password (default: current user) |
| [paste](#cmd-paste) | unclassified | 2 | [FILE]... | Paste lines from each input file, separated with tab |
| [patch](#cmd-patch) | state-changing | 6 | [ORIGFILE [PATCHFILE]] |  |
| [pidof](#cmd-pidof) | unclassified | 0 | [NAME]... | List PIDs of all processes with names that match NAMEs |
| [ping](#cmd-ping) | unclassified | 11 | HOST | Send ICMP ECHO_REQUESTs to HOST |
| [ping6](#cmd-ping6) | unclassified | 9 | HOST | Send ICMP ECHO_REQUESTs to HOST |
| [pivot_root](#cmd-pivot_root) | unclassified | 0 | NEW_ROOT, PUT_OLD | Move the current root file system to PUT_OLD and make NEW_ROOT |
| [poweroff](#cmd-poweroff) | destructive | 3 |  | Halt and shut off power |
| [printf](#cmd-printf) | unclassified | 0 | FORMAT, [ARG]... | Format and print ARG(s) according to FORMAT (a-la C printf) |
| [ps](#cmd-ps) | unclassified | 2 |  | Show list of processes |
| [pwd](#cmd-pwd) | unclassified | 0 |  | Print the full filename of the current working directory |
| [rdate](#cmd-rdate) | unclassified | 2 | HOST | Set and print time from HOST using RFC 868 |
| [readlink](#cmd-readlink) | unclassified | 3 | FILE | Display the value of a symlink |
| [realpath](#cmd-realpath) | unclassified | 0 | FILE... | Print absolute pathnames of FILEs |
| [reboot](#cmd-reboot) | destructive | 3 |  | Reboot the system |
| [renice](#cmd-renice) | state-changing | 4 | PRIORITY, [[-p\|g\|u] ID]... | Change scheduling priority of a running process |
| [reset](#cmd-reset) | unclassified | 0 |  | Reset terminal (ESC codes) and termios (signals, buffering, echo) |
| [resume](#cmd-resume) | unclassified | 0 | BLOCKDEV, [OFFSET] | Restore system state from 'suspend-to-disk' data in BLOCKDEV |
| [rev](#cmd-rev) | unclassified | 0 | [FILE]... | Reverse lines of FILE |
| [rm](#cmd-rm) | destructive | 4 | FILE... | Remove (unlink) FILEs |
| [rmdir](#cmd-rmdir) | destructive | 2 | DIRECTORY... | Remove DIRECTORY if it is empty |
| [rmmod](#cmd-rmmod) | state-changing | 3 | [MODULE]... | Unload kernel modules |
| [route](#cmd-route) | state-changing | 3 | [{add\|del} [-net\|-host] TARGET [netmask MASK] [gw GATEWAY] [metric N] [mss BYTES] [window BYTES]] | Show or edit kernel routing tables |
| [rpm](#cmd-rpm) | unclassified | 11 | PACKAGE.rpm;, rpm, PACKAGE.rpm | Manipulate RPM packages |
| [rpm2cpio](#cmd-rpm2cpio) | unclassified | 0 | PACKAGE.rpm | Output a cpio archive of the rpm file |
| [run-init](#cmd-run-init) | unclassified | 3 | NEW_ROOT, NEW_INIT, [ARGS] | Free initramfs and switch to another root fs: |
| [run-parts](#cmd-run-parts) | unclassified | 5 | DIRECTORY | Run a bunch of scripts in DIRECTORY |
| [sed](#cmd-sed) | state-changing | 10 | [FILE]... | or: sed [-i[SFX]] [-nrE] CMD [FILE]... |
| [seq](#cmd-seq) | unclassified | 2 | [FIRST [INC]], LAST | Print numbers from FIRST to LAST, in steps of INC. |
| [setkeycodes](#cmd-setkeycodes) | unclassified | 0 | { SCANCODE KEYCODE }... | Modify kernel's scancode-to-keycode map, |
| [setpriv](#cmd-setpriv) | unclassified | 0 | PROG, ARGS | Run PROG with different privilege settings |
| [setsid](#cmd-setsid) | state-changing | 1 | PROG, ARGS | Run PROG in a new session. PROG will have no controlling terminal |
| [sh](#cmd-sh) | unclassified | 5 |  | Unix shell interpreter |
| [sha1sum](#cmd-sha1sum) | unclassified | 3 | [FILE]... | Print or check SHA1 checksums |
| [sha256sum](#cmd-sha256sum) | unclassified | 3 | [FILE]... | Print or check SHA256 checksums |
| [sha3sum](#cmd-sha3sum) | unclassified | 4 | [FILE]... | Print or check SHA3 checksums |
| [sha512sum](#cmd-sha512sum) | unclassified | 3 | [FILE]... | Print or check SHA512 checksums |
| [shred](#cmd-shred) | destructive | 5 | FILE... | Overwrite/delete FILEs |
| [shuf](#cmd-shuf) | unclassified | 5 | [FILE \| -e [ARG...] \| -i L-H] | Randomly permute lines |
| [sleep](#cmd-sleep) | unclassified | 0 | [N]... | Pause for a time equal to the total of the args given, where each arg can |
| [sort](#cmd-sort) | unclassified | 17 |  | Sort lines of text |
| [ssl_client](#cmd-ssl_client) | unclassified | 4 | FD |  |
| [start-stop-daemon](#cmd-start-stop-daemon) | unclassified | 17 |  | Search for matching processes, and then |
| [stat](#cmd-stat) | unclassified | 5 | FILE... | Display file (default) or filesystem status |
| `static-sh` | unclassified | 0 |  | no usage section in help output |
| [strings](#cmd-strings) | unclassified | 4 | [FILE]... | Display printable strings in a binary file |
| [stty](#cmd-stty) | unclassified | 3 | [SETTING]... | Without arguments, prints baud rate, line discipline, |
| [su](#cmd-su) | unclassified | 6 | [USER [FILE ARGS \| -c 'CMD' [ARG0 ARGS]]] | Run shell under USER (by default, root) |
| [sulogin](#cmd-sulogin) | unclassified | 2 | [TTY] | Single user login |
| [svc](#cmd-svc) | unclassified | 12 | SERVICE_DIR... | Control services monitored by runsv supervisor |
| [svok](#cmd-svok) | unclassified | 0 | SERVICE_DIR | Check whether runsv supervisor is running. |
| [swapoff](#cmd-swapoff) | state-changing | 1 | [DEVICE] | Stop swapping on DEVICE |
| [swapon](#cmd-swapon) | state-changing | 7 | [DEVICE] | Start swapping on DEVICE |
| [switch_root](#cmd-switch_root) | unclassified | 1 | NEW_ROOT, NEW_INIT, [ARGS] | Free initramfs and switch to another root fs: |
| [sync](#cmd-sync) | unclassified | 2 | [FILE]... | Write all buffered blocks (in FILEs) to disk |
| [sysctl](#cmd-sysctl) | state-changing | 6 | { -a \| -p [FILE]... \| [-w] [KEY[=VALUE]]... } | Show/set kernel parameters |
| [syslogd](#cmd-syslogd) | unclassified | 12 |  | System logging utility |
| [tac](#cmd-tac) | unclassified | 0 | [FILE]... | Concatenate FILEs and print them in reverse |
| [tail](#cmd-tail) | unclassified | 7 | [FILE]... | Print last 10 lines of FILEs (or stdin) to. |
| [tar](#cmd-tar) | unclassified | 20 | c\|x\|t, [FILE]... | Create, extract, or list files from a tar file |
| [taskset](#cmd-taskset) | unclassified | 3 | [HEXMASK \| -c LIST], { PID \| PROG ARGS } | Set or get CPU affinity |
| [tc](#cmd-tc) | state-changing | 0 | OBJECT, CMD, [dev STRING] | OBJECT: qdisc\|class\|filter |
| [tee](#cmd-tee) | state-changing | 2 | [FILE]... | Copy stdin to each FILE, and also to stdout |
| [telnet](#cmd-telnet) | unclassified | 2 | HOST, [PORT] | Connect to telnet server |
| [telnetd](#cmd-telnetd) | unclassified | 7 |  | Handle incoming telnet connections |
| `test` | unclassified | 0 |  | no help output |
| [tftp](#cmd-tftp) | unclassified | 5 | HOST, [PORT] | Transfer a file from/to tftp server |
| [time](#cmd-time) | unclassified | 5 | PROG, ARGS | Run PROG, display resource usage when it exits |
| [timeout](#cmd-timeout) | unclassified | 2 | SECS, PROG, ARGS | Run PROG. Send SIG to it if it is not gone in SECS seconds. |
| [top](#cmd-top) | unclassified | 4 |  | Show a view of process activity in real time. |
| [touch](#cmd-touch) | state-changing | 7 | FILE... | Update mtime of FILEs |
| [tr](#cmd-tr) | unclassified | 3 | STRING1, [STRING2] | Translate, squeeze, or delete characters from stdin, writing to stdout |
| [traceroute](#cmd-traceroute) | unclassified | 16 | HOST, [BYTES] | Trace the route to HOST |
| [traceroute6](#cmd-traceroute6) | unclassified | 12 | HOST, [BYTES] | Trace the route to HOST |
| `true` | unclassified | 0 |  | no help output |
| [truncate](#cmd-truncate) | destructive | 2 | SIZE, FILE... | Truncate FILEs to SIZE |
| [ts](#cmd-ts) | unclassified | 2 | [STRFTIME] | Pipe stdin to stdout, add timestamp to each line |
| [tty](#cmd-tty) | unclassified | 1 |  | Print file name of stdin's terminal |
| [tunctl](#cmd-tunctl) | unclassified | 3 |  | Create or delete TUN/TAP interfaces |
| [ubirename](#cmd-ubirename) | unclassified | 0 | UBI_DEVICE, OLD_VOLNAME, NEW_VOLNAME, [OLD2 NEW2]... | Rename UBI volumes on UBI_DEVICE |
| [udhcpc](#cmd-udhcpc) | state-changing | 24 |  | Signals: |
| [udhcpc6](#cmd-udhcpc6) | unclassified | 19 |  | Signals: |
| [udhcpd](#cmd-udhcpd) | state-changing | 4 | [CONFFILE] | DHCP server |
| [uevent](#cmd-uevent) | unclassified | 0 | [PROG ARGS] | PROG's environment contains data passed from the kernel. |
| [umount](#cmd-umount) | state-changing | 6 | FILESYSTEM\|DIRECTORY | Unmount filesystems |
| [uname](#cmd-uname) | unclassified | 9 |  | Print system information |
| [uncompress](#cmd-uncompress) | unclassified | 2 | [FILE]... | Decompress FILEs (or stdin) |
| [unexpand](#cmd-unexpand) | unclassified | 3 | [FILE]... | Convert spaces to tabs, writing to stdout |
| [uniq](#cmd-uniq) | unclassified | 9 | [FILE [OUTFILE]] | Discard duplicate lines |
| [unix2dos](#cmd-unix2dos) | unclassified | 2 | [FILE] | Convert FILE in-place from Unix to DOS format. |
| [unlink](#cmd-unlink) | unclassified | 0 | FILE | Delete FILE by calling unlink() |
| [unlzma](#cmd-unlzma) | unclassified | 4 | [FILE]... | Decompress FILEs (or stdin) |
| [unshare](#cmd-unshare) | unclassified | 11 | [PROG ARGS] |  |
| [unxz](#cmd-unxz) | unclassified | 4 | [FILE]... | Decompress FILEs (or stdin) |
| [unzip](#cmd-unzip) | unclassified | 10 | FILE[.zip], [FILE]... | Extract FILEs from ZIP archive |
| [uptime](#cmd-uptime) | unclassified | 0 |  | Display the time since the last boot |
| [usleep](#cmd-usleep) | unclassified | 0 | N | Pause for N microseconds |
| [uudecode](#cmd-uudecode) | unclassified | 1 | [INFILE] | Uudecode a file |
| [uuencode](#cmd-uuencode) | unclassified | 1 | [FILE], STORED_FILENAME | Uuencode FILE (or stdin) to stdout |
| [vconfig](#cmd-vconfig) | state-changing | 0 | COMMAND | Create and remove virtual ethernet devices |
| [vi](#cmd-vi) | unclassified | 3 | [FILE]... | Edit FILE |
| [w](#cmd-w) | unclassified | 0 |  | Show who is logged on |
| [watch](#cmd-watch) | unclassified | 2 | PROG, ARGS | Run PROG periodically |
| [watchdog](#cmd-watchdog) | unclassified | 3 | DEV | Periodically write to watchdog device DEV |
| [wc](#cmd-wc) | unclassified | 5 | [FILE]... | Count lines, words, and bytes for FILEs (or stdin) |
| [wget](#cmd-wget) | unclassified | 14 | URL... | Retrieve files via HTTP or FTP |
| [which](#cmd-which) | unclassified | 1 | COMMAND... | Locate COMMAND |
| [who](#cmd-who) | unclassified | 2 |  | Show who is logged on |
| [whoami](#cmd-whoami) | unclassified | 0 |  | Print the user name associated with the current effective user id |
| [xargs](#cmd-xargs) | unclassified | 12 | [PROG ARGS] | Run PROG on every item given by stdin |
| [xxd](#cmd-xxd) | unclassified | 8 | [FILE] | Hex dump FILE (or stdin) |
| [xz](#cmd-xz) | unclassified | 5 | [FILE]... | Decompress FILEs (or stdin) |
| [xzcat](#cmd-xzcat) | unclassified | 0 | [FILE]... | Decompress to stdout |
| [yes](#cmd-yes) | unclassified | 0 | [STRING] | Repeatedly print a line with STRING, or 'y' |
| [zcat](#cmd-zcat) | unclassified | 0 | [FILE]... | Decompress to stdout |

## Details

<a id="cmd-acpid"></a>
### acpid

Listen to ACPI events and spawn specific helpers on event arrival

Risk: unclassified. Source: busybox.

```text
acpid  [-df] [-c CONFDIR] [-l LOGFILE] [-a ACTIONFILE] [-M MAPFILE] [-e PROC_EVENT_FILE] [-p PIDFILE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  |  | Log to stderr, not log file (implies -f) |
| -f |  |  | Run in foreground |
| -c |  | CONFDIR | Config directory [/etc/acpi] |
| -l |  | LOGFILE | Log file [/var/log/acpid.log] |
| -a |  | ACTIONFILE | Action file [/etc/acpid.conf] |
| -M |  | MAPFILE |  |
| -e |  | PROC_EVENT_FILE | /proc event file [/proc/acpi/event] |
| -p |  | PIDFILE | Pid file [/var/run/acpid.pid] |

<a id="cmd-adjtimex"></a>
### adjtimex

Read or set kernel time variables. See adjtimex(2)

Risk: unclassified. Source: busybox.

```text
adjtimex  [-q] [-o OFS] [-f FREQ] [-p TCONST] [-t TICK]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -q |  |  | Quiet |
| -o |  | OFS | Time offset, microseconds |
| -f |  | FREQ | Frequency adjust, integer kernel units (65536 is 1ppm) |
| -p |  | TCONST |  |
| -t |  | TICK | Microseconds per tick, usually 10000 (positive -t or -f values make clock run faster) |

<a id="cmd-ar"></a>
### ar

Extract or list FILEs from an ar archive

Risk: unclassified. Source: busybox.

```text
ar  x|p|t [-ov] ARCHIVE [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -o |  |  | Restore mtime |
| -v |  |  | Verbose |

<a id="cmd-arch"></a>
### arch

Print system architecture

Risk: unclassified. Source: busybox.

```text
arch 
```


<a id="cmd-arp"></a>
### arp

Manipulate ARP cache

Risk: unclassified. Source: busybox.

```text
arp  [-vn]	[-H HWTYPE] [-i IF] -a [HOSTNAME] [-v]		    [-i IF] -d HOSTNAME [pub] [-v]	[-H HWTYPE] [-i IF] -s HOSTNAME HWADDR [temp] [-v]	[-H HWTYPE] [-i IF] -s HOSTNAME HWADDR [netmask MASK] pub [-v]	[-H HWTYPE] [-i IF] -Ds HOSTNAME IFACE [netmask MASK] pub
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -v |  |  | Verbose |
| -n |  |  | Don't resolve names |
| -H |  | HWTYPE | Hardware address type |
| -i |  | IF | Network interface |
| -a |  |  | Display (all) hosts |
| -d |  |  | Delete ARP entry |
| -s |  |  | Set new entry |
| -D |  |  | Read HWADDR from IFACE |
| -A (-p) |  | AF | Protocol family |

<a id="cmd-arping"></a>
### arping

Send ARP requests/replies

Risk: unclassified. Source: busybox.

```text
arping  [-fqbDUA] [-c CNT] [-w TIMEOUT] [-I IFACE] [-s SRC_IP] DST_IP
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Quit on first ARP reply |
| -q |  |  | Quiet |
| -b |  |  | Keep broadcasting, don't go unicast |
| -D |  |  | Exit with 1 if DST_IP replies |
| -U |  |  | Unsolicited ARP mode, update your neighbors |
| -A |  |  | ARP answer mode, update your neighbors |
| -c |  | CNT | Stop after sending N ARP requests |
| -w |  | TIMEOUT | Seconds to wait for ARP reply |
| -I |  | IFACE | Interface to use (default eth0) |
| -s |  | SRC_IP | Sender IP address DST_IP		Target IP address |

<a id="cmd-ash"></a>
### ash

Unix shell interpreter

Risk: unclassified. Source: busybox.

```text
ash  [-il] [-|+Cabefmnuvx] [-|+o OPT]... [-c 'SCRIPT' [ARG0 ARGS] | FILE ARGS | -s ARGS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -i |  |  |  |
| -l |  |  |  |
| - |  |  |  |
| -c |  | 'SCRIPT' [ARG0 ARGS] |  |
| -s |  | ARGS |  |

<a id="cmd-awk"></a>
### awk

Risk: unclassified. Source: busybox.

```text
awk  [OPTIONS] [AWK_PROGRAM] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -v |  | VAR=VAL | Set variable |
| -F |  | SEP | Use SEP as field separator |
| -f |  | FILE | Read program from FILE |
| -e |  | AWK_PROGRAM |  |

<a id="cmd-base64"></a>
### base64

Base64 encode or decode FILE to standard output

Risk: unclassified. Source: busybox.

```text
base64  [-d] [-w COL] [FILE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  |  | Decode data |
| -w |  | COL | Wrap lines at COL (default 76, 0 disables) |

<a id="cmd-basename"></a>
### basename

Strip directory path and SUFFIX from FILE

Risk: unclassified. Source: busybox.

```text
basename  FILE [SUFFIX] | -a FILE... | -s SUFFIX FILE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | All arguments are FILEs |
| -s |  | SUFFIX | Remove SUFFIX (implies -a) |

<a id="cmd-bc"></a>
### bc

Arbitrary precision calculator

Risk: unclassified. Source: busybox.

```text
bc  [-sqlw] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -s |  |  | Be POSIX compatible |
| -q |  |  | Quiet |
| -l |  |  | Load standard library |
| -w |  |  | Warn if extensions are used |

<a id="cmd-blkdiscard"></a>
### blkdiscard

Discard sectors on DEVICE

Risk: destructive. Source: busybox.

```text
blkdiscard  [-o OFS] [-l LEN] [-s] DEVICE
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -o |  | OFS | Byte offset into device |
| -l |  | LEN | Number of bytes to discard |
| -s |  |  | Perform a secure discard |

<a id="cmd-blockdev"></a>
### blockdev

Risk: unclassified. Source: busybox.

```text
blockdev  OPTION BLOCKDEV
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
|  | --setro |  | Set ro |
|  | --setrw |  | Set rw |
|  | --getro |  | Get ro |
|  | --getss |  | Get sector size |
|  | --getbsz |  | Get block size |
|  | --setbsz | BYTES | Set block size |
|  | --getsz |  | Get device size in 512-byte sectors |
|  | --getsize64 |  | Get device size in bytes |
|  | --getra |  | Get readahead in 512-byte sectors |
|  | --setra | SECTORS | Set readahead |
|  | --flushbufs |  | Flush buffers |
|  | --rereadpt |  | Reread partition table |

<a id="cmd-brctl"></a>
### brctl

Manage ethernet bridges

Risk: state-changing. Source: busybox.

```text
brctl  COMMAND [BRIDGE [ARGS]]
```


<a id="cmd-bunzip2"></a>
### bunzip2

Decompress FILEs (or stdin)

Risk: unclassified. Source: busybox.

```text
bunzip2  [-cfk] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Write to stdout |
| -f |  |  | Force |
| -k |  |  | Keep input files |
| -t |  |  | Test integrity |

<a id="cmd-busybox"></a>
### busybox

Currently defined functions:

Risk: unclassified. Source: busybox.

```text
busybox  [function [arguments]...]
busybox --list[-full]
busybox --install [-s] [DIR]
function [arguments]...
```


<a id="cmd-bzcat"></a>
### bzcat

Decompress to stdout

Risk: unclassified. Source: busybox.

```text
bzcat  [FILE]...
```


<a id="cmd-bzip2"></a>
### bzip2

Compress FILEs (or stdin) with bzip2 algorithm

Risk: unclassified. Source: busybox.

```text
bzip2  [-cfkdt123456789] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Write to stdout |
| -f |  |  | Force |
| -k |  |  | Keep input files |
| -d |  |  | Decompress |
| -t |  |  | Test integrity |
| -1 |  |  |  |
| -2 |  |  |  |
| -3 |  |  |  |
| -4 |  |  |  |
| -5 |  |  |  |
| -6 |  |  |  |
| -7 |  |  |  |
| -8 |  |  |  |
| -9 |  |  |  |
| -1..9 |  |  | Compression level |

<a id="cmd-cal"></a>
### cal

Display a calendar

Risk: unclassified. Source: busybox.

```text
cal  [-jmy] [[MONTH] YEAR]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -j |  |  | Use julian dates |
| -m |  |  | Week starts on Monday |
| -y |  |  | Display the entire year |

<a id="cmd-cat"></a>
### cat

Print FILEs to stdout

Risk: unclassified. Source: busybox.

```text
cat  [-nbvteA] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n |  |  | Number output lines |
| -b |  |  | Number nonempty lines |
| -v |  |  | Show nonprinting characters as ^x or M-x |
| -t |  |  | ...and tabs as ^I |
| -e |  |  | ...and end lines with $ |
| -A |  |  | Same as -vte |

<a id="cmd-chgrp"></a>
### chgrp

Change the group membership of FILEs to GROUP

Risk: state-changing. Source: busybox.

```text
chgrp  [-RhLHPcvf]... GROUP FILE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -R |  |  | Recurse |
| -h |  |  | Affect symlinks instead of symlink targets |
| -L |  |  | Traverse all symlinks to directories |
| -H |  |  | Traverse symlinks on command line only |
| -P |  |  | Don't traverse symlinks (default) |
| -c |  |  | List changed files |
| -v |  |  | Verbose |
| -f |  |  | Hide errors |

<a id="cmd-chmod"></a>
### chmod

MODE is octal number (bit pattern sstrwxrwxrwx) or [ugoa]{+|-|=}[rwxXst]

Risk: state-changing. Source: busybox.

```text
chmod  [-Rcvf] MODE[,MODE]... FILE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -R |  |  | Recurse |
| -c |  |  | List changed files |
| -v |  |  | Verbose |
| -f |  |  | Hide errors |

<a id="cmd-chown"></a>
### chown

Change the owner and/or group of FILEs to USER and/or GRP

Risk: state-changing. Source: busybox.

```text
chown  [-RhLHPcvf]... USER[:[GRP]] FILE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -R |  |  | Recurse |
| -h |  |  | Affect symlinks instead of symlink targets |
| -L |  |  | Traverse all symlinks to directories |
| -H |  |  | Traverse symlinks on command line only |
| -P |  |  | Don't traverse symlinks (default) |
| -c |  |  | List changed files |
| -v |  |  | Verbose |
| -f |  |  | Hide errors |

<a id="cmd-chpasswd"></a>
### chpasswd

Read user:password from stdin and update /etc/passwd

Risk: unclassified. Source: busybox.

```text
chpasswd  [-me] [-c ALG] [-R DIR]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -m |  |  | Encrypt using md5, not des |
| -e |  |  | Supplied passwords are in encrypted form |
| -c |  | ALG | des,md5,sha256/512 (default sha256) |
| -R |  | DIR | Directory to chroot into |

<a id="cmd-chroot"></a>
### chroot

Run PROG with root directory set to NEWROOT

Risk: state-changing. Source: busybox.

```text
chroot  NEWROOT [PROG ARGS]
```


<a id="cmd-chvt"></a>
### chvt

Change the foreground virtual terminal to /dev/ttyN

Risk: unclassified. Source: busybox.

```text
chvt  N
```


<a id="cmd-clear"></a>
### clear

Clear screen

Risk: unclassified. Source: busybox.

```text
clear 
```


<a id="cmd-cmp"></a>
### cmp

Compare FILE1 with FILE2 (or stdin)

Risk: unclassified. Source: busybox.

```text
cmp  [-ls] [-n NUM] FILE1 [FILE2 [SKIP1 [SKIP2]]]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -l |  |  | Write the byte numbers (decimal) and values (octal) for all differing bytes |
| -s |  |  | Quiet |
| -n |  | NUM | Compare at most NUM bytes |

<a id="cmd-cp"></a>
### cp

or: cp [-arPLHpfinlsu] SOURCE... { -t DIRECTORY | DIRECTORY }

Risk: state-changing. Source: busybox.

```text
cp  [-arPLHpfinlsTu] SOURCE DEST
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Same as -dpR |
| -r |  |  |  |
| -P |  |  |  |
| -L |  |  | Follow all symlinks |
| -H |  |  | Follow symlinks on command line |
| -p |  |  | Preserve file attributes if possible |
| -f |  |  | Overwrite |
| -i |  |  | Prompt before overwrite |
| -n |  |  | Don't overwrite |
| -l (-s) |  |  | Create (sym)links |
| -s |  |  |  |
| -T |  |  | Refuse to copy if DEST is a directory |
| -u |  |  | Copy only newer files |
| -R (-r) |  |  | Recurse |
| -d (-P) |  |  | Preserve symlinks (default if -R) |
| -t |  | DIR | Copy all SOURCEs into DIR |

<a id="cmd-cpio"></a>
### cpio

Extract (-i) or list (-t) files from a cpio archive, or

Risk: unclassified. Source: busybox.

```text
cpio  [-dmvu] [-F FILE] [-R USER[:GRP]] [-H newc] [-tio] [EXTR_FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  |  | Make leading directories |
| -m |  |  | Restore mtime |
| -v |  |  | Verbose |
| -u |  |  | Overwrite |
| -F |  | FILE | Input (-t,-i,-p) or output (-o) file |
| -R |  | USER[:GRP] | Set owner of created files |
| -H |  | newc | Archive format |
| -t |  |  | List |
| -i |  |  | Extract EXTR_FILEs (or all) |
| -o |  |  | Create (requires -H newc) |
| -L |  |  | Dereference symlinks |
| -0 |  |  | NUL terminated input |
|  | --ignore-devno |  |  |
|  | --renumber-inodes |  |  |

<a id="cmd-crc32"></a>
### crc32

Calculate CRC32 checksum of FILEs

Risk: unclassified. Source: busybox.

```text
crc32  FILE...
```


<a id="cmd-crond"></a>
### crond

Risk: unclassified. Source: busybox.

```text
crond  [-fbS] [-l N] [-L LOGFILE] [-c DIR]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Foreground |
| -b |  |  | Background (default) |
| -S |  |  | Log to syslog (default) |
| -l |  | N | Set log level. Most verbose 0, default 8 |
| -L |  | LOGFILE | Log to FILE |
| -c |  | DIR | Cron dir. Default:/var/spool/cron/crontabs |

<a id="cmd-crontab"></a>
### crontab

Risk: state-changing. Source: busybox.

```text
crontab  [-c DIR] [-u USER] [-ler]|[FILE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  | DIR | Crontab directory |
| -u |  | USER | User |
| -l |  |  | List crontab |
| -e |  |  | Edit crontab |
| -r |  |  | Delete crontab FILE	Replace crontab by FILE ('-': stdin) |

<a id="cmd-cttyhack"></a>
### cttyhack

Give PROG a controlling tty if possible.

Risk: unclassified. Source: busybox.

```text
cttyhack  [PROG ARGS]
```


<a id="cmd-cut"></a>
### cut

Print selected fields from FILEs to stdout

Risk: unclassified. Source: busybox.

```text
cut  [OPTIONS] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -b |  | LIST | Output only bytes from LIST |
| -c |  | LIST | Output only characters from LIST |
| -d |  | SEP | Field delimiter for input (default -f TAB, -F run of whitespace) |
| -O |  | SEP | Field delimiter for output (default = -d for -f, one space for -F) |
| -D |  |  | Don't sort/collate sections or match -fF lines without delimiter |
| -f |  | LIST | Print only these fields (-d is single char) |
| -F |  | LIST | Print only these fields (-d is regex) |
| -s |  |  | Output only lines containing delimiter |
| -n |  |  | Ignored |

<a id="cmd-date"></a>
### date

Display time (using +FMT), or set time

Risk: state-changing. Source: busybox.

```text
date  [OPTIONS] [+FMT] [[-s] TIME]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -u |  |  | Work in UTC (don't convert to local time) [-s] TIME	Set time to TIME |
| -d |  | TIME | Display TIME, not 'now' |
| -D |  | FMT | FMT (strptime format) for -s/-d TIME conversion |
| -r |  | FILE | Display last modification time of FILE |
| -R |  |  | Output RFC-2822 date |
| -I[SPEC] |  |  | Output ISO-8601 date |
| SPEC= |  | date (default), hours, minutes, seconds or ns |  |

<a id="cmd-dc"></a>
### dc

Tiny RPN calculator. Operations:

Risk: unclassified. Source: busybox.

```text
dc  [-x] [-eSCRIPT]... [-fFILE]... [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -x |  |  |  |
| -e |  |  |  |
| -S |  |  |  |
| -C |  |  |  |
| -R |  |  |  |
| -I |  |  |  |
| -P |  |  |  |
| -T |  |  |  |
| -f |  |  |  |
| -F |  |  |  |
| -L |  |  |  |
| -E |  |  |  |

<a id="cmd-dd"></a>
### dd

Copy a file with converting and formatting

Risk: destructive. Source: busybox.

```text
dd  [if=FILE] [of=FILE] [ibs=N obs=N/bs=N] [count=N] [skip=N] [seek=N] [conv=notrunc|noerror|sync|fsync] [iflag=skip_bytes|count_bytes|fullblock|direct] [oflag=seek_bytes|append|direct]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| if= |  | FILE | Read from FILE instead of stdin |
| of= |  | FILE | Write to FILE instead of stdout |
| ibs= |  | N | Read N bytes at a time |
| obs= |  | N/bs=N | Write N bytes at a time |
| count= |  | N | Copy only N input blocks |
| skip= |  | N | Skip N input blocks |
| seek= |  | N | Skip N output blocks |
| conv= |  | notrunc\|noerror\|sync\|fsync | Don't truncate output file; Continue after read errors; Pad blocks with zeros; Physically write data out before finishing; Swap every pair of bytes |
| iflag= |  | skip_bytes\|count_bytes\|fullblock\|direct | skip=N is in bytes; count=N is in bytes; O_DIRECT input; Read full blocks |
| oflag= |  | seek_bytes\|append\|direct | seek=N is in bytes; O_DIRECT output; Open output in append mode |
| bs= |  | N | Read and write N bytes at a time |
| status= |  | noxfer | Suppress rate output; Suppress all output |

<a id="cmd-deallocvt"></a>
### deallocvt

Deallocate unused virtual terminal /dev/ttyN

Risk: unclassified. Source: busybox.

```text
deallocvt  [N]
```


<a id="cmd-depmod"></a>
### depmod

Generate modules.dep, alias, and symbols files

Risk: unclassified. Source: busybox.

```text
depmod  [-n] [-b BASE] [VERSION] [MODFILES]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n |  |  | Dry run: print files to stdout |
| -b |  | BASE | Use BASE/lib/modules/VERSION |

<a id="cmd-devmem"></a>
### devmem

Read/write from physical address

Risk: unclassified. Source: busybox.

```text
devmem  ADDRESS [WIDTH [VALUE]]
```


<a id="cmd-df"></a>
### df

Print filesystem usage statistics

Risk: unclassified. Source: busybox.

```text
df  [-PkmhTai] [-B SIZE] [-t TYPE] [FILESYSTEM]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -P |  |  | POSIX output format |
| -k |  |  | 1024-byte blocks (default) |
| -m |  |  | 1M-byte blocks |
| -h |  |  | Human readable (e.g. 1K 243M 2G) |
| -T |  |  | Print filesystem type |
| -a |  |  | Show all filesystems |
| -i |  |  | Inodes |
| -B |  | SIZE | Blocksize |
| -t |  | TYPE | Print only mounts of this type |

<a id="cmd-diff"></a>
### diff

Compare files line by line and output the differences between them.

Risk: unclassified. Source: busybox.

```text
diff  [-abBdiNqrTstw] [-L LABEL] [-S FILE] [-U LINES] FILE1 FILE2
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Treat all files as text |
| -b |  |  | Ignore changes in the amount of whitespace |
| -B |  |  | Ignore changes whose lines are all blank |
| -d |  |  | Try hard to find a smaller set of changes |
| -i |  |  | Ignore case differences |
| -N |  |  | Treat absent files as empty |
| -q |  |  | Output only whether files differ |
| -r |  |  | Recurse |
| -T |  |  | Make tabs line up by prefixing a tab when necessary |
| -s |  |  | Report when two files are the same |
| -t |  |  | Expand tabs to spaces in output |
| -w |  |  | Ignore all whitespace |
| -L |  | LABEL | Use LABEL instead of the filename in the unified header |
| -S |  | FILE | Start with FILE when comparing directories |
| -U |  | LINES | Output LINES lines of context |

<a id="cmd-dirname"></a>
### dirname

Strip non-directory suffix from FILENAME

Risk: unclassified. Source: busybox.

```text
dirname  FILENAME
```


<a id="cmd-dmesg"></a>
### dmesg

Print or control the kernel ring buffer

Risk: unclassified. Source: busybox.

```text
dmesg  [-cr] [-n LEVEL] [-s SIZE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Clear ring buffer after printing |
| -r |  |  | Print raw message buffer |
| -n |  | LEVEL | Set console logging level |
| -s |  | SIZE | Buffer size |

<a id="cmd-dos2unix"></a>
### dos2unix

Convert FILE in-place from DOS to Unix format.

Risk: unclassified. Source: busybox.

```text
dos2unix  [-ud] [FILE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -u |  |  | dos2unix |
| -d |  |  | unix2dos |

<a id="cmd-dpkg"></a>
### dpkg

Install, remove and manage Debian packages

Risk: unclassified. Source: busybox.

```text
dpkg  [-ilCPru] [-F OPT] PACKAGE
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -i | --install |  | Install the package |
| -l | --list |  | List of installed packages |
| -C |  |  |  |
| -P | --purge |  | Purge all files of a package |
| -r | --remove |  | Remove all but the configuration files for a package |
| -u |  |  |  |
| -F |  | OPT |  |
|  | --configure |  | Configure an unpackaged package |
|  | --unpack |  | Unpack a package, but don't configure it |
|  | --force-depends |  | Ignore dependency problems |
|  | --force-confnew |  | Overwrite existing config files when installing |
|  | --force-confold |  | Keep old config files when installing |

<a id="cmd-dpkg-deb"></a>
### dpkg-deb

Perform actions on Debian packages (.deb)

Risk: unclassified. Source: busybox.

```text
dpkg-deb  [-cefxX] FILE [DIR]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | List files |
| -e |  |  | Extract control files to DIR (default: ./DEBIAN) |
| -f |  |  | Print control fields |
| -x |  |  | Extract files to DIR (no default) |
| -X |  |  | Verbose extract |

<a id="cmd-du"></a>
### du

Summarize disk space used for FILEs (or directories)

Risk: unclassified. Source: busybox.

```text
du  [-aHLdclsxhmk] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Show file sizes too |
| -H |  |  | Follow symlinks on command line |
| -L |  |  | Follow all symlinks |
| -d |  | N | Limit output to directories (and files with -a) of depth < N |
| -c |  |  | Show grand total |
| -l |  |  | Count sizes many times if hard linked |
| -s |  |  | Display only a total for each argument |
| -x |  |  | Skip directories on different filesystems |
| -h |  |  | Sizes in human readable format (e.g., 1K 243M 2G) |
| -m |  |  | Sizes in megabytes |
| -k |  |  | Sizes in kilobytes (default) |
| -b |  |  | Apparent size (including holes) |

<a id="cmd-dumpkmap"></a>
### dumpkmap

Print a binary keyboard translation table to stdout

Risk: unclassified. Source: busybox.

```text
dumpkmap  > keymap
```


<a id="cmd-dumpleases"></a>
### dumpleases

Display DHCP leases granted by udhcpd

Risk: unclassified. Source: busybox.

```text
dumpleases  [-r|-a] [-d] [-f LEASEFILE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -r |  |  | Show remaining time |
| -a |  |  | Show expiration time |
| -d |  |  | Show time in seconds |
| -f |  | LEASEFILE | Lease file |

<a id="cmd-ed"></a>
### ed

Risk: unclassified. Source: busybox.

```text
ed  [-p PROMPT] [-s] [FILE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -p |  | PROMPT |  |
| -s |  |  |  |

<a id="cmd-env"></a>
### env

Print current environment or run PROG after setting up environment

Risk: unclassified. Source: busybox.

```text
env  [-i0] [-u NAME]... [-] [NAME=VALUE]... [PROG ARGS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -i |  |  |  |
| -0 |  |  | NUL terminated output |
| -u |  | NAME | Remove variable from environment |
| - (-i) |  |  | Start with empty environment |

<a id="cmd-expand"></a>
### expand

Convert tabs to spaces, writing to stdout

Risk: unclassified. Source: busybox.

```text
expand  [-i] [-t N] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -i |  |  | Don't convert tabs after non blanks |
| -t |  | N | Tabstops every N chars |

<a id="cmd-expr"></a>
### expr

Print the value of EXPRESSION

Risk: unclassified. Source: busybox.

```text
expr  EXPRESSION
```


<a id="cmd-factor"></a>
### factor

Print prime factors

Risk: unclassified. Source: busybox.

```text
factor  [NUMBER]...
```


<a id="cmd-fallocate"></a>
### fallocate

Preallocate space for FILE

Risk: unclassified. Source: busybox.

```text
fallocate  [-o OFS] -l LEN FILE
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -o |  | OFS | Offset of range |
| -l |  | LEN | Length of range |

<a id="cmd-fatattr"></a>
### fatattr

Change file attributes on FAT filesystem

Risk: unclassified. Source: busybox.

```text
fatattr  [-+rhsvda] FILE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -r |  |  |  |
| -h |  |  |  |
| -s |  |  |  |
| -v |  |  |  |
| -d |  |  |  |
| -a |  |  |  |

<a id="cmd-fdisk"></a>
### fdisk

Change partition table

Risk: destructive. Source: busybox.

```text
fdisk  [-ul] [-C CYLINDERS] [-H HEADS] [-S SECTORS] [-b SSZ] DISK
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -u |  |  | Start and End are in sectors (instead of cylinders) |
| -l |  |  | Show partition table for each DISK, then exit |
| -C |  | CYLINDERS | Set number of cylinders/heads/sectors |
| -H |  | HEADS | Typically 255 |
| -S |  | SECTORS | Typically 63 |
| -b |  | SSZ | (for certain MO disks) use 2048-byte sectors |

<a id="cmd-find"></a>
### find

Search for files and perform actions on them.

Risk: unclassified. Source: busybox.

```text
find  [-HL] [PATH]... [OPTIONS] [ACTIONS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -H |  |  | ...on command line only |
| -L (-follow) |  |  | Follow symlinks |
| -xdev |  |  | Don't descend directories on other filesystems |
| -maxdepth |  | N | Descend at most N levels. -maxdepth 0 applies actions to command line arguments only |
| -mindepth |  | N | Don't act on first N levels |
| -depth |  |  | Act on directory *after* traversing it |
| -name |  | PATTERN | Match file name (w/o directory name) to PATTERN |
| -iname |  | PATTERN | Case insensitive -name |
| -path |  | PATTERN | Match path to PATTERN |
| -ipath |  | PATTERN | Case insensitive -path |
| -regex |  | PATTERN | Match path to regex PATTERN |
| -type |  | X | File type is X (one of: f,d,l,b,c,s,p) |
| -executable |  |  | File is executable |
| -perm |  | MASK | At least one mask bit (+MASK), all bits (-MASK), or exactly MASK bits are set in file's mode |
| -mtime |  | DAYS | mtime is greater than (+N), less than (-N), or exactly N days in the past |
| -atime |  | DAYS | atime +N/-N/N days in the past |
| -ctime |  | DAYS | ctime +N/-N/N days in the past |
| -mmin |  | MINS | mtime is greater than (+N), less than (-N), or exactly N minutes in the past |
| -amin |  | MINS | atime +N/-N/N minutes in the past |
| -cmin |  | MINS | ctime +N/-N/N minutes in the past |
| -newer |  | FILE | mtime is more recent than FILE's |
| -inum |  | N | File has inode number N |
| -samefile |  | FILE | File is same as FILE |
| -user |  | NAME/ID | File is owned by given user |
| -group |  | NAME/ID | File is owned by given group |
| -size |  | N[bck] | File size is N (c:bytes,k:kbytes,b:512 bytes(def.)) +/-N: file size is bigger/smaller than N |
| -links |  | N | Number of links is greater than (+N), less than (-N), or exactly N |
| -empty |  |  | Match empty file/directory |
| -prune |  |  | If current file is directory, don't descend into it |
| -print |  |  | Print file name |
| -print0 |  |  | Print file name, NUL terminated |
| -exec |  | CMD ARG ; | Run CMD with all instances of {} replaced by file name. Fails if CMD exits with nonzero |
| -quit |  |  | Exit |

<a id="cmd-findfs"></a>
### findfs

Find a filesystem device based on a label or UUID

Risk: unclassified. Source: busybox.

```text
findfs  LABEL=label or UUID=uuid
```


<a id="cmd-fold"></a>
### fold

Wrap input lines in FILEs (or stdin), writing to stdout

Risk: unclassified. Source: busybox.

```text
fold  [-bs] [-w WIDTH] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -b |  |  | Count bytes rather than columns |
| -s |  |  | Break at spaces |
| -w |  | WIDTH | Use WIDTH columns instead of 80 |

<a id="cmd-free"></a>
### free

Display free and used memory

Risk: unclassified. Source: busybox.

```text
free  [-bkmgh]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -b |  |  |  |
| -k |  |  |  |
| -m |  |  |  |
| -g |  |  |  |
| -h |  |  |  |

<a id="cmd-freeramdisk"></a>
### freeramdisk

Free all memory used by the specified ramdisk

Risk: unclassified. Source: busybox.

```text
freeramdisk  DEVICE
```


<a id="cmd-fsfreeze"></a>
### fsfreeze

Flush and halt writes to MOUNTPOINT

Risk: unclassified. Source: busybox.

```text
fsfreeze  --[un]freeze MOUNTPOINT
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
|  | --[un]freeze |  |  |

<a id="cmd-fstrim"></a>
### fstrim

Risk: unclassified. Source: busybox.

```text
fstrim  [OPTIONS] MOUNTPOINT
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -o |  | OFFSET | Offset in bytes to discard from |
| -l |  | LEN | Bytes to discard |
| -m |  | MIN | Minimum extent length |
| -v |  |  | Print number of discarded bytes |

<a id="cmd-ftpget"></a>
### ftpget

Download a file via FTP

Risk: unclassified. Source: busybox.

```text
ftpget  [OPTIONS] HOST [LOCAL_FILE] REMOTE_FILE
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Continue previous transfer |
| -v |  |  | Verbose |
| -u |  | USER | Username |
| -p |  | PASS | Password |
| -P |  | PORT |  |

<a id="cmd-ftpput"></a>
### ftpput

Upload a file to a FTP server

Risk: unclassified. Source: busybox.

```text
ftpput  [OPTIONS] HOST [REMOTE_FILE] LOCAL_FILE
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -v |  |  | Verbose |
| -u |  | USER | Username |
| -p |  | PASS | Password |
| -P |  | PORT |  |

<a id="cmd-getopt"></a>
### getopt

Example:

Risk: unclassified. Source: busybox.

```text
getopt  [OPTIONS] [--] OPTSTRING PARAMS
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
|  | -- |  |  |
| -a |  |  | Allow long options starting with single - |
| -l |  | LOPT[ ...] | Long options to recognize |
| -n |  | PROGNAME | The name under which errors are reported |
| -o |  | OPTSTRING | Short options to recognize |
| -q |  |  | No error messages on unrecognized options |
| -Q |  |  | No normal output |
| -s |  | SHELL | Set shell quoting conventions |
| -T |  |  | Version test (exits with 4) |
| -u |  |  | Don't quote output |
| -a) |  |  | echo A; shift;; |
| -b\|--bb) |  | echo "B:'$2'"; shift 2;; |  |
| -c) |  |  | case "$2" in "")	echo C; shift 2;; *)	echo "C:'$2'"; shift 2;; esac;; |
|  | --) |  | shift; break;; *)	echo Error; exit 1;; esac |

<a id="cmd-getty"></a>
### getty

Open TTY, prompt for login name, then invoke /bin/login

Risk: unclassified. Source: busybox.

```text
getty  [OPTIONS] BAUD_RATE[,BAUD_RATE]... TTY [TERMTYPE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -h |  |  | Enable hardware RTS/CTS flow control |
| -L |  |  | Set CLOCAL (ignore Carrier Detect state) |
| -m |  |  | Get baud rate from modem's CONNECT status message |
| -n |  |  | Don't prompt for login name |
| -w |  |  | Wait for CR or LF before sending /etc/issue |
| -i |  |  | Don't display /etc/issue |
| -f |  | ISSUE_FILE | Display ISSUE_FILE instead of /etc/issue |
| -l |  | LOGIN | Invoke LOGIN instead of /bin/login |
| -t |  | SEC | Terminate after SEC if no login name is read |
| -I |  | INITSTR | Send INITSTR before anything else |
| -H |  | HOST | Log HOST into the utmp file as the hostname |

<a id="cmd-grep"></a>
### grep

Search for PATTERN in FILEs (or stdin)

Risk: unclassified. Source: busybox.

```text
grep  [-HhnlLoqvsrRiwFEz] [-m N] [-A|B|C N] { PATTERN | -e PATTERN... | -f FILE... } [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -H |  |  | Add 'filename:' prefix |
| -h |  |  | Do not add 'filename:' prefix |
| -n |  |  | Add 'line_no:' prefix |
| -l |  |  | Show only names of files that match |
| -L |  |  | Show only names of files that don't match |
| -o |  |  | Show only the matching part of line |
| -q |  |  | Quiet. Return 0 if PATTERN is found, 1 otherwise |
| -v |  |  | Select non-matching lines |
| -s |  |  | Suppress open and read errors |
| -r |  |  | Recurse |
| -R |  |  | Recurse and dereference symlinks |
| -i |  |  | Ignore case |
| -w |  |  | Match whole words only |
| -F |  |  | PATTERN is a literal (not regexp) |
| -E |  |  | PATTERN is an extended regexp |
| -z |  |  | NUL terminated input |
| -m |  | N | Match up to N times per file |
| -A |  | N | Print N lines of trailing context |
| -c |  |  | Show only count of matching lines |
| -x |  |  | Match whole lines only |
| -B |  | N | Print N lines of leading context |
| -C |  | N | Same as '-A N -B N' |
| -e |  | PTRN | Pattern to match |
| -f |  | FILE | Read pattern from file |

<a id="cmd-groups"></a>
### groups

Print the groups USER is in

Risk: unclassified. Source: busybox.

```text
groups  [USER]
```


<a id="cmd-gunzip"></a>
### gunzip

Decompress FILEs (or stdin)

Risk: unclassified. Source: busybox.

```text
gunzip  [-cfkt] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Write to stdout |
| -f |  |  | Force |
| -k |  |  | Keep input files |
| -t |  |  | Test integrity |

<a id="cmd-gzip"></a>
### gzip

Compress FILEs (or stdin)

Risk: unclassified. Source: busybox.

```text
gzip  [-cfkdt] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Write to stdout |
| -f |  |  | Force |
| -k |  |  | Keep input files |
| -d |  |  | Decompress |
| -t |  |  | Test integrity |

<a id="cmd-halt"></a>
### halt

Halt the system

Risk: destructive. Source: busybox.

```text
halt  [-d DELAY] [-nfw]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  | DELAY | Delay interval |
| -n |  |  | Do not sync |
| -f |  |  | Force (don't go through init) |
| -w |  |  | Only write a wtmp record |

<a id="cmd-head"></a>
### head

Print first 10 lines of FILEs (or stdin).

Risk: unclassified. Source: busybox.

```text
head  [OPTIONS] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n (-N[bkm]) |  | N[bkm] | Print first N lines; Print all except N last lines |
| -c |  | [-] | Print first N bytes (b:*512 k:*1024 m:*1024^2) |
| -q |  |  | Never print headers |
| -v |  |  | Always print headers |

<a id="cmd-hexdump"></a>
### hexdump

Display FILEs (or stdin) in a user specified format

Risk: unclassified. Source: busybox.

```text
hexdump  [-bcdoxCv] [-e FMT] [-f FMT_FILE] [-n LEN] [-s OFS] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -b |  |  | 1-byte octal display |
| -c |  |  | 1-byte character display |
| -d |  |  | 2-byte decimal display |
| -o |  |  | 2-byte octal display |
| -x |  |  | 2-byte hex display |
| -C |  |  | hex+ASCII 16 bytes per line |
| -v |  |  | Show all (no dup folding) |
| -e |  | FMT | Example: '16/1 "%02x\|""\n"' |
| -f |  | FMT_FILE |  |
| -n |  | LEN | Show only first LENGTH bytes |
| -s |  | OFS | Skip OFFSET bytes |

<a id="cmd-hostid"></a>
### hostid

Print out a unique 32-bit identifier for the machine

Risk: unclassified. Source: busybox.

```text
hostid 
```


<a id="cmd-hostname"></a>
### hostname

Show or set hostname or DNS domain name

Risk: unclassified. Source: busybox.

```text
hostname  [-sidf] [HOSTNAME | -F FILE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -s |  |  | Short |
| -i |  |  | Addresses for the hostname |
| -d |  |  | DNS domain name |
| -f |  |  | Fully qualified domain name |
| -F |  | FILE | Use FILE's content as hostname |

<a id="cmd-httpd"></a>
### httpd

or httpd -d/-e/-m STRING

Risk: unclassified. Source: busybox.

```text
httpd  [-ifv[v]] [-c CONFFILE] [-p [IP:]PORT] [-u USER[:GRP]] [-r REALM] [-h HOME]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -i |  |  | Inetd mode |
| -f |  |  | Run in foreground |
| -v |  |  |  |
| -c |  | CONFFILE | Configuration file (default {/etc,HOME}/httpd.conf) |
| -p |  | [IP:]PORT | Bind to IP:PORT (default *:80) |
| -u |  | USER[:GRP] | Set uid/gid after binding to port |
| -r |  | REALM | Authentication Realm for Basic Authentication |
| -h |  | HOME | Home directory (default .) |
| -v[v] |  |  | Verbose |
| -m |  | STRING | MD5 crypt STRING |
| -e |  | STRING | HTML encode STRING |
| -d |  | STRING | URL decode STRING |

<a id="cmd-hwclock"></a>
### hwclock

Show or set hardware clock (RTC)

Risk: state-changing. Source: busybox.

```text
hwclock  [-swul] [--systz] [-f DEV]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -s |  |  | Set system time from RTC |
| -w |  |  | Set RTC from system time |
| -u |  |  | Assume RTC is kept in UTC |
| -l |  |  | Assume RTC is kept in local time (if neither is given, read from /etc/adjtime) |
|  | --systz |  | Set in-kernel timezone, correct system time if RTC is kept in local time |
| -f |  | DEV | Use specified device (e.g. /dev/rtc2) |

<a id="cmd-i2cdetect"></a>
### i2cdetect

Detect I2C chips

Risk: unclassified. Source: busybox.

```text
i2cdetect  -l | -F I2CBUS | [-ya] [-q|-r] I2CBUS [FIRST LAST]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -l |  |  | List installed buses |
| -F |  | BUS# | List functionalities on this bus |
| -y |  |  | Disable interactive mode |
| -a |  |  | Force scanning of non-regular addresses |
| -q |  |  | Use smbus quick write commands for probing (default) |
| -r |  |  | Use smbus read byte commands for probing FIRST and LAST limit probing range |

<a id="cmd-i2cdump"></a>
### i2cdump

Examine I2C registers

Risk: unclassified. Source: busybox.

```text
i2cdump  [-fy] [-r FIRST-LAST] BUS ADDR [MODE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Force access |
| -y |  |  | Disable interactive mode |
| -r |  | FIRST-LAST | Limit the number of registers being accessed |

<a id="cmd-i2cget"></a>
### i2cget

Read from I2C/SMBus chip registers

Risk: unclassified. Source: busybox.

```text
i2cget  [-fy] BUS CHIP-ADDRESS [DATA-ADDRESS [MODE]]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Force access |
| -y |  |  | Disable interactive mode |

<a id="cmd-i2cset"></a>
### i2cset

Set I2C registers

Risk: unclassified. Source: busybox.

```text
i2cset  [-fy] [-m MASK] BUS CHIP-ADDRESS DATA-ADDRESS [VALUE] ... [MODE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Force access |
| -y |  |  | Disable interactive mode |
| -m |  | MASK | Mask specifying which bits to write |
| -r |  |  | Read back and compare the result |

<a id="cmd-i2ctransfer"></a>
### i2ctransfer

Read/write I2C data in one transfer

Risk: unclassified. Source: busybox.

```text
i2ctransfer  [-fay] I2CBUS { rLENGTH[@ADDR] | wLENGTH[@ADDR] DATA...}...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Force access to busy addresses |
| -a |  |  | Force access to non-regular addresses |
| -y |  |  | Disable interactive mode |

<a id="cmd-id"></a>
### id

Print information about USER or the current user

Risk: unclassified. Source: busybox.

```text
id  [-ugGnr] [USER]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -u |  |  | User ID |
| -g |  |  | Group ID |
| -G |  |  | Supplementary group IDs |
| -n |  |  | Print names instead of numbers |
| -r |  |  | Print real ID instead of effective ID |

<a id="cmd-ifconfig"></a>
### ifconfig

Configure a network interface

Risk: state-changing. Source: busybox.

```text
ifconfig  [-a] [IFACE] [ADDRESS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  |  |

<a id="cmd-ifdown"></a>
### ifdown

Risk: state-changing. Source: busybox.

```text
ifdown  [-nmvf] [-i FILE] -a | IFACE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n |  |  | Dry run (note: doesn't disable mappings) |
| -m |  |  | Don't run any mappings |
| -v |  |  | Print out what would happen before doing it |
| -f |  |  | Force |
| -i |  | FILE | Use FILE instead of /etc/network/interfaces |
| -a |  |  | Deconfigure all interfaces |

<a id="cmd-ifup"></a>
### ifup

Risk: state-changing. Source: busybox.

```text
ifup  [-nmvf] [-i FILE] -a | IFACE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n |  |  | Dry run (note: doesn't disable mappings) |
| -m |  |  | Don't run any mappings |
| -v |  |  | Print out what would happen before doing it |
| -f |  |  | Force |
| -i |  | FILE | Use FILE instead of /etc/network/interfaces |
| -a |  |  | Configure all interfaces |

<a id="cmd-init"></a>
### init

Init is the first process started during boot. It never exits.

Risk: destructive. Source: busybox.

```text
init 
```


<a id="cmd-insmod"></a>
### insmod

Load kernel module

Risk: state-changing. Source: busybox.

```text
insmod  FILE [SYMBOL=VALUE]...
```


<a id="cmd-ionice"></a>
### ionice

Change I/O priority and class

Risk: unclassified. Source: busybox.

```text
ionice  [-c 1-3] [-n 0-7] [-t] { -p PID | PROG ARGS }
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  | 1-3 | Class. 1:realtime 2:best-effort 3:idle |
| -n |  | 0-7 | Priority |
| -t |  |  | Ignore errors |

<a id="cmd-ip"></a>
### ip

Risk: state-changing. Source: busybox.

```text
ip  [OPTIONS] address|route|link|tunnel|neigh|rule [ARGS]
ip addr add|del IFADDR dev IFACE | show|flush [dev IFACE] [to PREFIX]
ip route list|flush|add|del|change|append|replace|test ROUTE
ip link set IFACE [up|down] [arp on|off] [multicast on|off]
ip tunnel add|change|del|show [NAME]
ip neigh show|flush [to PREFIX] [dev DEV] [nud STATE]
ip rule [list] | add|del SELECTOR ACTION
```


<a id="cmd-ipcalc"></a>
### ipcalc

Calculate and display network settings from IP address

Risk: unclassified. Source: busybox.

```text
ipcalc  [-bnmphs] ADDRESS[/PREFIX] [NETMASK]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -b |  |  | Broadcast address |
| -n |  |  | Network address |
| -m |  |  | Default netmask for IP |
| -p |  |  | Prefix for IP/NETMASK |
| -h |  |  | Resolved host name |
| -s |  |  | No error messages |

<a id="cmd-kill"></a>
### kill

Send a signal (default: TERM) to given PIDs

Risk: destructive. Source: busybox.

```text
kill  [-l] [-SIG] PID...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -l |  |  | List all signal names and numbers |
| -S |  |  |  |
| -I |  |  |  |
| -G |  |  |  |

<a id="cmd-killall"></a>
### killall

Send a signal (default: TERM) to given processes

Risk: destructive. Source: busybox.

```text
killall  [-lq] [-SIG] PROCESS_NAME...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -l |  |  | List all signal names and numbers |
| -q |  |  | Don't complain if no processes were killed |
| -S |  |  |  |
| -I |  |  |  |
| -G |  |  |  |

<a id="cmd-klogd"></a>
### klogd

Log kernel messages to syslog

Risk: unclassified. Source: busybox.

```text
klogd  [-c N] [-n]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  | N | Print to console messages more urgent than prio N (1-8) |
| -n |  |  | Run in foreground |

<a id="cmd-last"></a>
### last

Show listing of the last users that logged into the system

Risk: unclassified. Source: busybox.

```text
last 
```


<a id="cmd-less"></a>
### less

View FILE (or stdin) one screenful at a time

Risk: unclassified. Source: busybox.

```text
less  [-EFIMmNSRh~] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -E |  |  | Quit once the end of a file is reached |
| -F |  |  | Quit if entire file fits on first screen |
| -I |  |  | Ignore case in all searches |
| -M (-m) |  |  | Display status line with line numbers and percentage through the file |
| -m |  |  |  |
| -N |  |  | Prefix line number to each line |
| -S |  |  | Truncate long lines |
| -R |  |  | Remove color escape codes in input |
| -h |  |  |  |
| -~ |  |  | Suppress ~s displayed past EOF |

<a id="cmd-link"></a>
### link

Create hard LINK to FILE

Risk: unclassified. Source: busybox.

```text
link  FILE LINK
```


<a id="cmd-ln"></a>
### ln

Create a link LINK or DIR/TARGET to the specified TARGET(s)

Risk: state-changing. Source: busybox.

```text
ln  [-sfnbtv] [-S SUF] TARGET... LINK|DIR
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -s |  |  | Make symlinks instead of hardlinks |
| -f |  |  | Remove existing destinations |
| -n |  |  | Don't dereference symlinks - treat like normal file |
| -b |  |  | Make a backup of the target (if exists) before link operation |
| -t |  |  |  |
| -v |  |  | Verbose |
| -S |  | SUF | Use suffix instead of ~ when making backup files |
| -T |  |  | Treat LINK as a file, not DIR |

<a id="cmd-loadfont"></a>
### loadfont

Load a console font from stdin

Risk: unclassified. Source: busybox.

```text
loadfont  < font
```


<a id="cmd-loadkmap"></a>
### loadkmap

Load a binary keyboard translation table from stdin

Risk: unclassified. Source: busybox.

```text
loadkmap  < keymap
```


<a id="cmd-logger"></a>
### logger

Write MESSAGE (or stdin) to syslog

Risk: unclassified. Source: busybox.

```text
logger  [-s] [-t TAG] [-p PRIO] [MESSAGE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -s |  |  | Log to stderr as well as the system log |
| -t |  | TAG | Log using the specified tag (defaults to user name) |
| -p |  | PRIO | Priority (number or FACILITY.LEVEL pair) |

<a id="cmd-login"></a>
### login

Begin a new session on the system

Risk: unclassified. Source: busybox.

```text
login  [-p] [-h HOST] [[-f] USER]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -p |  |  | Preserve environment |
| -h |  | HOST | Host user came from (for network logins) |
| -f |  |  | Don't authenticate (user already authenticated) |

<a id="cmd-logname"></a>
### logname

Print the name of the current user

Risk: unclassified. Source: busybox.

```text
logname 
```


<a id="cmd-logread"></a>
### logread

Show messages in syslogd's circular buffer

Risk: unclassified. Source: busybox.

```text
logread  [-fF]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Output data as log grows |
| -F |  |  | Same as -f, but dump buffer first |

<a id="cmd-losetup"></a>
### losetup

Risk: unclassified. Source: busybox.

```text
losetup  [-rP] [-o OFS] {-f|LOOPDEV} FILE: associate loop devices
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -r |  |  | Read-only |
| -P |  |  | Scan for partitions |
| -o |  | OFS | Start OFS bytes into FILE |
| -f |  |  | Show/use next free loop device |

<a id="cmd-ls"></a>
### ls

List directory contents

Risk: unclassified. Source: busybox.

```text
ls  [-1AaCxdLHRFplinshrSXvctu] [-w WIDTH] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -1 |  |  | One column output |
| -A |  |  | Like -a, but exclude . and .. |
| -a |  |  | Include names starting with . |
| -C |  |  |  |
| -x |  |  | List by lines |
| -d |  |  | List directory names, not contents |
| -L |  |  | Follow symlinks |
| -H |  |  | Follow symlinks on command line |
| -R |  |  | Recurse |
| -F |  |  | Append indicator (one of */=@\|) to names |
| -p |  |  | Append / to directory names |
| -l |  |  | Long format |
| -i |  |  | List inode numbers |
| -n |  |  | List numeric UIDs and GIDs instead of names |
| -s |  |  | List allocated blocks |
| -h |  |  | Human readable sizes (1K 243M 2G) |
| -r |  |  | Reverse sort order |
| -S |  |  | Sort by size |
| -X |  |  | Sort by extension |
| -v |  |  | Sort by version |
| -c |  |  |  |
| -t |  |  | Sort by mtime |
| -u |  |  |  |
| -w |  | WIDTH | Format N columns wide |
| -lc |  |  | List ctime |
| -lu |  |  | List atime |
|  | --full-time |  | List full date/time |
|  | --group-directories-first |  |  |
| -tc |  |  | Sort by ctime |
| -tu |  |  | Sort by atime |
|  | --color | [{always never auto}]] |  |

<a id="cmd-lsmod"></a>
### lsmod

List loaded kernel modules

Risk: unclassified. Source: busybox.

```text
lsmod 
```


<a id="cmd-lzcat"></a>
### lzcat

Decompress to stdout

Risk: unclassified. Source: busybox.

```text
lzcat  [FILE]...
```


<a id="cmd-lzma"></a>
### lzma

Decompress FILEs (or stdin)

Risk: unclassified. Source: busybox.

```text
lzma  -d [-cfk] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  |  | Decompress |
| -c |  |  | Write to stdout |
| -f |  |  | Force |
| -k |  |  | Keep input files |
| -t |  |  | Test integrity |

<a id="cmd-lzop"></a>
### lzop

Risk: unclassified. Source: busybox.

```text
lzop  [-cfUvd123456789CF] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Write to stdout |
| -f |  |  | Force |
| -U |  |  | Delete input files |
| -v |  |  | Verbose |
| -d |  |  | Decompress |
| -1 |  |  |  |
| -2 |  |  |  |
| -3 |  |  |  |
| -4 |  |  |  |
| -5 |  |  |  |
| -6 |  |  |  |
| -7 |  |  |  |
| -8 |  |  |  |
| -9 |  |  |  |
| -C |  |  | Also write checksum of compressed block |
| -F |  |  | Don't store or verify checksum |
| -1..9 |  |  | Compression level |

<a id="cmd-md5sum"></a>
### md5sum

Print or check MD5 checksums

Risk: unclassified. Source: busybox.

```text
md5sum  [-c[sw]] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Check sums against list in FILEs |
| -s |  |  | Don't output anything, status code shows success |
| -w |  |  | Warn about improperly formatted checksum lines |

<a id="cmd-mdev"></a>
### mdev

Bare mdev is a kernel hotplug helper. To activate it:

Risk: unclassified. Source: busybox.

```text
mdev  [-vS] { [-s] | [-df] }
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -v |  |  | Verbose |
| -S |  |  | Log to syslog too |
| -s |  |  | Scan /sys and populate /dev |
| -d |  |  | Daemon, listen on netlink |
| -f |  |  | Run in foreground |

<a id="cmd-microcom"></a>
### microcom

Copy bytes from stdin to TTY and from TTY to stdout

Risk: unclassified. Source: busybox.

```text
microcom  [-d DELAY_MS] [-t TIMEOUT_MS ] [-s SPEED] [-X] TTY
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  | DELAY_MS | Wait up to DELAY ms for TTY output before sending every next byte to it |
| -t |  | TIMEOUT_MS | Exit if both stdin and TTY are silent for TIMEOUT ms |
| -s |  | SPEED | Set serial line to SPEED |
| -X |  |  | Disable special meaning of NUL and Ctrl-X from stdin |

<a id="cmd-mim"></a>
### mim

Run a script from a Makefile-like specification file

Risk: unclassified. Source: busybox.

```text
mim  [-f FILE] [SHELL_OPTIONS] [TARGET] ...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  | FILE | Spec file (default Mimfile) |

<a id="cmd-mkdir"></a>
### mkdir

Create DIRECTORY

Risk: state-changing. Source: busybox.

```text
mkdir  [-m MODE] [-p] DIRECTORY...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -m |  | MODE | Mode |
| -p |  |  | No error if exists; make parent directories as needed |

<a id="cmd-mkdosfs"></a>
### mkdosfs

Make a FAT32 filesystem

Risk: destructive. Source: busybox.

```text
mkdosfs  [-v] [-n LABEL] BLOCKDEV [KBYTES]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -v |  |  | Verbose |
| -n |  | LABEL | Volume label |

<a id="cmd-mke2fs"></a>
### mke2fs

Risk: destructive. Source: busybox.

```text
mke2fs  [-Fn] [-b BLK_SIZE] [-i INODE_RATIO] [-I INODE_SIZE] [-m RESERVED_PERCENT] [-L LABEL] BLOCKDEV [KBYTES]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -F |  |  | Force |
| -n |  |  | Dry run |
| -b |  | BLK_SIZE | Block size, bytes |
| -i |  | INODE_RATIO | Max number of files is filesystem_size / RATIO |
| -I |  | INODE_SIZE | Inode size (min 128) |
| -m |  | RESERVED_PERCENT | Percent of blocks to reserve for admin |
| -L |  | LABEL | Volume label |

<a id="cmd-mkfifo"></a>
### mkfifo

Create named pipe

Risk: state-changing. Source: busybox.

```text
mkfifo  [-m MODE] NAME
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -m |  | MODE | Mode (default a=rw) |

<a id="cmd-mknod"></a>
### mknod

Create a special file (block, character, or pipe)

Risk: state-changing. Source: busybox.

```text
mknod  [-m MODE] NAME TYPE [MAJOR MINOR]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -m |  | MODE | Creation mode (default a=rw) |

<a id="cmd-mkpasswd"></a>
### mkpasswd

Print crypt(3) hashed PASSWORD

Risk: unclassified. Source: busybox.

```text
mkpasswd  [-P FD] [-m TYPE] [-S SALT] [PASSWORD] [SALT]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -P |  | FD | Read password from fd N |
| -m |  | TYPE | des,md5,sha256/512 (default sha256) |
| -S |  | SALT |  |

<a id="cmd-mkswap"></a>
### mkswap

Prepare BLOCKDEV to be used as swap partition

Risk: destructive. Source: busybox.

```text
mkswap  [-L LBL] BLOCKDEV [KBYTES]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -L |  | LBL | Label |

<a id="cmd-mktemp"></a>
### mktemp

Create a temporary file with name based on TEMPLATE and print its name.

Risk: unclassified. Source: busybox.

```text
mktemp  [-dt] [-p DIR] [TEMPLATE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  |  | Make directory, not file |
| -t |  |  | Prepend base directory name to TEMPLATE |
| -p |  | DIR | Use DIR as a base directory (implies -t) |
| -q |  |  | Fail silently on errors |
| -u |  |  | Do not create anything; print a name |

<a id="cmd-modinfo"></a>
### modinfo

Risk: unclassified. Source: busybox.

```text
modinfo  [-adlpn0] [-F keyword] MODULE
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Shortcut for '-F author' |
| -d |  |  | Shortcut for '-F description' |
| -l |  |  | Shortcut for '-F license' |
| -p |  |  | Shortcut for '-F parm' |
| -n |  |  |  |
| -0 |  |  | NUL terminated output |
| -F |  | keyword | Keyword to look for |

<a id="cmd-modprobe"></a>
### modprobe

Risk: state-changing. Source: busybox.

```text
modprobe  [-alrqvsDb] MODULE [SYMBOL=VALUE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Load multiple MODULEs |
| -l |  |  | List (MODULE is a pattern) |
| -r |  |  | Remove MODULE (stacks) or do autoclean |
| -q |  |  | Quiet |
| -v |  |  | Verbose |
| -s |  |  | Log to syslog |
| -D |  |  | Show dependencies |
| -b |  |  | Apply blacklist to module names too |

<a id="cmd-more"></a>
### more

View FILE (or stdin) one screenful at a time

Risk: unclassified. Source: busybox.

```text
more  [FILE]...
```


<a id="cmd-mount"></a>
### mount

Mount a filesystem. Filesystem autodetection requires /proc.

Risk: state-changing. Source: busybox.

```text
mount  [OPTIONS] [-o OPT] DEVICE NODE
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -o |  | OPT |  |
| -a |  |  | Mount all filesystems in fstab |
| -f |  |  | Dry run |
| -i |  |  | Don't run mount helper |
| -r |  |  | Read-only mount |
| -t |  | FSTYPE[ ...] | Filesystem type(s) |
| -T |  | FILE | Read FILE instead of /etc/fstab |
| -O |  | OPT | Mount only filesystems with option OPT (-a only) |

<a id="cmd-mt"></a>
### mt

Control magnetic tape drive operation

Risk: unclassified. Source: busybox.

```text
mt  [-f DEVICE] OPCODE VALUE
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  | DEVICE |  |

<a id="cmd-mv"></a>
### mv

or: mv [-fin] SOURCE... { -t DIRECTORY | DIRECTORY }

Risk: state-changing. Source: busybox.

```text
mv  [-finT] SOURCE DEST
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Don't prompt before overwriting |
| -i |  |  | Interactive, prompt before overwrite |
| -n |  |  | Don't overwrite an existing file |
| -T |  |  | Refuse to move if DEST is a directory |
| -t |  | DIR | Move all SOURCEs into DIR |

<a id="cmd-nameif"></a>
### nameif

Rename network interface while it in the down state.

Risk: unclassified. Source: busybox.

```text
nameif  [-s] [-c FILE] [IFNAME HWADDR]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -s |  |  | Log to syslog |
| -c |  | FILE | Configuration file (default: /etc/mactab) |

<a id="cmd-nbd-client"></a>
### nbd-client

Connect to HOST and provide network block device on BLOCKDEV

Risk: unclassified. Source: busybox.

```text
nbd-client  { [-b BLKSIZE] [-N NAME] [-t SEC] [-p] HOST [PORT] | -d } BLOCKDEV
```


<a id="cmd-nc"></a>
### nc

Open a pipe to IP:PORT or FILE

Risk: unclassified. Source: busybox.

```text
nc  [-iN] [-wN] [-l] [-p PORT] [-f FILE|IPADDR PORT] [-e PROG]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -i |  | SEC | Delay interval for lines sent |
| -N |  |  |  |
| -w |  | SEC | Connect timeout |
| -l |  |  | Listen mode, for inbound connects (use -ll with -e for persistent server) |
| -p |  | PORT | Local port |
| -f |  | FILE | Use file (ala /dev/ttyS0) instead of network |
| -e |  | PROG | Run PROG after connect |

<a id="cmd-netstat"></a>
### netstat

Display networking information

Risk: unclassified. Source: busybox.

```text
netstat  [-ral] [-tuwx] [-en]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -r |  |  | Routing table |
| -a |  |  | All sockets |
| -l |  |  | Listening sockets Else: connected sockets |
| -t |  |  | TCP sockets |
| -u |  |  | UDP sockets |
| -w |  |  | Raw sockets |
| -x |  |  | Unix sockets Else: all socket types |
| -e |  |  | Other/more information |
| -n |  |  | Don't resolve names |

<a id="cmd-nl"></a>
### nl

Write FILEs to standard output with line numbers added

Risk: unclassified. Source: busybox.

```text
nl  [OPTIONS] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -b |  | STYLE | Which lines to number - a: all, t: nonempty, n: none |
| -i |  | N | Line number increment |
| -s |  | STRING | Use STRING as line number separator |
| -v |  | N | Start from N |
| -w |  | N | Width of line numbers |

<a id="cmd-nologin"></a>
### nologin

Politely refuse a login

Risk: unclassified. Source: busybox.

```text
nologin 
```


<a id="cmd-nproc"></a>
### nproc

Print number of available CPUs

Risk: unclassified. Source: busybox.

```text
nproc  [--all] [--ignore=N]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
|  | --all |  | Number of installed CPUs |
|  | --ignore | N | Exclude N CPUs |

<a id="cmd-nsenter"></a>
### nsenter

Risk: unclassified. Source: busybox.

```text
nsenter  [OPTIONS] [PROG ARGS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -t |  | PID | Target process to get namespaces from |
| -m[FILE] |  |  | Enter mount namespace |
| -u[FILE] |  |  | Enter UTS namespace (hostname etc) |
| -i[FILE] |  |  | Enter System V IPC namespace |
| -n[FILE] |  |  | Enter network namespace |
| -p[FILE] |  |  | Enter pid namespace |
| -U[FILE] |  |  | Enter user namespace |
| -S |  | UID | Set uid in entered namespace |
| -G |  | GID | Set gid in entered namespace |
|  | --preserve-credentials |  | Don't touch uids or gids |
| -r[DIR] |  |  | Set root directory |
| -w[DIR] |  |  | Set working directory |
| -F |  |  | Don't fork before exec'ing PROG |

<a id="cmd-nslookup"></a>
### nslookup

Query DNS about HOST

Risk: unclassified. Source: busybox.

```text
nslookup  [-type=QUERY_TYPE] [-debug] HOST [DNS_SERVER]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -type |  |  |  |
| -d |  |  |  |
| -e |  |  |  |
| -b |  |  |  |
| -u |  |  |  |
| -g |  |  |  |

<a id="cmd-nuke"></a>
### nuke

Remove DIRs

Risk: unclassified. Source: busybox.

```text
nuke  DIR...
```


<a id="cmd-od"></a>
### od

Print FILEs (or stdin) unambiguously, as octal bytes by default

Risk: unclassified. Source: busybox.

```text
od  [-abcdfhilovxs] [-t TYPE] [-A RADIX] [-N SIZE] [-j SKIP] [-S MINSTR] [-w WIDTH] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  |  |
| -b |  |  |  |
| -c |  |  |  |
| -d |  |  |  |
| -f |  |  |  |
| -h |  |  |  |
| -i |  |  |  |
| -l |  |  |  |
| -o |  |  |  |
| -v |  |  |  |
| -x |  |  |  |
| -s |  |  |  |
| -t |  | TYPE |  |
| -A |  | RADIX |  |
| -N |  | SIZE |  |
| -j |  | SKIP |  |
| -S |  | MINSTR |  |
| -w |  | WIDTH |  |

<a id="cmd-openvt"></a>
### openvt

Start PROG on a new virtual terminal

Risk: unclassified. Source: busybox.

```text
openvt  [-c N] [-sw] [PROG ARGS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  | N | Use specified VT |
| -s |  |  | Switch to the VT |
| -w |  |  | Wait for PROG to exit |

<a id="cmd-partprobe"></a>
### partprobe

Ask kernel to rescan partition table

Risk: unclassified. Source: busybox.

```text
partprobe  DEVICE...
```


<a id="cmd-passwd"></a>
### passwd

Change USER's password (default: current user)

Risk: state-changing. Source: busybox.

```text
passwd  [-a ALG] [-dlu] [USER]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  | ALG | des,md5,sha256/512 (default sha256) |
| -d |  |  | Set password to '' |
| -l |  |  | Lock (disable) account |
| -u |  |  | Unlock (enable) account |

<a id="cmd-paste"></a>
### paste

Paste lines from each input file, separated with tab

Risk: unclassified. Source: busybox.

```text
paste  [-d LIST] [-s] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  | LIST | Use delimiters from LIST, not tab |
| -s |  |  | Serial: one file at a time |

<a id="cmd-patch"></a>
### patch

Risk: state-changing. Source: busybox.

```text
patch  [-RNE] [-p N] [-i DIFF] [ORIGFILE [PATCHFILE]]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -R |  |  | Reverse patch |
| -N |  |  | Ignore already applied patches |
| -E |  |  | Remove output files if they become empty |
| -p |  | N | Strip N leading components from file names |
| -i |  | DIFF | Read DIFF instead of stdin |
|  | --dry-run |  | Don't actually change files |

<a id="cmd-pidof"></a>
### pidof

List PIDs of all processes with names that match NAMEs

Risk: unclassified. Source: busybox.

```text
pidof  [NAME]...
```


<a id="cmd-ping"></a>
### ping

Send ICMP ECHO_REQUESTs to HOST

Risk: unclassified. Source: busybox.

```text
ping  [OPTIONS] HOST
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -4 (-6) |  |  | Force IP or IPv6 name resolution |
| -c |  | CNT | Send only CNT pings |
| -s |  | SIZE | Send SIZE data bytes in packets (default 56) |
| -i |  | SECS | Interval |
| -A |  |  | Ping as soon as reply is received |
| -t |  | TTL | Set TTL |
| -I |  | IFACE/IP | Source interface or IP address |
| -W |  | SEC | Seconds to wait for the first response (default 10) (after all -c CNT packets are sent) |
| -w |  | SEC | Seconds until ping exits (default:infinite) (can exit earlier with -c CNT) |
| -q |  |  | Quiet, only display output at start/finish |
| -p |  | HEXBYTE | Payload pattern |

<a id="cmd-ping6"></a>
### ping6

Send ICMP ECHO_REQUESTs to HOST

Risk: unclassified. Source: busybox.

```text
ping6  [OPTIONS] HOST
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  | CNT | Send only CNT pings |
| -s |  | SIZE | Send SIZE data bytes in packets (default 56) |
| -i |  | SECS | Interval |
| -A |  |  | Ping as soon as reply is received |
| -I |  | IFACE/IP | Source interface or IP address |
| -W |  | SEC | Seconds to wait for the first response (default 10) (after all -c CNT packets are sent) |
| -w |  | SEC | Seconds until ping exits (default:infinite) (can exit earlier with -c CNT) |
| -q |  |  | Quiet, only display output at start/finish |
| -p |  | HEXBYTE | Payload pattern |

<a id="cmd-pivot_root"></a>
### pivot_root

Move the current root file system to PUT_OLD and make NEW_ROOT

Risk: unclassified. Source: busybox.

```text
pivot_root  NEW_ROOT PUT_OLD
```


<a id="cmd-poweroff"></a>
### poweroff

Halt and shut off power

Risk: destructive. Source: busybox.

```text
poweroff  [-d DELAY] [-nf]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  | DELAY | Delay interval |
| -n |  |  | Do not sync |
| -f |  |  | Force (don't go through init) |

<a id="cmd-printf"></a>
### printf

Format and print ARG(s) according to FORMAT (a-la C printf)

Risk: unclassified. Source: busybox.

```text
printf  FORMAT [ARG]...
```


<a id="cmd-ps"></a>
### ps

Show list of processes

Risk: unclassified. Source: busybox.

```text
ps  [-o COL1,COL2=HEADER] [-T]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -o |  | COL1,COL2=HEADER | Select columns for display |
| -T |  |  | Show threads |

<a id="cmd-pwd"></a>
### pwd

Print the full filename of the current working directory

Risk: unclassified. Source: busybox.

```text
pwd 
```


<a id="cmd-rdate"></a>
### rdate

Set and print time from HOST using RFC 868

Risk: unclassified. Source: busybox.

```text
rdate  [-s/-p] HOST
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -s |  |  | Only set system time |
| -p |  |  | Only print time |

<a id="cmd-readlink"></a>
### readlink

Display the value of a symlink

Risk: unclassified. Source: busybox.

```text
readlink  [-fnv] FILE
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Canonicalize by following all symlinks |
| -n |  |  | Don't add newline |
| -v |  |  | Verbose |

<a id="cmd-realpath"></a>
### realpath

Print absolute pathnames of FILEs

Risk: unclassified. Source: busybox.

```text
realpath  FILE...
```


<a id="cmd-reboot"></a>
### reboot

Reboot the system

Risk: destructive. Source: busybox.

```text
reboot  [-d DELAY] [-nf]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  | DELAY | Delay interval |
| -n |  |  | Do not sync |
| -f |  |  | Force (don't go through init) |

<a id="cmd-renice"></a>
### renice

Change scheduling priority of a running process

Risk: state-changing. Source: busybox.

```text
renice  [-n] PRIORITY [[-p|g|u] ID...]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n |  |  | Add PRIORITY to current nice value Without -n, nice value is set to PRIORITY |
| -p |  |  | Process ids (default) |
| -g |  |  | Process group ids |
| -u |  |  | Process user names |

<a id="cmd-reset"></a>
### reset

Reset terminal (ESC codes) and termios (signals, buffering, echo)

Risk: unclassified. Source: busybox.

```text
reset 
```


<a id="cmd-resume"></a>
### resume

Restore system state from 'suspend-to-disk' data in BLOCKDEV

Risk: unclassified. Source: busybox.

```text
resume  BLOCKDEV [OFFSET]
```


<a id="cmd-rev"></a>
### rev

Reverse lines of FILE

Risk: unclassified. Source: busybox.

```text
rev  [FILE]...
```


<a id="cmd-rm"></a>
### rm

Remove (unlink) FILEs

Risk: destructive. Source: busybox.

```text
rm  [-irf] FILE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -i |  |  | Always prompt before removing |
| -r |  |  |  |
| -f |  |  | Never prompt |
| -R (-r) |  |  | Recurse |

<a id="cmd-rmdir"></a>
### rmdir

Remove DIRECTORY if it is empty

Risk: destructive. Source: busybox.

```text
rmdir  [-p] DIRECTORY...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -p |  |  | Include parents |
|  | --ignore-fail-on-non-empty |  |  |

<a id="cmd-rmmod"></a>
### rmmod

Unload kernel modules

Risk: state-changing. Source: busybox.

```text
rmmod  [-wfa] [MODULE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -w |  |  | Wait until the module is no longer used |
| -f |  |  | Force unload |
| -a |  |  | Remove all unused modules (recursively) |

<a id="cmd-route"></a>
### route

Show or edit kernel routing tables

Risk: state-changing. Source: busybox.

```text
route  [-ne] [-A inet[6]] [{add|del} [-net|-host] TARGET [netmask MASK] [gw GATEWAY] [metric N] [mss BYTES] [window BYTES] [reject] [IFACE]]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n |  |  | Don't resolve names |
| -e |  |  | Display other/more information |
| -A |  | inet[6] | Select address family |

<a id="cmd-rpm"></a>
### rpm

Manipulate RPM packages

Risk: unclassified. Source: busybox.

```text
rpm  -i PACKAGE.rpm; rpm -qp[ildc] PACKAGE.rpm
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -i |  |  | Install package |
| -q |  |  |  |
| -p |  |  |  |
| -l |  |  |  |
| -d |  |  |  |
| -c |  |  |  |
| -qp |  |  | Query package |
| -qpi |  |  | Show information |
| -qpl |  |  | List contents |
| -qpd |  |  | List documents |
| -qpc |  |  | List config files |

<a id="cmd-rpm2cpio"></a>
### rpm2cpio

Output a cpio archive of the rpm file

Risk: unclassified. Source: busybox.

```text
rpm2cpio  PACKAGE.rpm
```


<a id="cmd-run-init"></a>
### run-init

Free initramfs and switch to another root fs:

Risk: unclassified. Source: busybox.

```text
run-init  [-d CAP,CAP...] [-n] [-c CONSOLE_DEV] NEW_ROOT NEW_INIT [ARGS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  | CAP,CAP... | Drop capabilities |
| -n |  |  | Dry run |
| -c |  | CONSOLE_DEV | Reopen stdio to DEV after switch |

<a id="cmd-run-parts"></a>
### run-parts

Run a bunch of scripts in DIRECTORY

Risk: unclassified. Source: busybox.

```text
run-parts  [-a ARG]... [-u UMASK] [--reverse] [--test] [--exit-on-error] DIRECTORY
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  | ARG | Pass ARG as argument to scripts |
| -u |  | UMASK | Set UMASK before running scripts |
|  | --reverse |  | Reverse execution order |
|  | --test |  | Dry run |
|  | --exit-on-error |  | Exit if a script exits with non-zero |

<a id="cmd-sed"></a>
### sed

or: sed [-i[SFX]] [-nrE] CMD [FILE]...

Risk: state-changing. Source: busybox.

```text
sed  [-i[SFX]] [-nrE] [-f FILE]... [-e CMD]... [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -i |  |  |  |
| -S |  |  |  |
| -F |  |  |  |
| -X |  |  |  |
| -n |  |  | Suppress automatic printing of pattern space |
| -r (-E) |  |  | Use extended regex syntax |
| -E |  |  |  |
| -f |  | FILE | Add FILE contents to sed commands to be executed |
| -e |  | CMD | Add CMD to sed commands to be executed |
| -i[SFX] |  |  | Edit files in-place (otherwise write to stdout) Optionally back files up, appending SFX |

<a id="cmd-seq"></a>
### seq

Print numbers from FIRST to LAST, in steps of INC.

Risk: unclassified. Source: busybox.

```text
seq  [-w] [-s SEP] [FIRST [INC]] LAST
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -w |  |  | Pad to last with leading zeros |
| -s |  | SEP | String separator |

<a id="cmd-setkeycodes"></a>
### setkeycodes

Modify kernel's scancode-to-keycode map,

Risk: unclassified. Source: busybox.

```text
setkeycodes  { SCANCODE KEYCODE }...
```


<a id="cmd-setpriv"></a>
### setpriv

Run PROG with different privilege settings

Risk: unclassified. Source: busybox.

```text
setpriv  [OPTIONS] PROG ARGS
```


<a id="cmd-setsid"></a>
### setsid

Run PROG in a new session. PROG will have no controlling terminal

Risk: state-changing. Source: busybox.

```text
setsid  [-c] PROG ARGS
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Set controlling terminal to stdin |

<a id="cmd-sh"></a>
### sh

Unix shell interpreter

Risk: unclassified. Source: busybox.

```text
sh  [-il] [-|+Cabefmnuvx] [-|+o OPT]... [-c 'SCRIPT' [ARG0 ARGS] | FILE ARGS | -s ARGS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -i |  |  |  |
| -l |  |  |  |
| - |  |  |  |
| -c |  | 'SCRIPT' [ARG0 ARGS] |  |
| -s |  | ARGS |  |

<a id="cmd-sha1sum"></a>
### sha1sum

Print or check SHA1 checksums

Risk: unclassified. Source: busybox.

```text
sha1sum  [-c[sw]] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Check sums against list in FILEs |
| -s |  |  | Don't output anything, status code shows success |
| -w |  |  | Warn about improperly formatted checksum lines |

<a id="cmd-sha256sum"></a>
### sha256sum

Print or check SHA256 checksums

Risk: unclassified. Source: busybox.

```text
sha256sum  [-c[sw]] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Check sums against list in FILEs |
| -s |  |  | Don't output anything, status code shows success |
| -w |  |  | Warn about improperly formatted checksum lines |

<a id="cmd-sha3sum"></a>
### sha3sum

Print or check SHA3 checksums

Risk: unclassified. Source: busybox.

```text
sha3sum  [-c[sw]] [-a BITS] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Check sums against list in FILEs |
| -s |  |  | Don't output anything, status code shows success |
| -w |  |  | Warn about improperly formatted checksum lines |
| -a |  | BITS | 224 (default), 256, 384, 512 |

<a id="cmd-sha512sum"></a>
### sha512sum

Print or check SHA512 checksums

Risk: unclassified. Source: busybox.

```text
sha512sum  [-c[sw]] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Check sums against list in FILEs |
| -s |  |  | Don't output anything, status code shows success |
| -w |  |  | Warn about improperly formatted checksum lines |

<a id="cmd-shred"></a>
### shred

Overwrite/delete FILEs

Risk: destructive. Source: busybox.

```text
shred  [-fuz] [-n N] [-s SIZE] FILE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Chmod to ensure writability |
| -u |  |  | Remove file |
| -z |  |  | Final overwrite with zeros |
| -n |  | N | Overwrite N times (default 3) |
| -s |  | SIZE | Size to write |

<a id="cmd-shuf"></a>
### shuf

Randomly permute lines

Risk: unclassified. Source: busybox.

```text
shuf  [-n NUM] [-o FILE] [-z] [FILE | -e [ARG...] | -i L-H]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n |  | NUM | Output at most NUM lines |
| -o |  | FILE | Write to FILE, not standard output |
| -z |  |  | NUL terminated output |
| -e |  |  | Treat ARGs as lines |
| -i |  | L-H | Treat numbers L-H as lines |

<a id="cmd-sleep"></a>
### sleep

Pause for a time equal to the total of the args given, where each arg can

Risk: unclassified. Source: busybox.

```text
sleep  [N]...
```


<a id="cmd-sort"></a>
### sort

Sort lines of text

Risk: unclassified. Source: busybox.

```text
sort  [-nrughMcszbdfiokt] [-o FILE] [-k START[.OFS][OPTS][,END[.OFS][OPTS]] [-t CHAR] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n |  |  | Sort numbers |
| -r |  |  | Reverse sort order |
| -u |  |  | Suppress duplicate lines |
| -g |  |  | General numerical sort |
| -h |  |  | Sort human readable numbers (2K 1G) |
| -M |  |  | Sort month |
| -c |  |  | Check whether input is sorted |
| -s |  |  | Stable (don't sort ties alphabetically) |
| -z |  |  | NUL terminated input and output |
| -b |  |  | Ignore leading blanks |
| -d |  |  | Dictionary order (blank or alphanumeric only) |
| -f |  |  | Ignore case |
| -i |  |  | Ignore unprintable characters |
| -o |  | FILE | Output to FILE |
| -k |  | START[.OFS][OPTS][,END[.OFS][OPTS]] [-t CHAR] [FILE]... |  |
| -t |  | CHAR | Field separator |
| -V |  |  | Sort version |

<a id="cmd-ssl_client"></a>
### ssl_client

Risk: unclassified. Source: busybox.

```text
ssl_client  [-e] -s FD [-r FD] [-n SNI]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -e |  |  |  |
| -s |  |  |  |
| -r |  | FD |  |
| -n |  | SNI |  |

<a id="cmd-start-stop-daemon"></a>
### start-stop-daemon

Search for matching processes, and then

Risk: unclassified. Source: busybox.

```text
start-stop-daemon  [OPTIONS] [-S|-K] ... [-- ARGS...]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -S |  |  |  |
| -K |  |  |  |
|  | -- | ARGS... |  |
| -u |  | USERNAME\|UID | Match only this user's processes |
| -n |  | NAME | Match processes with NAME in comm field in /proc/PID/stat |
| -x |  | EXECUTABLE | Match processes with this command in /proc/PID/cmdline; Program to run |
| -p |  | FILE | Match a process with PID from FILE All specified conditions must match |
| -a |  | NAME | Zeroth argument |
| -b |  |  | Background |
| -N |  | N | Change nice level |
| -c |  | USER[:[GRP]] | Change user/group |
| -m |  |  | Write PID to pidfile specified by -p |
| -s |  | SIG | Signal to send |
| -t |  |  | Match only, exit with 0 if found |
| -o |  |  | Exit with status 0 if nothing is done |
| -v |  |  | Verbose |
| -q |  |  | Quiet |

<a id="cmd-stat"></a>
### stat

Display file (default) or filesystem status

Risk: unclassified. Source: busybox.

```text
stat  [-ltf] [-c FMT] FILE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -l |  |  |  |
| -t |  |  | Terse display |
| -f |  |  | Display filesystem status |
| -c |  | FMT | Use the specified format |
| -L |  |  | Follow links |

<a id="cmd-strings"></a>
### strings

Display printable strings in a binary file

Risk: unclassified. Source: busybox.

```text
strings  [-fo] [-t o|d|x] [-n LEN] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Precede strings with filenames |
| -o |  |  | Precede strings with octal offsets |
| -t |  | o | Precede strings with offsets in base 8/10/16 |
| -n |  | LEN | At least LEN characters form a string (default 4) |

<a id="cmd-stty"></a>
### stty

Without arguments, prints baud rate, line discipline,

Risk: unclassified. Source: busybox.

```text
stty  [-a|g] [-F DEVICE] [SETTING]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Print all current settings in human-readable form |
| -F |  | DEVICE | Open device instead of stdin |
| -g |  |  | Print in stty-readable form [SETTING]	See manpage |

<a id="cmd-su"></a>
### su

Run shell under USER (by default, root)

Risk: unclassified. Source: busybox.

```text
su  [-lmp] [-s SH] [-] [USER [FILE ARGS | -c 'CMD' [ARG0 ARGS]]]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -l |  |  |  |
| -m |  |  |  |
| -p (-m) |  |  | Do not set new $HOME, $SHELL, $USER, $LOGNAME |
| -s |  | SH | Shell to use instead of user's default |
| - (-l) |  |  | Clear environment, go to home dir, run shell as login shell |
| -c |  | CMD | Command to pass to 'sh -c' |

<a id="cmd-sulogin"></a>
### sulogin

Single user login

Risk: unclassified. Source: busybox.

```text
sulogin  [-t N] [TTY]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -t |  | N | Timeout |
| -p |  |  | Start a login shell |

<a id="cmd-svc"></a>
### svc

Control services monitored by runsv supervisor

Risk: unclassified. Source: busybox.

```text
svc  [-udopchaitkx] SERVICE_DIR...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -u |  |  | If service is not running, start it; restart if it stops |
| -d |  |  | If service is running, send TERM+CONT signals; do not restart it |
| -o |  |  | Once: if service is not running, start it; do not restart it |
| -p |  |  |  |
| -c |  |  |  |
| -h |  |  |  |
| -a |  |  |  |
| -i |  |  |  |
| -t |  |  |  |
| -k |  |  |  |
| -x |  |  | Exit: runsv will exit as soon as the service is down |
| -pchaitk |  | Send STOP CONT HUP ALRM INT TERM KILL signal to service |  |

<a id="cmd-svok"></a>
### svok

Check whether runsv supervisor is running.

Risk: unclassified. Source: busybox.

```text
svok  SERVICE_DIR
```


<a id="cmd-swapoff"></a>
### swapoff

Stop swapping on DEVICE

Risk: state-changing. Source: busybox.

```text
swapoff  [-a] [DEVICE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Stop swapping on all swap devices |

<a id="cmd-swapon"></a>
### swapon

Start swapping on DEVICE

Risk: state-changing. Source: busybox.

```text
swapon  [-a] [-e] [-d[POL]] [DEVICE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Start swapping on all swap devices |
| -e |  |  | Silently skip devices that do not exist |
| -d |  |  |  |
| -P |  |  |  |
| -O |  |  |  |
| -L |  |  |  |
| -d[POL] |  |  | Discard blocks at swapon (POL=once), as freed (POL=pages), or both (POL omitted) |

<a id="cmd-switch_root"></a>
### switch_root

Free initramfs and switch to another root fs:

Risk: unclassified. Source: busybox.

```text
switch_root  [-c CONSOLE_DEV] NEW_ROOT NEW_INIT [ARGS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  | CONSOLE_DEV | Reopen stdio to DEV after switch |

<a id="cmd-sync"></a>
### sync

Write all buffered blocks (in FILEs) to disk

Risk: unclassified. Source: busybox.

```text
sync  [-df] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  |  | Avoid syncing metadata |
| -f |  |  | Sync filesystems underlying FILEs |

<a id="cmd-sysctl"></a>
### sysctl

Show/set kernel parameters

Risk: state-changing. Source: busybox.

```text
sysctl  [-enq] { -a | -p [FILE]... | [-w] [KEY[=VALUE]]... }
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -e |  |  | Don't warn about unknown keys |
| -n |  |  | Don't show key names |
| -q |  |  | Quiet |
| -a |  |  | Show all values |
| -p |  |  | Set values from FILEs (default /etc/sysctl.conf) |
| -w |  |  | Set values |

<a id="cmd-syslogd"></a>
### syslogd

System logging utility

Risk: unclassified. Source: busybox.

```text
syslogd  [OPTIONS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n |  |  | Run in foreground |
| -R |  | HOST[:PORT] | Log to HOST:PORT (default PORT:514) |
| -L |  |  | Log locally and via network (default is network only if -R) |
| -C[size_kb] |  |  | Log to shared mem buffer (use logread to read it) |
| -O |  | FILE | Log to FILE (default: /var/log/messages, stdout if -) |
| -s |  | SIZE | Max size (KB) before rotation (default 200KB, 0=off) |
| -b |  | N | N rotated logs to keep (default 1, max 99, 0=purge) |
| -l |  | N | Log only messages more urgent than prio N (1-8) |
| -S |  |  | Smaller output |
| -t |  |  | Strip client-generated timestamps |
| -D |  |  | Drop duplicates |
| -f |  | FILE | Use FILE as config (default:/etc/syslog.conf) |

<a id="cmd-tac"></a>
### tac

Concatenate FILEs and print them in reverse

Risk: unclassified. Source: busybox.

```text
tac  [FILE]...
```


<a id="cmd-tail"></a>
### tail

Print last 10 lines of FILEs (or stdin) to.

Risk: unclassified. Source: busybox.

```text
tail  [OPTIONS] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  | [+] | Print last N bytes |
| -n |  | N[bkm] | Print last N lines; Start on Nth line and print the rest (b:*512 k:*1024 m:*1024^2) |
| -q |  |  | Never print headers |
| -v |  |  | Always print headers |
| -f |  |  | Print data as file grows |
| -F |  |  | Same as -f, but keep retrying |
| -s |  | SECONDS | Wait SECONDS between reads with -f |

<a id="cmd-tar"></a>
### tar

Create, extract, or list files from a tar file

Risk: unclassified. Source: busybox.

```text
tar  c|x|t [-ZzJjahmvokO] [-f TARFILE] [-C DIR] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -Z |  |  | (De)compress using compress |
| -z |  |  | (De)compress using gzip |
| -J |  |  | (De)compress using xz |
| -j |  |  | (De)compress using bzip2 |
| -a |  |  | (De)compress based on extension |
| -h |  |  | Follow symlinks |
| -m |  |  | Don't restore mtime |
| -v |  |  | Verbose |
| -o |  |  | Don't restore user:group |
| -k |  |  | Don't replace existing files |
| -O |  |  | Extract to stdout |
| -f |  | TARFILE | Name of TARFILE ('-' for stdin/out) |
| -C |  | DIR | Change to DIR before operation |
|  | --lzma |  | (De)compress using lzma |
|  | --overwrite |  | Replace existing files |
|  | --strip-components | NUM | NUM of leading components to strip |
|  | --no-recursion |  | Don't descend in directories |
|  | --numeric-owner |  | Use numeric user:group |
|  | --no-same-permissions |  | Don't restore access permissions |
|  | --to-command | COMMAND | Pipe files to COMMAND |

<a id="cmd-taskset"></a>
### taskset

Set or get CPU affinity

Risk: unclassified. Source: busybox.

```text
taskset  [-ap] [HEXMASK | -c LIST] { PID | PROG ARGS }
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Operate on all threads |
| -p |  |  | Operate on PID |
| -c |  |  | Affinity is a list, not mask |

<a id="cmd-tc"></a>
### tc

OBJECT: qdisc|class|filter

Risk: state-changing. Source: busybox.

```text
tc  OBJECT CMD [dev STRING]
```


<a id="cmd-tee"></a>
### tee

Copy stdin to each FILE, and also to stdout

Risk: state-changing. Source: busybox.

```text
tee  [-ai] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Append to the given FILEs, don't overwrite |
| -i |  |  | Ignore interrupt signals (SIGINT) |

<a id="cmd-telnet"></a>
### telnet

Connect to telnet server

Risk: unclassified. Source: busybox.

```text
telnet  [-a] [-l USER] HOST [PORT]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Automatic login with $USER variable |
| -l |  | USER | Automatic login as USER |

<a id="cmd-telnetd"></a>
### telnetd

Handle incoming telnet connections

Risk: unclassified. Source: busybox.

```text
telnetd  [OPTIONS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -l |  | LOGIN | Exec LOGIN on connect |
| -f |  | ISSUE_FILE | Display ISSUE_FILE instead of /etc/issue |
| -K |  |  | Close connection as soon as login exits (normally wait until all programs close slave pty) |
| -p |  | PORT | Port to listen on. Default 23 |
| -b |  | ADDR[:PORT] | Address to bind to |
| -F |  |  | Run in foreground |
| -i |  |  | Inetd mode |

<a id="cmd-tftp"></a>
### tftp

Transfer a file from/to tftp server

Risk: unclassified. Source: busybox.

```text
tftp  [OPTIONS] HOST [PORT]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -l |  | FILE | Local FILE |
| -r |  | FILE | Remote FILE |
| -g |  |  | Get file |
| -p |  |  | Put file |
| -b |  | SIZE | Transfer blocks in bytes |

<a id="cmd-time"></a>
### time

Run PROG, display resource usage when it exits

Risk: unclassified. Source: busybox.

```text
time  [-vpa] [-o FILE] PROG ARGS
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -v |  |  | Verbose |
| -p |  |  | POSIX output format |
| -a |  |  | Append (else overwrite) |
| -o |  | FILE | Write result to FILE |
| -f |  | FMT | Custom format |

<a id="cmd-timeout"></a>
### timeout

Run PROG. Send SIG to it if it is not gone in SECS seconds.

Risk: unclassified. Source: busybox.

```text
timeout  [-s SIG] [-k KILL_SECS] SECS PROG ARGS
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -s |  | SIG |  |
| -k |  | KILL_SECS |  |

<a id="cmd-top"></a>
### top

Show a view of process activity in real time.

Risk: unclassified. Source: busybox.

```text
top  [-bH] [-n COUNT] [-d SECONDS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -b |  |  | Batch mode |
| -H |  |  | Show threads |
| -n |  | COUNT | Exit after N iterations |
| -d |  | SECONDS | Delay between updates |

<a id="cmd-touch"></a>
### touch

Update mtime of FILEs

Risk: state-changing. Source: busybox.

```text
touch  [-cham] [-d DATE] [-t DATE] [-r FILE] FILE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Don't create files |
| -h |  |  | Don't follow links |
| -a |  |  | Change only atime |
| -m |  |  | Change only mtime |
| -d |  | DATE | Date/time to use |
| -t |  | DATE | Date/time to use |
| -r |  | FILE | Use FILE's date/time |

<a id="cmd-tr"></a>
### tr

Translate, squeeze, or delete characters from stdin, writing to stdout

Risk: unclassified. Source: busybox.

```text
tr  [-cds] STRING1 [STRING2]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Take complement of STRING1 |
| -d |  |  | Delete input characters coded STRING1 |
| -s |  |  | Squeeze multiple output characters of STRING2 into one character |

<a id="cmd-traceroute"></a>
### traceroute

Trace the route to HOST

Risk: unclassified. Source: busybox.

```text
traceroute  [-46Flnrv] [-f 1ST_TTL] [-m MAXTTL] [-q PROBES] [-p PORT] [-t TOS] [-w WAIT_SEC] [-s SRC_IP] [-i IFACE] [-z PAUSE_MSEC] HOST [BYTES]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -4 (-6) |  |  | Force IP or IPv6 name resolution |
| -6 |  |  |  |
| -F |  |  | Set don't fragment bit |
| -l |  |  | Display TTL value of the returned packet |
| -n |  |  | Print numeric addresses |
| -r |  |  | Bypass routing tables, send directly to HOST |
| -v |  |  | Verbose |
| -f |  | 1ST_TTL | First number of hops (default 1) |
| -m |  | MAXTTL | Max number of hops |
| -q |  | PROBES | Number of probes per hop (default 3) |
| -p |  | PORT | Base UDP port number used in probes (default 33434) |
| -t |  | TOS | Type-of-service in probe packets (default 0) |
| -w |  | WAIT_SEC | Wait for a response (default 3) |
| -s |  | SRC_IP | Source address |
| -i |  | IFACE |  |
| -z |  | PAUSE_MSEC | Wait before each send |

<a id="cmd-traceroute6"></a>
### traceroute6

Trace the route to HOST

Risk: unclassified. Source: busybox.

```text
traceroute6  [-nrv] [-f 1ST_TTL] [-m MAXTTL] [-q PROBES] [-p PORT] [-t TOS] [-w WAIT_SEC] [-s SRC_IP] [-i IFACE] [-z PAUSE_MSEC] HOST [BYTES]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n |  |  | Print numeric addresses |
| -r |  |  | Bypass routing tables, send directly to HOST |
| -v |  |  | Verbose |
| -f |  | 1ST_TTL | First number of hops (default 1) |
| -m |  | MAXTTL | Max number of hops |
| -q |  | PROBES | Number of probes per hop (default 3) |
| -p |  | PORT | Base UDP port number used in probes (default 33434) |
| -t |  | TOS | Type-of-service in probe packets (default 0) |
| -w |  | WAIT_SEC | Wait for a response (default 3) |
| -s |  | SRC_IP | Source address |
| -i |  | IFACE |  |
| -z |  | PAUSE_MSEC | Wait before each send |

<a id="cmd-truncate"></a>
### truncate

Truncate FILEs to SIZE

Risk: destructive. Source: busybox.

```text
truncate  [-c] -s SIZE FILE...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Do not create files |
| -s |  | SIZE |  |

<a id="cmd-ts"></a>
### ts

Pipe stdin to stdout, add timestamp to each line

Risk: unclassified. Source: busybox.

```text
ts  [-is] [STRFTIME]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -i |  |  | Time since previous line |
| -s |  |  | Time since start |

<a id="cmd-tty"></a>
### tty

Print file name of stdin's terminal

Risk: unclassified. Source: busybox.

```text
tty  [-s]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -s |  |  | Print nothing, only return exit status |

<a id="cmd-tunctl"></a>
### tunctl

Create or delete TUN/TAP interfaces

Risk: unclassified. Source: busybox.

```text
tunctl  [-f DEVICE] [-t NAME | -d NAME]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  | DEVICE | TUN device (default /dev/net/tun) |
| -t |  | NAME | Create iface (default: tapN) |
| -d |  | NAME | Delete iface |

<a id="cmd-ubirename"></a>
### ubirename

Rename UBI volumes on UBI_DEVICE

Risk: unclassified. Source: busybox.

```text
ubirename  UBI_DEVICE OLD_VOLNAME NEW_VOLNAME [OLD2 NEW2]...
```


<a id="cmd-udhcpc"></a>
### udhcpc

Signals:

Risk: state-changing. Source: busybox.

```text
udhcpc  [-fbqRB] [-a[MSEC]] [-t N] [-T SEC] [-A SEC|-n] [-i IFACE] [-s PROG] [-p PIDFILE] [-oC] [-r IP] [-V VENDOR] [-F NAME] [-x OPT:VAL]... [-O OPT]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Run in foreground |
| -b |  |  | Background if lease is not obtained |
| -q |  |  | Exit after obtaining lease |
| -R |  |  | Release IP on exit |
| -B |  |  | Request broadcast replies |
| -a |  |  |  |
| -M |  |  |  |
| -S |  |  | Log to syslog too |
| -E |  |  |  |
| -C |  |  | Don't send MAC as client identifier |
| -t |  | N | Send up to N discover packets (default 3) |
| -T |  | SEC | Pause between packets (default 3) |
| -A |  | SEC | Wait if lease is not obtained (default 20) |
| -n |  |  | Exit if lease is not obtained |
| -i |  | IFACE | Interface to use (default eth0) |
| -s |  | PROG | Run PROG at DHCP events (default /etc/udhcpc/default.script) |
| -p |  | PIDFILE | Create pidfile |
| -o |  |  | Don't request any options (unless -O is given) |
| -r |  | IP | Request this IP address |
| -V |  | VENDOR | Vendor identifier (default 'udhcp VERSION') |
| -F |  | NAME | Ask server to update DNS mapping for NAME |
| -x (-) |  | OPT:VAL | Include option OPT in sent packets (cumulative) Examples of string, numeric, and hex byte opts: |
| -O |  | OPT | Request option OPT from server (cumulative) |
| -a[MSEC] |  |  | Validate offered address with ARP ping |

<a id="cmd-udhcpc6"></a>
### udhcpc6

Signals:

Risk: unclassified. Source: busybox.

```text
udhcpc6  [-fbqR] [-t N] [-T SEC] [-A SEC|-n] [-i IFACE] [-s PROG] [-p PIDFILE] [-ldo] [-r IPv6] [-x OPT:VAL]... [-O OPT]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Run in foreground |
| -b |  |  | Background if lease is not obtained |
| -q |  |  | Exit after obtaining lease |
| -R |  |  | Release IP on exit |
| -t |  | N | Send up to N discover packets |
| -T |  | SEC | Pause between packets (default 3) |
| -A |  | SEC | Wait if lease is not obtained (default 20) |
| -n |  |  | Exit if lease is not obtained |
| -i |  | IFACE | Interface to use (default eth0) |
| -s |  | PROG | Run PROG at DHCP events (default /etc/udhcpc/default6.script) |
| -p |  | PIDFILE | Create pidfile |
| -l |  |  | Send 'information request' instead of 'solicit' (used for servers which do not assign IPv6 addresses) |
| -d |  |  | Request prefix |
| -o |  |  | Don't request any options (unless -O is given) |
| -r |  | IPv6 | Request this address ('no' to not request any IP) |
| -x (-) |  | OPT:VAL | Include option OPT in sent packets (cumulative) Examples of string, numeric, and hex byte opts: |
| -O |  | OPT | Request option OPT from server (cumulative) |
| -B |  |  | Request broadcast replies |
| -S |  |  | Log to syslog too |

<a id="cmd-udhcpd"></a>
### udhcpd

DHCP server

Risk: state-changing. Source: busybox.

```text
udhcpd  [-fS] [-I ADDR] [-a MSEC] [CONFFILE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Run in foreground |
| -S |  |  | Log to syslog too |
| -I |  | ADDR | Local address |
| -a |  | MSEC | Timeout for ARP ping (default 2000) |

<a id="cmd-uevent"></a>
### uevent

PROG's environment contains data passed from the kernel.

Risk: unclassified. Source: busybox.

```text
uevent  [PROG ARGS]
uevent runs PROG for every netlink notification.
```


<a id="cmd-umount"></a>
### umount

Unmount filesystems

Risk: state-changing. Source: busybox.

```text
umount  [-rlfda] [-t FSTYPE] FILESYSTEM|DIRECTORY
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -r |  |  | Remount devices read-only if mount is busy |
| -l |  |  | Lazy umount (detach filesystem) |
| -f |  |  | Force umount (i.e., unreachable NFS server) |
| -d |  |  | Free loop device if it has been used |
| -a |  |  | Unmount all filesystems |
| -t |  | FSTYPE | Unmount only these filesystem type(s) |

<a id="cmd-uname"></a>
### uname

Print system information

Risk: unclassified. Source: busybox.

```text
uname  [-amnrspvio]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Print all |
| -m |  |  | Machine (hardware) type |
| -n |  |  | Hostname |
| -r |  |  | Kernel release |
| -s |  |  | Kernel name (default) |
| -p |  |  | Processor type |
| -v |  |  | Kernel version |
| -i |  |  | Hardware platform |
| -o |  |  | OS name |

<a id="cmd-uncompress"></a>
### uncompress

Decompress FILEs (or stdin)

Risk: unclassified. Source: busybox.

```text
uncompress  [-cf] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Write to stdout |
| -f |  |  | Overwrite |

<a id="cmd-unexpand"></a>
### unexpand

Convert spaces to tabs, writing to stdout

Risk: unclassified. Source: busybox.

```text
unexpand  [-fa][-t N] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -f |  |  | Convert only leading blanks |
| -a |  |  | Convert all blanks |
| -t |  | N | Tabstops every N chars |

<a id="cmd-uniq"></a>
### uniq

Discard duplicate lines

Risk: unclassified. Source: busybox.

```text
uniq  [-cduiz] [-f,s,w N] [FILE [OUTFILE]]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Prefix lines by the number of occurrences |
| -d |  |  | Only print duplicate lines |
| -u |  |  | Only print unique lines |
| -i |  |  | Ignore case |
| -z |  |  | NUL terminated output |
| -f,s,w |  | N |  |
| -f |  | N | Skip first N fields |
| -s |  | N | Skip first N chars (after any skipped fields) |
| -w |  | N | Compare N characters in line |

<a id="cmd-unix2dos"></a>
### unix2dos

Convert FILE in-place from Unix to DOS format.

Risk: unclassified. Source: busybox.

```text
unix2dos  [-ud] [FILE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -u |  |  | dos2unix |
| -d |  |  | unix2dos |

<a id="cmd-unlink"></a>
### unlink

Delete FILE by calling unlink()

Risk: unclassified. Source: busybox.

```text
unlink  FILE
```


<a id="cmd-unlzma"></a>
### unlzma

Decompress FILEs (or stdin)

Risk: unclassified. Source: busybox.

```text
unlzma  [-cfk] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Write to stdout |
| -f |  |  | Force |
| -k |  |  | Keep input files |
| -t |  |  | Test integrity |

<a id="cmd-unshare"></a>
### unshare

Risk: unclassified. Source: busybox.

```text
unshare  [OPTIONS] [PROG ARGS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -m | --mount | [FILE] | Unshare mount namespace |
| -u | --uts | [FILE] | Unshare UTS namespace (hostname etc.) |
| -i | --ipc | [FILE] | Unshare System V IPC namespace |
| -n | --net | [FILE] | Unshare network namespace |
| -p | --pid | [FILE] | Unshare PID namespace |
| -U | --user | [FILE] | Unshare user namespace |
| -f |  |  | Fork before execing PROG |
| -r |  |  | Map current user to root (implies -U) |
|  | --mount-proc | [DIR] | Mount /proc filesystem first (implies -m) |
|  | --propagation | slave\|shared\|private\|unchanged | Modify mount propagation in mount namespace |
|  | --setgroups | allow\|deny | Control the setgroups syscall in user namespaces |

<a id="cmd-unxz"></a>
### unxz

Decompress FILEs (or stdin)

Risk: unclassified. Source: busybox.

```text
unxz  [-cfk] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Write to stdout |
| -f |  |  | Force |
| -k |  |  | Keep input files |
| -t |  |  | Test integrity |

<a id="cmd-unzip"></a>
### unzip

Extract FILEs from ZIP archive

Risk: unclassified. Source: busybox.

```text
unzip  [-lnojpqK] FILE[.zip] [FILE]... [-x FILE]... [-d DIR]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -l |  |  | List contents (with -q for short form) |
| -n |  |  | Never overwrite files (default: ask) |
| -o |  |  | Overwrite |
| -j |  |  | Do not restore paths |
| -p |  |  | Write to stdout |
| -q |  |  | Quiet |
| -K |  |  | Do not clear SUID bit |
| -x |  | FILE | Exclude FILEs |
| -d |  | DIR | Extract into DIR |
| -t |  |  | Test |

<a id="cmd-uptime"></a>
### uptime

Display the time since the last boot

Risk: unclassified. Source: busybox.

```text
uptime 
```


<a id="cmd-usleep"></a>
### usleep

Pause for N microseconds

Risk: unclassified. Source: busybox.

```text
usleep  N
```


<a id="cmd-uudecode"></a>
### uudecode

Uudecode a file

Risk: unclassified. Source: busybox.

```text
uudecode  [-o OUTFILE] [INFILE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -o |  | OUTFILE |  |

<a id="cmd-uuencode"></a>
### uuencode

Uuencode FILE (or stdin) to stdout

Risk: unclassified. Source: busybox.

```text
uuencode  [-m] [FILE] STORED_FILENAME
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -m |  |  | Use base64 encoding per RFC1521 |

<a id="cmd-vconfig"></a>
### vconfig

Create and remove virtual ethernet devices

Risk: state-changing. Source: busybox.

```text
vconfig  COMMAND [OPTIONS]
```


<a id="cmd-vi"></a>
### vi

Edit FILE

Risk: unclassified. Source: busybox.

```text
vi  [-c CMD] [-R] [-H] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  | CMD | Initial command to run ($EXINIT and ~/.exrc also available) |
| -R |  |  | Read-only |
| -H |  |  | List available features |

<a id="cmd-w"></a>
### w

Show who is logged on

Risk: unclassified. Source: busybox.

```text
w 
```


<a id="cmd-watch"></a>
### watch

Run PROG periodically

Risk: unclassified. Source: busybox.

```text
watch  [-n SEC] [-t] PROG ARGS
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -n |  | SEC | Period (default 2) |
| -t |  |  | Don't print header |

<a id="cmd-watchdog"></a>
### watchdog

Periodically write to watchdog device DEV

Risk: unclassified. Source: busybox.

```text
watchdog  [-t N[ms]] [-T N[ms]] [-F] DEV
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -t |  | N[ms] | Reset every N seconds (default 30) |
| -T |  | N[ms] | Reboot after N seconds if not reset (default 60) |
| -F |  |  | Run in foreground |

<a id="cmd-wc"></a>
### wc

Count lines, words, and bytes for FILEs (or stdin)

Risk: unclassified. Source: busybox.

```text
wc  [-cmlwL] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Count bytes |
| -m |  |  | Count characters |
| -l |  |  | Count newlines |
| -w |  |  | Count words |
| -L |  |  | Print longest line length |

<a id="cmd-wget"></a>
### wget

Retrieve files via HTTP or FTP

Risk: unclassified. Source: busybox.

```text
wget  [-cqS] [--spider] [-O FILE] [-o LOGFILE] [--header STR] [--post-data STR | --post-file FILE] [-Y on/off] [--no-check-certificate] [-P DIR] [-U AGENT] [-T SEC] URL...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -c |  |  | Continue retrieval of aborted transfer |
| -q |  |  | Quiet |
| -S |  |  | Show server response |
|  | --spider |  | Only check URL existence: $? is 0 if exists |
| -O |  | FILE | Save to FILE ('-' for stdout) |
| -o |  | LOGFILE | Log messages to FILE |
|  | --header | STR | Add STR (of form 'header: value') to headers |
|  | --post-data | STR | Send STR using POST method |
|  | --post-file | FILE | Send FILE using POST method |
| -Y |  | on/off | Use proxy |
|  | --no-check-certificate |  | Don't validate the server's certificate |
| -P |  | DIR | Save to DIR (default .) |
| -U |  | AGENT | Use STR for User-Agent header |
| -T |  | SEC | Network read timeout is SEC seconds |

<a id="cmd-which"></a>
### which

Locate COMMAND

Risk: unclassified. Source: busybox.

```text
which  [-a] COMMAND...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Show all matches |

<a id="cmd-who"></a>
### who

Show who is logged on

Risk: unclassified. Source: busybox.

```text
who  [-aH]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -a |  |  | Show all |
| -H |  |  | Print column headers |

<a id="cmd-whoami"></a>
### whoami

Print the user name associated with the current effective user id

Risk: unclassified. Source: busybox.

```text
whoami 
```


<a id="cmd-xargs"></a>
### xargs

Run PROG on every item given by stdin

Risk: unclassified. Source: busybox.

```text
xargs  [OPTIONS] [PROG ARGS]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -0 |  |  | NUL terminated input |
| -a |  | FILE | Read from FILE instead of stdin |
| -o |  |  | Reopen stdin as /dev/tty |
| -r |  |  | Don't run command if input is empty |
| -t |  |  | Print the command on stderr before execution |
| -p |  |  | Ask user whether to run each command |
| -E (-e[STR]) |  | STR | STR stops input processing |
| -I |  | STR | Replace STR within PROG ARGS with input line |
| -n |  | N | Pass no more than N args to PROG |
| -s |  | N | Pass command line of no more than N bytes |
| -P |  | N | Run up to N PROGs in parallel |
| -x |  |  | Exit if size is exceeded |

<a id="cmd-xxd"></a>
### xxd

Hex dump FILE (or stdin)

Risk: unclassified. Source: busybox.

```text
xxd  [-pri] [-g N] [-c N] [-l LEN] [-s OFS] [-o OFS] [FILE]
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -p |  |  | Show only hex bytes, assumes -c30 |
| -r |  |  | Reverse (with -p, assumes no offsets in input) |
| -i |  |  | C include file style |
| -g |  | N | Bytes per group |
| -c |  | N | Bytes per line |
| -l |  | LEN | Show only first LENGTH bytes |
| -s |  | OFS | Skip OFFSET bytes |
| -o |  | OFS | Add OFFSET to displayed offset |

<a id="cmd-xz"></a>
### xz

Decompress FILEs (or stdin)

Risk: unclassified. Source: busybox.

```text
xz  -d [-cfk] [FILE]...
```

| Option | Long | Argument | Description |
| --- | --- | --- | --- |
| -d |  |  | Decompress |
| -c |  |  | Write to stdout |
| -f |  |  | Force |
| -k |  |  | Keep input files |
| -t |  |  | Test integrity |

<a id="cmd-xzcat"></a>
### xzcat

Decompress to stdout

Risk: unclassified. Source: busybox.

```text
xzcat  [FILE]...
```


<a id="cmd-yes"></a>
### yes

Repeatedly print a line with STRING, or 'y'

Risk: unclassified. Source: busybox.

```text
yes  [STRING]
```


<a id="cmd-zcat"></a>
### zcat

Decompress to stdout

Risk: unclassified. Source: busybox.

```text
zcat  [FILE]...
```

