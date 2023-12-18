/**
 * @file File.cpp
 * @brief Composant de file avec capacité paramétrée
 */
 
#include <cassert>
#include "File.h"

void initialiser(File& f, unsigned int capa) {
	assert(capa>0);
	initialiser(f.c, capa);
	f.indPremier = 0;
	f.indProchain = 0;
	f.nb = 0;
}

void detruire(File& f) {
	 detruire(f.c); 
}

bool estPleine(const File& f) {
	return (f.nb == f.c.capacite);  
}

bool estVide(const File& f) {
	return (f.nb == 0);
}

Item tete(const File& f) {
	assert(!estVide(f));
	return lire(f.c, f.indPremier);
}

void entrer(File& f, const Item& it) {
	assert(!estPleine(f));
	ecrire(f.c, f.indProchain, it);
	f.indProchain = (f.indProchain+1)%f.c.capacite;
	f.nb++;
}

void sortir(File& f) {
	assert(!estVide(f));
	f.indPremier = (f.indPremier+1)%f.c.capacite;;
	f.nb--;
}
