#include "Structures/structures.h"
#include "Fonctions/Map/map.h"
#include "Fonctions/Construction/construction.h"
#include "Fonctions/Initialisation/initialisation.h"

void test (City* city){
    initialisationVille(city);
    initDataMap(city);
    //detecterConstruction(city);
    constructionViable(city);
}

int main () {
    City city = {0};
    test(&city);
    return 0;
}