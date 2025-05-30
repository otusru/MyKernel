/*// Заглушка для управления памятью
// kernel/memory.c
#include "memory.h"
#include "malloc.h"

void init_memory() {
    // Пока что логика отсутствует — можно подключать malloc
}

*/

// kernel/memory.c

#include "memory.h"

#define HEAP_SIZE 0x100000  // 1 МБ хип
static unsigned char heap[HEAP_SIZE];
static size_t used = 0;

void *kmalloc(size_t size) {
    if (used + size >= HEAP_SIZE) return 0;
    void *ptr = &heap[used];
    used += size;
    return ptr;
}

void kfree(void *ptr) {
    // Простейшая реализация без возврата памяти
    (void)ptr;
}

void init_memory() {
    used = 0;
}
