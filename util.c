#include "util.h"
#include <stdlib.h>
#include <time.h>

int
readInputFile(const char * _filename, int ** _array, int * _arraySize)
{
	int i;

	FILE * file = NULL;


	file = fopen(_filename, "r");

	if (file != NULL)
	{
		fscanf(file, "%d", _arraySize);

		(*_array) = (int *)malloc(sizeof(int) * (*_arraySize));

		for(i = 0; i < (*_arraySize); i++)
		{
			int nextInt;

			fscanf(file, "%d", &nextInt);
			(*_array)[i] = nextInt;
		}
		fclose(file);
		return 1;
	}	

	return 0;
}

void echanger(Sommet*** _array, int _arraySize ,int _indexA, int _indexB)
{

	Sommet* temp = NULL;
	temp = (Sommet*) malloc(sizeof(Sommet));
	if (_indexA < _arraySize && _indexA >= 0 
		&& _indexB < _arraySize && _indexB >= 0 )
	{
		temp = (*_array)[_indexA];
		(*_array)[_indexA] = (*_array)[_indexB];
		(*_array)[_indexB] = temp;
	}
}

Sommet* extraireMin(Tas* _tas)
{
	Sommet* sommet = NULL;

	sommet = _tas->tabSommets[0];
	echanger(&(_tas->tabSommets), _tas->length, 0, _tas->length-1);
	_tas->length--;
	entasserMin(_tas, 0);

	return sommet; 
}

void printArray(Sommet** _array, int _size)
{
	int i;
	for (i = 0; i < _size ; i++)
	{
		printf("Numero %d: %d \t Distance : %d\n", i, _array[i]->cle, _array[i]->distance);
	}
}

int * randomArray(int _size)
{
	int * array;
	int i;

	array = (int *) malloc(sizeof(int) * _size);
	srand(time(NULL));
	for (i = 0; i < _size; i++)
	{
		array[i] = rand();
	}

	return array;
}

int * arrayCopy(int * _source, int _sizeSource)
{
	int i;
	int * array;

	array = (int *) malloc(sizeof(int) * _sizeSource);
	for (i = 0; i < _sizeSource; i++) 
	{
		array[i] = _source[i];
	}

	return array;
}

Sommet* chercherTas(Tas* _tas, int _cle)
{
	int i;

	for(i = 0; i < _tas->length; i++)
	{
		if(_tas->tabSommets[i]->cle == _cle)
		{
			return _tas->tabSommets[i];
		}
	}

	return NULL;
}