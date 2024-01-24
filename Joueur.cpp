#include "Joueur.h"
#include "Carte.h"
#include "Joueurs.h"
#include <iostream>

void initialiserJoueur(Joueur&joueur, unsigned int id) {
    joueur.nbCartes = 0;
    joueur.points = 0;
    joueur.malus = false;
}

void retirerCarteJoueur(Joueur& joueur, char valeurCarte) {
    int indexCarte = -1;
    for (int i = 0; i < joueur.nbCartes; i++) {
        if (joueur.main[i].valeur == valeurCarte) {
            indexCarte = i;
            break;
        }
    }

    if (indexCarte == -1) {
        std::cout << "Carte non trouvée." << std::endl;
        return;
    }

    // Libérer la mémoire de la carte retirée

    // Décaler les cartes restantes
    for (int i = indexCarte; i < joueur.nbCartes - 1; i++) {
        joueur.main[i] = joueur.main[i + 1];
    }

    // Diminuez le nombre de cartes
    joueur.nbCartes--;
}

bool carteDansMain(Joueur& joueur, char attribut) {
    for (int i = 0; i < joueur.nbCartes; i++) {
        if (joueur.main[i].valeur == attribut) {
            return true;
        }
    }
    return false;
}

void ajouterCarteALaMain(Joueur& joueur, Carte* carte) {
    if (joueur.nbCartes < Joueur::TAILLE_MAIN && carte != nullptr) {
        joueur.main[joueur.nbCartes] = *carte;  // Assuming main is an array of Carte
        joueur.nbCartes++;
    } else {
        std::cout << "Main pleine ou carte invalide, impossible d'ajouter la carte." << std::endl;
    }
}


void jouerCarte(Joueur& joueur, char lettre, Pile& pileApparente, Pile& talon) {
    bool possedeCarte = false;
    int indexCarte = -1;
    for (int i = 0; i < joueur.nbCartes; i++) {
        if (joueur.main[i].valeur == lettre) {
            possedeCarte = true;
            indexCarte = i;
            break;
        }
    }
}


Carte retirerCarteDeMain(Joueur& joueur, char lettre) {
    int indexCarte = -1;
    for (int i = 0; i < joueur.nbCartes; i++) {
        if (joueur.main[i].valeur == lettre) {
            indexCarte = i;
            break;
        }
    }

    if (indexCarte == -1) {
        return Carte(); // Retourner une carte vide si la carte n'est pas trouvée
    }

    Carte carteRetiree = joueur.main[indexCarte]; // Sauvegarder la carte retirée

    for (int i = indexCarte; i < joueur.nbCartes - 1; i++) {
        joueur.main[i] = joueur.main[i + 1]; // Décaler les cartes
    }

    joueur.nbCartes--;  // Diminuer le nombre de cartes dans la main

    return carteRetiree;
}


