* `memory.c` / `memory.h`
* `scheduler.c` / `scheduler.h`
* `interrupt.c` / `interrupt.h`
* `keyboard.c`
* `timer.c`
* `io.h`
* Стандартные функции из `lib/`
* `kernel.c`

---

## 📄 `MODULE7_kernel_subsystems.md`

````markdown
# МОДУЛЬ 7: Реализация подсистем ядра — планировщик, память, драйверы

В этом модуле реализованы базовые подсистемы ядра:

- Подсистема управления памятью
- Планировщик задач
- Подсистема обработки прерываний
- Драйвер клавиатуры
- Драйвер программного таймера

---

## 📁 kernel/memory.c

```c
#include "memory.h"

void init_memory() {
    // Здесь должна быть реализация инициализации менеджера памяти
}
````

---

## 📁 include/memory.h

```c
#ifndef MEMORY_H
#define MEMORY_H

void init_memory();

#endif
```

---

## 📁 kernel/scheduler.c

```c
#include "scheduler.h"

// Структура задачи (заглушка)
typedef struct task {
    int id;
    void (*entry)(void);
} task_t;

void init_scheduler() {
    // Подготовка списков задач и т.п.
}

void start_scheduler() {
    // Цикл запуска задач (упрощённо)
}
```

---

## 📁 include/scheduler.h

```c
#ifndef SCHEDULER_H
#define SCHEDULER_H

void init_scheduler();
void start_scheduler();

#endif
```

---

## 📁 kernel/interrupt.c

```c
#include "interrupt.h"

// Заглушка для инициализации IDT, обработчиков
void init_interrupts() {
    // Здесь должна быть регистрация ISR и IRQ
}
```

---

## 📁 include/interrupt.h

```c
#ifndef INTERRUPT_H
#define INTERRUPT_H

void init_interrupts();

#endif
```

---

## 📁 kernel/keyboard.c

```c
#include "keyboard.h"

void init_keyboard() {
    // Настройка контроллера клавиатуры, регистрация IRQ1
}
```

---

## 📁 kernel/timer.c

```c
#include "timer.h"

void init_timer() {
    // Настройка аппаратного таймера (например, PIT) и регистрация IRQ0
}
```

---

## 📁 include/io.h

```c
#ifndef IO_H
#define IO_H

static inline unsigned char inb(unsigned short port) {
    unsigned char ret;
    __asm__ volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

static inline void outb(unsigned short port, unsigned char val) {
    __asm__ volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

#endif
```

---

## 📁 lib/string.c

```c
void *memcpy(void *dest, const void *src, unsigned long n) {
    char *d = dest;
    const char *s = src;
    for (unsigned long i = 0; i < n; i++)
        d[i] = s[i];
    return dest;
}
```

---

## 📁 lib/memory.c

```c
void *memset(void *s, int c, unsigned long n) {
    unsigned char *p = s;
    for (unsigned long i = 0; i < n; ++i)
        p[i] = (unsigned char)c;
    return s;
}
```

---

## 📁 kernel/kernel.c

```c
#include "kernel.h"
#include "memory.h"
#include "scheduler.h"
#include "interrupt.h"
#include "keyboard.h"
#include "timer.h"

void kernel_main(void) {
    init_memory();
    init_interrupts();
    init_keyboard();
    init_timer();
    init_scheduler();
    start_scheduler();
}
```

---

## 🔧 Следующий шаг

Если вы планируете расширение:

* Реализуйте **IDT, ISR и IRQ** таблицы;
* Создайте **очередь задач** в планировщике;
* Добавьте **динамическое распределение памяти** (`malloc`/`free`);
* Реализуйте полноценные **драйверы устройств**.

---

