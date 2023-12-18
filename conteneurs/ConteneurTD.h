#pragma once

/**
 * @file ConteneurTD.h
 * @brief Composant de conteneur d'items en mémoire dynamique à capacité fixe.
 */

#include "Item.h"

/** @brief Type des conteneurs d'itemes alloués en mémoire dynamique
 *  et de capacité fixe. */ 
struct ConteneurTD {
	/// Capacité du conteneur.
	unsigned int capacite; 	
	/// Tableau d'items alloué en mémoire dynamique.
	Item* tab;				
};

/**
 * @brief Initialise un conteneur d'items vide (allocation dynamique de mémoire - @see detruire pour sa 
 * désallocation en fin d'utilisation). 
 * @param[out] c Conteneur d'items.
 * @param [in] capa Capacité du conteneur.
 * @pre capa > 0
 */
void initialiser(ConteneurTD& c, unsigned int capa);

/**
 * @brief Désalloue un conteneur d'items en mémoire dynamique.
 * @param[out] c Conteneur d'items.
 */
void detruire(ConteneurTD& c);

/**
 * @brief Lecture d'un item d'un conteneur.
 * @param[in] c Conteneur d'items.
 * @param[in] i Indice de l'item à lire.
 * @return L'item se trouvant à la position i dans le conteneur c.
 * @pre i < c.capacite.
 */
 Item lire(const ConteneurTD& c, unsigned int i); 

/**
 * @brief Ecrire un item dans un conteneur d'items.
 * @param[out] c Conteneur d'items.
 * @param[in] i Position où ajouter/modifier l'item.
 * @param[in] item Item à écrire.
 * @pre i < c.capacite.
 */
void ecrire(ConteneurTD& t, unsigned int i, const Item& it);
