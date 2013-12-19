#include "tas.h"
#include "util.h"

int parent(int _index)
{
	return (_index < 0 ? -1 : (_index-1)/2);
}

int gauche(int _index)
{
	return (_index < 0 ? -1 : 2*_index + 1);
}

int droite(int _index)
{
	return (_index < 0 ? -1 : (2*_index +2));
}

void entasserMin(Tas * _tas, int _index)
{
	int g = gauche(_index);
	int d = droite(_index);
	int min;


	if (g < _tas->length && _tas->tabSommets[g]->distance < _tas->tabSommets[_index]->distance)
	{
		min = g;
	}
	else
	{
		min = _index;
	}

	if ( d < _tas->length && _tas->tabSommets[d]->distance < _tas->tabSommets[min]->distance)
	{
		min = d;
	}

	if (min != _index)
	{
		echanger( &_tas->tabSommets, _tas->length, _index, min);
		entasserMin(_tas, min);
	}
}

Tas * construireTasMin(Sommet** _array, int _size)
{
	Tas * tas;
	int i;

	tas = (Tas *) malloc (sizeof(Tas));
	tas->length = _size;
	tas->size = _size;
	tas->tabSommets = (Sommet**) malloc (sizeof(Sommet*) * _size);
	for (i = 0; i < _size; i++)
	{
		tas->tabSommets[i] = _array[i];
	}

	for (i = ((_size-1)/2); i >= 0; i--)
	{
		entasserMin(tas, i);
	}

	return tas;
}

void detruireTas(Tas** tas)
{
	free((*tas)->tabSommets);
	free((*tas));
}