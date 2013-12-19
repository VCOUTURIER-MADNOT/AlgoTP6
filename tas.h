#ifndef DEF_TAS
#define DEF_TAS

	#include "graphe.h"
	typedef struct
	{
		int length;
		int size;
		Sommet** tabSommets;
	} Tas;

	int parent(int _index);
	int gauche(int _index);
	int droite(int _index);

	void entasserMin(Tas * _tas, int _index);
	Tas * construireTasMin(Sommet** _array, int _size);
	void detruireTas(Tas** tas);

#endif