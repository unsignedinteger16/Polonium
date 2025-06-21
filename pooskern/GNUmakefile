### pooskern/GNUmakefile - building script for pooskern

MAKEFILE += -rR
.SUFFIXES:

override OUTPUT := pooskern.exe

ARCH := x86_64

ifeq ($(filter $(ARCH),),)
    $(error Architecture $(ARCH) not supported)
endif

CC := cc

CFLAGS := -g -O2 -pipe

CPPFLAGS := 

LDFLAGS :=

override CFLAGS += \
	-Wall \
	-Wextra \
	-std=c11 \
	-nostdinc \
	-ffreestanding \
	-fno-stack-protector \
	-fno-stack-check \
	-fno-PIC \
	-ffunction-sections \
	-fdata-sections \
	-g

include ../mk/git.mk

override CPPFLAGS := \
	-I include \
	-I ../common/include \
	-I deps/freestnd-c-hdrs-0bsd \
	-I deps/flanterm/src \
	$(CPPFLAGS) \
	-DLIMINE_API_REVISION=3 \
	-DPOOSKERN_ARCH=$(ARCH) \
	-DGIT_BRANCH_NAME=\"$(GIT_BRANCH_NAME)\" \
	-DGIT_COMMIT_SHORT=\"$(GIT_COMMIT_ID_SHORT)\" \
	-DPOLONIUM_KERNEL \
	-MMD \
	-MP

include arch-$(ARCH)-flags.mk

override LDFLAGS += \
	-Wl,--build-id=none \
	-nostdlib \
	-static \
	-g \
	-z max-page-size=0x1000 \
	-Wl,--gc-sections \
	-T linker-$(ARCH).ld

include sources.mk

override SOURCES_C := $(filter %.c,$(SOURCES))
override SOURCES_AS := $(filter %.S,$(SOURCES))
override OBJECTS := $(addprefix obj-$(ARCH)/,$(SOURCES_C:.c=.c.o) $(SOURCES_AS:.S=.S.o))
override HEADER_DEPENDENCIES := $(addprefix obj-$(ARCH)/,$(SOURCES_C:.c=.c.d) $(SOURCES_AS:.S=.S.d))

.PHONY: all
all: bin-$(ARCH)/$(OUTPUT)

-include $(HEADER_DEPENDENCIES)

bin-$(ARCH)/$(OUTPUT): GNUmakefile sources.mk arch-$(ARCH)-flags.mk linker-$(ARCH).ld $(OBJECTS)
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJECTS) -o $@

obj-$(ARCH)/%.c.o: %.c GNUmakefile sources.mk arch-$(ARCH)-flags.mk
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@


obj-$(ARCH)/%.S.o: %.S GNUmakefile sources.mk arch-$(ARCH)-flags.mk
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf bin-* obj-*