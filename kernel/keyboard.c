#include "keyboard.h"
#include "io.h"

#define KEYBOARD_DATA_PORT 0x60

void init_keyboard() {
    // Здесь можно настроить IRQ1
    // Заглушка: Инициализация клавиатуры
}

unsigned char keyboard_read() {
    return inb(KEYBOARD_DATA_PORT);
}
