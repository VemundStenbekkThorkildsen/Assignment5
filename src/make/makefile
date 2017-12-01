#Makefile for "The diffusion equation" C++ application

PROG = diff
CC = g++
OBJS = main.o
FLAGS = -O3

$(PROG) : $(OBJS)
	$(CC) $(FLAGS) -o $(PROG) $(OBJS)
main.o: ../cpp/main.cpp
	$(CC) $(FLAGS) -c ../cpp/main.cpp
clean:
	rm -f core $(PROG) $(OBJS)
