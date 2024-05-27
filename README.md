# Task Scheduler

This project implements task scheduling algorithms: Round-Robin with Priority (RR_p) and Earliest Deadline First (EDF).

## Requirements

- Regarding RR_p, priority should only be considered when choosing which task to execute if there are two (or more) tasks to be executed at the moment. In case of equal priorities, you can implement your own criterion, such as the one that is first in the list (for example). In this project, consider the highest priority to be 1. Additionally, the use of multiple queues for priority management is mandatory.

- You should consider more ready queues for different priorities. Add two tasks for each created priority.

- The time counting (slice) can be implemented as you wish, such as with libraries or through a shared global variable.

- Remember that the task list (ready queue) must be kept "alive" throughout the execution. Therefore, it is recommended to implement it in a library (it can be within the schedulers.h itself) and share it as a global variable.

- Again, you can modify the files, especially the “list”, but without compromising their original essence. However, this file helps in creating priority since it works in the stack model.

- To use the Makefile, generate a schedule_rr.c, schedule_rrp.c, and schedule_fcfs.c file that include the schedulers.h library (you can also change the library name). If you don't want to use the Makefile, you can work with the preferred IDE or compile via terminal.

- Use a slice of a maximum of 10 time units.

- For the algorithms, you must use a first extra thread to simulate the occurrence of the timer in hardware. This thread will simulate the time and generate the timer overflow flag (for the slice). Additionally, for the EDF algorithm, it will be necessary to evaluate the tasks' deadlines and check which task has the closest deadline.