// DP : Les fichiers .h doivent commencer par la ligne suivante
#pragma once

// DP : on inclu pas de .cpp et on ne doit employer les chevrons <> que pour les fichiers d'entête de la bibliothèque standard
// DP : je n'ai pas ce fichier Pile.cpp
// DP : le type Pile est défini dans Carte.h, si tu as besoin du type Pile, c'est le fichier qu'il faut inclure.
// DP : je mets l'inclusion en commentaire
// #include <Pile.cpp> // on inclut Pile.

// Tu as besoin du type Carte car tu l'utilises dans la structure Joueur. Il faut donc inclure Carte.h
#include "Carte.h"

struct Joueur // structure d'un joueur
{
    int id; // numéro d'ordre
    Carte** mains; // tableau de cartes
    
    bool malus = false; // malus ou pas
    int nbCartes; // nombre de cartes
};

struct Joueurs // tableau de joueurs
{
    unsigned int nbJoueurs; // nombre de joueurs
    Joueur** joueurs; // tableau de joueurs
};

// DP : On ne met pas de code dans les .h mais uniquement le prototype des fonctions.
// DP : Le code des fonctions doit être dans un .cpp
void initialiser(Joueurs& j, unsigned int c); // c = nombre de joueurs 

void detruire(Joueurs& j); // détruit les joueurs

void gererMalus(Joueur* joueur);

int compterJoueurs(Joueur* joueurs, int nombreJoueurs);

void jouerCoup(char* coup, Joueur& joueur, char mots[], int numMots, Pile& talon, Carte& carteExposee);

void tirerCartes(Joueur& joueur, Pile& pile, int nombreCartes);

int compterJoueurs(Joueurs& joueurs);

void afficherEtatJeu(Joueurs& joueurs, int joueurActuel);

void retirerCarte(Joueur* joueur, char attribut);

bool carteDansMain(Joueur* joueur, char attribut);

bool peutFormerMot(Joueur* joueur, std::string mot);

bool peutChangerMot(Joueur* joueur, std::string motExistant, std::string nouveauMot);
