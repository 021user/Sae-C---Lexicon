/**
 * @file ConteneurTD.cpp
 * @brief Composant de conteneur d'items en mémoire dynamique à capacité fixe.
 */

#include <iostream>
#include <cassert>

#include "ConteneurTD.h"

using namespace std;

void initialiser(ConteneurTD& c, unsigned int capa) {
	assert(capa>0);
	c.capacite = capa;
	c.tab = new Item[capa];	
}

void detruire(ConteneurTD& c) {
	delete [] c.tab;
	c.tab = NULL;
}

 Item lire(const ConteneurTD& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

void ecrire(ConteneurTD& c, unsigned int i, const Item& it) {
	assert(i < c.capacite);
	c.tab[i] = it;
}
