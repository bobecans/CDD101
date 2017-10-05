# Robert Scully
# using semaphone singal and wait to control the pattern of a rendezvous threads.

CC=g++
CFLAGS=-std=c++11 -pthread
CFILES=rendezvousThread.cpp Semaphore.cpp
HFILES=Semaphore.h

ALL:$(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o rendezvous

CLEAN:
	rm *.o
