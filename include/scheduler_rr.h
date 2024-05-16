#ifndef SCHEDULER_RR_H
#define SCHEDULER_RR_H

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// Add a task to the list (Round-Robin with Priority)
void add_rr(char *name, int priority, int burst);

// Invoke the Scheduler (Round-Robin with Priority)
void schedule_rr();

#endif