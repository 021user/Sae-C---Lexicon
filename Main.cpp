#include "Pile.cpp"
#include "Carte.cpp"
#include "Joueur.cpp"


int main()
{
    void initialiser(Pile& j, unsigned int c);
    unsigned int c = 2; // nombre de joueurs 2
    Pile pileapparente; // pile apparente
    initialiser(pileapparente, 10); // initialise la pile apparente
    Pile pilecachee; // pile cachée
    initialiser(pilecachee, 51); // initialise la pile cachée


    void initialiser(Joueur& j, unsigned int c); 
    Joueur joueur; // tableau de joueurs
    std::cout << "(Commandes valides : TEPRC)\n";

    // while (compterJoueurs() > 1) {
        // ...
    //}
    
    while (joueur.mains != 0) 
    {

    }

    // Nettoie la mémoire
    detruire(pileapparente);
    detruire(pilecachee);
    
    return 0;
}
