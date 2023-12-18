/**
 * @file Liste.cpp
 * @brief Composant de liste en mémoire dynamique et extensible
 */
 
#include <cassert> 
#include "Liste.h"

void initialiser(Liste& l, unsigned int capa, unsigned int pas) {
	assert ((capa>0) && (pas>0));
	initialiser(l.c, capa, pas);
	l.nb=0;
}
 
void detruire(Liste& l) {
	detruire(l.c);
}

unsigned int longueur(const Liste& l) {
	return l.nb;
}

Item lire(const Liste& l, unsigned int pos) {
	assert(pos<l.nb);
	return lire(l.c, pos);
}

void ecrire(Liste& l, unsigned int pos, const Item& it) {
	assert(pos<l.nb);
	ecrire(l.c, pos, it);
}	

void inserer(Liste& l, unsigned int pos, const Item& it) {
	assert(pos<=l.nb);
	for (unsigned int i=l.nb; i>pos; i--) {
		ecrire(l.c, i, lire(l.c, i-1));
	}
	ecrire(l.c, pos, it);
	l.nb++;
}

void supprimer(Liste& l, unsigned int pos) {
	assert((l.nb!=0) && (pos<l.nb));
	l.nb--;
	for (unsigned int i=pos; i<l.nb; ++i)
	   ecrire(l.c, i, lire(l.c,i+1));
}
