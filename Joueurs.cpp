#include "Joueurs.h"

void initialiserJoueurs(Joueurs& j, unsigned int c)
{
    if (c < 1 || c > 4) {
        std::cout << "Le nombre de joueurs doit etre entre 1 et 4." << std::endl;
        return;  // Quitte la fonction si le nombre n'est pas valide
    }
    j.nbJoueurs = c;
    j.joueurs = new Joueur*[c];
    for (unsigned int i = 0; i < c; i++)
    {
        Joueur* joueur = new Joueur;
        joueur->id = i + 1;  // Les ID commencent à 1 pour les joueurs
        joueur->nbCartes = Joueur::TAILLE_MAIN;  // Chaque joueur commence avec 10 cartes
        joueur->points = 0;  // Initialiser les points à 0de chaque joueur

        for (int k = 0; k < Joueur::TAILLE_MAIN; k++) // Initialiser chaque carte dans la main du joueur a 10
        {
            joueur->main[k] = Carte{/* valeur appropriée */};  // Remplacer par la logique de création de cartes
        }

        j.joueurs[i] = joueur;  // Stocker le nouveau joueur dans le tableau
    }
}

void detruire(Joueurs& joueurs) {
    // Parcourir chaque joueur
    for (unsigned int i = 0; i < joueurs.nbJoueurs; i++) {
        // Libérer le joueur lui-même
        delete joueurs.joueurs[i];
    }

    // Enfin, libérer le tableau de joueurs
    delete[] joueurs.joueurs;
    joueurs.joueurs = nullptr; // Assurez-vous de définir le pointeur à nullptr après la suppression
}

int compterJoueurs(Joueurs&j) {
    int nbJoueurs = 0;
    for (unsigned int i = 0; i < j.nbJoueurs; i++) {
        if (j.joueurs[i]->nbCartes > 0) {
            nbJoueurs++;
        }
    }
    return nbJoueurs;
}

void afficherEtatJeu(const Joueur& joueur, int indexJoueur, const Carte& carteExposee, const char motsSurTable[][50], int nbMots) {
    // Afficher l'identité du joueur et la carte exposée
    std::cout << "* Joueur " << (indexJoueur + 1) << " (" << carteExposee.valeur << ") ";

    // Afficher les cartes détenues par le joueur
    for (int i = 0; i < joueur.nbCartes; i++) {
        std::cout << joueur.main[i].valeur;
    }
    std::cout << std::endl;

    // Afficher les mots sur la table
    for (int i = 0; i < nbMots; i++) {
        std::cout << i + 1 << " - " << motsSurTable[i] << std::endl;
    }
}


void distribuerCartes(Joueurs& joueurs, Pile& pilecachee) {
    // Assurer que la pile a assez de cartes pour tous les joueurs
    assert(pilecachee.sommet + 1 >= joueurs.nbJoueurs * Joueur::TAILLE_MAIN);

    for (unsigned int i = 0; i < joueurs.nbJoueurs; i++) {
        for (int k = 0; k < Joueur::TAILLE_MAIN; k++) {
            Carte* carte = retirerCarte(pilecachee);  // Retirer une carte du haut de la pile cachee
            if (carte != nullptr) {
                joueurs.joueurs[i]->main[k] = *carte;  // Ajouter la carte à la main du joueur
            }
        }
    }
}

int compterPoints(Joueur* joueur) {
    int score = 0;
    for (int i = 0; i < joueur->nbCartes; i++) {
        score += joueur->main[i].point;
    }
    return score;
}





