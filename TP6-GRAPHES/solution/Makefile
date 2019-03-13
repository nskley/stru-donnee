#construction du main

all : Graphes_LC.o main.o
	gcc -o main Graphes_LC.o main.o

Graphes_LC.o : Graphes_LC.c
	gcc -c Graphes_LC.c -Wall -o Graphes_LC.o

main.o : main.c
	gcc -c main.c -Wall -o main.o