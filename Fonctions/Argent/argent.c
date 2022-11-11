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
            if (city->terrain[i][j].typeBloc == 1) {
                city->argent -= city->route.prix;
            }
        }
    }
}

    //if cycle = true
