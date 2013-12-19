CC = gcc -Wall -O3
OBJETS = main.o graphe.o cellule.o listeAdj.o outilsListeAdj.o file.o outilsGraphe.o tri.o tas.o util.o element.o outilsSaisie.o
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

tri.o: tri.c tri.h
	$(CC) -c tri.c

element.o: element.c element.h
	$(CC) -c element.c

tas.o: tas.c tas.h
	$(CC) -c tas.c

util.o: util.c util.h
	$(CC) -c util.c

outilsSaisie.o: outilsSaisie.c outilsSaisie.h
	$(CC) -c outilsSaisie.c
	
clean:
	rm *.o
