#ifndef CPU_H
#define CPU_H

#include "task.h"

#define QUANTUM 10

// Run the specified task for the given time slice
void run(Task *task, int slice);

#endif
