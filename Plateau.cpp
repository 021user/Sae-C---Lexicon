#include "Plateau.h"
// Constantes pour la gestion du dictionnaire
const int MAX_MOTS_DICT = 400000; // Taille maximale du dictionnaire
const int MAX_LONGUEUR_MOT = 30;  // Longueur maximale d'un mot


void initialiserPlateau(Plateau &plateau) {
    for (int i = 0; i < MAX_MOTS; i++) {
        plateau.motsSurTable[i][0] = '\0';
    }
    plateau.nbMots = 0;
}

bool remplacerMot(Plateau &plateau, int numeroMot, const char *nouveauMot, Joueur &joueur) {
    if (numeroMot >= 0 && numeroMot < plateau.nbMots) {
        int i = 0;
        for (; nouveauMot[i] != '\0' && i < MAX_LETTRES - 1; i++) {
            plateau.motsSurTable[numeroMot][i] = nouveauMot[i];
        }
        plateau.motsSurTable[numeroMot][i] = '\0';
        joueur.nbCartes++;
        return true;
    }
    return false;
}

// fonction pour vérifier si le jeu est toujours en cours
bool estJeuEnCours(const EtatJeu &etat) {
    return etat.jeuEnCours;
}

// Fonction pour terminer le jeu
void terminerJeu(EtatJeu &etat) {
    etat.jeuEnCours = false;
}

bool lettreDansMot(char lettre, const char *mot) {
    int i = 0;
    while (mot[i] != '\0') {
        if (mot[i] == lettre) {
            return true;
        }
        i++;
    }
    return false;
}


bool completerMot(Plateau &plateau, int numeroMot, const char *nouveauMot, Joueur &joueur) {
    if (numeroMot < 0 || numeroMot >= plateau.nbMots) {
        return false; // Numéro de mot invalide
    }

    const char *motOriginal = plateau.motsSurTable[numeroMot];
    int lettreCountJoueur[26] = {0};

    // Compter les lettres dans la main du joueur
    for (int i = 0; i < joueur.nbCartes; i++) {
        lettreCountJoueur[joueur.main[i].valeur - 'A']++;
    }

    // Vérifier si le joueur a les lettres nécessaires
    int i = 0;
    while (nouveauMot[i] != '\0') {
        char lettre = nouveauMot[i] - 'A';
        if (lettreCountJoueur[lettre] > 0) {
            lettreCountJoueur[lettre]--;
        } else if (!lettreDansMot(nouveauMot[i], motOriginal)) {
            return false; // Le joueur n'a pas cette lettre et elle n'est pas dans le mot original
        }
        i++;
    }

    // Vérifier si toutes les lettres du mot original sont utilisées
    i = 0;
    while (motOriginal[i] != '\0') {
        if (!lettreDansMot(motOriginal[i], nouveauMot)) {
            return false; // Une lettre du mot original n'est pas utilisée
        }
        i++;
    }

    // Le joueur peut former le mot, donc mettre à jour le plateau et la main du joueur
    i = 0;
    while (nouveauMot[i] != '\0' && i < MAX_LETTRES - 1) {
        plateau.motsSurTable[numeroMot][i] = nouveauMot[i];
        i++;
    }
    plateau.motsSurTable[numeroMot][i] = '\0';

    // Retirer les lettres utilisées de la main du joueur
    for (int j = 0; j < 26; j++) {
        while (lettreCountJoueur[j] > 0) {
            for (int k = 0; k < joueur.nbCartes; k++) {
                if (joueur.main[k].valeur == 'A' + j) {
                    for (int l = k; l < joueur.nbCartes - 1; l++) {
                        joueur.main[l] = joueur.main[l + 1];
                    }
                    joueur.nbCartes--;
                    break;
                }
            }
            lettreCountJoueur[j]--;
        }
    }

    return true;
}

bool verifierOrdreLettres(const char *motOriginal, const char *nouveauMot) {
    int positionDansOriginal[26] = {0};

    // Marquer la première apparition de chaque lettre dans le mot original
    for (int i = 0; motOriginal[i] != '\0'; ++i) {
        int index = motOriginal[i] - 'A';
        if (positionDansOriginal[index] == 0) {
            positionDansOriginal[index] = i + 1;
        }
    }

    int dernierePosition = -1;

    // Vérifier si chaque lettre du nouveau mot maintient l'ordre relatif
    for (int i = 0; nouveauMot[i] != '\0'; ++i) {
        int index = nouveauMot[i] - 'A';
        if (positionDansOriginal[index] != 0 && positionDansOriginal[index] - 1 < dernierePosition) {
            return false; // Une lettre existante a reculé dans l'ordre
        }
        if (positionDansOriginal[index] != 0) {
            dernierePosition = positionDansOriginal[index] - 1;
        }
    }

    return true;
}



// Fonction pour charger le dictionnaire
char **chargerDictionnaire(const char *nomFichier, int &nbMots) {
    std::ifstream fichier(nomFichier);
    char **dictionnaire = new char *[MAX_MOTS_DICT];
    char mot[MAX_LONGUEUR_MOT];
    nbMots = 0;

    while (fichier >> mot) {
        dictionnaire[nbMots] = new char[strlen(mot) + 1];
        strcpy(dictionnaire[nbMots], mot);
        nbMots++;
    }

    fichier.close();
    return dictionnaire;
}

bool estDansDictionnaire(const char *mot, char **dictionnaire, int nbMotsDict) {
    return rechercheBinaire(dictionnaire, nbMotsDict, mot) != -1;
}


int rechercheBinaire(char **dictionnaire, int nbMotsDict, const char *mot) {
    int gauche = 0;
    int droite = nbMotsDict - 1;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;

        // Comparaison du mot avec le mot au milieu du dictionnaire
        int res = strcmp(dictionnaire[milieu], mot);

        // Si le mot est trouvé
        if (res == 0)
            return milieu;

        // Si le mot est plus grand, ignorer la moitié gauche
        if (res < 0)
            gauche = milieu + 1;

            // Si le mot est plus petit, ignorer la moitié droite
        else
            droite = milieu - 1;
    }

    return -1; // Si le mot n'est pas trouvé
}
