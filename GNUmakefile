MAKEFLAGS += -rR

ARCH := x86_64

OS_NAME := polonium

OS_FILENAME := $(OS_NAME)_$(ARCH)

HOST_CC := cc
HOST_CFLAGS := -g -O2 -pipe
HOST_CPPFLAGS :=
HOST_LDFLAGS :=
HOST_LIBS :=

.PHONY: all
all: $(OS_FILENAME).iso

.PHONY: all-hdd
all-hdd: $(OS_FILENAME).hdd

.PHONY: run
run: run-$(ARCH)

.PHONY: run-hdd
run-hdd: run-hdd-$(ARCH)

.PHONY: run-x86_64
run-x86_64: ovmf/ovmf-code-$(ARCH).fd $(OS_FILENAME).iso
	qemu-system-$(ARCH) \
		-M q35 \
		-drive if=pflash,unit=0,format=raw,file=ovmf/ovmf-code-$(ARCH).fd,readonly=on \
		-cdrom $(OS_FILENAME).iso \
		$(QEMUFLAGS)

.PHONY: run-hdd-x86_64
run-hdd-x86_64: ovmf/ovmf-code-$(ARCH).fd $(OS_FILENAME).hdd
	qemu-system-$(ARCH) \
		-M q35 \
		-drive if=pflash,unit=0,format=raw,file=ovmf/ovmf-code-$(ARCH).fd,readonly=on \
		-hda $(OS_FILENAME).hdd \
		$(QEMUFLAGS)

		.PHONY: run-bios
run-bios: $(OS_FILENAME).iso
	qemu-system-$(ARCH) \
		-M q35 \
		-cdrom $(OS_FILENAME).iso \
		-boot d \
		$(QEMUFLAGS)

.PHONY: run-hdd-bios
run-hdd-bios: $(OS_FILENAME).hdd
	qemu-system-$(ARCH) \
		-M q35 \
		-hda $(OS_FILENAME).hdd \
		$(QEMUFLAGS)

ovmf/ovmf-code-$(ARCH).fd:
	mkdir -p ovmf
	curl -Lo $@ https://github.com/osdev0/edk2-ovmf-nightly/releases/latest/download/ovmf-code-$(ARCH).fd


.PHONY: pooskern
pooskern: 
	$(MAKE) -C pooskern

deps/limine-binary/limine:
	-rm -r deps/limine-binary/limine
	make -C deps/limine-binary \
		CC="$(HOST_CC)" \
		CFLAGS="$(HOST_CFLAGS)" \
		CPPFLAGS="$(HOST_CPPFLAGS)" \
		LDFLAGS="$(HOST_LDFLAGS)" \
		LIBS="$(HOST_LIBS)"

$(OS_FILENAME).iso: deps/limine-binary/limine pooskern
	rm -rf iso_root
	mkdir -p iso_root/boot
	cp -v pooskern/bin-$(ARCH)/pooskern.exe iso_root/boot/
	mkdir -p iso_root/boot/limine
	cp -v limine.conf iso_root/boot/limine/
	mkdir -p iso_root/EFI/BOOT
ifeq ($(ARCH),x86_64)
	cp -v deps/limine-binary/limine-bios.sys deps/limine-binary/limine-bios-cd.bin deps/limine-binary/limine-uefi-cd.bin iso_root/boot/limine/
	cp -v deps/limine-binary/BOOTX64.EFI iso_root/EFI/BOOT/
	cp -v deps/limine-binary/BOOTIA32.EFI iso_root/EFI/BOOT/
	xorriso -as mkisofs -R -r -J -b boot/limine/limine-bios-cd.bin \
		-no-emul-boot -boot-load-size 4 -boot-info-table -hfsplus \
		-apm-block-size 2048 --efi-boot boot/limine/limine-uefi-cd.bin \
		-efi-boot-part --efi-boot-image --protective-msdos-label \
		iso_root -o $(OS_FILENAME).iso
	./deps/limine-binary/limine bios-install $(OS_FILENAME).iso
endif

$(OS_FILENAME).hdd: deps/limine-binary/limine pooskern 
	rm -f $(OS_FILENAME).hdd
	dd if=/dev/zero bs=1M count=0 seek=64 of=$(OS_FILENAME).hdd
ifeq ($(ARCH),x86_64)
	PATH=$$PATH:/usr/sbin:/sbin sgdisk $(OS_FILENAME).hdd -n 1:2048 -t 1:ef00 -m 1
	./deps/limine-binary/limine bios-install $(OS_FILENAME).hdd
else
	PATH=$$PATH:/usr/sbin:/sbin sgdisk $(OS_FILENAME).hdd -n 1:2048 -t 1:ef00
endif
	mformat -i $(OS_FILENAME).hdd@@1M
	mmd -i $(OS_FILENAME).hdd@@1M ::/EFI ::/EFI/BOOT ::/boot ::/boot/limine
	mcopy -i $(OS_FILENAME).hdd@@1M pooskern/bin-$(ARCH)/pooskern ::/boot
	mcopy -i $(OS_FILENAME).hdd@@1M limine.conf ::/boot/limine
ifeq ($(ARCH),x86_64)
	mcopy -i $(OS_FILENAME).hdd@@1M deps/limine-binary/limine-bios.sys ::/boot/limine
	mcopy -i $(OS_FILENAME).hdd@@1M deps/limine-binary/BOOTX64.EFI ::/EFI/BOOT
	mcopy -i $(OS_FILENAME).hdd@@1M deps/limine-binary/BOOTIA32.EFI ::/EFI/BOOT
endif

.PHONY: clean
clean:
	$(MAKE) -C pooskern clean
	rm -rf iso_root $(OS_FILENAME).iso $(OS_FILENAME).hdd