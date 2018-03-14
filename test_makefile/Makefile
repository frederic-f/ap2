CC = gcc

01_longueur: 01_longueur.o liste.o
	$(CC) -o 01_longueur 01_longueur.o liste.o

liste.o: liste.c liste.h
	$(CC) -Wall -c liste.c

01_longueur.o: 01_longueur.c
	$(CC) -Wall -c 01_longueur.c

