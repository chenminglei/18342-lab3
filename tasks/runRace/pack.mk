PROGS_RUNRACE_OBJS := runRace.o
PROGS_RUNRACE_OBJS := $(PROGS_RUNRACE_OBJS:%=$(TDIR)/runRace/%)
ALL_OBJS += $(PROGS_RUNRACE_OBJS)

$(TDIR)/bin/runRace : $(TSTART) $(PROGS_RUNRACE_OBJS) $(TLIBC)
