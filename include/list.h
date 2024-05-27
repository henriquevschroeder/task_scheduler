#ifndef LIST_H
#define LIST_H

#include "task.h"

/**
 * Node structure for the linked list.
 *
 * This structure represents a node in a linked list. Each node contains
 * a pointer to a Task and a pointer to the next node in the list.
 */
struct Node {
  Task *task;        // Pointer to the task associated with this node
  struct Node *next; // Pointer to the next node in the list
};

/**
 * Inserts a new task into the linked list.
 *
 * This function creates a new node for the given task and inserts it
 * at the head of the linked list.
 */
void insert(struct Node **head, Task *task);

/**
 * Deletes a task from the linked list.
 *
 * This function removes the node containing the specified task from
 * the linked list.
 */
void delete(struct Node **head, Task *task);

/**
 * Traverses the linked list and prints the tasks.
 *
 * This function iterates through the linked list and prints the details
 * of each task.
 */
void traverse(struct Node *head);

#endif
