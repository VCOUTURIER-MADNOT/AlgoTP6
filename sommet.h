#ifndef DEF_SOMMET
#define DEF_SOMMET

	typedef struct So{
		char 		couleur;
		int 		distance;
		struct So* 	pere;
		int 		cle;
		int 		debut;
		int 		fin;
	} Sommet ;


	Sommet* creerSommet();

#endif