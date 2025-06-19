include ../mk/clang_test.mk

ifeq ($(CC_IS_CLANG),1)
	override CC += \
		-target x86_64-unknown-none
endif

override CFLAGS += \
	-m64 \
	-march=x86-64 \
	-mno-80387 \
	-mno-mmx \
	-mno-sse \
	-mno-sse2 \
	-mno-red-zone \
	-mcmodel=kernel
override LDFLAGS := \
	-Wl,-m,elf_x86_64