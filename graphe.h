#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <stdbool.h>
#include "listeAdj.h"
#include "cellule.h"
#include "outilsListeAdj.h"
#include "sommet.h"
#include "arete.h"

typedef struct{
	int 		nbrSommet;
	int 		oriente;
	int 		value;
	int 		complet;
	ListeAdj** 	listeAdj;
	int** 		matriceAdj;
	Sommet** 	tabSommet;
	Arete** 	tabAretes;
} Graphe ;

ListeAdj** creerListesAdjacences(char*);
void afficherListesAdjacences(Graphe*);
int** creerMatriceAdjacences(char*);
void afficherMatriceAdjacences(Graphe*);
Graphe* creerGraphe(char*);
void detruireGraphe(Graphe**);
void detruireTableauSommet(Sommet**);
void parcoursLargeur(Graphe*, Sommet*);
void afficherChemin(Graphe*,Sommet*,Sommet*);
void parcoursProfondeur(Graphe*,Sommet*);
void visiterPP(Graphe*, Sommet*, int*);
void afficherParcoursProfondeur(Graphe*,Sommet*);
void initialiserAretes(Graphe*);

#endif