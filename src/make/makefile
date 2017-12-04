#Makefile for "The diffusion equation" C++ application

PROG = diff
CC = g++
OBJS = main.o bwdeuler.o cranknic.o fwdeuler.o fwdeuler2.o trisolver.o writetofile.o writematfile.o
FLAGS = -O3

$(PROG) : $(OBJS)
	$(CC) $(FLAGS) -o $(PROG) $(OBJS)
main.o: ../cpp/main.cpp
	$(CC) $(FLAGS) -c ../cpp/main.cpp
bwdeuler.o : ../methods.h ../bwdeuler.cpp 
	$(CC) $(FLAGS) -c ../bwdeuler.cpp
cranknic.o : ../methods.h ../cranknic.cpp 
	$(CC) $(FLAGS) -c ../cranknic.cpp
fwdeuler.o : ../methods.h ../fwdeuler.cpp 
	$(CC) $(FLAGS) -c ../fwdeuler.cpp
fwdeuler2.o : ../methods.h ../fwdeuler2.cpp 
	$(CC) $(FLAGS) -c ../fwdeuler2.cpp
trisolver.o : ../methods.h ../trisolver.cpp 
	$(CC) $(FLAGS) -c ../trisolver.cpp
writetofile.o : ../methods.h ../writetofile.cpp 
	$(CC) $(FLAGS) -c ../writetofile.cpp
writematfile.o : ../methods.h ../writematfile.cpp 
	$(CC) $(FLAGS) -c ../writematfile.cpp
clean:
	rm -f core $(PROG) $(OBJS)
