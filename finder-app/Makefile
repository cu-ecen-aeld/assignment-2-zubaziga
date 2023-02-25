CC       =gcc
CFLAGS   =
_OBJS    =writer.o
OBJDIR   =obj
BUILDDIR =.
TARGET   =writer
VALID_CROSS_COMPILE =aarch64-none-linux-gnu-

ifdef CROSS_COMPILE
ifneq ($(CROSS_COMPILE),$(VALID_CROSS_COMPILE))
$(info Invalid cross-compiler, resetting to default.)
override CROSS_COMPILE=
endif
endif

target: $(BUILDDIR)/$(TARGET)


OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(BUILDDIR)/$(TARGET): $(OBJS)
	$(CROSS_COMPILE)$(CC) -o $@ $^ $(CFLAGS)

$(OBJDIR)/%.o: %.c | $(OBJDIR) $(BUILDDIR)
	@echo Using $(CROSS_COMPILE)$(CC) ...
	@echo $<
	@$(CROSS_COMPILE)$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR):
	@echo Creating $@ dir
	@mkdir -p $@

$(BUILDDIR):
	@echo Creating $@ dir
	@mkdir -p $@

.PHONY: clean
clean:
	@echo Cleaning up ...
	@rm -rf $(OBJDIR)
ifneq ($(BUILDDIR),.)
	@rm -rf $(BUILDDIR)
else
	@rm -f ./$(TARGET)
endif
