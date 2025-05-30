#include "timer.h"
#include "io.h"

#define PIT_FREQ 1193180
#define PIT_PORT 0x40

void init_timer() {
    unsigned int divisor = PIT_FREQ / 100; // 100 Гц
    outb(0x43, 0x36); // Command register
    outb(PIT_PORT, divisor & 0xFF);
    outb(PIT_PORT, (divisor >> 8) & 0xFF);
}
