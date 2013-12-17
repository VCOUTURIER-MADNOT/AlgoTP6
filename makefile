CC = gcc -Wall -O3
OBJETS = main.o graphe.o cellule.o listeAdj.o outilsListeAdj.o file.o outilsGraphe.o arete.o sommet.o tri.o

main: $(OBJETS)
	$(CC) -o main $(OBJETS) -lm

main.o: main.c
	$(CC) -c main.c

graphe.o: graphe.c graphe.h
	$(CC) -c graphe.c

cellule.o: cellule.c cellule.h
	$(CC) -c cellule.c

listeAdj.o: listeAdj.c listeAdj.h
	$(CC) -c listeAdj.c

outilsListeAdj.o: outilsListeAdj.c outilsListeAdj.h
	$(CC) -c outilsListeAdj.c

file.o: file.c file.h
	$(CC) -c file.c

outilsGraphe.o: outilsGraphe.c outilsGraphe.h
	$(CC) -c outilsGraphe.c

arete.o: arete.c arete.h
	$(CC) -c arete.c

sommet.o: sommet.c sommet.h
	$(CC) -c sommet.c

tri.o: tri.c tri.h
	$(CC) -c tri.c

clean:
	rm *.o
