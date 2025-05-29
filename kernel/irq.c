#include "irq.h"
#include "io.h"

#define PIC1            0x20
#define PIC2            0xA0
#define PIC1_COMMAND    PIC1
#define PIC1_DATA       (PIC1+1)
#define PIC2_COMMAND    PIC2
#define PIC2_DATA       (PIC2+1)

void remap_pic() {
    outb(PIC1_COMMAND, 0x11);
    outb(PIC2_COMMAND, 0x11);
    outb(PIC1_DATA, 0x20); // IRQ0-7 -> INT20h-27h
    outb(PIC2_DATA, 0x28); // IRQ8-15 -> INT28h-2Fh
    outb(PIC1_DATA, 0x04);
    outb(PIC2_DATA, 0x02);
    outb(PIC1_DATA, 0x01);
    outb(PIC2_DATA, 0x01);
}

void irq_handler() {
    // Сброс запроса PIC
    outb(PIC1_COMMAND, 0x20);
    outb(PIC2_COMMAND, 0x20);
}
