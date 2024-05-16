#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "scheduler_edf.h"
#include "scheduler_rr.h"

#define SIZE 100

// Read the file with the tasks and schedules them
int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s <task file> <scheduler type (rr|edf)>\n", argv[0]);
    return 1;
  }

  FILE *in;
  char *temp;
  char task[SIZE];
  char *name;
  int priority;
  int burst;
  int deadline;

  // Open the file with the tasks
  in = fopen(argv[1], "r");
  if (in == NULL)
  {
    fprintf(stderr, "Error opening file %s\n", argv[1]);
    return 1;
  }

  // Identify the scheduler type
  int is_rr = strcmp(argv[2], "rr") == 0;
  int is_edf = strcmp(argv[2], "edf") == 0;
  if (!is_rr && !is_edf)
  {
    fprintf(stderr, "Invalid scheduler type: %s. Use 'rr' or 'edf'.\n", argv[2]);
    fclose(in);
    return 1;
  }

  // Read the tasks from the file and add them to the scheduler's list
  while (fgets(task, SIZE, in) != NULL)
  {
    temp = strdup(task);
    name = strsep(&temp, ",");
    priority = atoi(strsep(&temp, ","));
    burst = atoi(strsep(&temp, ","));

    if (is_edf)
    {
      deadline = atoi(strsep(&temp, ","));
      add_edf(name, priority, burst, deadline); // Specific function for EDF
    }
    else
    {
      add_rr(name, priority, burst); // Specific function for RR
    }

    free(temp);
  }

  fclose(in);

  if (is_edf)
  {
    schedule_edf();
  }
  else
  {
    schedule_rr();
  }

  return 0;
}
