cmake_minimum_required(VERSION 3.22)
project(ece-city-1-e C)

set(CMAKE_C_STANDARD 11)

add_executable(ece-city-1-e main.c Structures/structures.c Structures/structures.h Fonctions/Initialisation/initialisation.c Fonctions/Initialisation/initialisation.h txt/fichierTexte.c txt/fichierTexte.h Fonctions/Map/map.c Fonctions/Map/map.h Fonctions/Construction/construction.c Fonctions/Construction/construction.h)
