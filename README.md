GUESBA IYAD
ARIF Imran
Groupe 108



SAE 1.02 
COMPARAISON D’APPROCHES ALGORITHMIQUES







TABLE DES MATIÈRES

But du projet……………………………………………………………………………………….…...2
Graphe de dépendance….……………………………………………………………………….3
Bilan.………………………………………………………………………………………………………...4
Annexe………………………………………………………………………………………………………5

En quoi consiste le projet ? : 

Il s’agit de développer un logiciel permettant à un ensemble de joueurs (2 à 4) de disputer une partie de LEXICON un jeu de lettres des années 30. 

Le logiciel a pour but de gérer le déroulement de la partie jusqu’à l’annonce du gagnant et doit être strictement conforme aux règles du jeu. 

La partie se fait à tour de rôle, chaque joueur reçoit 10 cartes le reste forme une pile face cachée (le talon aussi appelé “la pioche”), la première carte de cette pile est exposée et constitue la première carte de “la pile des cartes exposées” (aussi appelé “l’exposée”). À chaque tour un joueur doit effectuer une et une seule des 4 actions suivantes : 

Échanger une carte par une autre piochée dans le talon ou au sommet de l’exposé (en mettant nécessairement la sienne sur la l’exposée).
Poser des cartes pour former un mot complet existant dans le dictionnaire.
Remplacer une lettre d’un mot déjà posé pour former un nouveau mot en échangeant la lettre posée et celle remplacée.
Compléter un mot en insérant des nouvelles lettres qu’il détient afin de former un nouveau mot.

Le logiciel s’occupe d’initialiser la partie en gérant le mélange des cartes, la distribution de celles-ci, la première carte exposée et affiche la situation actuelle du jeu affichant l’identité du joueur devant jouer le prochain coup (sous la forme Joueur [NUMERO D’ORDRE] de 1 à 4), le sommet de l’exposée, les cartes qu’il détient, la liste numérotée des mots déjà constitués. Puis le joueur doit tapper le coup qu’il souhaite effectuer

Chacun de ces coups se traduit par une de ces commandes 
T LETTRE : Pioche la première carte du talon et en pose une sur l’exposée
E LETTRE : Même chose que celle d’avant mais en piochant la première carte de l’exposé
P MOT : Pose un mot complet grâce aux lettres détenues
R NUMERO MOT : Remplace un mot par un autre en indiquant le NUMERO du mot posé
C NUMERO MOT : Complète un mot désigné par le NUMERO en écrivant le nouveau MOT


La partie prend fin automatiquement lorsque le nombre de joueur restant est moins de deux.

Graphe de dépendance des fichier sources :


Bilan du projet :

Dans le projet plusieurs difficultés ont été rencontrées et notamment le démarrage du projet qui a été assez compliqué concernant la compréhension et le fonctionnement des tableaux dynamiques. Pour les 3 premières commandes ce fut long et laborieux, car nous devions faire attention à la réutilisation de variable qui ne devaient pas être “globale” et celle des attributs des structures ainsi que l’interdiction d’utiliser <stack>, <vector> et <string> ce qui nous a donné du fil à retordre et nous a obligé plusieurs fois à recommencer car rien ne compilait. 

Pour les commandes “R” et “C” nous avons trouvé cela plus simple, en effet nous avions acquis les connaissances nécessaires afin de les coder même si des des erreurs persistent comme la sortie de la commande “C” quand le mot indiqué n’est pas dans le dictionnaire.

Beaucoup de problèmes ont été rencontrés sur la commande “P”, et en particulier des erreurs d’affichage.

De plus, nous n’avons pas pu réaliser la fonction nécessaire au tour (exemple : attribution ID joueur = numéro tour). Nous aurions pu intégrer une boucle à notre boucle principale du jeu, et assimiler l’ID du joueur qui commencerait le tour à un entier que l’on aurait pu incrémenter à la fin de chaque tour de jeu.

Mis à part tout cela nous n’avons pas rencontré de grosses difficultés même si le code demeures incomplet. Cependant le cahier des charges reste en grande partie bien réalisé et la base du jeu et le respect des règles reste fonctionnel.




Annexe programme:
Fichier main :
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Plateau.h"


int main(int argc, const char *argv[]) {
   char motsSurTable[100][50]{};
   int nbMots = 0;
   char commandeLine[100];
   int nbMotsDict;
   char **dictionnaire = chargerDictionnaire("ods4.txt", nbMotsDict);
   std::ifstream fichier("ods4.txt");
   srand(time(nullptr));


   Pile pilecachee;
   initialiser(pilecachee, 51);


   Pile pileapparente;
   initialiser(pileapparente, 0);


   transfererCarteSommet(pilecachee, pileapparente);


   EtatJeu etatJeu;
   Joueurs joueurs;
   Plateau plateau;
   joueurs.nbJoueurs = atoi(argv[1]);
   initialiserPlateau(plateau);
   do {
       std::cin.ignore();
       initialiserJoueurs(joueurs, joueurs.nbJoueurs);
       distribuerCartes(joueurs, pilecachee);
   } while (joueurs.nbJoueurs < 0 || joueurs.nbJoueurs > 4);


   std::cout << "(Commandes valides : TEPRC)\n";


   while (estJeuEnCours(etatJeu) && compterJoueurs(joueurs) > 1) {
       for (unsigned int i = 0; i < joueurs.nbJoueurs; i++) {
           Joueur &joueurActuel = *joueurs.joueurs[i];
           Carte &carteExposee = *pileapparente.tab[pileapparente.sommet];
           afficherEtatJeu(joueurActuel, i, carteExposee, motsSurTable, nbMots);
           if (joueurActuel.nbCartes > 0) {
               std::cout << "> ";
               std::cin.getline(commandeLine, 100);
               char action = commandeLine[0];
               bool possedeCarte = false;


               if (commandeLine[0] == '\0' || commandeLine[1] == '\0' || commandeLine[0] == 'T' || commandeLine[0] == 'E' || commandeLine[0] == 'P' || commandeLine[0] == 'R' || commandeLine[0] == 'C'){
                   std::cout << "Coup invalide, recommencez" << std::endl;
                   i =-1; // Permet au même joueur de rejouer
                   continue;
               }
               if (action == 'T') {
                   if (commandeLine[1] == ' ' && commandeLine[1] == ' ' &&
                       commandeLine[2] >= 'A' &&
                       commandeLine[2] <= 'Z' &&
                       commandeLine[3] == '\0') {
                       commandeLine[3] = '\0';
                       char lettre = commandeLine[2];
                       int indexCarte = -1;
                       for (int k = 0; k < joueurActuel.nbCartes; k++) {
                           if (joueurActuel.main[k].valeur == lettre) {
                               possedeCarte = true;
                               indexCarte = k;
                               break;
                           }
                       }


                       if (possedeCarte) {
                           char valeurTemp = carteExposee.valeur;
                           carteExposee.valeur = joueurActuel.main[indexCarte].valeur;
                           joueurActuel.main[indexCarte].valeur = valeurTemp;


                           for (int j = indexCarte; j < joueurActuel.nbCartes - 1; j++) {
                               joueurActuel.main[j] = joueurActuel.main[j + 1];
                           }
                           joueurActuel.nbCartes--;


                           if (pilecachee.sommet >= 0) {
                               Carte *nouvelleCarte = retirerCarte(pilecachee);
                               joueurActuel.main[joueurActuel.nbCartes] = *nouvelleCarte;
                               joueurActuel.nbCartes++;
                           } else {
                               std::cout << "Coup invalide, recommencez" << std::endl;
                           }
                       } else {
                           std::cout << "Coup invalide, recommencez" << std::endl;
                       }
                   } else {
                       std::cout << "Coup invalide, recommencez" << std::endl;
                   }
               } else if (action == 'E' && commandeLine[1] == ' ' &&
                          commandeLine[2] >= 'A' &&
                          commandeLine[2] <= 'Z' &&
                          commandeLine[3] == '\0') {
                   if (commandeLine[1] == ' ' && commandeLine[2] != '\0') {
                       char lettre = commandeLine[2];
                       bool possedeCarte = false;
                       int indexCarte = -1;


                       for (int k = 0; k < joueurActuel.nbCartes; k++) {
                           if (joueurActuel.main[k].valeur == lettre) {
                               possedeCarte = true;
                               indexCarte = k;
                               break;
                           }
                       }


                       if (possedeCarte) {
                           Carte *ancienneCarteExposee = retirerCarte(pileapparente);
                           if (ancienneCarteExposee != nullptr) {
                               Carte carteJouee = joueurActuel.main[indexCarte];
                               joueurActuel.main[indexCarte] = *ancienneCarteExposee;


                               ajouterCarte(pileapparente, &carteJouee);


                               carteExposee = *pileapparente.tab[pileapparente.sommet];
                           }
                       } else {
                           std::cout << "Coup invalide, recommencez" << std::endl;
                       }
                   } else {
                       std::cout << "Coup invalide, recommencez" << std::endl;
                   }
               } else if (action == 'P') {
                   char *motPropose = &commandeLine[2]; // Le mot proposé commence après le caractère de commande
                   bool hasAllLetters = true;
                   int lettreCount[26] = {0}; // Tableau pour compter les lettres dans le mot proposé


                   // Compter les occurrences de chaque lettre dans le mot proposé
                   for (int i = 0; motPropose[i] != '\0'; i++) {
                       if (motPropose[i] >= 'A' && motPropose[i] <= 'Z') {
                           lettreCount[motPropose[i] - 'A']++;
                       } else {
                           std::cout << "Coup invalide, recommencez" << std::endl;
                           hasAllLetters = false;
                           i =-1; // Permet au même joueur de rejouer
                           continue;
                       }
                   }


                   // Vérifier si le joueur a toutes les lettres nécessaires dans sa main
                   if (hasAllLetters) {
                       for (int k = 0; k < 26; k++) {
                           int countInHand = 0;
                           for (int j = 0; j < joueurActuel.nbCartes; j++) {
                               if (joueurActuel.main[j].valeur == 'A' + k) {
                                   countInHand++;
                               }
                           }
                           if (countInHand < lettreCount[k]) {
                               hasAllLetters = false;
                               std::cout << "Coup invalide, recommencez" << std::endl;
                               i--; // Permet au même joueur de rejouer
                               break; // Sort de la boucle
                           }
                       }
                   }


                   // Vérifier si le mot est dans le dictionnaire
                   if (hasAllLetters && estDansDictionnaire(motPropose, dictionnaire, nbMotsDict)) {
                       strcpy(motsSurTable[nbMots], motPropose);
                       nbMots++;


                       for (int i = 0; i < 26; i++) {
                           while (lettreCount[i] > 0) {
                               for (int j = 0; j < joueurActuel.nbCartes; j++) {
                                   if (joueurActuel.main[j].valeur == 'A' + i) {
                                       for (int k = j; k < joueurActuel.nbCartes - 1; k++) {
                                           joueurActuel.main[k] = joueurActuel.main[k + 1];
                                       }
                                       joueurActuel.nbCartes--;
                                       lettreCount[i]--;
                                       break;
                                   }
                               }
                           }
                       }
                   } else if (hasAllLetters) {
                       // Si le mot n'est pas dans le dictionnaire
                       std::cout << "Mot invalide, passez votre tour" << std::endl;
                       joueurActuel.score += 3; // Pénalité de 3 points au joueur
                   }
               }


               else if (action == 'R') {
                   int numMot;
                   char nouveauMot[26];
                   if (sscanf(commandeLine, "R %d %25s", &numMot, nouveauMot) == 2) {
                       if (numMot > 0 && numMot <= nbMots) {
                           if (estDansDictionnaire(nouveauMot, dictionnaire, nbMotsDict)) {
                               strcpy(plateau.motsSurTable[numMot - 1], nouveauMot);
                           } else {
                               i--; // Permet au même joueur de rejouer
                           }
                       } else {
                           i--; // Permet au même joueur de rejouer
                       }
                   } else {
                       i--; // Permet au même joueur de rejouer
                   }
               }


               else if (action == 'C') {
                   int numMot;
                   char nouveauMot[26];
                   if (sscanf(commandeLine, "C %d %25s", &numMot, nouveauMot) == 2) {
                       if (numMot > 0 && numMot <= nbMots) { // Assurez-vous que l'indice est dans la plage valide
                           if (verifierOrdreLettres(motsSurTable[numMot - 1], nouveauMot) &&
                               estDansDictionnaire(nouveauMot, dictionnaire, nbMotsDict)) {


                               strcpy(motsSurTable[numMot - 1], nouveauMot); // Mise à jour du mot dans motsSurTable


                               // Afficher l'état mis à jour du plateau
                               for (int n = 0; n < nbMots; n++) {
                                   std::cout << n + 1 << " - " << motsSurTable[n] << std::endl;
                               }
                           } else {
                               std::cout << "Coup invalide, recommencez" << std::endl;
                               i--; // Permet au même joueur de rejouer
                           }
                       } else {
                           std::cout << "Coup invalide, recommencez" << std::endl;
                           i--; // Permet au même joueur de rejouer
                       }
                   } else {
                       std::cout << "Coup invalide, recommencez" << std::endl;
                       i--; // Permet au même joueur de rejouer
                   }
               }










           }
           // Verifier si un joueur a termine ses cartes
           if (joueurActuel.nbCartes == 0) {
               for (int j = 0; j < joueurs.nbJoueurs; j++) {
                   if (i != j) {
                       joueurs.joueurs[j]->score += compterPoints(joueurs.joueurs[j]);
                   }
               }
               terminerJeu(etatJeu);
               break;
           }
       }
   }
   if (!estJeuEnCours(etatJeu)) {
       std::cout << "Le tour est fini\n";
       std::cout << "* Scores:\n";


       // Élimination des joueurs ayant 100 points ou plus
       for (int i = 0; i < joueurs.nbJoueurs; i++) {
           if (joueurs.joueurs[i]->score >= 100) {
               std::cout << "Joueur " << i + 1 << " est éliminé avec " << joueurs.joueurs[i]->score << " points\n";
           } else {
               std::cout << "Joueur " << i + 1 << ": " << joueurs.joueurs[i]->score << " points\n";
           }
       }
   }


   // Après la boucle principale du jeu
   if (!estJeuEnCours(etatJeu)) {
       std::cout << "Le tour est fini\n";
       std::cout << "* Scores:\n";
       bool jeuTermine = false;


       for (int i = 0; i < joueurs.nbJoueurs; i++) {
           std::cout << "Joueur " << i + 1 << ": " << joueurs.joueurs[i]->score << " points\n";
           if (joueurs.joueurs[i]->score >= 100) {
               jeuTermine = true;
           }
       }


       if (jeuTermine) {
           std::cout << "La partie est finie\n";


       } else {
           // Réinitialisez l'état du jeu pour le tour suivant si nécessaire
           etatJeu.jeuEnCours = true;
       }




       detruire(joueurs);
       detruire(pileapparente);
       detruire(pilecachee);
       for (int i = 0; i < nbMotsDict; ++i) {
           delete[] dictionnaire[i];
       }
       delete[] dictionnaire;


       return 0;
   }
}

