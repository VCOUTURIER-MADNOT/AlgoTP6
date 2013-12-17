#ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED

typedef struct Cel{
  int cle;
  int poids;
  struct Cel* predecesseur;
  struct Cel* successeur;
} Cellule ;

Cellule* creerCellule(int cle, int poids);
void detruireCellule(Cellule**);

#endif // CELLULE_H_INCLUDED