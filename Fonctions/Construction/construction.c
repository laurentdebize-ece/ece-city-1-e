#include "construction.h"

void detecterConstruction(City *city) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 2) {
                city->route.matriceX = i;
                city->route.matriceY = j;
                //printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->route.nomBlock, city->route.matriceX, city->route.matriceY, city->route.tailleX, city->route.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 3) {
                city->centrale.matriceX = i;
                city->centrale.matriceY = j;
                //printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->centrale.nomBlock, city->centrale.matriceX, city->centrale.matriceY, city->centrale.tailleX, city->centrale.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 4) {
                city->chateauEau.matriceX = i;
                city->chateauEau.matriceY = j;
                //printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->chateauEau.nomBlock, city->chateauEau.matriceX, city->chateauEau.matriceY, city->chateauEau.tailleX, city->chateauEau.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 5) {
                city->ruine.matriceX = i;
                city->ruine.matriceY = j;
                //printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->ruine.nomBlock, city->ruine.matriceX, city->ruine.matriceY, city->ruine.tailleX, city->ruine.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 6) {
                city->cabane.matriceX = i;
                city->cabane.matriceY = j;
                //printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->cabane.nomBlock, city->cabane.matriceX, city->cabane.matriceY, city->cabane.tailleX, city->cabane.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 7) {
                city->maison.matriceX = i;
                city->maison.matriceY = j;
                //printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->maison.nomBlock, city->maison.matriceX, city->maison.matriceY, city->maison.tailleX, city->maison.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 8) {
                city->immeuble.matriceX = i;
                city->immeuble.matriceY = j;
                //printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->immeuble.nomBlock, city->immeuble.matriceX, city->immeuble.matriceY, city->immeuble.tailleX, city->chateauEau.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 9) {
                city->gratteCiel.matriceX = i;
                city->gratteCiel.matriceY = j;
                //printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->gratteCiel.nomBlock, city->gratteCiel.matriceX, city->gratteCiel.matriceY, city->gratteCiel.tailleX, city->gratteCiel.tailleY);
            }
        }
    }
}

void constructionViable(City *city) { //relier à la route
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            //city->route.matriceX, city->route.matriceY
            //city->terrain[i][j].typeBloc == 2
            if (city->terrain[i][j].typeBloc == 3) { //si c'est une centrale
                city->centrale.matriceX = i;
                city->centrale.matriceY = j;
                if (city->centrale.matriceX == city->route.matriceX) {

                }
            }
            if (city->terrain[i][j].typeBloc == 4) { // si c'est chateau d'eau
                city->chateauEau.matriceX = i;
                city->chateauEau.matriceY = j;
            }
        }
    }
}

void viabiliteeElectrique (City *city) {

}

void viabiliteeEau (City *city) {

}




















