#include "outilsGraphe.h"
#include "outilsListeAdj.h"
#include "tri.h"
#include "tas.h"
#include "util.h"
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

void acm_prim(Graphe* _graphe, Sommet* _sommet)
{
	Tas* tas = NULL;
	int i;
	Sommet* sommetU = NULL;
	Sommet* sommetV = NULL;
	Cellule* cellV = NULL;

	for(i=0; i < _graphe->nbrSommet; i++)
	{
		_graphe->tabSommet[i]->cle = 1000;
		_graphe->tabSommet[i]->pere = NULL;
	}

	_sommet->cle = 0;
	tas = construireTasMin(_graphe->tabSommet, _graphe->nbrSommet);

	while(tas->length != 0)
	{
		sommetU = extraireMin(tas);
		cellV = _graphe->listeAdj[sommetU->cle]->tete;
		while(cellV != NULL)
		{
			/*sommetV = chercherTas(tas, cellV->cle);
			if(sommetV != NULL && cellV->poids < sommetV->distance)
			{
				sommetV->distance = cellV->poids;
				sommetV->pere = sommetU;
			}
			*/
			printf("Sommet : %d\n", cellV->cle);
			cellV = cellV->successeur;
		}
	}
}