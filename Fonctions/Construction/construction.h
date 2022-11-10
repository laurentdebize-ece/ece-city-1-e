#ifndef ECE_CITY_1_E_CONSTRUCTION_H
#define ECE_CITY_1_E_CONSTRUCTION_H

#include "../../Structures/structures.h"

void detecterConstruction (City *city);

void coordonneesConstructions (City *city);
void nbConstruction (City *city);
void nbHabitant (City *city);

void savoirNumeroConstruction (City *city);

void getCoordonneConstruction4x6 (City *city);
void getCoordonneConstruction3x3 (City *city);

bool constructionViable(City *city, int numeroConstruction);

bool viabiliteeRoutiere(City *city, int numeroConstruction);
bool viabiliteeElectrique (City *city, int numeroConstruction);
bool viabiliteeEau (City *city, int numeroConstruction);

#endif
