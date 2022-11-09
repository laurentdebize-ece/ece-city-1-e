#include "map.h"

void initDataMap (City *city) {
    lireFichierTexte ("../txt/map.txt", city);
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            printf("%d ", city->terrain[i][j].typeBloc);
        }
        printf("\n");
    }
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
            if (city->terrain[i][j].typeBloc == 2) {
                city->terrain[i][j].blocPlein = false;
                city->route.nomBlock = "une route";
                city->route.matriceX = i;
                city->route.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 3) {
                city->terrain[i][j].blocPlein = false;
                city->centrale.nomBlock = "une centrale electrique";
                city->centrale.matriceX = i;
                city->centrale.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 4) {
                city->terrain[i][j].blocPlein = true;
                city->chateauEau.nomBlock = "un chateau d'eau";
                city->chateauEau.matriceX = i;
                city->chateauEau.matriceX = i;
                city->chateauEau.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 5) {
                city->terrain[i][j].blocPlein = false;
                city->ruine.nomBlock = "une ruine";
                city->ruine.matriceX = i;
                city->ruine.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 6) {
                city->terrain[i][j].blocPlein = false;
                city->cabane.nomBlock = "une cabane";
                city->cabane.matriceX = i;
                city->cabane.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 7) {
                city->terrain[i][j].blocPlein = true;
                city->maison.nomBlock = "une maison";
                city->maison.matriceX = i;
                city->maison.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 8) {
                city->terrain[i][j].blocPlein = false;
                city->immeuble.nomBlock = "un immeuble";
                city->immeuble.matriceX = i;
                city->immeuble.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 9) {
                city->terrain[i][j].blocPlein = false;
                city->gratteCiel.nomBlock = "un gratte ciel";
                city->gratteCiel.matriceX = i;
                city->gratteCiel.matriceY = j;
            }
        }
    }
}