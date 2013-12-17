#ifndef LISTEADJ
#define LISTEADJ
#include "cellule.h"

typedef struct{
  Cellule* tete;
} ListeAdj;

ListeAdj* creerListeAdj();
void detruireListeAdj(ListeAdj**);
void inserer(ListeAdj*,Cellule*);
Cellule* rechercher(ListeAdj*,int);
void supprimer(ListeAdj*,Cellule*);


#endif