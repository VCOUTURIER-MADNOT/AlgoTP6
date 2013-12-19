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

EnsembleAretes* acm_kruskal(Graphe* _graphe)
{
	int i;
	Sommet* u;
	Sommet* v;
	EnsembleAretes* e = NULL;

	e = creerEnsembleAretes();

	/* On Initialise tous les ensembles */
	creerTabEnsemble(_graphe);
	/* On tri le tableau des aretes */
	trierTabAretes(_graphe);

	for(i = 0; i < compterAretes(_graphe); i++)
	{
		u = _graphe->tabAretes[i]->u;
		v = _graphe->tabAretes[i]->v;
		if(trouverEnsemble(u)->cle != trouverEnsemble(v)->cle)
		{
			insererEnsembleAretes(e, _graphe->tabAretes[i]);
			unionEnsemble(u, v, _graphe);
		}
	}

	return e;
}

int calculerPoidsEnsembleAretes(EnsembleAretes* _e)
{
	int total = 0;
	Arete* a = _e->arete;
	while(a!=NULL)
	{
		total += a->poids;
		a = a->successeur;
	}
	return total;
}

void acm_prim(Graphe* _graphe, Sommet* _sommet)
{
	Tas* tas = NULL;
	int i;
	int total = 0;
	Sommet* sommetU = NULL;
	Sommet* sommetV = NULL;
	Cellule* cellV = NULL;
	int indexADiminuer = -1;

	for(i=0; i < _graphe->nbrSommet; i++)
	{
		_graphe->tabSommet[i]->distance = 1000;
		_graphe->tabSommet[i]->pere = NULL;
	}

	_sommet->distance = 0;

	/* On construit notre file de priorité par l'implémentation d'un tas min */
	tas = construireTasMin(_graphe->tabSommet, _graphe->nbrSommet);

	/* Tant qu'on n'a pas parcouru tous les sommets */
	while(tas->length != 0)
	{
		sommetU = extraireMin(tas);
		cellV = _graphe->listeAdj[sommetU->cle]->tete;
		/* On calcul le poids de l'arbre couvrant */
		total += sommetU->distance;

		/* On parcours les sommets adjacents au sommet extrait */
		while(cellV != NULL)
		{
			/* On récupère l'indice de l'element du tas à diminuer */
			indexADiminuer = chercherIndexTas(tas, cellV->cle);
			/* On récupère le sommet à mettre à jour */
			sommetV = chercherSommetTas(tas, cellV->cle);
			if(sommetV != NULL && cellV->poids < sommetV->distance)
			{
				/* Si le poids de l'arete est plus faible que la distance de l'arete, on met à jour la distance du sommet */
				sommetV->distance = cellV->poids;
				/* On diminue la clé dans le tas */
				diminuerCle(tas, indexADiminuer, cellV->poids);
				sommetV->pere = sommetU;
			}
			cellV = cellV->successeur;
		}
	}

	printf("L'arbre couvrant de poids minimal par l'algorithme de prism est de poids : %d\n", total);
}