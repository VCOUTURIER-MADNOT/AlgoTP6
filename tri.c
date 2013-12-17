#include "tri.h"

void triInsertion(Arete** _array, int _taille)
{
	int i, j;
	Arete* cle;

	for (j = 1; j < _taille; j++)
	{
		cle = _array[j];
		i = j-1;
		while(i>=0 && _array[i]->poids>cle->poids){
			_array[i + 1] = _array[i];
			i = i-1;
		}
		_array[i+1] = cle;
	}
}
