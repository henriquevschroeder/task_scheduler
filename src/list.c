#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

// Add a new task to the list of tasks
void insert(struct Node **head, Task *newTask)
{
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->task = newTask;
  new_node->next = *head;
  *head = new_node;
}

// Delete the selected task from the list
void delete(struct Node **head, Task *task)
{
  struct Node *temp = *head;
  struct Node *prev = NULL;

  // Special case - beginning of list
  if (temp != NULL && strcmp(task->name, temp->task->name) == 0)
  {
    *head = temp->next;
    free(temp);
    return;
  }

  // Traverse the list to find the task to be deleted
  while (temp != NULL && strcmp(task->name, temp->task->name) != 0)
  {
    prev = temp;
    temp = temp->next;
  }

  // Task not found
  if (temp == NULL) return;

  // Remove the task from the list
  prev->next = temp->next;
  free(temp);
}

// Traverse the list
void traverse(struct Node *head)
{
  struct Node *temp = head;

  while (temp != NULL)
  {
    printf(
      "Task: [%s] [Priority: %d] [Burst: %d]\n",
      temp->task->name, temp->task->priority, temp->task->burst
    );

    temp = temp->next;
  }
}
