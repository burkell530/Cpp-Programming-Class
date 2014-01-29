#compiler
CC=g++ -std=c++0x

all: sim

sim: sim.o pqueue.o cust.o
	$(CC) sim.o pqueue.o cust.o -o sim

sim.o: sim.cpp
	$(CC) -c sim.cpp -o sim.o

pqueue.o: pqueue.cpp
	$(CC) -c pqueue.cpp -o pqueue.o

cust.o: cust.cpp
	$(CC) -c cust.cpp -o cust.o

