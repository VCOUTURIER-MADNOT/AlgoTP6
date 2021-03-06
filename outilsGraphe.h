#ifndef DEF_OUTILSGRAPHE
#define DEF_OUTILSGRAPHE

	#include "graphe.h"

	int compterAretes(Graphe*);
	void afficherAretes(Graphe*);
	void trierTabAretes(Graphe*);

	void acm_prim(Graphe*, Sommet*);
	EnsembleAretes* acm_kruskal(Graphe*);
	int calculerPoidsEnsembleAretes(EnsembleAretes*);
#endif