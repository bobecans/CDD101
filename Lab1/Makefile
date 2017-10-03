# Robert Scully
# using semaphone singal and wait to control two thread output.

CC=g++
CFLAGS=-std=c++11 -pthread
CFILES=signal.cpp Semaphore.cpp
HFILES=Semaphore.h

ALL:$(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o SemaphoreThread
