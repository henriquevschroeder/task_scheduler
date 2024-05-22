#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"
#include "task.h"
#include "list.h"
#include "scheduler_rr.h"
#include "globals.h"

// Add a task to the tasks list (Round-Robin with Priority)
void add_rr(char *name, int priority, int burst)
{
  Task *newTask = (Task *)malloc(sizeof(Task));
  newTask->name = strdup(name);
  newTask->priority = priority;
  newTask->burst = burst;

  // Add the task to the end of the list by priority
  if (task_list[priority] == NULL)
  {
    task_list[priority] = (struct Node *)malloc(sizeof(struct Node));
    task_list[priority]->task = newTask;
    task_list[priority]->next = NULL;
  }
  else
  {
    struct Node *temp = task_list[priority];
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = (struct Node *)malloc(sizeof(struct Node));
    temp->next->task = newTask;
    temp->next->next = NULL;
  }
}

// Invoke the Scheduler (Round-Robin with Priority)
void schedule_rr()
{
  int all_tasks_done = 0;

  while (!all_tasks_done)
  {
    all_tasks_done = 1;

    for (int i = MIN_PRIORITY; i <= MAX_PRIORITY; i++)
    {
      struct Node *temp = task_list[i];

      while (temp != NULL)
      {
        Task *task = temp->task;
        delete(&task_list[i], task);

        int slice = (task->burst > QUANTUM) ? QUANTUM : task->burst;
        run(task, slice);
        task->burst -= slice;

        if (task->burst > 0)
        {
          // Task is not yet completed, move it to the end of the queue
          add_rr(task->name, task->priority, task->burst); // Reuse add_rr to re-add the task to the end
          all_tasks_done = 0;
        }
        else
        {
          // Task is completed
          free(task->name);
          free(task);
        }

        // Move to the next task in the list
        temp = task_list[i];
      }
    }
  }
}
