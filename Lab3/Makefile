# Robert Scully
# license: GNU GENERAL PUBLIC LICENSE
# created: 3-10-17 and modify: 13-11-17
# using mutex semaphore to count a global varuable, which should give us the
# out come of 3.

CC=g++
CFLAGS=-std=c++11 -pthread
CFILES=mutexSema.cpp Semaphore.cpp
HFILES=Semaphore.h

ALL:$(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o mutexResult $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

# this is customary and just deletes all .o files
CLEAN:
	rm *.o
