# Robert Scully
# using barrier and mutex semaphore to control the flow of threads.

CC=g++
CFLAGS=-std=c++11 -pthread
CFILES=Battiers.cpp Semaphore.cpp
HFILES=Semaphore.h

ALL:$(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o barrierResult $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
