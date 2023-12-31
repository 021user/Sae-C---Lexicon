#include <cassert>
#include <random>

struct Carte 
{
    int point; 
    char* attribut;
};

struct Pile 
{
    unsigned int capacite;
    Carte** tab;
    int sommet;
};

void initialiser(Pile& pile, unsigned int c) 
{
    assert(c > 0);
    char * Cartes[51] = {"A", "A", "B", "B", "C", "C", "D", "D", "E", "E","E","E","E","E","F","G","G","H","H","I","I","I","I","J","K","L","M","N","N","N","O","O","P","Q","R","R","R","S","S","S","T","T","T","U","U","U","V","W","X","Y","Z"};
    int Points[51] = {2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 6, 7, 8, 8, 9, 9, 1, 1, 1, 1, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    pile.capacite = c;
    pile.tab = new Carte*[c];
    pile.sommet = -1;

    for (unsigned int i = 0; i < c; ++i) 
    {
        pile.tab[i] = new Carte;
        pile.tab[i]->attribut = Cartes[i];
        pile.tab[i]->point = Points[i];
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
initialiser(pileDynamique, 0); // Initialise la pile avec une capacité de 0
    
}

void detruire(Pile& pile)
{
    for(unsigned int i = 0; i < pile.capacite; ++i)
    {
        delete pile.tab[i];
    }
    delete[] pile.tab;
    pile.tab = nullptr;
}

void melange(Pile& pile) {
    srand(time(NULL));
    for (int i = pile.capacite - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Carte* temp = pile.tab[i];
        pile.tab[i] = pile.tab[j];
        pile.tab[j] = temp;
    }
}

