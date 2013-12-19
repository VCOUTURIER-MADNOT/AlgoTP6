#include "tri.h"
#include "tas.h"
#include "util.h"

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

void triTas(Sommet** _array, int _arraySize)
{
	int index;
	Tas * tas = construireTasMin(_array, _arraySize);
	for (index = _arraySize-1; index >= 1; index--)
	{
		echanger(&tas->tabSommets, tas->length, index, 0);
		tas->length--;
		entasserMin(tas, 0);
	}
	
	detruireTas(&tas);
}
