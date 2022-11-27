#ifndef ECE_CITY_1_E_AFFICHAGE_H
#define ECE_CITY_1_E_AFFICHAGE_H
#include "../../Structures/structures.h"
#include "../Construction/construction.h"
#include "../Eau/eau.h"
#include "raylib.h"

#define LARGEUR_ECRAN 1200
#define HAUTEUR_ECRAN 800

void dessinerGrille();

void initBitmap(City *city);
void unloadTexture(City *city);

void initAffichage(City *city);
void affichageBoucle(City *city);

#endif
