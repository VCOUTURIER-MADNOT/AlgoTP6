CC = gcc -Wall -O3
OBJETS = main.o graphe.o cellule.o liste.o outilsListe.o file.o

main : $(OBJETS)
	$(CC) -o main $(OBJETS) -lm

main.o : main.c graphe.h liste.h cellule.h outilsListe.h file.h
	$(CC) -c main.c

graphe.o : graphe.c graphe.h
	$(CC) -c graphe.c

cellule.o : cellule.c cellule.h
	$(CC) -c cellule.c

liste.o : liste.c liste.h
	$(CC) -c liste.c

outilsListe.o : outilsListe.c outilsListe.h
	$(CC) -c outilsListe.c

file.o : file.c file.h
	$(CC) -c file.c

clean :
	rm main $(OBJETS)
