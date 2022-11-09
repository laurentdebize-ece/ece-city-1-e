#include "map.h"

void initDataMap (City *city) {
    lireFichierTexte ("../txt/map.txt", city);
    /*for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            printf("%d ", city->terrain[i][j].typeBloc);
        }
        printf("\n");
    }*/
    associerFichierAuxBlocs(city);
    /*for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].blocPlein == true) {
                printf("%d ", city->terrain[i][j].typeBloc);
            }else {
                printf("  ");
            }
        }
        printf("\n");
    }*/
}

void associerFichierAuxBlocs (City* city) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 0) { //Herbe
                city->terrain[i][j].blocPlein = false;
            }
            if (city->terrain[i][j].typeBloc == 1) { //Arbre
                city->terrain[i][j].blocPlein = true;
            }
            if (city->terrain[i][j].typeBloc == 2) { //Route
                city->terrain[i][j].blocPlein = false;
            }
            if (city->terrain[i][j].typeBloc == 3) { //Centrale électrique
                city->terrain[i][j].blocPlein = false;
            }
            if (city->terrain[i][j].typeBloc == 4) { //Chateau d'eau
                city->terrain[i][j].blocPlein = true;
            }
            if (city->terrain[i][j].typeBloc == 5) { //Ruines
                city->terrain[i][j].blocPlein = false;
            }
            if (city->terrain[i][j].typeBloc == 6) { //Cabannes
                city->terrain[i][j].blocPlein = false;
            }
            if (city->terrain[i][j].typeBloc == 7) { //Maisons
                city->terrain[i][j].blocPlein = true;
            }
            if (city->terrain[i][j].typeBloc == 8) { //mmeubles
                city->terrain[i][j].blocPlein = false;
            }
            if (city->terrain[i][j].typeBloc == 9) { //Gratte Ciel
                city->terrain[i][j].blocPlein = false;
            }
        }
    }
}