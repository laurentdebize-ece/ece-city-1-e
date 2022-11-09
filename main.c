#include "Structures/structures.h"
#include "Fonctions/Map/map.h"
#include "Fonctions/Construction/construction.h"
#include "Fonctions/Initialisation/initialisation.h"

void test (City* city){
    initialisationVille(city);
    initDataMap(city);

    printf("La coordonnee de la centrale sont (%d,%d)\n", city->centrale.laCoordonneX, city->centrale.laCoordonneY);
    printf("La coordonnee du chateau d'eau sont (%d,%d)\n", city->chateauEau.laCoordonneX, city->chateauEau.laCoordonneY);

    //detecterConstruction(city);
    /*printf("Il y a %d centrale, %d chateau eau et %d habitations\n", city->centrale.numeroBatiment, city->chateauEau.numeroBatiment, city->nombreBatiment - city->centrale.numeroBatiment - city->chateauEau.numeroBatiment);
    for (int i = 1 ; i <= city->nombreBatiment ; i++) {
        printf("n°%d : %d\n", i, city->nombreBatiment);
    }*/

    //constructionViable(city);

    // ------- Trouver nbHabitant dans la ville ------- //
    //printf("Dans la ville il y a %d habitants", city->nbHabitant);
}

int main () {
    City city = {0};
    test(&city);
    return 0;
}