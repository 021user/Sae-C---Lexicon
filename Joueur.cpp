struct Joueur
{
    int NoOrdre;
    int main;
    bool malus = false;

};

struct Joueurs
{
    unsigned int nbJoueurs;
    Joueur** joueurs;
};

void initialiser(Joueurs& j, unsigned int c){
    j.nbJoueurs = c;
    j.joueurs = new Joueur* [c];
    for (unsigned int i = 0; i < c; i++)
    {
        Joueur* joueur = new Joueur;
        joueur->NoOrdre = i;
        //faire main joueur
        j.joueurs[i] = joueur;
    }
};

void detruire(Joueurs& j){
    for (unsigned int i = 0; i < j.nbJoueurs; i++)
    {
        delete j.joueurs[i];
        j.joueurs[i] = nullptr;
    } 
    delete[] j.joueurs;
    j.joueurs = nullptr;
}; 