#include <stdlib.h>
#include "globals.h"

// Global task list
struct Node *task_list[MAX_PRIORITY + 1] = { NULL };
