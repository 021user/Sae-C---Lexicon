#include <iostream>
#include <cassert>

#include "Pile.h"

/**
 * @file Pile.cpp
 * @brief Implémentation du composant de pile à capacité paramétrée. 
*/

void initialiser(Pile& p, unsigned int c) {
	assert(c > 0);
	p.capacite = c;
	p.tab = new Item[c];
	p.sommet = -1;
}

void detruire(Pile& p) {
	delete [] p.tab;
	p.tab = NULL;
}

bool estPleine(const Pile& p) {
	return (p.sommet == (p.capacite-1));
}

bool estVide(const Pile& p) {
	return (p.sommet == -1);
}

Item sommet(const Pile& p) {
	assert(!estVide(p));
	return p.tab[p.sommet];
}

void empiler(Pile& p, const Item& it) {
	assert(!estPleine(p));
	p.sommet++;
	p.tab[p.sommet] = it;
}

void depiler(Pile& p) {
	assert(!estVide(p));
	p.sommet--;
}
