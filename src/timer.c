#include <unistd.h>  // For usleep function
#include "globals.h"

/**
 * Simulates a hardware timer interrupt.
 *
 * This function runs in a separate thread and periodically sets the
 * `timer_interrupt` flag to simulate a timer interrupt.
 */
void *timer(void *arg)
{
  while (1)
  {
    usleep(10000);  // Sleep for 10 milliseconds (10000 microseconds)
    timer_interrupt = 1;  // Set the timer interrupt flag
  }
  
  return NULL;
}
