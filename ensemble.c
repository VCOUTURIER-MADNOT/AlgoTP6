#include "ensemble.h"
#include <stdlib.h>

Ensemble* creerEnsemble(Sommet* _sommet)
{
	Ensemble* ensemble = NULL;
	Element* element = NULL;

	ensemble = (Ensemble*)malloc(sizeof(Ensemble));
	element = creerElement(_sommet->cle);

	ensemble->tete = element;
	ensemble->queue = element;

	return ensemble;
}

Ensemble* trouverEnsemble(Sommet* _sommet, Ensemble** _tabEnsemble, int _nbEnsembles)
{
	int i;
	Element* element;

	for(i = 0; i < _nbEnsembles; i++)
	{
		element = _tabEnsemble[i]->tete;
		while(element != NULL)
		{
			if(element->cle == _sommet->cle)
			{
				return _tabEnsemble[i];
			}
		}
	}
}

void unionEnsemble(Sommet* _x, Sommet* _y)
{
	Ensemble* ensembleX, ensembleY;
	Element* element;
	ensembleX = trouverEnsemble(_x);
	ensembleY = trouverEnsemble(_y);

	ensembleX->queue->successeur = ensembleY->tete;
	ensembleX->queue = ensembleY->queue;
	element = ensembleY->tete;
}