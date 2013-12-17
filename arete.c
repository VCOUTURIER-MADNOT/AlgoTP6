#include "arete.h"
#include <stdlib.h>

Arete* 	creerArete(Sommet* _u, Sommet* _v, int _poids)
{
	Arete* arete = (Arete*) malloc(sizeof(Arete));
	arete->u = _u;
	arete->v = _v;
	arete->poids = _poids;

	return arete;
}

void	detruireArete(Arete** _arete)
{
	free((*_arete)->u);
	free((*_arete)->v);
	free((*_arete));
}