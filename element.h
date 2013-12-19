#ifndef DEF_ELEMENT
#define DEF_ELEMENT


	typedef struct el
	{
		struct el* 	successeur;
		int			cle;
	}Element;

	Element* creerElement(int);
	void	 detruireElement(Element**);

#endif