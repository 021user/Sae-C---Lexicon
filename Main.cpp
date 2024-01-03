// DP : tu utilses std::cout, il faut inclure iostream
#include <iostream>

#include "Carte.h"
#include "Joueur.h"


int main()
{

    unsigned int c = 2; // nombre de joueurs 2

    Pile pileapparente; // pile apparente
    initialiser(pileapparente, 10); // initialise la pile apparente
    melange(pileapparente); // mélange la pile apparente

    Pile pilecachee; // pile cachée
    initialiser(pilecachee, 51); // initialise la pile cachée
    melange(pilecachee); // mélange la pile cachée

    Joueurs joueurs; // tableau de joueurs
    initialiser(joueurs, c); // initialise les joueurs

    std::cout << "(Commandes valides : TEPRC)\n"; // affiche les commandes valides

    while (compterJoueurs(joueurs) > 1) {
        for (unsigned int i = 0; i < joueurs.nbJoueurs; i++) {
            if (joueurs.joueurs[i]->nbCartes > 0) {
                afficherEtatJeu(joueurs, i);
                // DP : Utiliser le type string est interdit. C'est dit dans le sujet !
    //            std::string commande;
                // DP : je le change par une chaine du C
                char commande[100];
                do {
                    std::cout << "Entrez une commande : ";
                    // DP : l'appel qui suit est illégal, je le mets en commentaire
    //                std::getline(std::cin, commande);
                    // DP : Lire une ligne a été vu en TD...
                    std::cin.getline(commande, 100);

                    // Traiter la commande T
                    char lettre = '\0'; // Initialise la lettre à un caractère nul
                    // commande n'est plus de type std::string
    //                for (int j = 2; j < commande.length(); j++) {
                    // DP : on obtient la longueur d'une chaine C avec strlen
                    int longueur = strlen(commande);
                    for (int j = 2; j < longueur; j++) {
                        if (isalpha(commande[j])) { // Vérifie si le caractère est une lettre
                            lettre = commande[j];
                            break;
                        }
                    }
                    // DP : le code qui suit était mal indenté et donc illisible
                    // DP : en l'indentant correctement, on voit vite qu'il y a ... 
                    // DP : ... des else qui ne correspondent à aucun if et que cela ne peut donc pas compiler
                    if (lettre != '\0') { // Vérifie si une lettre a été trouvée
                        // Vérifiez que la lettre est dans la main du joueur, puis effectuez l'action correspondante
                        if (carteDansMain(joueurs.joueurs[i], lettre)) {
                            // Retirez la carte de la main du joueur
                            retirerCarte(joueurs.joueurs[i], lettre);
                        }
                        else {
                            std::cout << "Vous n'avez pas cette carte en main.\n";
                        }
                    }
                    else {
                        std::cout << "Commande invalide. Vous devez spécifier une lettre.\n";
                    }
                } // DP : Cette accolade ferme le do ligne 34... Le reste est mal placé et ne peut pas compiler
                // DP : pour un do, l'accolade fermante doit être suivi par while et une condition
                // DP : j'en rajoute une fictive pour que cela compile
                while (false);
                // DP : Je mets tout un bloc mal placé qui suit en commentaire
                /*
                                else if (commande[0] == 'E') {
                                    // Traiter la commande E
                                    char lettre = commande[2]; // suppose que la lettre est le troisième caractère
                                    // Vérifiez que la lettre est dans la main du joueur, puis effectuez l'action correspondante
                                    if (carteDansMain(joueurs.joueurs[i], lettre)) {
                                        // Retirez la carte de la main du joueur
                                        retirerCarte(joueurs.joueurs[i], lettre);
                                    } else {
                                        std::cout << "Vous n'avez pas cette carte en main.\n";
                                    }
                                    // Ce else ne correspond à aucun if
                                    else if (commande[0] == 'P') {
                                       // Traiter la commande P
                                    char mot[100]; // Assurez-vous que ce tableau est suffisamment grand pour tous les mots possibles
                                    strcpy(mot, commande + 2); // Copie le mot de la commande dans le tableau 'mot'
                                    // Vérifiez que toutes les lettres du mot sont dans la main du joueur, puis effectuez l'action correspondante
                                } else if (commande[0] == 'R') {
                                    // Traiter la commande R
                                    int numero = commande[2] - '0'; // Convertit le troisième caractère en un nombre
                                    char mot[100]; // Assurez-vous que ce tableau est suffisamment grand pour tous les mots possibles
                                    strcpy(mot, commande + 4); // Copie le mot de la commande dans le tableau 'mot'
                                    // Vérifiez que le numéro est valide et que le nouveau mot peut être formé, puis effectuez l'action correspondante
                                } else if (commande[0] == 'C') {
                                    // Traiter la commande C
                                    int numero = commande[2] - '0'; // Convertit le troisième caractère en un nombre
                                    char mot[100]; // Assurez-vous que ce tableau est suffisamment grand pour tous les mots possibles
                                    strcpy(mot, commande + 4); // Copie le mot de la commande dans le tableau 'mot'
                                    // Vérifiez que le numéro est valide et que le nouveau mot peut être formé, puis effectuez l'action correspondante
                                } else {
                                    std::cout << "Commande invalide.\n";
                                }
                */
            }
        }
        // DP : Il manque l'accolade fermante du premier while. J'imagine que c'est ici qu'il faut la mettre
    }
    // Nettoie la mémoire
    detruire(pileapparente);
    detruire(pilecachee);
    detruire(joueurs);
    return 0;
}
