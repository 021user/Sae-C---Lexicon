// DP : on commence par inclure les fichiers d'entête de la bibliothèque standard
#include <cassert>
#include <random>
#include <algorithm>
#include <chrono>

// DP : puis les siens
#include "Carte.h"

void initialiser(Pile& pile, unsigned int c)
{
    assert(c > 0);
    // DP : 51 est un nombre magique
    // DP : le tableau est un tableau de char et non pas de char*, je change aussi tous les " en '
    char Cartes[51] = { 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E','E','E','E','E','F','G','G','H','H','I','I','I','I','J','K','L','M','N','N','N','O','O','P','Q','R','R','R','S','S','S','T','T','T','U','U','U','V','W','X','Y','Z' };
    int Points[51] = { 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 6, 7, 8, 8, 9, 9, 1, 1, 1, 1, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
    pile.capacite = c;
    pile.tab = new Carte * [c];
    pile.sommet = -1; // DP : la pile est donc vide 

    for (unsigned int i = 0; i < c; ++i)
    {
        pile.tab[i] = new Carte;
        pile.tab[i]->attribut = Cartes[i];
        pile.tab[i]->point = Points[i];
        // DP : si pile.sommet n'est pas incrémenté, la pile reste vide
        // DP : tu devrais employer la fonction empiler pour remplir la pile...
    }

    // Création de la pile statique (cachée) qui est initialisée à 52
    Carte* pileStatique[52];
    for (int i = 0; i < 52; ++i) {
        pileStatique[i] = new Carte;
        pileStatique[i]->attribut = Cartes[i]; // On met les cartes dans la pile statique
        pileStatique[i]->point = Points[i]; // On met les points dans la pile statique
    }

    // Création de la pile dynamique (apparente) qui commence à 0
    Pile pileDynamique;
    // DP : quelle fonction appelles tu ci-dessous ? Nous sommes dans la fonction initialiser !!!
    // DP : une fonction qui s'appelle elle même est possible mais cela n'a aucun sens ici !!
    initialiser(pileDynamique, 0); // Initialise la pile avec une capacité de 0

    // DP : Les variables pileStatique et pileDynamique sont locales à cette fonction et vont disparaitre.

}

void detruire(Pile& pile)
{
    for (unsigned int i = 0; i < pile.capacite; ++i)
    {
        delete pile.tab[i];
    }
    delete[] pile.tab;
    pile.tab = nullptr;
}

void melange(Pile& pile) {
    // DP : L'utilisation de std::shuffle est interdite ! L'algorithme de mélange d'un tableau est donné sur Moodle et tu dois le programmer !
    // Obtenez un générateur de nombres aléatoires
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // Utilisez std::shuffle pour mélanger le tableau
    std::shuffle(pile.tab, pile.tab + pile.capacite, generator);
}