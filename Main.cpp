#include <Joueur.cpp>
#include <Pile.cpp>
#include <Carte.cpp>



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
    initialiser(joueur, c); // initialise les joueurs

    
    melange(pilecachee); // mélange les cartes
    tirerCartes(joueur, pilecachee, 7); // tire 7 cartes pour chaque joueur
    while (joueur.mains != 0) 
    {

    }

    // Nettoie la mémoire
    detruire(pileapparente);
    detruire(pilecachee);
    
    return 0;
}
