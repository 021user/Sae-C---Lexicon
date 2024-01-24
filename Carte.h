#include <iostream>
#include <cstdlib>
#ifndef CARTE_H
#define CARTE_H
struct Carte 
{
    int point; 
    char valeur;
};

struct Pile 
{
    unsigned int capacite;
    Carte** tab;
    int sommet;
};

// Prototypes des fonctions
void initialiser(Pile& pile, unsigned int c);

void detruire(Pile& pile);

void melange(Pile& pile);

void ajouterCarte(Pile& pile, Carte* nouvelleCarte);
void transfererCarteSommet(Pile& pileSource, Pile& pileDestination);
Carte* retirerCarte(Pile& pile);
#endif // CARTE_H



