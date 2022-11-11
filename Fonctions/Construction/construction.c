#include "construction.h"

void detecterConstructionPRINTF(City *city) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 2) {
                printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->route.nomBlock, city->route.matriceX,
                       city->route.matriceY, city->route.tailleX, city->route.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 3) {
                printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->centrale.nomBlock, city->centrale.matriceX,
                       city->centrale.matriceY, city->centrale.tailleX, city->centrale.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 4) {
                printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->chateauEau.nomBlock, city->chateauEau.matriceX,
                       city->chateauEau.matriceY, city->chateauEau.tailleX, city->chateauEau.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 5) {
                printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->ruine.nomBlock, city->ruine.matriceX,
                       city->ruine.matriceY, city->ruine.tailleX, city->ruine.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 6) {
                printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->cabane.nomBlock, city->cabane.matriceX,
                       city->cabane.matriceY, city->cabane.tailleX, city->cabane.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 7) {
                printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->maison.nomBlock, city->maison.matriceX,
                       city->maison.matriceY, city->maison.tailleX, city->maison.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 8) {
                printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->immeuble.nomBlock, city->immeuble.matriceX,
                       city->immeuble.matriceY, city->immeuble.tailleX, city->chateauEau.tailleY);
            }
            if (city->terrain[i][j].typeBloc == 9) {
                printf("Il y a %s en (%d,%d) de taille %dx%d\n", city->gratteCiel.nomBlock, city->gratteCiel.matriceX,
                       city->gratteCiel.matriceY, city->gratteCiel.tailleX, city->gratteCiel.tailleY);
            }
        }
    }
    //printf("Il y a %d centrale, %d chateau eau et %d habitations", city->centrale.numeroBatiment, city->chateauEau.numeroBatiment, city->nombreConstruction - city->centrale.numeroBatiment - city->chateauEau.numeroBatiment);
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

    city->centrale.capacite = city->centrale.numeroBatiment * city->centrale.capacite;
    city->chateauEau.capacite = city->chateauEau.numeroBatiment * city->chateauEau.capacite;

    city->nombreConstruction = (city->centrale.numeroBatiment +
                                city->chateauEau.numeroBatiment + city->ruine.numeroBatiment +
                                city->cabane.numeroBatiment + city->maison.numeroBatiment +
                                city->immeuble.numeroBatiment + city->gratteCiel.numeroBatiment);
    city->nombreHabitation = (city->ruine.numeroBatiment +
                              city->cabane.numeroBatiment + city->maison.numeroBatiment +
                              city->immeuble.numeroBatiment + city->gratteCiel.numeroBatiment);
}

void nbHabitant(City *city) {
    if (city->cabane.numeroBatiment != 0) {
        city->nbHabitant += city->cabane.nbHabitant * city->cabane.numeroBatiment;
    }
    if (city->maison.numeroBatiment != 0) {
        city->nbHabitant += city->maison.nbHabitant * city->maison.numeroBatiment;
    }
    if (city->immeuble.numeroBatiment != 0) {
        city->nbHabitant += city->immeuble.nbHabitant * city->immeuble.numeroBatiment;
    }
    if (city->gratteCiel.numeroBatiment != 0) {
        city->nbHabitant += city->gratteCiel.nbHabitant * city->gratteCiel.numeroBatiment;
    }
}

// --------------- A FAIRE --------------- //
void savoirNumeroConstruction(City *city) {
    for (int i = 0; i < city->nombreConstruction; i++) {
        //city->numeroConstruction[i];
    }
    //city->numeroConstruction[i];
}
// --------------- A FAIRE --------------- //

void getCoordonneConstruction4x6(City *city) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 3) {
                if ((city->terrain[i][(j + 5)].typeBloc == 3) && (city->terrain[i + 4][j].typeBloc != 3) &&
                    (city->terrain[i - 1][j].typeBloc != 3) && (city->terrain[i][j - 1].typeBloc != 3)) {
                    city->centrale.laCoordonneX = i;
                    city->centrale.laCoordonneY = j;
                } else if ((city->terrain[i][(j + 5)].typeBloc != 3) && (city->terrain[i + 4][j].typeBloc == 3) &&
                           (city->terrain[i - 1][j].typeBloc != 3) && (city->terrain[i][j - 1].typeBloc != 3)) {
                    city->centrale.laCoordonneX = i;
                    city->centrale.laCoordonneY = j + 3;
                }
            }
            if (city->terrain[i][j].typeBloc == 4) {
                if ((city->terrain[i][(j + 5)].typeBloc == 4) && (city->terrain[i + 4][j].typeBloc != 4) &&
                    (city->terrain[i - 1][j].typeBloc != 4) && (city->terrain[i][j - 1].typeBloc != 4)) {
                    city->chateauEau.laCoordonneX = i;
                    city->chateauEau.laCoordonneY = j;
                } else if ((city->terrain[i][(j + 5)].typeBloc != 4) && (city->terrain[i + 4][j].typeBloc == 4) &&
                           (city->terrain[i - 1][j].typeBloc != 4) && (city->terrain[i][j - 1].typeBloc != 4)) {
                    city->chateauEau.laCoordonneX = i;
                    city->chateauEau.laCoordonneY = j + 3;
                }
            }
        }
    }
}

void getCoordonneConstruction3x3(City *city) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 5) {
                city->ruine.laCoordonneX = i;
                city->ruine.laCoordonneY = j;
                city->ruine.matriceX = i;
                city->ruine.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 6) {
                city->cabane.laCoordonneX = i;
                city->cabane.laCoordonneY = j;
                city->cabane.matriceX = i;
                city->cabane.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 7) {
                city->maison.laCoordonneX = i;
                city->maison.laCoordonneY = j;
                city->maison.matriceX = i;
                city->maison.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 8) {
                city->immeuble.laCoordonneX = i;
                city->immeuble.laCoordonneY = j;
                city->immeuble.matriceX = i;
                city->immeuble.matriceY = j;
            }
            if (city->terrain[i][j].typeBloc == 9) {
                city->gratteCiel.laCoordonneX = i;
                city->gratteCiel.laCoordonneY = j;
                city->gratteCiel.matriceX = i;
                city->gratteCiel.matriceY = j;
            }
        }
    }
}

void poserConstruction(City *city, char *nomFichier) {
    FILE *file = fopen(nomFichier, "w+");
    if (!file) {
        printf("Erreur d'écriture fichier\n");
        exit(-1);
    }
    char choix;
    int coordonneeX, coordonneeY;
    printf("Entrez un batiment\n");
    scanf(" %c", &choix);
    printf("coordonnées X : \n");
    scanf(" %d", &coordonneeX);
    printf("coordonnées Y : \n");
    scanf(" %d", &coordonneeY);

    if ((city->terrain[coordonneeX][coordonneeY].typeBloc != 1) ||
        (city->terrain[coordonneeX][coordonneeY + 1].typeBloc != 1) ||
        (city->terrain[coordonneeX][coordonneeY + 2].typeBloc != 1) ||
        (city->terrain[coordonneeX + 1][coordonneeY].typeBloc != 1) ||
        (city->terrain[coordonneeX + 1][coordonneeY + 1].typeBloc != 1) ||
        (city->terrain[coordonneeX + 1][coordonneeY + 2].typeBloc != 1) ||
        (city->terrain[coordonneeX + 2][coordonneeY].typeBloc != 1) ||
        (city->terrain[coordonneeX + 2][coordonneeY + 1].typeBloc != 1) ||
        (city->terrain[coordonneeX + 2][coordonneeY + 2].typeBloc != 1)) {
        switch (choix) {
            case 'r' : {
                city->terrain[coordonneeX][coordonneeY].typeBloc = 5;
                city->terrain[coordonneeX][coordonneeY + 1].typeBloc = 5;
                city->terrain[coordonneeX][coordonneeY + 2].typeBloc = 5;
                city->terrain[coordonneeX + 1][coordonneeY].typeBloc = 5;
                city->terrain[coordonneeX + 1][coordonneeY + 1].typeBloc = 5;
                city->terrain[coordonneeX + 1][coordonneeY + 2].typeBloc = 5;
                city->terrain[coordonneeX + 2][coordonneeY].typeBloc = 5;
                city->terrain[coordonneeX + 2][coordonneeY + 1].typeBloc = 5;
                city->terrain[coordonneeX + 2][coordonneeY + 2].typeBloc = 5;
                break;
            }
            case 'c' : {
                city->terrain[coordonneeX][coordonneeY].typeBloc = 6;
                city->terrain[coordonneeX][coordonneeY + 1].typeBloc = 6;
                city->terrain[coordonneeX][coordonneeY + 2].typeBloc = 6;
                city->terrain[coordonneeX + 1][coordonneeY].typeBloc = 6;
                city->terrain[coordonneeX + 1][coordonneeY + 1].typeBloc = 6;
                city->terrain[coordonneeX + 1][coordonneeY + 2].typeBloc = 6;
                city->terrain[coordonneeX + 2][coordonneeY].typeBloc = 6;
                city->terrain[coordonneeX + 2][coordonneeY + 1].typeBloc = 6;
                city->terrain[coordonneeX + 2][coordonneeY + 2].typeBloc = 6;
                break;
            }
            case 'm' : {
                city->terrain[coordonneeX][coordonneeY].typeBloc = 7;
                city->terrain[coordonneeX][coordonneeY + 1].typeBloc = 7;
                city->terrain[coordonneeX][coordonneeY + 2].typeBloc = 7;
                city->terrain[coordonneeX + 1][coordonneeY].typeBloc = 7;
                city->terrain[coordonneeX + 1][coordonneeY + 1].typeBloc = 7;
                city->terrain[coordonneeX + 1][coordonneeY + 2].typeBloc = 7;
                city->terrain[coordonneeX + 2][coordonneeY].typeBloc = 7;
                city->terrain[coordonneeX + 2][coordonneeY + 1].typeBloc = 7;
                city->terrain[coordonneeX + 2][coordonneeY + 2].typeBloc = 7;
                break;
            }
            case 'i' : {
                city->terrain[coordonneeX][coordonneeY].typeBloc = 8;
                city->terrain[coordonneeX][coordonneeY + 1].typeBloc = 8;
                city->terrain[coordonneeX][coordonneeY + 2].typeBloc = 8;
                city->terrain[coordonneeX + 1][coordonneeY].typeBloc = 8;
                city->terrain[coordonneeX + 1][coordonneeY + 1].typeBloc = 8;
                city->terrain[coordonneeX + 1][coordonneeY + 2].typeBloc = 8;
                city->terrain[coordonneeX + 2][coordonneeY].typeBloc = 8;
                city->terrain[coordonneeX + 2][coordonneeY + 1].typeBloc = 8;
                city->terrain[coordonneeX + 2][coordonneeY + 2].typeBloc = 8;
                break;
            }
            case 'g' : {
                city->terrain[coordonneeX][coordonneeY].typeBloc = 9;
                city->terrain[coordonneeX][coordonneeY + 1].typeBloc = 9;
                city->terrain[coordonneeX][coordonneeY + 2].typeBloc = 9;
                city->terrain[coordonneeX + 1][coordonneeY].typeBloc = 9;
                city->terrain[coordonneeX + 1][coordonneeY + 1].typeBloc = 9;
                city->terrain[coordonneeX + 1][coordonneeY + 2].typeBloc = 9;
                city->terrain[coordonneeX + 2][coordonneeY].typeBloc = 9;
                city->terrain[coordonneeX + 2][coordonneeY + 1].typeBloc = 9;
                city->terrain[coordonneeX + 2][coordonneeY + 2].typeBloc = 9;
                break;
            }
            default : {
                city->terrain[coordonneeX][coordonneeY].typeBloc = 0;
                city->terrain[coordonneeX][coordonneeY + 1].typeBloc = 0;
                city->terrain[coordonneeX][coordonneeY + 2].typeBloc = 0;
                city->terrain[coordonneeX + 1][coordonneeY].typeBloc = 0;
                city->terrain[coordonneeX + 1][coordonneeY + 1].typeBloc = 0;
                city->terrain[coordonneeX + 1][coordonneeY + 2].typeBloc = 0;
                city->terrain[coordonneeX + 2][coordonneeY].typeBloc = 0;
                city->terrain[coordonneeX + 2][coordonneeY + 1].typeBloc = 0;
                city->terrain[coordonneeX + 2][coordonneeY + 2].typeBloc = 0;
            }
        }
    } else {
        printf("Construction impossible OBSTACLE");
    }

    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            fprintf(file, " %d", (city->terrain[i][j].typeBloc));
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

bool constructionViable(City *city, int numeroConstruction) {
    if ((viabiliteeRoutiere(city, numeroConstruction) == true) &&
        (viabiliteeElectrique(city, numeroConstruction) == true) &&
        (viabiliteeEau(city, numeroConstruction) == true)) {
        return true;
    } else {
        return false;
    }
}

// --------------- A FAIRE --------------- //
bool viabiliteeRoutiere(City *city, int numeroConstruction) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            // si position numeroConstruction de -1 jusqu'a +1 en i pareil en j
            // si il y a une route alors OUI
            if ((city->terrain[i][j].typeBloc == 3) || (city->terrain[i][j].typeBloc == 4) ||
                (city->terrain[i][j].typeBloc == 5) || (city->terrain[i][j].typeBloc == 6) ||
                (city->terrain[i][j].typeBloc == 7) || (city->terrain[i][j].typeBloc == 8) ||
                (city->terrain[i][j].typeBloc == 9)) {
                if ((city->terrain[i - 1][j - 1].typeBloc == 2) ||
                    (city->terrain[i + 1][j + 1].typeBloc == 2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool viabiliteeElectrique(City *city, int numeroConstruction) {
    return false;
}

bool viabiliteeEau(City *city, int numeroConstruction) {
    return false;
}
// --------------- A FAIRE --------------- //



















