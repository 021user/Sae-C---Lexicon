#include <Carte.cpp> // on inclut Carte.
#include <Pile.cpp> // on inclut Pile.

struct Joueur // structure d'un joueur
{
    int id; // numéro d'ordre
    Carte** mains; // tableau de cartes
    bool malus = false; // malus ou pas
    int nbCartes; // nombre de cartes
};

struct Joueurs // tableau de joueurs
{
    unsigned int nbJoueurs; // nombre de joueurs
    Joueur** joueurs; // tableau de joueurs
};

void initialiser(Joueurs& j, unsigned int c) // c = nombre de joueurs 
{
    j.nbJoueurs = c; // nombre de joueurs
    j.joueurs = new Joueur* [c]; // tableau de joueurs
    for (unsigned int i = 0; i < c; i++) // pour chaque joueur 
    {
        Joueur* joueur = new Joueur; 
        joueur->id = i; // change "NoOrdre" to "id"
        joueur->mains = new Carte* [10]; // 10 cartes par joueur
        joueur->nbCartes = 0; // 0 cartes au début
        j.joueurs[i] = joueur; // on met le joueur dans le tableau de joueurs
    }
};

void detruire(Joueurs& j) // détruit les joueurs
{
    for (unsigned int i = 0; i < j.nbJoueurs; i++) // pour chaque joueur
    {
        delete[] j.joueurs[i]->mains; // on détruit les mains
        delete j.joueurs[i]; // on détruit le joueur
        j.joueurs[i] = nullptr; // on met le joueur à nullptr
    } 
    delete[] j.joueurs; // on détruit le tableau de joueurs
    j.joueurs = nullptr; // on met le tableau de joueurs à nullptr
}; 

// Gestions des malus
void gererMalus(Joueur* joueur) {
    if (joueur->malus) {
        // Ajoutez le code pour gérer le malus ici
    }
}


void afficherSituation(Joueur& joueur, Carte& carteExposee, std::vector<std::string>& mots) {
    std::cout << "C'est au tour du joueur " << joueur.id << " de jouer.\n";
    std::cout << "La carte exposée est : " << carteExposee.attribut << "\n";
    std::cout << "Les cartes détenues par ce joueur sont : ";
    for (int i = 0; i < joueur.nbCartes; ++i) {
        std::cout << joueur.mains[i]->attribut << " ";
    }
    std::cout << "\n";
    std::cout << "Les mots posés sur la table sont : \n";
    for (int i = 0; i < mots.size(); ++i) {
        std::cout << i+1 << ". " << mots[i] << "\n";
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
            // Vérifiez que le joueur a la lettre, puis déplacez la carte du talon à la main du joueur
            break;
        }
        case 'E': {
            char lettre = coup[2];
            // Vérifiez que le joueur a la lettre, puis échangez la carte avec la carte exposée
            break;
        }
        case 'P': {
            char* mot = &coup[2];
            // Vérifiez que le joueur a toutes les lettres du mot, puis posez le mot sur la table
            break;
        }
        case 'R': {
            int numero = coup[2] - '0';
            char* mot = &coup[4];
            // Vérifiez que le joueur peut construire le nouveau mot, puis remplacez le mot sur la table
            break;
        }
        case 'C': {
            int numero = coup[2] - '0';
            char* mot = &coup[4];
            // Vérifiez que le joueur peut construire le nouveau mot, puis complétez le mot sur la table
            break;
        }
        default:
            printf("Coup non reconnu.\n");
    }
}

void afficherSituation(Joueur& joueur, Carte& carteExposee, char cartesJoueur[], char* mots, int numMots) {
    printf("* Joueur %d (%c) ", joueur.id, carteExposee.attribut);
    for (int i = 0; i < joueur.nbCartes; i++) {
        printf("%c", cartesJoueur[i]);
    }
    printf("\n");
    for (int i = 0; i < numMots; i++) {
        printf("%d: %s\n", i + 1, mots[i]);
    }
}

void melange(Pile& pile) {
    // Utilise l'algorithme de Fisher-Yates pour mélanger la pile
    for (int i = pile.sommet; i > 0; i--) {
        int j = rand() % (i + 1);

        // Échange pile.tab[i] et pile.tab[j]
        Carte* temp = pile.tab[i];
        pile.tab[i] = pile.tab[j];
        pile.tab[j] = temp;
    }
}

void tirerCartes(Joueur& joueur, Pile& pile, int nombreCartes) {
    // Assurez-vous qu'il y a assez de cartes dans la pile
    if (pile.sommet + 1 < nombreCartes) {
        printf("Pas assez de cartes dans la pile\n");
        return;
    }

    // Ajoute les cartes à la main du joueur
    for (int i = 0; i < nombreCartes; i++) {
        joueur.mains[i] = pile.tab[pile.sommet];
        pile.sommet--;
    }
}
