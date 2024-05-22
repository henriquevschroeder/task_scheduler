#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"
#include "task.h"
#include "list.h"
#include "globals.h"
#include "scheduler_rr.h"

// Add a task to the tasks list (Round-Robin with Priority)
void add_rr(char *name, int priority, int burst)
{
  Task *newTask = (Task *)malloc(sizeof(Task));
  newTask->name = strdup(name);
  newTask->priority = priority;
  newTask->burst = burst;

  // Add the task to the list by priority
  insert(&task_list[priority], newTask);
}

// Invoke the Scheduler (Round-Robin with Priority)
void schedule_rr()
{
  for (int i = MIN_PRIORITY; i <= MAX_PRIORITY; i++)
  {
    while (task_list[i] != NULL)
    {
      struct Node *temp = task_list[i];

      Task *task = temp->task;
      delete(&task_list[i], task);
      run(task, QUANTUM);

      // Verify if the task is not completed yet
      if (task->burst > QUANTUM)
      {
        task->burst -= QUANTUM;
        insert(&task_list[i], task);
      }
      else
      {
        free(task);
      }
    }
  }
}
