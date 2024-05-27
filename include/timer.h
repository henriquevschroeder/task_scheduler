#ifndef TIMER_H
#define TIMER_H

/**
 * Simulates a hardware timer interrupt.
 *
 * This function runs in a separate thread and periodically sets the
 * `timer_interrupt` flag to simulate a timer interrupt.
 */
void *timer(void *arg);

#endif
