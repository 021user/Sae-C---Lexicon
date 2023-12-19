#include <cassert>


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

    int *tabdyn; // un tableau dynamique
    tabdyn = new int[10];
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
