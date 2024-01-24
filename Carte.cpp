#include "Carte.h"


void initialiser(Pile& pile, unsigned int c)
{
    const unsigned int CAPACITE_CARTE = 51;
    const unsigned int CAPACITE_POINT = 51;
    // Utilisation de caractères simples (au lieu de chaînes de caractères) avec des apostrophes
    char Cartes[CAPACITE_CARTE] = { 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'E', 'E', 'E', 'E', 'F', 'G', 'G', 'H', 'H', 'I', 'I', 'I', 'I', 'J', 'K', 'L', 'M', 'N', 'N', 'N', 'O', 'O', 'P', 'Q', 'R', 'R', 'R', 'S', 'S', 'S', 'T', 'T', 'T', 'U', 'U', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    int Points[CAPACITE_POINT] = { 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 6, 7, 8, 8, 9, 9, 1, 1, 1, 1, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
    pile.capacite = c;
    pile.tab = new Carte*[c];
    pile.sommet = -1;

    for (unsigned int i = 0; i < c; ++i)
    {
        pile.tab[i] = new Carte;
        pile.tab[i]->valeur = Cartes[i];
        pile.tab[i]->point = Points[i];
        pile.sommet = i;
    }
    melange(pile);
    pile.sommet = c - 1;
}

void detruire(Pile& pile)
{
    for (unsigned int i = 0; i < pile.capacite; ++i)
    {
        delete pile.tab[i];
        pile.tab[i] = nullptr;
    }
    delete [] pile.tab;
    pile.tab = nullptr;
}

void melange(Pile& pile) {
    Carte** t = pile.tab;
    int nb = pile.sommet; // Index du dernier élément
    for (int i = nb; i > 0; --i) { // i devrait continuer jusqu'à 0 pour inclure le premier élément
        int j = rand() % (i + 1); // Génère un index aléatoire entre 0 et i inclus
        // Échange les cartes à l'index i et j
        Carte* temp = t[i];
        t[i] = t[j];
        t[j] = temp;
    }
}

void ajouterCarte(Pile& pile, Carte* nouvelleCarte) {
    // Vérifier si la pile est pleine et besoin de redimensionner
    if (pile.sommet == pile.capacite - 1) {
        int nouvelleCapacite = pile.capacite * 2;
        Carte** nouveauTab = new Carte*[nouvelleCapacite];

        for (int i = 0; i <= pile.sommet; i++) {
            nouveauTab[i] = pile.tab[i];
        }

        delete[] pile.tab;
        pile.tab = nouveauTab;
        pile.capacite = nouvelleCapacite;
    }

    // Ajouter la carte au sommet de la pile
    pile.sommet++;
    pile.tab[pile.sommet] = nouvelleCarte;
}

void transfererCarteSommet(Pile& source, Pile& destination) {
    Carte* carte = retirerCarte(source);
    if (carte != nullptr) {  // Assurez-vous qu'une carte a été retirée
        ajouterCarte(destination, carte);
    }
}

Carte* retirerCarte(Pile& pile) {
    if (pile.sommet == -1) {
        return nullptr;  // Pile vide
    }
    Carte* carteRetiree = pile.tab[pile.sommet];
    pile.sommet--;
    return carteRetiree;
}


