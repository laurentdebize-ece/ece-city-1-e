#include "Structures/structures.h"
#include "Fonctions/Map/map.h"
#include "Fonctions/Construction/construction.h"
#include "Fonctions/Initialisation/initialisation.h"
#include "Fonctions/Electricite/electriciter.h"

void mainAurelien(City *city) {
    alimenteElectricite(city);
}

void mainNino(City *city) {

}

void mainTrystan(City *city) {

}

void mainPL(City *city) {
    initialisationVille(city);
    initDataMap(city);
    //nbHabitant(city);
    //detecterConstruction(city);
    /*printf("Il y a %d centrale, %d chateau eau et %d habitations\n", city->centrale.numeroBatiment, city->chateauEau.numeroBatiment, city->nombreConstruction - city->centrale.numeroBatiment - city->chateauEau.numeroBatiment);
    printf("il y a %d centrales\n", city->centrale.numeroBatiment);
    printf("La coordonnee de la centrale est (%d,%d)\n", city->centrale.laCoordonneX, city->centrale.laCoordonneY);
    printf("La coordonnee du chateau d'eau est (%d,%d)\n", city->chateauEau.laCoordonneX, city->chateauEau.laCoordonneY);
    for (int i = 1 ; i <= city->nombreConstruction ; i++) {
        printf("n°%d : %d\n", i, city->nombreConstruction);
    }
    printf("La ville possède %d de capacité électrique\n", city->centrale.capacite);
    printf("La ville possède %d de capacité d'eau\n", city->chateauEau.capacite);
    }*/

    //printf("Il y a %d contructions\n", city->nombreConstruction);
    /*for (int i = 0; i < city->nombreConstruction; i++) {
        printf("Construction n°%d\n", city->numeroConstruction[i]);
    }*/

    /*if (viabiliteeRoute(city,) == true) {
        printf("OUI route");
    } else if (viabiliteeRoute(city, ) == false) {
        printf("NON route");
    }*/

    //constructionViable(city);

    // ------- Trouver nbHabitant dans la ville ------- //
    //printf("Il y a %d habitations\n", city->nombreHabitation);
    //printf("Dans la ville il y a %d habitants\n", city->nbHabitant);
}

int main() {
    City city = {0};
    mainPL(&city);
    //mainAurelien(&city);
    //mainNino(&city);
    //mainTrystan(&city);
    return 0;
}