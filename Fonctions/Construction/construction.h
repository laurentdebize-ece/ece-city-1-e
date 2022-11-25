#ifndef ECE_CITY_1_E_CONSTRUCTION_H
#define ECE_CITY_1_E_CONSTRUCTION_H

#include "../../Structures/structures.h"
#include "../Eau/eau.h"
#include "../Electricite/electriciter.h"

void detecterConstructionPRINTF(City *city);

void nbConstruction(City *city);

void nbHabitant(City *city);

void savoirIndiceConstruction(City *city);

void getCoordonneConstruction4x6(City *city);

void getCoordonneConstruction3x3(City *city);

void poserConstruction(City *city, char *nomFichier);

void parcoursRoute(City *city, int numeroConstructionInitial);

bool constructionViable(City *city, int numeroConstruction);

void ameliorationBatiment(City* city);

bool obstacleHabitation(City *city);

void mettreAJObstacleHabitation(City *city);

void mettreAJHabitationMap(City *city, int type);

bool obstacleAlimentation(City *city);

void mettreAJObstacleAlimentation(City *city);

void mettreAJAlimentationMap(City *city, int type);


bool viabiliteeRoutiere(City *city, int numeroConstruction);

bool viabiliteeRoutiereGraphique(City *city, int type);

bool viabiliteeElectrique(City *city, int numeroConstruction);

bool viabiliteeElectriqueGraphique(City *city, int type);

bool viabiliteeEau(City *city, int numeroConstruction);

bool viabiliteeEauGraphique(City *city, int type);

#endif
