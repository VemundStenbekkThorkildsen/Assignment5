#Makefile for "The diffusion equation" C++ application

PROG = diff
CC = g++
OBJS = main.o bwdeuler.o cranknic.o fwdeuler.o fwdeuler2.o trisolver.o writetofile.o writematfile.o geoeulerforward.o
FLAGS = -O3

$(PROG) : $(OBJS)
	$(CC) $(FLAGS) -o $(PROG) $(OBJS)
main.o : ../cpp/main.cpp
	$(CC) $(FLAGS) -c ../cpp/main.cpp
bwdeuler.o : ../cpp/methods.h ../cpp/bwdeuler.cpp
	$(CC) $(FLAGS) -c ../cpp/bwdeuler.cpp
cranknic.o : ../cpp/methods.h ../cpp/cranknic.cpp
	$(CC) $(FLAGS) -c ../cpp/cranknic.cpp
fwdeuler.o : ../cpp/methods.h ../cpp/fwdeuler.cpp
	$(CC) $(FLAGS) -c ../cpp/fwdeuler.cpp
fwdeuler2.o : ../cpp/methods.h ../cpp/fwdeuler2.cpp
	$(CC) $(FLAGS) -c ../cpp/fwdeuler2.cpp
trisolver.o : ../cpp/methods.h ../cpp/trisolver.cpp
	$(CC) $(FLAGS) -c ../cpp/trisolver.cpp
writetofile.o : ../cpp/methods.h ../cpp/writetofile.cpp
	$(CC) $(FLAGS) -c ../cpp/writetofile.cpp
writematfile.o : ../cpp/methods.h ../cpp/writematfile.cpp
	$(CC) $(FLAGS) -c ../cpp/writematfile.cpp
geoeulerforward.o : ../cpp/methods.h ../cpp/geoeulerforward.cpp
	$(CC) $(FLAGS) -c ../cpp/geoeulerforward.cpp
clean:
	rm -f core $(PROG) $(OBJS)
