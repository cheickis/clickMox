ROBOCLAW = roboclaw.o
CC = gcc
CXX = g++
DEBUG = 
CFLAGS = -O2 -Wall -c $(DEBUG)
CXX_FLAGS = -O2 -Wall -c $(DEBUG)
LFLAGS = -O2 -Wall $(DEBUG)

roboclaw.o : roboclaw.h roboclaw.c
	$(CC) $(CFLAGS) roboclaw.c
		
all : $(ROBOCLAW) 
		

