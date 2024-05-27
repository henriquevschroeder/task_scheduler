#include <stdlib.h>
#include "globals.h"

// Global task list
struct Node *task_list[MAX_PRIORITY + 1] = { NULL };

// Global variable to indicate timer interrupt
volatile int timer_interrupt = 0;
