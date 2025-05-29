#include "scheduler.h"

static task_t *current_task = NULL;
static task_t *task_queue = NULL;

void init_scheduler(void) {
    // Инициализация планировщика
}

void create_task(void (*task_func)(void)) {
    // Создание новой задачи
}

void schedule(void) {
    // Выбор следующей задачи для выполнения
    current_task = task_queue;
    // Переключение контекста
}
