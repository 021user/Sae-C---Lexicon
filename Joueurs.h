#ifndef SAE_C___LEXICON_JOUEURS_H
#define SAE_C___LEXICON_JOUEURS_H
#include <cassert>
#include "Joueur.h"

struct Joueurs {
    unsigned int nbJoueurs; // Le nombre de joueurs
    Joueur** joueurs;  // tableau de pointeurs de Joueur pour representer les joueurs
};

// implémentation des fonctions
void initialiserJoueurs(Joueurs& j, unsigned int c);
void detruire(Joueurs& joueurs);
int compterJoueurs(Joueurs& j);
void afficherEtatJeu(const Joueur& joueur, int indexJoueur, const Carte& carteExposee, const char motsSurTable[][50], int nbMots);
void distribuerCartes(Joueurs& joueurs, Pile& pilecachee);
int compterPoints(Joueur* joueur);

#endif //SAE_C_LEXICON_JOUEURS_H
