#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include <stdbool.h>
#include "file.h"
#include "outilsGraphe.h"
#include "tas.h"
#include "util.h"

int main(){
	Tas* tas = NULL;
	Graphe* graphe = creerGraphe("graphe2.txt");
	
	afficherChemin(graphe,graphe->tabSommet[1],graphe->tabSommet[11]);
	afficherParcoursProfondeur(graphe,graphe->tabSommet[0]);
	afficherListesAdjacences(graphe);
	afficherMatriceAdjacences(graphe);

	acm_prim(graphe, graphe->tabSommet[0]);


	detruireGraphe(&graphe);
	return 0;	
}