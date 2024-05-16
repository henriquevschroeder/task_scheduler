#include <stdio.h>
#include "cpu.h"

// Run the specified task for the given time slice
void run(Task *task, int slice)
{
  printf(
    "Running task = [%s] [Priority: %d] [Burst: %d] for %d units of time.\n",
    task->name, task->priority, task->burst, slice
  );
}
