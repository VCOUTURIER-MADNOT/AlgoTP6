#ifndef DEF_ELEMENT
#define DEF_ELEMENT

	typedef struct el
	{
		struct el* 	successeur;
		struct el*	representant;
		int			cle;
	}Element;

	Element* creerElement(int);
	void	 detruireElement(Element**);

#endif