#ifndef TASK_H
#define TASK_H

typedef struct task {
  char *name;     // Task name
  int tid;        // Unique task identifier
  int priority;   // Task priority
  int burst;      // Execution time needed
  int deadline;   // Task deadline (only for EDF)
} Task;

#endif
