// DP : Les fichiers .h doivent commencer par la ligne suivante
#pragma once

struct Carte 
{
    int point; 
    char attribut; // DP : un caratere suffit (char* transformé en char)
};

struct Pile 
{
    unsigned int capacite;
    Carte** tab;
    int sommet;
};

// DP : On ne met pas de code dans les .h mais uniquement le prototype des fonctions.
// DP : Le code des fonctions doit être dans un .cpp
void initialiser(Pile& pile, unsigned int c);

void detruire(Pile& pile);

void melange(Pile& pile);