#ifndef GLOBALS_H
#define GLOBALS_H

#include "list.h"

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// Global task list
extern struct Node *task_list[MAX_PRIORITY + 1];

// Global variable to indicate timer interrupt
extern volatile int timer_interrupt;

#endif
