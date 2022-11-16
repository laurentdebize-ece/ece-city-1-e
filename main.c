#include "Structures/structures.h"
#include "Fonctions/Map/map.h"
#include "Fonctions/Construction/construction.h"
#include "Fonctions/Initialisation/initialisation.h"
#include "Fonctions/Electricite/electriciter.h"
#include "Fonctions/Eau/eau.h"
#include "Fonctions/Sauvegarde/sauvegarde.h"

void mainAurelien(City *city) {
    alimenteElectricite(city);
}

void mainNino(City *city) {
    initialisationVille(city);
    initDataMap(city);
    for (int i = 0; i < city->nombreConstruction; i++) {
        printf("Construction n°%d est de type %d et de coordonnées (%d,%d)\n",
               city->tabConstruction[i].numeroDesConstructions + 1, city->tabConstruction[i].typeDeConstruction,
               city->tabConstruction[i].coordonneeX, city->tabConstruction[i].coordonneeY);
    }
}

void mainTrystan(City *city) {

}

void mainPL(City *city) {
    initialisationVille(city);
    initDataMap(city);
    //sauvegarderPartie(city, "../txt/map.txt");
    for (int i = 0; i < city->nombreConstruction; i++) {
        printf("La construction n°%d est de type %d, à pour coordonnées (%d,%d)", i,
               city->tabConstruction[i].typeDeConstruction, city->tabConstruction[i].coordonneeX,
               city->tabConstruction[i].coordonneeY);
        if (viabiliteeRoutiere(city, i)) {
            printf("\t\tVIABLE ROUTE");
        } else if (!viabiliteeRoutiere(city, i)) {
            printf("\t\tNON VIABLE ROUTE");
        }
        if (viabiliteeElectrique(city, i)) {
            printf("\t\tVIABLE ELECTRIQUE");
        } else if (!viabiliteeElectrique(city, i)) {
            printf("\t\tNON VIABLE ELECTRIQUE");
        }
        if (viabiliteeEau(city, i)) {
            printf("\t\tVIABLE EAU");
        } else if (!viabiliteeEau(city, i)) {
            printf("\t\tNON VIABLE EAU");
        }
        printf("\n");
    }
    for (int i = 0; i < city->nombreConstruction; i++) {
        parcoursRoute(city, i);
    }
}


int main() {
    City city = {0};
    mainPL(&city);
    //mainAurelien(&city);
    //mainNino(&city);
    //mainTrystan(&city);
    return 0;
}