#include "cellule.h"
#include "listeAdj.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListeAdj* creerListeAdj(){
	ListeAdj* listeAdj = malloc(sizeof(listeAdj));
	listeAdj->tete = NULL;
	return listeAdj;
}

void inserer(ListeAdj* listeAdj, Cellule* cellule){
	cellule->successeur = listeAdj->tete;
	if(listeAdj->tete != NULL){
		listeAdj->tete->predecesseur = cellule;
	}
	listeAdj->tete = cellule;
	cellule->predecesseur = NULL;
}

Cellule* rechercher(ListeAdj* listeAdj, int _sommet){
	Cellule* c = NULL;
	if(listeAdj->tete != NULL){
		c = listeAdj->tete;
		while(c != NULL && c->cle != _sommet){
			c = c->successeur;
		}
	}
	return c;
}

void supprimer(ListeAdj* listeAdj, Cellule* cellule){
	if(cellule->predecesseur != NULL)
		cellule->predecesseur->successeur = cellule->successeur;
	else
		listeAdj->tete = cellule->successeur;
	if(cellule->successeur != NULL)
		cellule->successeur->predecesseur = cellule->predecesseur;
}

void detruireListeAdj(ListeAdj** listeAdj){
	(*listeAdj)=NULL;
	free(*listeAdj);
}