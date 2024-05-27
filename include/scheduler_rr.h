#ifndef SCHEDULER_RR_H
#define SCHEDULER_RR_H

#define MIN_PRIORITY 1  // Minimum priority for tasks
#define MAX_PRIORITY 10 // Maximum priority for tasks

/**
 * Adds a task to the list using the Round-Robin with Priority scheduling algorithm.
 *
 * This function creates a new task with the specified parameters and inserts it into the
 * task list. Tasks are organized by their priority levels.
 */
void add_rr(char *name, int priority, int burst);

/**
 * Invokes the Round-Robin with Priority scheduler.
 *
 * This function processes and runs the tasks in the task list according to the
 * Round-Robin with Priority scheduling algorithm. Tasks are executed in a round-robin
 * fashion within each priority level, with higher priority tasks being scheduled before
 * lower priority ones.
 */
void schedule_rr();

#endif
