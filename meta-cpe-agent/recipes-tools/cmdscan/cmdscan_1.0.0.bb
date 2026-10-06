SUMMARY = "cmdscan - discover the commands, options and arguments of a command namespace"
DESCRIPTION = "Lists the applets of BusyBox or Toybox, the executables in a set of \
directories, or a custom command set, and parses each command's help into usage, \
options and arguments. Tags commands by risk to seed the CPE Agent Safety Gate. \
Writes JSON, JSON Lines and Markdown. Intended for lab and debug images."
SECTION = "devel"

# Proprietary by default; see toolcal_1.0.0.bb for switching to Apache-2.0.
LICENSE = "CLOSED"

SRC_URI = "file://cmdscan/"
S = "${WORKDIR}/cmdscan"
# Yocto 5.1 (styhead) and later:  S = "${UNPACKDIR}/cmdscan"

DEPENDS = "cjson"
EXTRA_OEMAKE = "'CC=${CC}' CJSON=system"

do_compile() {
    oe_runmake cmdscan
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/cmdscan ${D}${bindir}/cmdscan

    install -d ${D}${datadir}/cmdscan
    install -m 0644 ${S}/examples/cmdscan.example.json ${D}${datadir}/cmdscan/
    install -m 0644 ${S}/README.md                     ${D}${datadir}/cmdscan/
}

FILES:${PN} += "${datadir}/cmdscan"

# The BusyBox provider needs the busybox binary at run time; it is normally
# already in every RDK-B image as the base-utils provider.
RDEPENDS:${PN} = "${VIRTUAL-RUNTIME_base-utils}"
