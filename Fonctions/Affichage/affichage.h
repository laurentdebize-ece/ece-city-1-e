#ifndef ECE_CITY_1_E_AFFICHAGE_H
#define ECE_CITY_1_E_AFFICHAGE_H
#include "../../Structures/structures.h"
#include "raylib.h"

#define LARGEUR_ECRAN 1100
#define HAUTEUR_ECRAN 800

void dessinerGrille();

void initBitmap(City *city);
void unloadTexture(City *city);

void initAffichage(City *city);

#endif
