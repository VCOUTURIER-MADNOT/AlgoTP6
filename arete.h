#ifndef DEF_ARETE
#define DEF_ARETE

	#include "sommet.h"

	typedef struct
	{
		Sommet* 	u;
		Sommet* 	v;
		int			poids;
	} Arete;

	Arete* 	creerArete(Sommet* _u, Sommet* _v, int _poids);
	void	detruireArete(Arete** _arete);
#endif