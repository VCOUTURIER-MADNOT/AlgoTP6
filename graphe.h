#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <stdbool.h>
#include "listeAdj.h"
#include "cellule.h"
#include "outilsListeAdj.h"
#include "element.h"


typedef struct
{
	Element* tete;
	Element* queue;
}Ensemble;

typedef struct So
{
	char 		couleur;
	int 		distance;
	struct So* 	pere;
	int 		cle;
	int 		debut;
	int 		fin;

	Ensemble*	ensemble;
} Sommet ;

typedef struct Arete1
{
	Sommet* 	u;
	Sommet* 	v;
	int			poids;

	struct Arete1*	successeur;
} Arete;

typedef struct{
	int 		nbrSommet;
	int 		oriente;
	int 		value;
	int 		complet;
	ListeAdj** 	listeAdj;
	int** 		matriceAdj;
	Sommet** 	tabSommet;
	Arete** 	tabAretes;
	Ensemble**	tabEnsembles;

} Graphe ;

typedef struct{
	Arete*	arete;
} EnsembleAretes;

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
void creerTabEnsemble(Graphe*);

Ensemble* creerEnsemble(Sommet*);
Element* trouverEnsemble(Sommet*);
void unionEnsemble(Sommet*, Sommet*, Graphe*);

Sommet* creerSommet();

Arete* 	creerArete(Sommet* _u, Sommet* _v, int _poids);
void	detruireArete(Arete** _arete);

EnsembleAretes* creerEnsembleAretes();
void insererEnsembleAretes(EnsembleAretes*, Arete*);

#endif