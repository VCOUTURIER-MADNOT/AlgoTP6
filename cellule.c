#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"

Cellule* creerCellule(int cle, int poids){

	Cellule* cellule =(Cellule*) malloc(sizeof(Cellule));
	cellule->cle=cle;
	cellule->predecesseur = NULL;
	cellule->successeur = NULL;

	return cellule;
}

void detruireCellule(Cellule** cellule){
	//free((*cellule)->cle);
	(*cellule)->predecesseur=NULL;
	(*cellule)->successeur=NULL;
	(*cellule)=NULL;
	free(*cellule);
}