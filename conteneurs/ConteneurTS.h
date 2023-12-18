#pragma once

/**
 * @file ConteneurTS.h
 * @brief Composant d'un conteneur d'items de capacité statique (connue à la compilation).
 */

#include "Item.h"

/** @brief Conteneur (de capacité 15) généralisé à tout type d'item. */
struct ConteneurTS {
	/// Capacité des conteneurs.
	static const unsigned int CAPACITE = 15;
	/// Tableau statique contenant les items.
	Item tab[CAPACITE];	 
	/// Nombre d'items déjà stockés.
	unsigned int nbItems; 
};

/**
 * @brief Initialiser à vide un conteneur.
 * @param[out] c Le conteneur devant être initialisé.
 */
void initialiser(ConteneurTS& c);

/**
 * @brief Récupérer un item étant stocké dans un conteneur.
 * @param[in] c Le conteneur devant être lu.
 * @param[in] i L'indice de l'item dans le conteneur.
 * @return L'item se trouvant à l'indice i dans c.
 * @pre i doit être strictement inférieur au nombre d'items déjà stockés.
 */
Item lire(const ConteneurTS& c, unsigned int i);

/**
 * @brief Stocker un item dans un conteneur.
 * @param[in,out] c Le conteneur où stocker l'item.
 * @param[in] i L'indice où écrire l'item.
 * @param[in] item L'item devant être stocké.
 * @pre L'indice i doit désigner soit une case déjà occupée (et celle-ci sera mise à jour),
 * soit la première case libre (et le conteneur contiendra un item de plus). Dans ce second
 * cas, La capacité du conteneur ne doit pas être dépassée.
 */
void ecrire(ConteneurTS& c, unsigned int i, const Item& item);
