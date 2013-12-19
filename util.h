#ifndef DEF_UTILS
#define DEF_UTILS 
	
	#include <stdio.h>
	#include <stdlib.h>
	#include "graphe.h"
	#include "tas.h"

	int readInputFile(const char* _filename, int ** _array, int * _arraySize);

	void echanger(Sommet*** _array, int _arraySize ,int _indexA, int _indexB);

	void printArray(Sommet** _array, int _size);

	int * randomArray(int _size);

	int * arrayCopy(int * _source, int _sizeSource);

	Sommet* extraireMin(Tas*);

	Sommet* chercherSommetTas(Tas*, int);

	int chercherIndexTas(Tas*, int);

	void	diminuerCle(Tas*, int, int);

#endif