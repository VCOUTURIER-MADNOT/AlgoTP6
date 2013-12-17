#include "graphe.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

File* creerFile(int taille){
	File* file = malloc(sizeof(File));
	file->tab = (Sommet**) malloc(sizeof(Sommet*) * taille);

	int i;
	for(i=0;i<taille;i++){
		file->tab[i]=NULL;
	}

	file->tete=1;
	file->queue=1;
	file->taille=taille; 

	return file;
}

void detruireFile(File** file){
	(*file)->tete=0;
	(*file)->queue=0;
	(*file)->taille=0;
	(*file)->tab=NULL;
	free((*file)->tab);
	(*file)=NULL;
	free(*file);
}

bool fileVide(File* file){
	if(abs(file->tete - file->queue)<1)
		return true;
	return false;
}

void enfiler(File* file,Sommet* sommet){
	if(file->queue==file->taille-1){
		file->tab[file->queue]=sommet;
		file->queue=0;
	}
	else{
		file->tab[file->queue]=sommet;
		file->queue=file->queue+1;
	}
}

Sommet* defiler(File* file){
	if(fileVide(file)){
		printf("Erreur: File vide!\n");
		return NULL;
	}
	else{
		Sommet* sommet;
		sommet = file->tab[file->tete];
		if(file->tete==file->taille-1)
			file->tete=0;
		else
			file->tete=file->tete+1;
		return sommet;
	}
}