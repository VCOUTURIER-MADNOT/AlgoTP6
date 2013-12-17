#include <stdlib.h>
#include "sommet.h"


Sommet* creerSommet(){
	Sommet* sommet;
	sommet = malloc(sizeof(Sommet));

	sommet->couleur='b';
	sommet->pere = NULL;
	sommet->distance = 0;
	sommet->debut=0;
	sommet->fin=0;

	return sommet;
}