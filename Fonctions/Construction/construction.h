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

bool constructionViable(City *city, int numeroConstruction);

bool viabiliteeRoutiere(City *city, int numeroConstruction);

bool viabiliteeElectrique(City *city, int numeroConstruction);

bool viabiliteeEau(City *city, int numeroConstruction);

#endif
