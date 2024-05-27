#ifndef SCHEDULER_EDF_H
#define SCHEDULER_EDF_H

/**
 * Adds a task to the list using the Earliest Deadline First scheduling algorithm.
 *
 * This function creates a new task with the specified parameters and inserts it into the
 * task list in order of their deadlines. Tasks with earlier deadlines are given higher priority.
 */
void add_edf(char *name, int priority, int burst, int deadline);

/**
 * Invokes the Earliest Deadline First scheduler.
 *
 * This function processes and runs the tasks in the task list according to the
 * Earliest Deadline First scheduling algorithm. Tasks are executed in the order
 * of their deadlines, with tasks having earlier deadlines being executed first.
 */
void schedule_edf();

#endif
