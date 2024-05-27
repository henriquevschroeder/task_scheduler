#ifndef GLOBALS_H
#define GLOBALS_H

#include "list.h"

#define MIN_PRIORITY 1  // Minimum priority for tasks
#define MAX_PRIORITY 10 // Maximum priority for tasks

/**
 * Global task list, organized by priority.
 * 
 * task_list is an array of pointers to Node structures, each representing
 * a linked list of tasks at a specific priority level. The index of the array
 * corresponds to the priority level of the tasks in the linked list.
 */
extern struct Node *task_list[MAX_PRIORITY + 1];

/**
 * Global variable to indicate a timer interrupt.
 * 
 * timer_interrupt is a flag that is set by the timer thread to indicate that
 * a timer interrupt has occurred. This flag is used by the scheduler to manage
 * task preemption and execution timing.
 */
extern volatile int timer_interrupt;

#endif
