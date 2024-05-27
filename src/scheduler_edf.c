#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "task.h"
#include "list.h"
#include "scheduler_edf.h"
#include "globals.h"
#include "timer.h"

extern void run(Task *task, int slice);

// Add a new task to the list of tasks (Earliest Deadline First)
void add_edf(char *name, int priority, int burst, int deadline)
{
  Task *newTask = (Task *)malloc(sizeof(Task));
  newTask->name = strdup(name);
  newTask->priority = priority;
  newTask->burst = burst;
  newTask->deadline = deadline;

  // Add the task to the list in order of deadline
  if (task_list[priority] == NULL || task_list[priority]->task->deadline > deadline)
  {
    insert(&task_list[priority], newTask);
  }
  else
  {
    struct Node *temp = task_list[priority];

    while (temp->next != NULL && temp->next->task->deadline <= deadline)
    {
        temp = temp->next;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->task = newTask;
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

// Invoke the scheduler (Earliest Deadline First)
void schedule_edf()
{
  pthread_t timer_thread;
  pthread_create(&timer_thread, NULL, timer, NULL);

  for (int i = MIN_PRIORITY; i <= MAX_PRIORITY; i++)
  {
    while (task_list[i] != NULL)
    {
      struct Node *temp = task_list[i];
      Task *task = temp->task;
      delete(&task_list[i], task);

      while (task->burst > 0)
      {
        while (!timer_interrupt);  // Wait for the timer interrupt
        timer_interrupt = 0;  // Reset the timer interrupt flag

        run(task, 1);  // Simulate running the task for 1 time unit
        task->burst -= 1;

        // Check if the task is completed
        if (task->burst == 0)
        {
          free(task->name);
          free(task);
          break;
        }
      }
    }
  }

  pthread_cancel(timer_thread);
  pthread_join(timer_thread, NULL);
}
