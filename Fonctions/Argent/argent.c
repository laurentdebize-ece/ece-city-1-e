#include "argent.h"

void retirerArgent(City * city){
    // en mode graphique -> if click alors -payement batiment
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 5) {
                city->argent -= city->ruine.prix;
            }
            if (city->terrain[i][j].typeBloc == 4) {
                city->argent -= city->chateauEau.prix;
            }
            if (city->terrain[i][j].typeBloc == 3) {
                city->argent -= city->centrale.prix;
            }
            if (city->terrain[i][j].typeBloc == 2) {
                city->argent -= city->route.prix;
            }
        }
    }
}

void argentAJour (City *city, int i) {
    if (city->tabConstruction[i].typeDeConstruction == 9) {
        city->argent += 1000 * 10;
    }
    if (city->tabConstruction[i].typeDeConstruction == 8) {
        city->argent += 100 * 10;
    }
    if (city->tabConstruction[i].typeDeConstruction == 7) {
        city->argent += 50 * 10;
    }
    if (city->tabConstruction[i].typeDeConstruction == 6) {
        city->argent += 10 * 10;
    }
    if (city->tabConstruction[i].typeDeConstruction == 5) {
        city->argent += 0 * 10;
    }
}

bool verifierArgent (City *city, int somme) {
    if (city->argent - somme >= 0) {
        return true;
    }
    return false;
}

    //if cycle = true
