// Инициализация IDT и переназначение PIC
// kernel/interrupt.c

#include "interrupt.h"
#include "io.h"

#define PIC1 0x20
#define PIC2 0xA0
#define PIC1_COMMAND PIC1
#define PIC1_DATA (PIC1+1)
#define PIC2_COMMAND PIC2
#define PIC2_DATA (PIC2+1)
#define ICW1_INIT 0x10
#define ICW1_ICW4 0x01
#define ICW4_8086 0x01

void remap_pic() {
    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
    outb(PIC1_DATA, 0x20); // IRQ0–7 → INT 32–39
    outb(PIC2_DATA, 0x28); // IRQ8–15 → INT 40–47
    outb(PIC1_DATA, 0x04); // PIC1 связан с PIC2
    outb(PIC2_DATA, 0x02);
    outb(PIC1_DATA, ICW4_8086);
    outb(PIC2_DATA, ICW4_8086);
    outb(PIC1_DATA, 0);
    outb(PIC2_DATA, 0);
}

void init_interrupts() {
    remap_pic();
    // Настройка IDT добавляется отдельно
}
