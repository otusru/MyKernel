#ifndef SCHEDULER_H
#define SCHEDULER_H

void init_scheduler();
void add_task(void (*func)(void));
void start_scheduler();

#endif
