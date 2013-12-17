#include "cellule.h"
#include "listeAdj.h"
#include <stdio.h>
#include <stdlib.h>

void afficherListeAdj(ListeAdj* listeAdj){
	if(listeAdj->tete != NULL){
		Cellule* c = listeAdj->tete;
		while(c != NULL){
			if(c->predecesseur == NULL)
				printf("NULL      ");
			else
				printf("%d",c->predecesseur->cle);
			printf(" ---------- %d ---------- ",c->cle);
			if(c->successeur == NULL)
				printf("NULL      ");
			else
				printf("%d",c->successeur->cle);
			//printf("%s ---------- %s ---------- %s",c->predecesseur->cle,c->cle,c->successeur->cle);
			printf("\n");
			c=c->successeur;
		}
		printf("\n");
	}
	else
		printf("Erreur: rien a afficher!\n");
	
}

int compterListeAdj(ListeAdj* listeAdj){
	int i=0;
	if(listeAdj->tete != NULL){
		Cellule* c = listeAdj->tete;
		while(c!=NULL){
			i++;
			c=c->successeur;
		}
	}
	else
		i=0;
	return i;
}