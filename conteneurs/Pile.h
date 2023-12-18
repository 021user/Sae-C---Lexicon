#pragma once

#include "Item.h"

/**
 * @file Pile.h
 * @brief Composant de pile à capacité fixée. 
*/

/// Le type représentant une pile.
struct Pile {
	/// Capacité de la pile (> 0).
	unsigned int capacite;
	/// Tableau des éléments de pile en mémoire dynamique 
	Item* tab; 
	/// Indice de sommet de pile dans tab
	int sommet;  
};

/**
 * @brief Initialiser une pile vide. La pile est allouée en mémoire dynamique.
 * @see detruire, pour une désallocation en fin d’utilisation.
 * @param[out] p La pile à initialiser.
 * @param[in] c Capacité de la pile (nb maximum d‘items stockés). 
 * @pre c > 0.
*/
void initialiser(Pile& p, unsigned int c);

/**
 * @brief Désallouer une pile.
 * @see initialiser, la pile a déjà été initialisée.
 * @param[in,out] p La pile à désallouer.
 */
void detruire(Pile& p);

/**
 * @brief Test de pile pleine.
 * @param[in] p La pile testée
 * @return true si p est pleine, false sinon.
*/
bool estPleine(const Pile& p);

/**
 * @brief Test de pile vide.
 * @param[in] p La pile testée
 * @return true si p est vide, false sinon.
 */
bool estVide(const Pile& p);

/**
 * @brief Obtenir l'item étant au sommet de pile.
 * @param[in] p La pile.
 * @return La valeur de l'item au sommet de pile.
 * @pre La pile n’est pas vide.
*/
Item sommet(const Pile& p);

/**
 * @brief Empiler un item sur une pile.
 * @param[in,out] p La pile.
 * @param[in] it L'item à empiler.
 * @pre La pile n’est pas pleine.
 */
void empiler(Pile& p, const Item& it);

/**
 * @brief Dépiler l’item au sommet de pile.
 * @param[in,out] p La pile.
 * @pre La pile n’est pas vide.
 */
void depiler(Pile& p);
