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
    //printf("Il y a %d centrale, %d chateau eau et %d habitations", city->centrale.numeroBatiment, city->chateauEau.numeroBatiment, city->nombreBatiment - city->centrale.numeroBatiment - city->chateauEau.numeroBatiment);
}

void coordonneesConstructions(City *city) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 5) {
                city->ruine.matriceX = i;
                city->ruine.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 6) {
                city->cabane.matriceX = i;
                city->cabane.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 7) {
                city->maison.matriceX = i;
                city->maison.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 8) {
                city->immeuble.matriceX = i;
                city->immeuble.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 9) {
                city->gratteCiel.matriceX = i;
                city->gratteCiel.matriceY = j;
            }
        }
    }
}

void nbConstruction(City *city) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 3) {
                city->centrale.numeroBatiment++;
            }
            if (city->terrain[i][j].typeBloc == 4) {
                city->chateauEau.numeroBatiment++;
            }
            if (city->terrain[i][j].typeBloc == 5) {
                city->ruine.numeroBatiment++;
            }
            if (city->terrain[i][j].typeBloc == 6) {
                city->cabane.numeroBatiment++;
            }
            if (city->terrain[i][j].typeBloc == 7) {
                city->maison.numeroBatiment++;
            }
            if (city->terrain[i][j].typeBloc == 8) {
                city->immeuble.numeroBatiment++;
            }
            if (city->terrain[i][j].typeBloc == 9) {
                city->gratteCiel.numeroBatiment++;
            }
        }
    }
    city->centrale.numeroBatiment = city->centrale.numeroBatiment / 24;
    city->chateauEau.numeroBatiment = city->chateauEau.numeroBatiment / 24;
    city->ruine.numeroBatiment = city->ruine.numeroBatiment / 9;
    city->cabane.numeroBatiment = city->cabane.numeroBatiment / 9;
    city->maison.numeroBatiment = city->maison.numeroBatiment / 9;
    city->immeuble.numeroBatiment = city->immeuble.numeroBatiment / 9;
    city->gratteCiel.numeroBatiment = city->gratteCiel.numeroBatiment / 9;

    city->nombreBatiment = (city->centrale.numeroBatiment +
                            city->chateauEau.numeroBatiment + city->ruine.numeroBatiment +
                            city->cabane.numeroBatiment + city->maison.numeroBatiment +
                            city->immeuble.numeroBatiment + city->gratteCiel.numeroBatiment);
}

void getCoordonneConstruction4x6(City *city) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 3) {
                if ((city->terrain[i][(j + 5)].typeBloc == 3) && (city->terrain[i + 4][j].typeBloc != 3) &&
                    (city->terrain[i - 1][j].typeBloc != 3) && (city->terrain[i][j - 1].typeBloc != 3)) {
                    city->centrale.laCoordonneX = i;
                    city->centrale.laCoordonneY = j;
                } else {
                    city->centrale.laCoordonneX = i;
                    city->centrale.laCoordonneY = j + 3;
                }
            }
            if (city->terrain[i][j].typeBloc == 4) {
                if (city->terrain[i][(j + 5)].typeBloc == city->terrain[i][j].typeBloc) {
                    city->chateauEau.laCoordonneX = i - 5;
                    city->chateauEau.laCoordonneY = j;
                } else {
                    city->chateauEau.laCoordonneX = i - 5;
                    city->chateauEau.laCoordonneY = (j + 3);
                }
            }
        }
    }
}

bool constructionViable(City *city, int numeroConstruction) { //relier à la route
    if ((viabiliteeRoute(city, numeroConstruction) == true) &&
        (viabiliteeElectrique(city, numeroConstruction) == true) &&
        (viabiliteeEau(city, numeroConstruction) == true)) {
        return true;
    } else {
        return false;
    }
}

bool viabiliteeRoute(City *city, int numeroConstruction) {
    int coordonneX, coordonneY;
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            // si position numeroConstruction de -1 jusqu'a +1 en i pareil en j
            // si il y a une route alors OUI
            if ((city->terrain[i][j].typeBloc == 3) || (city->terrain[i][j].typeBloc == 4)) {

            }
            if (city->terrain[i][j].typeBloc == 4) {
                for (int k = 0; k < city->centrale.tailleX + 2; k++) {
                    for (int l = 0; l < city->centrale.tailleY + 2; l++) {
                        if (city->terrain[k][l].typeBloc == 2) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
            }
            if (city->terrain[i][j].typeBloc == 5) {
                city->ruine.numeroBatiment++;
            }
            if (city->terrain[i][j].typeBloc == 6) {
                city->cabane.numeroBatiment++;
            }
            if (city->terrain[i][j].typeBloc == 7) {
                city->maison.numeroBatiment++;
            }
            if (city->terrain[i][j].typeBloc == 8) {
                city->immeuble.numeroBatiment++;
            }
            if (city->terrain[i][j].typeBloc == 9) {
                city->gratteCiel.numeroBatiment++;
            }
        }
    }
}

bool viabiliteeElectrique(City *city, int numeroConstruction) {

}

bool viabiliteeEau(City *city, int numeroConstruction) {

}




















