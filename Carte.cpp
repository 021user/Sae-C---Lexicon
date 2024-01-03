// DP : on commence par inclure les fichiers d'ent�te de la biblioth�que standard
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
        // DP : si pile.sommet n'est pas incr�ment�, la pile reste vide
        // DP : tu devrais employer la fonction empiler pour remplir la pile...
    }

    // Cr�ation de la pile statique (cach�e) qui est initialis�e � 52
    Carte* pileStatique[52];
    for (int i = 0; i < 52; ++i) {
        pileStatique[i] = new Carte;
        pileStatique[i]->attribut = Cartes[i]; // On met les cartes dans la pile statique
        pileStatique[i]->point = Points[i]; // On met les points dans la pile statique
    }

    // Cr�ation de la pile dynamique (apparente) qui commence � 0
    Pile pileDynamique;
    // DP : quelle fonction appelles tu ci-dessous ? Nous sommes dans la fonction initialiser !!!
    // DP : une fonction qui s'appelle elle m�me est possible mais cela n'a aucun sens ici !!
    initialiser(pileDynamique, 0); // Initialise la pile avec une capacit� de 0

    // DP : Les variables pileStatique et pileDynamique sont locales � cette fonction et vont disparaitre.

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
    // DP : L'utilisation de std::shuffle est interdite ! L'algorithme de m�lange d'un tableau est donn� sur Moodle et tu dois le programmer !
    // Obtenez un g�n�rateur de nombres al�atoires
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // Utilisez std::shuffle pour m�langer le tableau
    std::shuffle(pile.tab, pile.tab + pile.capacite, generator);
}