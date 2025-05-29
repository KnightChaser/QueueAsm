ASM      := nasm
ASMFLAGS := -f elf64
CC       := gcc
CFLAGS   := -no-pie -fno-pie
LDFLAGS  := -z noexecstack

SRCDIR   := src
OBJDIR   := build
OBJS     := \
    $(OBJDIR)/create_queue.o \
    $(OBJDIR)/main.o

.PHONY: all clean
all: queue

# Ensure build directory exists
$(OBJDIR):
	mkdir -p $@

# Assemble ASM module into build/
$(OBJDIR)/create_queue.o: $(SRCDIR)/create_queue.asm $(SRCDIR)/structs.inc | $(OBJDIR)
	$(ASM) $(ASMFLAGS) $< -o $@

# Compile C main into build/
$(OBJDIR)/main.o: main.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link all object files from build/ into final binary
queue: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(OBJDIR) queue

