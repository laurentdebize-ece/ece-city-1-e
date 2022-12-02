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
            if (city->terrain[i][j].typeBloc == 0) {
                city->terrain[i][j].obstacle = false;
            }
            if (city->terrain[i][j].typeBloc == 1) {
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 2) {
                city->route.numeroBatiment++;
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 3) {
                city->centrale.numeroBatiment++;
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 4) {
                city->chateauEau.numeroBatiment++;
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 5) {
                city->ruine.numeroBatiment++;
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 6) {
                city->cabane.numeroBatiment++;
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 7) {
                city->maison.numeroBatiment++;
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 8) {
                city->immeuble.numeroBatiment++;
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 9) {
                city->gratteCiel.numeroBatiment++;
                city->terrain[i][j].obstacle = true;
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
    city->centrale.capaciteTotal = city->centrale.numeroBatiment * city->centrale.capacite;
    city->chateauEau.capaciteTotal = city->chateauEau.numeroBatiment * city->chateauEau.capacite;
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

void savoirIndiceConstruction(City *city) {
    for (int i = 0; i < city->nombreConstruction; i++) {
        city->tabConstruction[i].numeroDesConstructions = i;
    }
}

void ameliorationBatiment(City *city, int i) {
        if (city->tabConstruction[i].typeDeConstruction == 8) {
            city->nbHabitant -= 100;
            city->nbHabitant += 1000;
            city->tabConstruction[i].typeDeConstruction = 9;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY].typeBloc = 9;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY].typeBloc = 9;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY].typeBloc = 9;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY + 1].typeBloc = 9;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY +
                                                                    1].typeBloc = 9;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY +
                                                                    1].typeBloc = 9;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY + 2].typeBloc = 9;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY +
                                                                    2].typeBloc = 9;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY +
                                                                    2].typeBloc = 9;
        }
        if (city->tabConstruction[i].typeDeConstruction == 7) {
            city->nbHabitant -= 50;
            city->nbHabitant += 100;
            city->tabConstruction[i].typeDeConstruction = 8;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY].typeBloc = 8;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY].typeBloc = 8;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY].typeBloc = 8;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY + 1].typeBloc = 8;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY +
                                                                    1].typeBloc = 8;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY +
                                                                    1].typeBloc = 8;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY + 2].typeBloc = 8;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY +
                                                                    2].typeBloc = 8;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY +
                                                                    2].typeBloc = 8;
        }
        if (city->tabConstruction[i].typeDeConstruction == 6) {
            city->nbHabitant -= 10;
            city->nbHabitant += 50;
            city->tabConstruction[i].typeDeConstruction = 7;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY].typeBloc = 7;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY].typeBloc = 7;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY].typeBloc = 7;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY + 1].typeBloc = 7;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY +
                                                                    1].typeBloc = 7;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY +
                                                                    1].typeBloc = 7;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY + 2].typeBloc = 7;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY +
                                                                    2].typeBloc = 7;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY +
                                                                    2].typeBloc = 7;
        }
        if (city->tabConstruction[i].typeDeConstruction == 5) {
            city->nbHabitant -= 0;
            city->nbHabitant += 10;
            city->tabConstruction[i].typeDeConstruction = 6;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY].typeBloc = 6;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY].typeBloc = 6;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY].typeBloc = 6;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY + 1].typeBloc = 6;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY +
                                                                    1].typeBloc = 6;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY +
                                                                    1].typeBloc = 6;
            city->terrain[city->tabConstruction[i].coordonneeX][city->tabConstruction[i].coordonneeY + 2].typeBloc = 6;
            city->terrain[city->tabConstruction[i].coordonneeX + 1][city->tabConstruction[i].coordonneeY +
                                                                    2].typeBloc = 6;
            city->terrain[city->tabConstruction[i].coordonneeX + 2][city->tabConstruction[i].coordonneeY +
                                                                    2].typeBloc = 6;
    }
}

void getCoordonneConstruction4x6(City *city) {
    int nbConstru = 0;
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 3) {
                if ((city->terrain[i][(j + 5)].typeBloc == 3) && (city->terrain[i + 4][j].typeBloc != 3) &&
                    (city->terrain[i - 1][j].typeBloc != 3) && (city->terrain[i][j - 1].typeBloc != 3)) {
                    city->centrale.laCoordonneX = i;
                    city->centrale.laCoordonneY = j;
                    city->tabConstruction[nbConstru].coordonneeX = i;
                    city->tabConstruction[nbConstru].coordonneeY = j;
                    city->tabConstruction[nbConstru].typeDeConstruction = 3;
                    city->tabConstruction[nbConstru].horizontale = true;
                    city->tabConstruction[nbConstru].compteur=0;
                    city->tabConstruction[nbConstru].tempsPose=0;
                    nbConstru++;
                } else if ((city->terrain[i][(j + 5)].typeBloc != 3) && (city->terrain[i + 4][j].typeBloc == 3) &&
                           (city->terrain[i - 1][j].typeBloc != 3) && (city->terrain[i][j - 1].typeBloc != 3)) {
                    city->centrale.laCoordonneX = i;
                    city->centrale.laCoordonneY = j + 3;
                    city->tabConstruction[nbConstru].coordonneeX = i;
                    city->tabConstruction[nbConstru].coordonneeY = j + 3;
                    city->tabConstruction[nbConstru].typeDeConstruction = 3;
                    city->tabConstruction[nbConstru].horizontale = false;
                    city->tabConstruction[nbConstru].compteur=0;
                    city->tabConstruction[nbConstru].tempsPose=0;
                    nbConstru++;
                }
            }
            if (city->terrain[i][j].typeBloc == 4) {
                if ((city->terrain[i][(j + 5)].typeBloc == 4) && (city->terrain[i + 4][j].typeBloc != 4) &&
                    (city->terrain[i - 1][j].typeBloc != 4) && (city->terrain[i][j - 1].typeBloc != 4)) {
                    city->chateauEau.laCoordonneX = i;
                    city->chateauEau.laCoordonneY = j;
                    city->tabConstruction[nbConstru].coordonneeX = i;
                    city->tabConstruction[nbConstru].coordonneeY = j;
                    city->tabConstruction[nbConstru].typeDeConstruction = 4;
                    city->tabConstruction[nbConstru].horizontale = true;
                    city->tabConstruction[nbConstru].compteur=0;
                    city->tabConstruction[nbConstru].tempsPose=0;
                    nbConstru++;
                } else if ((city->terrain[i][(j + 5)].typeBloc != 4) && (city->terrain[i + 4][j].typeBloc == 4) &&
                           (city->terrain[i - 1][j].typeBloc != 4) && (city->terrain[i][j - 1].typeBloc != 4)) {
                    city->chateauEau.laCoordonneX = i;
                    city->chateauEau.laCoordonneY = j + 3;
                    city->tabConstruction[nbConstru].coordonneeX = i;
                    city->tabConstruction[nbConstru].coordonneeY = j + 3;
                    city->tabConstruction[nbConstru].typeDeConstruction = 4;
                    city->tabConstruction[nbConstru].horizontale = false;
                    city->tabConstruction[nbConstru].compteur=0;
                    city->tabConstruction[nbConstru].tempsPose=0;
                    nbConstru++;
                }
            }
            if (city->terrain[i][j].typeBloc == 5) {
                if ((city->terrain[i][(j + 2)].typeBloc == 5) && (city->terrain[i + 2][j].typeBloc == 5) &&
                    (city->terrain[i - 1][j].typeBloc != 5) && (city->terrain[i][j - 1].typeBloc != 5)) {
                    city->ruine.laCoordonneX = i;
                    city->ruine.laCoordonneY = j;
                    city->ruine.matriceX = i;
                    city->ruine.matriceY = j;
                    city->tabConstruction[nbConstru].coordonneeX = i;
                    city->tabConstruction[nbConstru].coordonneeY = j;
                    city->tabConstruction[nbConstru].typeDeConstruction = 5;
                    city->tabConstruction[nbConstru].compteur=0;
                    city->tabConstruction[nbConstru].tempsPose=0;
                    nbConstru++;
                }
            }
            if (city->terrain[i][j].typeBloc == 6) {
                if ((city->terrain[i][(j + 2)].typeBloc == 6) && (city->terrain[i + 2][j].typeBloc == 6) &&
                    (city->terrain[i - 1][j].typeBloc != 6) && (city->terrain[i][j - 1].typeBloc != 6)) {
                    city->cabane.laCoordonneX = i;
                    city->cabane.laCoordonneY = j;
                    city->cabane.matriceX = i;
                    city->cabane.matriceY = j;
                    city->tabConstruction[nbConstru].coordonneeX = i;
                    city->tabConstruction[nbConstru].coordonneeY = j;
                    city->tabConstruction[nbConstru].typeDeConstruction = 6;
                    city->tabConstruction[nbConstru].compteur=0;
                    city->tabConstruction[nbConstru].tempsPose=0;
                    nbConstru++;
                }
            }
            if (city->terrain[i][j].typeBloc == 7) {
                if ((city->terrain[i][(j + 2)].typeBloc == 7) && (city->terrain[i + 2][j].typeBloc == 7) &&
                    (city->terrain[i - 1][j].typeBloc != 7) && (city->terrain[i][j - 1].typeBloc != 7)) {
                    city->maison.laCoordonneX = i;
                    city->maison.laCoordonneY = j;
                    city->maison.matriceX = i;
                    city->maison.matriceY = j;
                    city->tabConstruction[nbConstru].coordonneeX = i;
                    city->tabConstruction[nbConstru].coordonneeY = j;
                    city->tabConstruction[nbConstru].typeDeConstruction = 7;
                    city->tabConstruction[nbConstru].compteur=0;
                    city->tabConstruction[nbConstru].tempsPose=0;
                    nbConstru++;
                }
            }
            if (city->terrain[i][j].typeBloc == 8) {
                if ((city->terrain[i][(j + 2)].typeBloc == 8) && (city->terrain[i + 2][j].typeBloc == 8) &&
                    (city->terrain[i - 1][j].typeBloc != 8) && (city->terrain[i][j - 1].typeBloc != 8)) {
                    city->immeuble.laCoordonneX = i;
                    city->immeuble.laCoordonneY = j;
                    city->immeuble.matriceX = i;
                    city->immeuble.matriceY = j;
                    city->tabConstruction[nbConstru].coordonneeX = i;
                    city->tabConstruction[nbConstru].coordonneeY = j;
                    city->tabConstruction[nbConstru].typeDeConstruction = 8;
                    city->tabConstruction[nbConstru].compteur=0;
                    city->tabConstruction[nbConstru].tempsPose=0;
                    nbConstru++;
                }
            }
            if (city->terrain[i][j].typeBloc == 9) {
                if ((city->terrain[i][(j + 2)].typeBloc == 9) && (city->terrain[i + 2][j].typeBloc == 9) &&
                    (city->terrain[i - 1][j].typeBloc != 9) && (city->terrain[i][j - 1].typeBloc != 9)) {
                    city->gratteCiel.laCoordonneX = i;
                    city->gratteCiel.laCoordonneY = j;
                    city->gratteCiel.matriceX = i;
                    city->gratteCiel.matriceY = j;
                    city->tabConstruction[nbConstru].coordonneeX = i;
                    city->tabConstruction[nbConstru].coordonneeY = j;
                    city->tabConstruction[nbConstru].typeDeConstruction = 9;
                    city->tabConstruction[nbConstru].compteur=0;
                    city->tabConstruction[nbConstru].tempsPose=0;
                    nbConstru++;
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
                for (int i = coordonneeX; i < coordonneeX + 2; ++i) {
                    for (int j = coordonneeY; j < coordonneeY + 2; ++j) {
                        city->terrain[i][j].nbBatiment = city->nombreConstruction + 1;
                    }
                }
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
                for (int i = coordonneeX; i < coordonneeX + 2; ++i) {
                    for (int j = coordonneeY; j < coordonneeY + 2; ++j) {
                        city->terrain[i][j].nbBatiment = city->nombreConstruction + 1;
                    }
                }
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
                for (int i = coordonneeX; i < coordonneeX + 2; ++i) {
                    for (int j = coordonneeY; j < coordonneeY + 2; ++j) {
                        city->terrain[i][j].nbBatiment = city->nombreConstruction + 1;
                    }
                }
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
                for (int i = coordonneeX; i < coordonneeX + 2; ++i) {
                    for (int j = coordonneeY; j < coordonneeY + 2; ++j) {
                        city->terrain[i][j].nbBatiment = city->nombreConstruction + 1;
                    }
                }
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
                for (int i = coordonneeX; i < coordonneeX + 2; ++i) {
                    for (int j = coordonneeY; j < coordonneeY + 2; ++j) {
                        city->terrain[i][j].nbBatiment = city->nombreConstruction + 1;
                    }
                }
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
        printf("Construction impossible car OBSTACLE");
    }
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            fprintf(file, " %d", (city->terrain[i][j].typeBloc));
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void parcoursRoute(City *city, int numeroConstructionInitial) {
//    city->tabConstruction[i].source = 0;
//    city->tabConstruction[i].destination = 0;
//    city->tabConstruction[i].longueur = 0;
//    city->tabConstruction[i].indiceParcours = 0;
//    city->tabConstruction[i].plusCourt = false;

    while (!city->cabane.type || !city->ruine.type || !city->maison.type || !city->immeuble.type ||
           !city->gratteCiel.type) {
        if ((city->tabConstruction[numeroConstructionInitial].typeDeConstruction == 3) ||
            (city->tabConstruction[numeroConstructionInitial].typeDeConstruction == 4)) {
            if (city->tabConstruction[numeroConstructionInitial].horizontale) {
                for (int i = city->tabConstruction[numeroConstructionInitial].coordonneeX - 1;
                     i <= city->tabConstruction[numeroConstructionInitial].coordonneeX + 4; i++) {
                    for (int j = city->tabConstruction[numeroConstructionInitial].coordonneeY - 1;
                         j <= city->tabConstruction[numeroConstructionInitial].coordonneeY + 6; j++) {
                        if (city->terrain[i][j].typeBloc == 2) {
                            if (!(i == city->tabConstruction[numeroConstructionInitial].coordonneeX - 1 &&
                                  j == city->tabConstruction[numeroConstructionInitial].coordonneeY - 1) &&
                                !(i == city->tabConstruction[numeroConstructionInitial].coordonneeX - 1 &&
                                  j == city->tabConstruction[numeroConstructionInitial].coordonneeY + 6) &&
                                !(i == city->tabConstruction[numeroConstructionInitial].coordonneeX + 4 &&
                                  j == city->tabConstruction[numeroConstructionInitial].coordonneeY - 1) &&
                                !(i == city->tabConstruction[numeroConstructionInitial].coordonneeX + 4 &&
                                  j == city->tabConstruction[numeroConstructionInitial].coordonneeY + 6)) {
                                continue;
                            }
                        }
                    }
                }
            }
            if (!city->tabConstruction[numeroConstructionInitial].horizontale) {
                for (int i = city->tabConstruction[numeroConstructionInitial].coordonneeX - 1;
                     i <= city->tabConstruction[numeroConstructionInitial].coordonneeX + 6; i++) {
                    for (int j = city->tabConstruction[numeroConstructionInitial].coordonneeY - 4;
                         j <= city->tabConstruction[numeroConstructionInitial].coordonneeY + 1; j++) {
                        if (city->terrain[i][j].typeBloc == 2) {
                            if (!(i == city->tabConstruction[numeroConstructionInitial].coordonneeX - 1 &&
                                  j == city->tabConstruction[numeroConstructionInitial].coordonneeY - 4) &&
                                !(i == city->tabConstruction[numeroConstructionInitial].coordonneeX - 1 &&
                                  j == city->tabConstruction[numeroConstructionInitial].coordonneeY + 1) &&
                                !(i == city->tabConstruction[numeroConstructionInitial].coordonneeX + 6 &&
                                  j == city->tabConstruction[numeroConstructionInitial].coordonneeY - 4) &&
                                !(i == city->tabConstruction[numeroConstructionInitial].coordonneeX + 6 &&
                                  j == city->tabConstruction[numeroConstructionInitial].coordonneeY + 1)) {
                                continue;
                            }
                        }
                    }
                }
            }
        }
        if ((city->tabConstruction[numeroConstructionInitial].typeDeConstruction == 5) ||
            (city->tabConstruction[numeroConstructionInitial].typeDeConstruction == 6) ||
            (city->tabConstruction[numeroConstructionInitial].typeDeConstruction == 7) ||
            (city->tabConstruction[numeroConstructionInitial].typeDeConstruction == 8) ||
            (city->tabConstruction[numeroConstructionInitial].typeDeConstruction == 9)) {
            for (int i = city->tabConstruction[numeroConstructionInitial].coordonneeX - 1;
                 i <= city->tabConstruction[numeroConstructionInitial].coordonneeX + 3; i++) {
                for (int j = city->tabConstruction[numeroConstructionInitial].coordonneeY - 1;
                     j <= city->tabConstruction[numeroConstructionInitial].coordonneeY + 3; j++) {
                    if (city->terrain[i][j].typeBloc == 2) {
                        if (!(i == city->tabConstruction[numeroConstructionInitial].coordonneeX - 1 &&
                              j == city->tabConstruction[numeroConstructionInitial].coordonneeY - 1) &&
                            !(i == city->tabConstruction[numeroConstructionInitial].coordonneeX - 1 &&
                              j == city->tabConstruction[numeroConstructionInitial].coordonneeY + 3) &&
                            !(i == city->tabConstruction[numeroConstructionInitial].coordonneeX + 3 &&
                              j == city->tabConstruction[numeroConstructionInitial].coordonneeY - 1) &&
                            !(i == city->tabConstruction[numeroConstructionInitial].coordonneeX + 3 &&
                              j == city->tabConstruction[numeroConstructionInitial].coordonneeY + 3)) {
                            continue;
                        }
                    }
                }
            }
        }
    }

}

bool constructionViable(City *city, int numeroConstruction) {
    if (viabiliteeRoutiere(city, numeroConstruction) &&
        viabiliteeElectrique(city, numeroConstruction) &&
        viabiliteeEau(city, numeroConstruction)) {
        return true;
    }
    return false;
}

bool obstacleHabitation(City *city) {
    if (!city->terrain[city->ligneSurMap][city->colonneSurMap].obstacle
        && !city->terrain[city->ligneSurMap][city->colonneSurMap + 1].obstacle
        && !city->terrain[city->ligneSurMap][city->colonneSurMap + 2].obstacle
        && !city->terrain[city->ligneSurMap + 1][city->colonneSurMap].obstacle
        && !city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 1].obstacle
        && !city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 2].obstacle
        && !city->terrain[city->ligneSurMap + 2][city->colonneSurMap].obstacle
        && !city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 1].obstacle
        && !city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 2].obstacle) {
        return true;
    }
    return false;
}

void faireObstacleAlimentation (City *city) {
    city->terrain[city->ligneSurMap][city->colonneSurMap].obstacle = true;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 1].obstacle = true;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 2].obstacle = true;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 3].obstacle = true;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 4].obstacle = true;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 5].obstacle = true;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap].obstacle = true;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 1].obstacle = true;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 2].obstacle = true;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 3].obstacle = true;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 4].obstacle = true;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 5].obstacle = true;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap].obstacle = true;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 1].obstacle = true;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 2].obstacle = true;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 3].obstacle = true;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 4].obstacle = true;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 5].obstacle = true;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap].obstacle = true;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 1].obstacle = true;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 2].obstacle = true;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 3].obstacle = true;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 4].obstacle = true;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 5].obstacle = true;
}
void faireObstacleHabitation(City *city) {
    city->terrain[city->ligneSurMap][city->colonneSurMap].obstacle = true;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 1].obstacle = true;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 2].obstacle = true;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap].obstacle = true;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 1].obstacle = true;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 2].obstacle = true;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap].obstacle = true;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 1].obstacle = true;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 2].obstacle = true;
}

void faireAlimentationMap (City *city, int type) {
    city->tabConstruction[city->nombreConstruction].typeDeConstruction=type;
    city->tabConstruction[city->nombreConstruction].coordonneeX=city->ligneSurMap;
    city->tabConstruction[city->nombreConstruction].coordonneeY=city->colonneSurMap;
    city->terrain[city->ligneSurMap][city->colonneSurMap].typeBloc = type;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 1].typeBloc = type;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 2].typeBloc = type;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 3].typeBloc = type;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 4].typeBloc = type;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 5].typeBloc = type;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap].typeBloc = type;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 1].typeBloc = type;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 2].typeBloc = type;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 3].typeBloc = type;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 4].typeBloc = type;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 5].typeBloc = type;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap].typeBloc = type;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 1].typeBloc = type;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 2].typeBloc = type;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 3].typeBloc = type;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 4].typeBloc = type;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 5].typeBloc = type;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap].typeBloc = type;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 1].typeBloc = type;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 2].typeBloc = type;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 3].typeBloc = type;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 4].typeBloc = type;
    city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 5].typeBloc = type;

    city->argent -= 100000;
}
void faireHabitationMap (City *city, int type) {
    city->tabConstruction[city->nombreConstruction].compteur=0;
    city->tabConstruction[city->nombreConstruction].tempsPose=city->temps;
    city->tabConstruction[city->nombreConstruction].typeDeConstruction=type;
    city->tabConstruction[city->nombreConstruction].coordonneeX=city->ligneSurMap;
    city->tabConstruction[city->nombreConstruction].coordonneeY=city->colonneSurMap;
    city->terrain[city->ligneSurMap][city->colonneSurMap].typeBloc = type;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 1].typeBloc = type;
    city->terrain[city->ligneSurMap][city->colonneSurMap + 2].typeBloc = type;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap].typeBloc = type;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 1].typeBloc = type;
    city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 2].typeBloc = type;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap].typeBloc = type;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 1].typeBloc = type;
    city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 2].typeBloc = type;

    city->argent -= 1000;
}

bool obstacleAlimentation(City *city) {
    if (!city->terrain[city->ligneSurMap][city->colonneSurMap].obstacle
        && !city->terrain[city->ligneSurMap][city->colonneSurMap + 1].obstacle
        && !city->terrain[city->ligneSurMap][city->colonneSurMap + 2].obstacle
        && !city->terrain[city->ligneSurMap][city->colonneSurMap + 3].obstacle
        && !city->terrain[city->ligneSurMap][city->colonneSurMap + 4].obstacle
        && !city->terrain[city->ligneSurMap][city->colonneSurMap + 5].obstacle
        && !city->terrain[city->ligneSurMap + 1][city->colonneSurMap].obstacle
        && !city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 1].obstacle
        && !city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 2].obstacle
        && !city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 3].obstacle
        && !city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 4].obstacle
        && !city->terrain[city->ligneSurMap + 1][city->colonneSurMap + 5].obstacle
        && !city->terrain[city->ligneSurMap + 2][city->colonneSurMap].obstacle
        && !city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 1].obstacle
        && !city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 2].obstacle
        && !city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 3].obstacle
        && !city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 4].obstacle
        && !city->terrain[city->ligneSurMap + 2][city->colonneSurMap + 5].obstacle
        && !city->terrain[city->ligneSurMap + 3][city->colonneSurMap].obstacle
        && !city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 1].obstacle
        && !city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 2].obstacle
        && !city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 3].obstacle
        && !city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 4].obstacle
        && !city->terrain[city->ligneSurMap + 3][city->colonneSurMap + 5].obstacle
            ) {
        return true;
    }
    return false;
}

bool viabiliteeRoutiere(City *city, int numeroConstruction) {
    if ((city->tabConstruction[numeroConstruction].typeDeConstruction == 3) ||
        (city->tabConstruction[numeroConstruction].typeDeConstruction == 4)) {
        if (city->tabConstruction[numeroConstruction].horizontale) {
            for (int i = city->tabConstruction[numeroConstruction].coordonneeX - 1;
                 i <= city->tabConstruction[numeroConstruction].coordonneeX + 4; i++) {
                for (int j = city->tabConstruction[numeroConstruction].coordonneeY - 1;
                     j <= city->tabConstruction[numeroConstruction].coordonneeY + 6; j++) {
                    if (city->terrain[i][j].typeBloc == 2) {
                        if (!(i == city->tabConstruction[numeroConstruction].coordonneeX - 1 &&
                              j == city->tabConstruction[numeroConstruction].coordonneeY - 1) &&
                            !(i == city->tabConstruction[numeroConstruction].coordonneeX - 1 &&
                              j == city->tabConstruction[numeroConstruction].coordonneeY + 6) &&
                            !(i == city->tabConstruction[numeroConstruction].coordonneeX + 4 &&
                              j == city->tabConstruction[numeroConstruction].coordonneeY - 1) &&
                            !(i == city->tabConstruction[numeroConstruction].coordonneeX + 4 &&
                              j == city->tabConstruction[numeroConstruction].coordonneeY + 6)) {
                            return true;
                        }
                    }
                }
            }
        }
        if (!city->tabConstruction[numeroConstruction].horizontale) {
            for (int i = city->tabConstruction[numeroConstruction].coordonneeX - 1;
                 i <= city->tabConstruction[numeroConstruction].coordonneeX + 6; i++) {
                for (int j = city->tabConstruction[numeroConstruction].coordonneeY - 4;
                     j <= city->tabConstruction[numeroConstruction].coordonneeY + 1; j++) {
                    if (city->terrain[i][j].typeBloc == 2) {
                        if (!(i == city->tabConstruction[numeroConstruction].coordonneeX - 1 &&
                              j == city->tabConstruction[numeroConstruction].coordonneeY - 4) &&
                            !(i == city->tabConstruction[numeroConstruction].coordonneeX - 1 &&
                              j == city->tabConstruction[numeroConstruction].coordonneeY + 1) &&
                            !(i == city->tabConstruction[numeroConstruction].coordonneeX + 6 &&
                              j == city->tabConstruction[numeroConstruction].coordonneeY - 4) &&
                            !(i == city->tabConstruction[numeroConstruction].coordonneeX + 6 &&
                              j == city->tabConstruction[numeroConstruction].coordonneeY + 1)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    if ((city->tabConstruction[numeroConstruction].typeDeConstruction == 2) ||
        (city->tabConstruction[numeroConstruction].typeDeConstruction == 5) ||
        (city->tabConstruction[numeroConstruction].typeDeConstruction == 6) ||
        (city->tabConstruction[numeroConstruction].typeDeConstruction == 7) ||
        (city->tabConstruction[numeroConstruction].typeDeConstruction == 8) ||
        (city->tabConstruction[numeroConstruction].typeDeConstruction == 9)) {
        for (int i = city->tabConstruction[numeroConstruction].coordonneeX - 1;
             i <= city->tabConstruction[numeroConstruction].coordonneeX + 3; i++) {
            for (int j = city->tabConstruction[numeroConstruction].coordonneeY - 1;
                 j <= city->tabConstruction[numeroConstruction].coordonneeY + 3; j++) {
                if (city->terrain[i][j].typeBloc == 2) {
                    if (!(i == city->tabConstruction[numeroConstruction].coordonneeX - 1 &&
                          j == city->tabConstruction[numeroConstruction].coordonneeY - 1) &&
                        !(i == city->tabConstruction[numeroConstruction].coordonneeX - 1 &&
                          j == city->tabConstruction[numeroConstruction].coordonneeY + 3) &&
                        !(i == city->tabConstruction[numeroConstruction].coordonneeX + 3 &&
                          j == city->tabConstruction[numeroConstruction].coordonneeY - 1) &&
                        !(i == city->tabConstruction[numeroConstruction].coordonneeX + 3 &&
                          j == city->tabConstruction[numeroConstruction].coordonneeY + 3)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool viabiliteeRoutiereGraphique(City *city, int type) {
    if (type == 3 || type == 4) {
        for (int i = city->ligneSurMap - 1;
             i <= city->ligneSurMap + 4; i++) {
            for (int j = city->colonneSurMap - 1;
                 j <= city->colonneSurMap + 6; j++) {
                if (city->terrain[i][j].typeBloc == 2) {
                    if (!(i == city->ligneSurMap - 1 &&
                          j == city->colonneSurMap - 1) &&
                        !(i == city->ligneSurMap - 1 &&
                          j == city->colonneSurMap + 6) &&
                        !(i == city->ligneSurMap + 4 &&
                          j == city->colonneSurMap - 1) &&
                        !(i == city->ligneSurMap + 4 &&
                          j == city->colonneSurMap + 6)) {
                        return true;
                    }
                }
            }
        }
    }
    if ((type == 5) || (type == 6) ||
        (type == 7) || (type == 8) || (type == 9)) {
        for (int i = city->ligneSurMap - 1;
             i <= city->ligneSurMap + 3; i++) {
            for (int j = city->colonneSurMap - 1;
                 j <= city->colonneSurMap + 3; j++) {
                if (city->terrain[i][j].typeBloc == 2) {
                    if (!(i == city->ligneSurMap - 1 &&
                          j == city->colonneSurMap - 1) &&
                        !(i == city->ligneSurMap - 1 &&
                          j == city->colonneSurMap + 3) &&
                        !(i == city->ligneSurMap + 3 &&
                          j == city->colonneSurMap - 1) &&
                        !(i == city->ligneSurMap + 3 &&
                          j == city->colonneSurMap + 3)) {
                        return true;
                    }
                }
            }
        }
    }
    if (type == 2) {
        for (int i = city->ligneSurMap - 1;
             i <= city->ligneSurMap + 1; i++) {
            for (int j = city->colonneSurMap - 1;
                 j <= city->colonneSurMap + 1; j++) {
                if (city->terrain[i][j].typeBloc == 2) {
                    if (!(i == city->ligneSurMap - 1 &&
                          j == city->colonneSurMap - 1) &&
                        !(i == city->ligneSurMap - 1 &&
                          j == city->colonneSurMap + 1) &&
                        !(i == city->ligneSurMap + 1 &&
                          j == city->colonneSurMap - 1) &&
                        !(i == city->ligneSurMap + 1 &&
                          j == city->colonneSurMap + 1)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool viabiliteeElectrique(City *city, int numeroConstruction) {
    consommationElectrique(city);
    if (city->tabConstruction[numeroConstruction].typeDeConstruction == 5) {
        if ((city->centrale.flot - city->ruine.nbHabitant) >= 0) {
            return true;
        }
    }
    if (city->tabConstruction[numeroConstruction].typeDeConstruction == 6) {
        if ((city->centrale.flot - city->cabane.nbHabitant) >= 0) {
            return true;
        }
    }
    if (city->tabConstruction[numeroConstruction].typeDeConstruction == 7) {
        if ((city->centrale.flot - city->maison.nbHabitant) >= 0) {
            return true;
        }
    }
    if (city->tabConstruction[numeroConstruction].typeDeConstruction == 8) {
        if ((city->centrale.flot - city->immeuble.nbHabitant) >= 0) {
            return true;
        }
    }
    if (city->tabConstruction[numeroConstruction].typeDeConstruction == 9) {
        if ((city->centrale.flot - city->gratteCiel.nbHabitant) >= 0) {
            return true;
        }
    }
    return false;
}
bool viabiliteeElectriqueGraphique(City *city, int type) {
    consommationElectrique(city);
    if (type == 5) {
        if ((city->centrale.flot - city->ruine.nbHabitant) >= 0) {
            return true;
        }
    }
    if (type == 6) {
        if ((city->centrale.flot - city->cabane.nbHabitant) >= 0) {
            return true;
        }
    }
    if (type == 7) {
        if ((city->centrale.flot - city->maison.nbHabitant) >= 0) {
            return true;
        }
    }
    if (type == 8) {
        if ((city->centrale.flot - city->immeuble.nbHabitant) >= 0) {
            return true;
        }
    }
    if (type == 9) {
        if ((city->centrale.flot - city->gratteCiel.nbHabitant) >= 0) {
            return true;
        }
    }
    return false;
}

bool viabiliteeEau(City *city, int numeroConstruction) {
    consommationEau(city);
    if (city->tabConstruction[numeroConstruction].typeDeConstruction == 5) {
        if ((city->chateauEau.flot - city->ruine.nbHabitant) >= 0) {
            return true;
        }
    }
    if (city->tabConstruction[numeroConstruction].typeDeConstruction == 6) {
        if ((city->chateauEau.flot - city->cabane.nbHabitant) >= 0) {
            return true;
        }
    }
    if (city->tabConstruction[numeroConstruction].typeDeConstruction == 7) {
        if ((city->chateauEau.flot - city->maison.nbHabitant) >= 0) {
            return true;
        }
    }
    if (city->tabConstruction[numeroConstruction].typeDeConstruction == 8) {
        if ((city->chateauEau.flot - city->immeuble.nbHabitant) >= 0) {
            return true;
        }
    }
    if (city->tabConstruction[numeroConstruction].typeDeConstruction == 9) {
        if ((city->chateauEau.flot - city->gratteCiel.nbHabitant) >= 0) {
            return true;
        }
    }
    return false;
}
bool viabiliteeEauGraphique(City *city, int type) {
    consommationEau(city);
    if (type == 5) {
        if ((city->chateauEau.flot - city->ruine.nbHabitant) >= 0) {
            return true;
        }
    }
    if (type == 6) {
        if ((city->chateauEau.flot - city->cabane.nbHabitant) >= 0) {
            return true;
        }
    }
    if (type == 7) {
        if ((city->chateauEau.flot - city->maison.nbHabitant) >= 0) {
            return true;
        }
    }
    if (type == 8) {
        if ((city->chateauEau.flot - city->immeuble.nbHabitant) >= 0) {
            return true;
        }
    }
    if (type == 9) {
        if ((city->chateauEau.flot - city->gratteCiel.nbHabitant) >= 0) {
            return true;
        }
    }
    return false;
}