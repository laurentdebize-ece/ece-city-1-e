#include "map.h"

void matrice (City *city) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            printf("%d ", city->terrain[i][j].typeBloc);
        }
        printf("\n");
    }
}

void initDataMap (City *city) {
    lireFichierTexte ("../txt/map.txt", city);
    //matrice(city);
    associerFichierAuxBlocs(city);

    getCoordonneConstruction4x6 (city);
    getCoordonneConstruction3x3(city);

    nbConstruction(city);
    nbHabitant(city);

    poserConstruction(city, "../txt/map.txt");

    savoirNumeroConstruction(city);

    //viabiliteeRoutiere(city);
}

void associerFichierAuxBlocs (City* city) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 0) { //Herbe
                city->terrain[i][j].obstacle = false;
            }
            if (city->terrain[i][j].typeBloc == 1) { //Arbre
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 2) {
                city->terrain[i][j].obstacle = false;
                city->route.nomBlock = "une route";
            }
            if (city->terrain[i][j].typeBloc == 3) {
                city->terrain[i][j].obstacle = false;
                city->centrale.nomBlock = "une centrale electrique";
            }
            if (city->terrain[i][j].typeBloc == 4) {
                city->terrain[i][j].obstacle = true;
                city->chateauEau.nomBlock = "un chateau d'eau";
            }
            if (city->terrain[i][j].typeBloc == 5) {
                city->terrain[i][j].obstacle = false;
                city->ruine.nomBlock = "une ruine";
            }
            if (city->terrain[i][j].typeBloc == 6) {
                city->terrain[i][j].obstacle = false;
                city->cabane.nomBlock = "une cabane";
            }
            if (city->terrain[i][j].typeBloc == 7) {
                city->terrain[i][j].obstacle = true;
                city->maison.nomBlock = "une maison";
            }
            if (city->terrain[i][j].typeBloc == 8) {
                city->terrain[i][j].obstacle = false;
                city->immeuble.nomBlock = "un immeuble";
            }
            if (city->terrain[i][j].typeBloc == 9) {
                city->terrain[i][j].obstacle = false;
                city->gratteCiel.nomBlock = "un gratte ciel";
            }
        }
    }
}