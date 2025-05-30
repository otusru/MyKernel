// kernel/kernel.c

#include "kernel.h"
#include "timer.h"
#include "keyboard.h"
#include "scheduler.h"
#include "memory.h"
#include "interrupt.h"
#include "io.h"

// Простейшая задача для планировщика
void test_task() {
    while (1) {
        // Имитация работы: печать символа или задержка
        outb(0xE9, 'T'); // Вывод в Bochs/QEMU debug порт
    }
}

void kernel_main() {
    // Инициализация базовых подсистем
    init_memory();       // Подсистема динамической памяти (kmalloc/kfree)
    init_interrupts();   // IDT, PIC
    init_timer();        // Программируемый таймер (PIT)
    init_keyboard();     // Простейший драйвер клавиатуры
    init_scheduler();    // Очередь задач

    // Добавляем тестовую задачу в очередь планировщика
    add_task(test_task);

    // Запускаем планировщик задач (бесконечный цикл)
    start_scheduler();

    // Если вдруг выходим — просто повисаем
    while (1) {
        __asm__ volatile ("hlt");
    }
}
