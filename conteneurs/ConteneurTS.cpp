#include <cassert>

#include "ConteneurTS.h"

/**
 * @file ConteneurTS.cpp
 * @brief Composant d'un conteneur d'items de capacité statique (connue à la compilation).
 */

void initialiser(ConteneurTS& c) {
	c.nbItems = 0;
}

Item lire(const ConteneurTS& c, unsigned int i) {
	assert(i < c.nbItems);
	return c.tab[i];
}

void ecrire(ConteneurTS& c, unsigned int i, const Item& item) {
	assert(i <= c.nbItems && i < ConteneurTS::CAPACITE);
	c.tab[i] = item;
	if (i == c.nbItems)
		c.nbItems++;
}
