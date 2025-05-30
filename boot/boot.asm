; Загрузчик GRUB (Multiboot header)

; boot/boot.asm — совместим с GRUB Multiboot
[bits 32]

section .multiboot
align 4
multiboot_header:
    dd 0x1BADB002           ; magic
    dd 0x00                 ; flags
    dd -(0x1BADB002)        ; checksum = -(magic + flags)

section .text
global _start
extern kernel_main

_start:
    call kernel_main        ; запуск основной функции ядра
    cli
.hang:
    hlt
    jmp .hang
