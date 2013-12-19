#include "element.h"
#include <stdlib.h>

Element* creerElement(int _cle)
{
	Element* element = NULL;

	element = (Element*) malloc(sizeof(Element));
	element->cle = _cle;
	element->successeur = NULL;

	return element;
}

void detruireElement(Element** _element)
{
	free((*_element)->successeur);
	free((*_element));
}