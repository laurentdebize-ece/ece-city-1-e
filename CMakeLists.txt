cmake_minimum_required(VERSION 3.22)
project(ece-city-1-e C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(raylib)

add_executable(ece-city-1-e main.c Structures/structures.c Structures/structures.h Fonctions/Initialisation/initialisation.c Fonctions/Initialisation/initialisation.h txt/fichierTexte.c txt/fichierTexte.h Fonctions/Map/map.c Fonctions/Map/map.h Fonctions/Construction/construction.c Fonctions/Construction/construction.h Fonctions/Electricite/electriciter.c Fonctions/Electricite/electriciter.h Fonctions/Argent/argent.c Fonctions/Argent/argent.h Fonctions/Eau/eau.c Fonctions/Eau/eau.h Fonctions/Sauvegarde/sauvegarde.c Fonctions/Sauvegarde/sauvegarde.h Fonctions/Affichage/affichage.c Fonctions/Affichage/affichage.h Fonctions/Musique/musique.c Fonctions/Musique/musique.h)

target_link_libraries(ece-city-1-e raylib)