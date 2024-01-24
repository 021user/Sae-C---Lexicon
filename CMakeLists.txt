cmake_minimum_required(VERSION 3.26)
project(Sae_C___Lexicon)

set(CMAKE_CXX_STANDARD 23)

add_executable(Sae_C___Lexicon main.cpp
        Joueurs.cpp
        Joueurs.h
        Carte.h
        Carte.cpp
        Joueur.h
        Plateau.cpp
        Plateau.h
)
