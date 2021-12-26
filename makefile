all: main

main: main.o Course.o Assignment.o
	g++ Course.o Assignment.o main.o -o main
Course.o:	Course.cpp Course.h
		g++ -c Course.cpp
Assignment.o:	Assignment.cpp Assignment.h
		g++ -c Assignment.cpp
main.o:	main.cpp 
		g++ -c main.cpp

clean:
		rm -f *.o main
