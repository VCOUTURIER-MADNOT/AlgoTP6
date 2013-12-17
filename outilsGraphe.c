#include "outilsGraphe.h"
#include "outilsListeAdj.h"
#include "tri.h"
#include <stdio.h>

int compterAretes(Graphe* _graphe)
{
	int nbAretes = 0;
	int i;

	for(i = 0; i < _graphe->nbrSommet; i++)
	{
		nbAretes += compterListeAdj(_graphe->listeAdj[i]);
	}

	return (nbAretes/2);
}

void afficherAretes(Graphe* _graphe)
{
	int i, nbAretes;

	nbAretes = compterAretes(_graphe);
	for(i = 0; i < nbAretes; i++)
	{
		printf("Arete : %d\n", i+1);
		printf("\t Sommet u : %d\n", _graphe->tabAretes[i]->u->cle);
		printf("\t Sommet v : %d\n", _graphe->tabAretes[i]->v->cle);
		printf("\t Poids : %d\n", _graphe->tabAretes[i]->poids);
	}
}

void trierTabAretes(Graphe* _graphe)
{
	triInsertion(_graphe->tabAretes, compterAretes(_graphe));
}