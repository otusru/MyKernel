// Загрузчик GRUB (Multiboot header)

; boot/boot.asm
[bits 32]
section .multiboot
align 4
multiboot_header:
    dd 0x1BADB002          ; magic number
    dd 0x0                 ; flags
    dd -0x1BADB002         ; checksum

section .text
global _start
_start:
    call kernel_main
    cli
    hlt
