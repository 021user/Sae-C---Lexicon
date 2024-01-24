#ifndef SAE_C___LEXICON_PLATEAU_H
#define SAE_C___LEXICON_PLATEAU_H
#include <fstream>
#include <iostream>
#include "Joueurs.h"
#include <cstring>


const int MAX_MOTS = 100; // Nombre maximal de mots
const int MAX_LETTRES = 50; // Nombre maximal de lettres par mot

struct Plateau {
    char motsSurTable[MAX_MOTS][MAX_LETTRES]; // Tableau pour stocker les mots
    int nbMots; // Nombre de mots actuellement sur le plateau
};

struct EtatJeu {
    unsigned int tourJoueur; // Indice du joueur actuel
    bool jeuEnCours; // État du jeu, vrai tant que le jeu continue
    EtatJeu() : tourJoueur(0), jeuEnCours(true) {}
};
// implémentation des fonctions

void initialiserPlateau(Plateau &plateau);
void afficherEtatJeu(const Joueur& joueur, int indexJoueur, const Carte& carteExposee, const char motsSurTable[][50], int nbMots);
bool estJeuEnCours(const EtatJeu& etat);
void terminerJeu(EtatJeu& etat);
bool remplacerMot(Plateau &plateau, int numeroMot, const char* nouveauMot, Joueur &joueur);
bool lettreDansMot(char lettre, const char* mot);
bool completerMot(Plateau &plateau, int numeroMot, const char* motComplet, Joueur &joueur);
bool verifierOrdreLettres(const char* motOriginal, const char* nouveauMot);
char** chargerDictionnaire(const char* nomFichier, int& nbMots);
bool estDansDictionnaire(const char* mot, char** dictionnaire, int nbMotsDict);
int rechercheBinaire(char** dictionnaire, int nbMotsDict, const char* mot);
#endif //SAE_C___LEXICON_PLATEAU_H
