CC = gcc
AS = nasm
LD = ld
CFLAGS = -ffreestanding -O2 -Wall -Wextra -nostdlib -fno-builtin -fno-stack-protector -m32
LDFLAGS = -T linker.ld -ffreestanding -O2 -nostdlib -lgcc
ISO_NAME = mykernel.iso
GRUB_DIR = build/grub

all: $(ISO_NAME)

$(ISO_NAME): build/kernel.bin
	mkdir -p $(GRUB_DIR)/boot/grub
	cp build/kernel.bin $(GRUB_DIR)/boot/
	cp boot/grub.cfg $(GRUB_DIR)/boot/grub/
	grub-mkrescue -o $(ISO_NAME) $(GRUB_DIR)

build/kernel.bin: build/boot.o build/kernel.o
	$(LD) $(LDFLAGS) -o $@ $^

build/boot.o: boot/boot.asm
	$(AS) -f elf32 -o $@ $<

build/kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf build $(ISO_NAME)

run: $(ISO_NAME)
	qemu-system-i386 -cdrom $(ISO_NAME) -m 512M -s -S

