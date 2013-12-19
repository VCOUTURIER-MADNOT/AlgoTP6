#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include <stdbool.h>
#include "file.h"
#include "outilsGraphe.h"
#include "tas.h"
#include "util.h"

int main(){
	Graphe* graphe = creerGraphe("graphe2.txt");
	EnsembleAretes* e = NULL;

	/*afficherChemin(graphe,graphe->tabSommet[1],graphe->tabSommet[11]);
	afficherParcoursProfondeur(graphe,graphe->tabSommet[0]);*/
	afficherListesAdjacences(graphe);
	/*afficherMatriceAdjacences(graphe);

	e = acm_kruskal(graphe);
	printf("\n\n\n Le poids de l'acm par kruskal est :%d\n", calculerPoidsEnsembleAretes(e));*/

	acm_prim(graphe, graphe->tabSommet[0]);


	detruireGraphe(&graphe);
	return 0;	
}