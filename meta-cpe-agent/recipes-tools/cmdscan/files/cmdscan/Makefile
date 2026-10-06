# cmdscan - command namespace discovery
#
#   make                      build with the vendored cJSON (third_party/cjson)
#   make CJSON=system         link the platform cJSON (-lcjson), e.g. inside an RDK-B build
#   make CC=<cross-gcc>       cross-compile for the target
#
CC      ?= gcc
CFLAGS  ?= -O2 -Wall -Wextra
CJSON   ?= vendored

ifeq ($(CJSON),system)
  CPPFLAGS += -DCJSON_SYSTEM
  LDLIBS   += -lcjson
  SRCS      = src/cmdscan.c
else
  CPPFLAGS += -Ithird_party/cjson
  SRCS      = src/cmdscan.c third_party/cjson/cJSON.c
endif
LDLIBS += -lm

PREFIX ?= /usr

all: cmdscan

cmdscan: $(SRCS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(SRCS) $(LDFLAGS) $(LDLIBS)

install: cmdscan
	install -d $(DESTDIR)$(PREFIX)/bin $(DESTDIR)$(PREFIX)/share/cmdscan
	install -m 0755 cmdscan $(DESTDIR)$(PREFIX)/bin/cmdscan
	install -m 0644 examples/cmdscan.example.json $(DESTDIR)$(PREFIX)/share/cmdscan/

clean:
	rm -f cmdscan

.PHONY: all install clean
