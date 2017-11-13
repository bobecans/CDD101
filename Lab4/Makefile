#Author: Robert Scully
#created: 25-10-17
#license: GNU GENERAL PUBLIC LICENSE
#Update: 13-11-17
#Using barrier and mutex semaphore to control the flow of threads.

CC=g++
CFLAGS=-std=c++11 -pthread
CFILES=Barriers.cpp Semaphore.cpp BarriersMain.cpp
HFILES=Semaphore.h Barriers.h

ALL:$(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o barrierResult $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
