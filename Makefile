CC = gcc
CFLAGS = -Iinclude -Wall
OBJ = src/driver.o src/cpu.o src/list.o src/scheduler_rr.o src/scheduler_edf.o src/globals.o src/timer.o
DEPS = include/cpu.h include/list.h include/scheduler_rr.h include/scheduler_edf.h include/task.h include/globals.h include/timer.h

all: program

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

program: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o program src/*.o
