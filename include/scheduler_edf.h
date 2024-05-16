#ifndef SCHEDULER_EDF_H
#define SCHEDULER_EDF_H

// Add a task to the list (Earliest Deadline First)
void add_edf(char *name, int priority, int burst, int deadline);

// Invoke the scheduler (Earliest Deadline First)
void schedule_edf();

#endif
