# This file was generated by `gxv++' from `Cidd_snap.G'.

# If OPENWINHOME is set, then use that location to
# search for the include files and library files. If
# it is not set, then use /usr/openwin.

PROGRAM = Cidd_snap
SOURCES.cc =
SOURCES.h =
SOURCES.c = 
SOURCES.G = Cidd_snap.G
STUBS.G = Cidd_snap.G

# Derived parameters.

SOURCES = \
	$(SOURCES.G) \
	$(SOURCES.l) \
	$(SOURCES.y) \
	$(SOURCES.cps) \
	$(SOURCES.c) \
	$(SOURCES.h) \
	$(SOURCES.cc)

TARGETS.cc = \
	$(SOURCES.G:%.G=%_ui.cc) \
	$(STUBS.G:%.G=%_stubs.cc)

TARGETS.h = \
	$(SOURCES.G:%.G=%_ui.h) \
	$(SOURCES.l:%.l=%.h) \
	$(SOURCES.y:%.y=%.h) \
	$(SOURCES.cps:%.cps=%.h)

TARGETS.other = \
	$(SOURCES.G:%.G=%.info)

TARGETS = \
	$(TARGETS.other) \
	$(TARGETS.h) \
	$(TARGETS.cc)

OBJECTS = \
	$(SOURCES.c:%.c=%.o) \
	$(SOURCES.cc:%.cc=%.o) \
	$(TARGETS.cc:%.cc=%.o)

# Compiler flags.

CCFLAGS += -g 
CPPFLAGS += -I$(GUIDEHOME)/include -I$(WIN_HOME)/include -DMAIN -DSVR4
LDFLAGS += -L$(GUIDEHOME)/lib -L$(WIN_HOME)/lib
LDLIBS += -lsocket -lnsl -ldevguide -lguide -lxview -lolgx -lX11 -lintl

# Standard targets.

all:	 $(TARGETS.other) $(PROGRAM)
objects: $(SOURCES.c) $(SOURCES.cc) $(TARGETS.cc) $(TARGETS.h) $(OBJECTS)
sources: $(SOURCES)
targets: $(SOURCES) $(TARGETS)

$(PROGRAM): $(SOURCES.c) $(SOURCES.cc) $(TARGETS.cc) $(TARGETS.h) $(OBJECTS)
	LD_RUN_PATH=$(WIN_HOME)/lib $(LINK.cc) -o $@ $(OBJECTS) $(LDLIBS)

clean:
	$(RM) $(SOURCES.G:%.G=%_ui.cc) $(TARGETS.other) $(TARGETS.h) $(OBJECTS) *.BAK *.delta core

scour:
	$(RM) $(TARGETS.cc) $(TARGETS.other) $(TARGETS.h) $(PROGRAM).db $(OBJECTS) *.BAK *.delta $(PROGRAM) Makefile core

%_ui.cc: %.G
	$(GUIDEHOME)/bin/gxv++ $*

%_ui.h: %_ui.cc
	@touch $@

%_stubs.cc: %_ui.cc
	@touch $@

%.info: %_ui.cc
	@touch $@
