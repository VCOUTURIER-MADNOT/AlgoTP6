#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "graphe.h"
#include <stdbool.h>

typedef struct{
	Sommet** tab;
	int tete;
	int queue;
	int taille;
} File;

File* creerFile(int);
void detruireFile(File**);
bool fileVide(File*);
void enfiler(File*,Sommet*);
Sommet* defiler(File*);

#endif // FILE_H_INCLUDED