#ifndef LIST_H
#define LIST_H

#include "task.h"

// Node structure for the list
struct Node {
  Task *task;
  struct Node *next;
};

// List operations
void insert(struct Node **head, Task *task);
void delete(struct Node **head, Task *task);
void traverse(struct Node *head);

#endif
