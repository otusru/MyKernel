// Ядро 

#include "kernel.h"
#include "memory.h"
#include "scheduler.h"
#include "interrupt.h"
#include "keyboard.h"
#include "timer.h"

void kernel_main(void) {
    // Инициализация подсистем
    init_memory();
    init_interrupts();
    init_scheduler();
    init_keyboard();
    init_timer();

    // Создание задач
    create_task(task1);
    create_task(task2);

    // Запуск планировщика
    start_scheduler();
}
