struct Carte
{
int point;
char attribut[];
};

struct base
{
    Carte* tab[51];
    int nbCartes;
};

struct Pile 
{
    unsigned int capacite;
    Carte* tab;
    int sommet;
}Face;

struct Pile 
{
    unsigned int capacite;
    Carte* tab;
    int sommet;
}pile;

void base() 
{
    int nbCartes = 51;
    char * Carte[51] = {"A", "A", "B", "B", "C", "C", "D", "D", "E", "E","E","E","E","E","F","G","G","H","H","I","I","I","I","J","K","L","M","N","N","N","O","O","P","Q","R","R","R","S","S","S","T","T","T","U","U","U","V","W","X","Y","Z"};
};

void initialiser(Pile& p, unsigned int c, Carte* tab)
{
    p.capacite = c;
    p.tab = new Carte;
    p.sommet = 0;
};

void detruire(Pile& p)
{
    delete[] p.tab;
    p.tab = nullptr;
};
