#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
#include "cellule.h"

typedef struct{
  Cellule* tete;
} Liste ;

Liste* creerListe();
void detruireListe(Liste**);
void inserer(Liste*,Cellule*);
Cellule* rechercher(Liste*,char*);
void supprimer(Liste*,Cellule*);


#endif // LISTE_H_INCLUDED