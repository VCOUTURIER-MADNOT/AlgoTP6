#include "outilsSaisie.h"
#include <stdio.h>
#include <stdlib.h>

int choixInt(int _nbChoix)
{
	int choix = -1;
	while(choix<0 || choix>_nbChoix)
	{
		printf("Faites votre choix (Nombre inferieur a %d) : ", _nbChoix);
		scanf("%d", &choix);
	}
	
	return choix;
}

char* saisieNomFichier()
{
	char* nom;
	FILE* file = NULL;

	nom = (char*)malloc(sizeof(char)*50);
	while(file == NULL)
	{
		printf("Entrez le nom du fichier que vous souhaitez comparer :\n");
		scanf("%50s", nom);
		file = fopen(nom, "r");	
	}
	fclose(file);

	return nom;
}
