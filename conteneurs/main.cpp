#include <cassert>

#include "ConteneurTS.h"
#include "ConteneurTD.h"
#include "ConteneurTDE.h"
#include "Pile.h"
#include "File.h"
#include "Liste.h"

/** 
* @brief Un programme illustrant les différents conteneurs et structures 
* de données classiques vus en cours, td et tp de SDA.
* Chaque structure a été développée suite à des choix d'implémentation. Ces 
* choix sont souvent arbitraires et conduisent parfois à des limitations. Par exemple,
* les piles et les files ont une capacité maximale stricte décidée lors de l'initialisation.
* Ces choix d'implémentation peuvent être remis en question selon les besoins des utilisateurs.
* Certaines implémentations (File et Liste par exemple) reposent sur d'autres 
* conteneurs (ConteneurTD et ConteneurTDE).
*/
int main() {
	ConteneurTS ts;
	initialiser(ts);
	for (int i = 0; i < 3; ++i)
		ecrire(ts, i, i);
	for (int i = 0; i < 3; ++i)
		assert(lire(ts, i) == i);
	/////////////////////////////////////
	ConteneurTDE tde;
	initialiser(tde, 2, 2);
	for (int i = 0; i < 3; ++i)
		ecrire(tde, i, i);
	for (int i = 0; i < 3; ++i)
		assert(lire(tde, i) == i);
	detruire(tde);
	/////////////////////////////////////
	Pile p;
	initialiser(p, 10);
	assert(estVide(p));
	empiler(p, 7);
	assert(!estVide(p));
	assert(sommet(p) == 7);
	empiler(p, 3);
	assert(!estVide(p));
	assert(sommet(p) == 3);
	depiler(p);
	assert(!estVide(p));
	assert(sommet(p) == 7);
	depiler(p);
	assert(estVide(p));
	detruire(p);
	/////////////////////////////////////
	File f;
	initialiser(f, 3);
	assert(estVide(f));
	assert(!estPleine(f));
	entrer(f, 1);
	assert(!estVide(f));
	assert(!estPleine(f));
	assert(tete(f) == 1);
	entrer(f, 2);
	assert(!estVide(f));
	assert(!estPleine(f));
	assert(tete(f) == 1);
	entrer(f, 3);
	assert(!estVide(f));
	assert(estPleine(f));
	assert(tete(f) == 1);
	sortir(f);
	assert(!estVide(f));
	assert(!estPleine(f));
	assert(tete(f) == 2);
	entrer(f, 4);
	sortir(f);
	assert(!estVide(f));
	assert(!estPleine(f));
	assert(tete(f) == 3);
	sortir(f);
	assert(!estVide(f));
	assert(!estPleine(f));
	assert(tete(f) == 4);
	sortir(f);
	assert(estVide(f));
	detruire(f);
	/////////////////////////////////////
	Liste li;
	initialiser(li, 2, 2);
	for (int i = 0; i < 3; ++i)
		inserer(li, i, i);
	assert(longueur(li) == 3);
	for (int i = 0; i < 3; ++i)
		assert(lire(li, i) == i);
	inserer(li, 0, -1);
	assert(longueur(li) == 4);
	for (int i = 0; i < 4; ++i)
		assert(lire(li, i) == i - 1);
	supprimer(li, 0);
	assert(longueur(li) == 3);
	for (int i = 0; i < 3; ++i)
		assert(lire(li, i) == i);
	detruire(li);
}
