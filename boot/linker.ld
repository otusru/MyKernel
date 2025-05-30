/* boot/linker.ld — Линкует ядро с поддержкой Multiboot */
ENTRY(_start)

SECTIONS
{
    . = 1M; /* Стартуем с 1 МБ */

    .text : {
        *(.multiboot)   /* Заголовок GRUB */
        *(.text*)
    }

    .rodata : {
        *(.rodata*)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
        *(COMMON)
    }
}
