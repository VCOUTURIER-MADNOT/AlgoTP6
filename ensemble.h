#ifndef DEF_ENSEMBLE
#define DEF_ENSEMBLE

	#include "element.h"
	#include "sommet.h"
	#include "graphe.h"

	typedef struct
	{
		Element* tete;
		Element* queue;
	}Ensemble;

	Ensemble* creerEnsemble(Sommet*);
	Ensemble* trouverEnsemble(Sommet*, Ensemble**, int);
	void unionEnsemble(Sommet*, Sommet*);

#endif
