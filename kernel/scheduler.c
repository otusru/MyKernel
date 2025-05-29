/*#include "scheduler.h"

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

void init_scheduler() {
    // Заглушка: Инициализация очереди задач
}

void start_scheduler() {
    // Заглушка: Запуск задач
}
*/

#include "scheduler.h"

#define MAX_TASKS 10

typedef struct {
    int active;
    void (*func)(void);
} task_t;

task_t tasks[MAX_TASKS];
int current_task = 0;

void init_scheduler() {
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].active = 0;
        tasks[i].func = 0;
    }
}

void add_task(void (*func)(void)) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (!tasks[i].active) {
            tasks[i].active = 1;
            tasks[i].func = func;
            return;
        }
    }
}

void start_scheduler() {
    while (1) {
        if (tasks[current_task].active) {
            tasks[current_task].func();
        }
        current_task = (current_task + 1) % MAX_TASKS;
    }
}
