#ifndef CPU_H
#define CPU_H

#include "task.h"

#define QUANTUM 10 // Time slice (quantum) for the Round-Robin scheduler

/**
 * Simulates running a specified task for a given time slice.
 *
 * This function prints out the details of the task being run, including its name,
 * priority, remaining burst time, and the time slice it was given to run.
 */
void run(Task *task, int slice);

#endif
