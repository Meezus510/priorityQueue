#Makefile
#***************************************
#define variables to hold compiler and compiler flags values respectively
CC = g++
CFLAGS = -Wall -g

#target: main
#dependencies: main.o, queue.o
main: main.o queue.o
#generate target
		$(CC) $(CFLAGS) -o main main.o queue.o

#object files
#****************************************
#target: main.o
#dependencies: main.cpp queue.h
main.o: main.cpp queue.h
#generate target
		$(CC) $(CFLAGS) -c main.cpp

queue.o: queue.h

clean: 	
		$(RM) main *.o
