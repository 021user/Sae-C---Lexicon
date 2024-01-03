// DP : Tu utilises std::cout mais tu as oubli� d'inclure iostream
#include <iostream> 

#include "Joueur.h"

// DP : 7 est un nombre magique. Les joueurs commencent avec 10 cartes, pas 7.
void initialiser(Joueurs& j, unsigned int c) // c = nombre de joueurs 
{
    j.nbJoueurs = c; // nombre de joueurs
    j.joueurs = new Joueur * [c]; // tableau de joueurs
    for (unsigned int i = 0; i < c; i++) // pour chaque joueur 
    {
        Joueur* joueur = new Joueur;
        joueur->id = i; // change "NoOrdre" to "id"
        joueur->mains = new Carte * [7]; // 10 cartes par joueur
        joueur->nbCartes = 0; // 0 cartes au d�but
        j.joueurs[i] = joueur; // on met le joueur dans le tableau de joueurs
    }
}; // DP : Il y a un point-virgule de trop ici

void detruire(Joueurs& j) // d�truit les joueurs
{
    for (unsigned int i = 0; i < j.nbJoueurs; i++) // pour chaque joueur
    {
        delete[] j.joueurs[i]->mains; // on d�truit les mains
        delete j.joueurs[i]; // on d�truit le joueur
        j.joueurs[i] = nullptr; // on met le joueur � nullptr
    }
    delete[] j.joueurs; // on d�truit le tableau de joueurs
    j.joueurs = nullptr; // on met le tableau de joueurs � nullptr
}; // DP : Il y a un point-virgule de trop ici

// Gestions des malus
void gererMalus(Joueur* joueur) {
    if (joueur->malus) {
        // Ajoutez le code pour g�rer le malus ici
    }
}

int compterJoueurs(Joueur* joueurs, int nombreJoueurs) {
    int compteur = 0;
    for (int i = 0; i < nombreJoueurs; i++) {
        if (joueurs[i].mains != 0) {
            compteur++;
        }
    }
    return compteur;
}

void jouerCoup(char* coup, Joueur& joueur, char mots[], int numMots, Pile& talon, Carte& carteExposee) {
    char action = coup[0];
    switch (action) {
    case 'T': {
        char lettre = coup[2];
        // V�rifiez que le joueur a la lettre, puis d�placez la carte du talon � la main du joueur
        break;
    }
    case 'E': {
        char lettre = coup[2];
        // V�rifiez que le joueur a la lettre, puis �changez la carte avec la carte expos�e
        break;
    }
    case 'P': {
        char* mot = &coup[2];
        // V�rifiez que le joueur a toutes les lettres du mot, puis posez le mot sur la table
        break;
    }
    case 'R': {
        int numero = coup[2] - '0';
        char* mot = &coup[4];
        // V�rifiez que le joueur peut construire le nouveau mot, puis remplacez le mot sur la table
        break;
    }
    case 'C': {
        int numero = coup[2] - '0';
        char* mot = &coup[4];
        // V�rifiez que le joueur peut construire le nouveau mot, puis compl�tez le mot sur la table
        break;
    }
    default:
        printf("Coup non reconnu.\n");
    }
}

void tirerCartes(Joueur& joueur, Pile& pile, int nombreCartes) {
    // Assurez-vous qu'il y a assez de cartes dans la pile
    if (pile.sommet + 1 < nombreCartes) {
        printf("Pas assez de cartes dans la pile\n");
        return;
    }

    // Ajoute les cartes � la main du joueur
    for (int i = 0; i < nombreCartes; i++) {
        joueur.mains[i] = pile.tab[pile.sommet];
        pile.sommet--;
    }
}

int compterJoueurs(Joueurs& joueurs) {
    int count = 0;
    for (unsigned int i = 0; i < joueurs.nbJoueurs; i++) {
        if (joueurs.joueurs[i]->nbCartes > 0) {
            count++;
        }
    }
    return count;
}

// DP : Il faut inclure <iostream> pour pouvoir employer std::cout
void afficherEtatJeu(Joueurs& joueurs, int joueurActuel) {
    std::cout << "* Joueur " << joueurActuel + 1 << " (S) ";
    for (int i = 0; i < joueurs.joueurs[joueurActuel]->nbCartes; i++) {
        Carte* carte = joueurs.joueurs[joueurActuel]->mains[i];
        if (carte) {
            std::cout << carte->attribut; // Use "attribut" to get the card's name
        }
    }
    std::cout << std::endl;
}

void retirerCarte(Joueur* joueur, char attribut) {
    for (int i = 0; i < joueur->nbCartes; i++) {
        // DP : Le champ attribut a �t� chang� en un simple caract�re, il faut adapter le code
//        if (joueur->mains[i]->attribut[0] == attribut) {
        if (joueur->mains[i]->attribut == attribut) {
            // D�placez toutes les cartes apr�s cette carte une position vers la gauche
            for (int j = i; j < joueur->nbCartes - 1; j++) {
                joueur->mains[j] = joueur->mains[j + 1];
            }
            // R�duisez le nombre de cartes du joueur de un
            joueur->nbCartes--;
            // Arr�tez la boucle une fois que vous avez trouv� et retir� la carte
            break;
        }
    }
}

bool carteDansMain(Joueur* joueur, char attribut) {
    for (int i = 0; i < joueur->nbCartes; i++) {
        // DP : Le champ attribut a �t� chang� en un simple caract�re, il faut adapter le code
//        if (joueur->mains[i]->attribut[0] == attribut) {
        if (joueur->mains[i]->attribut == attribut) {
            return true;
        }
    }
    return false;
}

bool peutFormerMot(Joueur* joueur, std::string mot) {
    for (char c : mot) {
        if (!carteDansMain(joueur, c)) {
            return false;
        }
    }
    return true;
}

bool peutChangerMot(Joueur* joueur, std::string motExistant, std::string nouveauMot) {
    // Cr�ez une copie de la main du joueur
    Joueur copieJoueur = *joueur;
    // Retirez les lettres du mot existant de la copie de la main du joueur
    for (char c : motExistant) {
        retirerCarte(&copieJoueur, c);
    }
    // V�rifiez si le joueur peut former le nouveau mot avec les cartes restantes
    return peutFormerMot(&copieJoueur, nouveauMot);
}
