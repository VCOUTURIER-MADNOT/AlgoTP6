#include "graphe.h"
#include "listeAdj.h"
#include "outilsListeAdj.h"
#include "cellule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "file.h"
#include "outilsGraphe.h"

ListeAdj** creerListeAdjacences(char* nomFichier){
	ListeAdj** listeAdj = NULL;
	FILE *fichier = fopen(nomFichier,"r");
	
	int indice;
	int valeur;
	int nbrSommet;
	int poids;

	char mot[100];
	if(fichier != NULL){
		fscanf(fichier,"%s %d",mot,&nbrSommet);

		
		listeAdj = malloc(sizeof(ListeAdj) * nbrSommet);
		
		int i;
		for(i=0;i<nbrSommet;i++){
			listeAdj[i]=creerListeAdj();
		}

		do
		{
			fscanf(fichier, "%s", mot);
		}while(strcmp(mot, "debutDefAretes"));

		Cellule* c1 = NULL;
		Cellule* c2 = NULL;
		do{
			fscanf(fichier,"%s %d %d",mot,&valeur, &poids);
			if(strcmp(mot,"finDefAretes"))
			{
				indice = atoi(mot);
				c1 = creerCellule(indice, poids);
				c2 = creerCellule(valeur, poids);
			
				inserer(listeAdj[indice],c2);
				inserer(listeAdj[valeur],c1);
			}
		}while(strcmp(mot,"finDefAretes"));		
		
	}


	fclose(fichier);
	
	return listeAdj;
}

void afficherListesAdjacences(Graphe* graphe){
	if(graphe->listeAdj != NULL){
		int i;
		for(i = 0;i<graphe->nbrSommet;i++){
			Cellule* c = graphe->listeAdj[i]->tete;
			printf("ListeAdj %d :\t",i);
			while(c != NULL){
				printf("%d",c->cle );
				c=c->successeur;
				
				if(c!=NULL)
					printf(" - ");
			}
			printf("\n");
		}
	}
}

int** creerMatriceAdjacences(char* nomFichier){
	int** matrice = NULL;
	
	FILE *fichier = fopen(nomFichier,"r");

	int indice;
	int valeur;
	int nbrSommet;
	int poids;
	char mot[100];
	if(fichier != NULL){
		fscanf(fichier,"%s %d",mot,&nbrSommet);
		
		int i;
		matrice = (int**)malloc(sizeof(int*) * nbrSommet);
		
		for(i=0;i<nbrSommet;i++){
			matrice[i]= (int*) calloc(nbrSommet,sizeof(int));
		}

		do
		{
			fscanf(fichier, "%s", mot);
		}while(strcmp(mot, "debutDefAretes"));

		do{
			fscanf(fichier,"%s %d %d", mot, &valeur, &poids);
			if(strcmp(mot,"finDefAretes"))
			{
				indice = atoi(mot);
				matrice[indice][valeur]=poids;
				matrice[valeur][indice]=poids;
			}
		}while(strcmp(mot,"finDefAretes"));
	}
	fclose(fichier);
	return matrice;
}

void afficherMatriceAdjacences(Graphe* graphe){
	int i,j;
	for(i=0;i<graphe->nbrSommet;i++){
		for(j=0;j<graphe->nbrSommet;j++){
			printf("%d ",graphe->matriceAdj[i][j]);
		}
		printf("\n");
	}
}

Graphe* creerGraphe(char* nomFichier){
	int i;
	Graphe* graphe = malloc(sizeof(Graphe));
	
	FILE *fichier = fopen(nomFichier,"r");
	
	int nbrSommet;
	int oriente;
	int value;
	int complet;
	char mot[100];
	
	fscanf(fichier,"%s %d",mot,&nbrSommet);
	fscanf(fichier,"%s %d",mot,&oriente);
	fscanf(fichier,"%s %d",mot,&value);
	fscanf(fichier,"%s %d",mot,&complet);
	
	graphe->nbrSommet = nbrSommet;
	graphe->oriente = oriente;
	graphe->value = value;
	graphe->complet = complet;
	
	graphe->listeAdj = creerListeAdjacences(nomFichier);
	graphe->matriceAdj = creerMatriceAdjacences(nomFichier);

	graphe->tabSommet = (Sommet**) malloc(sizeof(Sommet) * graphe->nbrSommet);

	for(i=0;i<graphe->nbrSommet;i++){
		graphe->tabSommet[i] = creerSommet();
		graphe->tabSommet[i]->cle=i;
	}
	
	initialiserAretes(graphe);
	fclose(fichier);
	
	return graphe;
}

void detruireGraphe(Graphe** graphe){
	(*graphe)->nbrSommet = 0;
	(*graphe)->oriente = 0;
	(*graphe)->value = 0;
	(*graphe)->complet = 0;
	(*graphe)->listeAdj = NULL;
	(*graphe)->matriceAdj = NULL;
	detruireTableauSommet((*graphe)->tabSommet);
	free((*graphe)->listeAdj);
	free((*graphe)->matriceAdj);
	free(*graphe);
}

void detruireTableauSommet(Sommet** sommet){
	(*sommet)=NULL;
	free(*sommet);
}


void parcoursLargeur(Graphe* g, Sommet* s){
	int i;
	for(i=0;i<g->nbrSommet;i++){
		g->tabSommet[i]->distance=10000;
		g->tabSommet[i]->couleur='b';
		g->tabSommet[i]->pere=NULL;
	}
	s->distance = 0;
	s->couleur = 'g';
	File* f = creerFile(g->nbrSommet);

	enfiler(f,s);;
	while(!fileVide(f)){
		Sommet* u = defiler(f);
		Cellule* j = NULL;
		for(j = g->listeAdj[u->cle]->tete; j != NULL; j = j->successeur){
			if (g->tabSommet[j->cle]->couleur == 'b'){
				g->tabSommet[j->cle]->couleur='g';
				g->tabSommet[j->cle]->distance = u->distance + 1;
				g->tabSommet[j->cle]->pere = u;
				enfiler(f,g->tabSommet[j->cle]);
			}
		}
		u->couleur = 'n';
	}
	detruireFile(&f);
}

void afficherChemin(Graphe* g, Sommet* origine, Sommet* sommet){
	parcoursLargeur(g,origine);
	Sommet * s = sommet;
	printf("Chemin entre le sommet: %d et le sommet: %d : \n", origine->cle, sommet->cle);
	while(s != NULL)
	{
		if(s == origine)
		{
			printf("%d", s->cle);
		}
		else
		{
			printf("%d - ", s->cle);
		}
		
		s = s->pere;
	}

	printf("\n");

	printf("Distance origine/sommet : %d\n\n",sommet->distance);

	printf("Distance origine/sommets :\n");
	int i;
	for(i=0;i<g->nbrSommet;i++){
		printf("Sommet %i : %d\n",i,g->tabSommet[i]->distance);
	}
}

void parcoursProfondeur(Graphe* g){
	int i, date;
	for(i=0;i<g->nbrSommet;i++){
		g->tabSommet[i]->couleur='b';
		g->tabSommet[i]->pere=NULL;
	}
	date = 0;
	for(i=0;i<g->nbrSommet;i++){
		if(g->tabSommet[i]->couleur == 'b'){
			visiterPP(g,g->tabSommet[i],&date);
		}
	}
}

void visiterPP(Graphe* g, Sommet* u, int* date){
	u->couleur='g';
	*date=*date+1;
	u->debut=*date;
	Cellule* j = NULL;

	for(j = g->listeAdj[u->cle]->tete; j != NULL; j = j->successeur){
		if(g->tabSommet[j->cle]->couleur == 'b'){
			g->tabSommet[j->cle]->pere = u;
			visiterPP(g,g->tabSommet[j->cle],date);
		}
	}
	*date=*date+1;
	u->fin =*date;
	u->couleur = 'n';
}

void afficherParcoursProfondeur(Graphe* g){
	parcoursProfondeur(g);

	int i;
	for(i=0;i<g->nbrSommet;i++){
		printf("Sommet %i:\t debut: %d \t fin:%d\n",g->tabSommet[i]->cle,g->tabSommet[i]->debut,g->tabSommet[i]->fin);
	}
}

void initialiserAretes(Graphe* _graphe)
{
	int i, j, k, nbAretes;
	Arete * arete = NULL;

	nbAretes = compterAretes(_graphe);
	_graphe->tabAretes = (Arete**) malloc(sizeof(Arete*) * nbAretes);
	k = 0;
	for(i = 0; i < _graphe->nbrSommet; i++)
	{
		for(j = i; j < _graphe->nbrSommet; j++)
		{
			if(_graphe->matriceAdj[i][j])
			{
				arete = creerArete(_graphe->tabSommet[i], _graphe->tabSommet[j], _graphe->matriceAdj[i][j]);
				_graphe->tabAretes[k] = arete;
				k++;
			}
		}
	}
}

void creerTabEnsemble(Graphe* _graphe)
{
	int i;
	Sommet* s = NULL;
	Ensemble** tabEnsembles = (Ensemble**)malloc(sizeof(Ensemble*)*_graphe->nbrSommet);

	for(i = 0; i<_graphe->nbrSommet; i++)
	{
		s = _graphe->tabSommet[i];
		tabEnsembles[s->cle] = creerEnsemble(s);
	}
	_graphe->tabEnsembles = tabEnsembles;
}

Ensemble* creerEnsemble(Sommet* _sommet)
{
	Ensemble* ensemble = NULL;
	Element* element = NULL;

	ensemble = (Ensemble*)malloc(sizeof(Ensemble));
	element = creerElement(_sommet->cle);

	ensemble->tete = element;
	ensemble->queue = element;

	_sommet->ensemble = ensemble;

	return ensemble;
}

Element* trouverEnsemble(Sommet* _sommet)
{
	return _sommet->ensemble->tete;
}

void unionEnsemble(Sommet* _x, Sommet* _y, Graphe* _graphe)
{
	Ensemble* ensembleX;
	Ensemble* ensembleY;
	Element* element;
	ensembleX = _x->ensemble;
	ensembleY = _y->ensemble;

	ensembleX->queue->successeur = ensembleY->tete;
	ensembleX->queue = ensembleY->queue;
	element = ensembleY->tete;
	while(element != NULL)
	{
		_graphe->tabSommet[element->cle]->ensemble = ensembleX;
		element = element->successeur;
	}
}

Sommet* creerSommet(){
	Sommet* sommet;
	sommet = malloc(sizeof(Sommet));

	sommet->couleur='b';
	sommet->pere = NULL;
	sommet->distance = 0;
	sommet->debut=0;
	sommet->fin=0;

	sommet->ensemble = NULL;

	return sommet;
}

Arete* 	creerArete(Sommet* _u, Sommet* _v, int _poids)
{
	Arete* arete = (Arete*) malloc(sizeof(Arete));
	arete->u = _u;
	arete->v = _v;
	arete->poids = _poids;

	return arete;
}

void	detruireArete(Arete** _arete)
{
	free((*_arete)->u);
	free((*_arete)->v);
	free((*_arete));
}

EnsembleAretes* creerEnsembleAretes()
{
	EnsembleAretes* ensembleA = (EnsembleAretes*)malloc(sizeof(EnsembleAretes));
	ensembleA->arete = NULL;

	return ensembleA;
}

void insererEnsembleAretes(EnsembleAretes* _ensembleAretes, Arete* _arete)
{
	_arete->successeur = _ensembleAretes->arete;
	_ensembleAretes->arete = _arete;
}