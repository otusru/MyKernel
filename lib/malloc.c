#include "malloc.h"

#define HEAP_START 0x100000
#define HEAP_SIZE  0x10000

static unsigned char *heap = (unsigned char *)HEAP_START;
static unsigned int heap_offset = 0;

void *malloc(unsigned int size) {
    void *ptr = heap + heap_offset;
    heap_offset += size;
    if (heap_offset >= HEAP_SIZE) return 0;
    return ptr;
}

void free(void *ptr) {
    // Простейшая реализация: ничего не делаем
}
