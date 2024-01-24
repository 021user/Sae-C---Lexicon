#ifndef JOUEUR_H
#define JOUEUR_H
#include "iostream"
#include "Carte.h"

struct Joueur {
    static const int TAILLE_MAIN = 10; // La taille de la main du joueur
    int id; // L'identifiant du joueur
    Carte main[TAILLE_MAIN]; // Un tableau de pointeurs de Carte pour représenter la main du joueur
    bool malus = false;
    int nbCartes;    // Le nombre de cartes dans la main du joueur
    int points;  // Le nombre de points du joueur
    int score;  // Ajoutez cette ligne pour le score
};

// implémentation des fonctions
void initialiserJoueur(Joueur& joueur, unsigned int id);
bool carteDansMain(Joueur& joueur, char attribut);
bool peutFormerMot(Joueur& joueur, const char* mot);
bool peutChangerMot(Joueur& joueur, const char* motExistant, const char* nouveauMot);
void detruireJoueur(Joueur& joueur);
void ajouterCarteALaMain(Joueur& joueur, Carte* carte);
Carte retirerCarteDeMain(Joueur& joueur, char lettre);
#endif //JOUEUR_H