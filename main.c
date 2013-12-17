#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include <stdbool.h>
#include "file.h"

int main(){
	Graphe* graphe = creerGraphe("graphe2.txt");
	
	afficherChemin(graphe,graphe->tabSommet[1],graphe->tabSommet[11]);
	afficherParcoursProfondeur(graphe,graphe->tabSommet[0]);
	afficherListesAdjacences(graphe);
	afficherMatriceAdjacences(graphe);
	
	detruireGraphe(&graphe);

	return 0;	
}