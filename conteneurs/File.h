#pragma once

/**
 * @file File.h
 * @brief Composant de file avec capacité paramétrée.
 */

#include "ConteneurTD.h"

struct File {
	/// Conteneur des éléments de file.
	ConteneurTD c;
	/// Indice de la tête de file.
	unsigned int indPremier;
	/// Indice du prochain élément entré en file.
	unsigned int indProchain;
	/// Nombre d'éléments dans la file.
	unsigned int nb;
};

/**
 * @brief Initialiser une file vide.
 * @param[out] f File à initialiser.
 * @param[in] capa Capacité de la file (nb maximum d‘items stockés).
 * @pre capa > 0.
 */
void initialiser(File& f, unsigned int capa);

/**
* @brief Désallouer une file.
* @param[out] f La file. 
*/
void detruire(File& f);

/**
 * @brief Test de file pleine.
 * @param[in] f File testée.
 * @return true si f est pleine, false sinon.
 */
bool estPleine(const File& f);

/**
 * @brief Test de file vide.
 * @param[in] f File testée.
 * @return true si f est vide, false sinon.
 */
bool estVide(const File& f);

/**
 * @brief Lire l'item en tête de file.
 * @param[in] f La file.
 * @return La valeur de l'item en tête de file.
 * @pre La file n’est pas vide.
 */
Item tete(const File& f);

/**
 * @brief Entrer un item dans la file.
 * @param[in,out] f La file.
 * @param[in] it L'item à entrer.
 * @pre f n’est pas pleine.
 */
void entrer(File& f, const Item& it);

/**
 * @brief Sortir l’item tête de file.
 * @param[in,out] f La file.
 * @pre f n’est pas vide.
 */
void sortir(File& f);
