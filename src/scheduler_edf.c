#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "scheduler_edf.h"

// List of tasks (ordered by deadline)
struct Node *task_list = NULL;

// Add a new task to the list of tasks (Earliest Deadline First)
void add_edf(char *name, int priority, int burst, int deadline)
{
  Task *newTask = (Task *)malloc(sizeof(Task));
  newTask->name = strdup(name);
  newTask->priority = priority;
  newTask->burst = burst;
  newTask->deadline = deadline;

  // Add the task to the list in order of deadline
  if (task_list == NULL || task_list->task->deadline > deadline)
  {
    insert(&task_list, newTask);
  }
  else
  {
    struct Node *temp = task_list;

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
  while (task_list != NULL)
  {
    Task *task = task_list->task;
    delete(&task_list, task);
    run(task, task->burst);
    free(task);
  }
}
