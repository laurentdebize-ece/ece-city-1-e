#include "eau.h"
void consommationEau (City *city) {
    city->chateauEau.flot = city->chateauEau.capacite - city->nbHabitant;
}

void alimenteEau(City* city) {
    nbConstruction(city);
    //capaciteTotalEau(city);
    int Batiment = 0, nbChateauEauPlein = city->chateauEau.numeroBatiment;
    int  distance, etape;
    Case fileEau[45 * 35];
    Case batimentAlimenter[city->nombreHabitation];
    bool eauCity[LIGNES][COLONNES];
    int caseExplorer = 0, derniereCase = 0;
    for (int i = 0; i < 35; ++i) {
        for (int j = 0; j < 45; ++j) {
            eauCity[i][j] = false;
        }
    }
    while (nbChateauEauPlein != 0) {
        distance = 0;
        int capaciterRestante = city->chateauEau.capacite;
        for (int j = 0; j < 35 * 45; ++j) {
            fileEau[j].y = -1;
            fileEau[j].x = -1;
            fileEau[j].pred = -1;
            fileEau[j].distance=-1;
        }
        if (city->tabConstruction[Batiment].typeDeConstruction == 4) {
            for (int i = 0; i < 35; ++i) {
                for (int j = 0; j < 45; ++j) {
                    if(city->terrain[i][j].typeBloc==2) {
                        city->terrain[i][j].eau = false;
                    }
                }
            }
            distance = 1;
            if (city->tabConstruction[Batiment].horizontale == true) {//HG
                for (int j = city->tabConstruction[Batiment].coordonneeX;
                     j < city->tabConstruction[Batiment].coordonneeX + 4; ++j) {//Y!=0 a faire
                    if (city->terrain[j][city->tabConstruction[Batiment].coordonneeY - 1].typeBloc == 2) {
                        city->terrain[j][city->tabConstruction[Batiment].coordonneeY - 1].eau = true;
                        fileEau[derniereCase].y = city->tabConstruction[Batiment].coordonneeY - 1;
                        fileEau[derniereCase].x = j;
                        fileEau[derniereCase].pred = -1;
                        fileEau[derniereCase].distance = distance;
                        derniereCase++;
                    }
                }
                for (int j = city->tabConstruction[Batiment].coordonneeX;
                     j < city->tabConstruction[Batiment].coordonneeX + 4; ++j) {
                    if (city->terrain[j][city->tabConstruction[Batiment].coordonneeY + 3].typeBloc == 2) {
                        city->terrain[j][city->tabConstruction[Batiment].coordonneeY + 3].eau = true;
                        fileEau[derniereCase].y = city->tabConstruction[Batiment].coordonneeY + 3;
                        fileEau[derniereCase].x = j;
                        fileEau[derniereCase].pred = -1;
                        fileEau[derniereCase].distance = distance;
                        derniereCase++;
                    }
                }
                for (int j = city->tabConstruction[Batiment].coordonneeY;
                     j < city->tabConstruction[Batiment].coordonneeY + 3; ++j) {// a term modif
                    if (city->terrain[city->tabConstruction[Batiment].coordonneeX - 1][j].typeBloc == 2) {
                        city->terrain[city->tabConstruction[Batiment].coordonneeX - 1][j].eau = true;
                        fileEau[derniereCase].y = j;
                        fileEau[derniereCase].x = city->tabConstruction[Batiment].coordonneeX - 1;
                        fileEau[derniereCase].pred = -1;
                        fileEau[derniereCase].distance = distance;
                        derniereCase++;
                    }
                }
                for (int j = city->tabConstruction[Batiment].coordonneeY;
                     j < city->tabConstruction[Batiment].coordonneeY + 3; ++j) {
                    if (city->terrain[city->tabConstruction[Batiment].coordonneeX + 4][j].typeBloc == 2) {
                        city->terrain[city->tabConstruction[Batiment].coordonneeY + 4][j].eau = true;
                        fileEau[derniereCase].y = j;
                        fileEau[derniereCase].x = city->tabConstruction[Batiment].coordonneeX + 4;
                        fileEau[derniereCase].pred = -1;
                        fileEau[derniereCase].distance = distance;
                        derniereCase++;
                    }
                }
            } else {//HD
                for (int j = city->tabConstruction[Batiment].coordonneeX - 3;
                     j < city->tabConstruction[Batiment].coordonneeX; ++j) {//Y!=0 a faire
                    if (city->terrain[j][city->tabConstruction[Batiment].coordonneeY - 1].typeBloc == 2) {
                        city->terrain[j][city->tabConstruction[Batiment].coordonneeY - 1].eau = true;
                        fileEau[derniereCase].y = city->tabConstruction[Batiment].coordonneeY - 1;
                        fileEau[derniereCase].x = j;
                        fileEau[derniereCase].pred = -1;
                        fileEau[derniereCase].distance = distance;
                        derniereCase++;
                    }
                }
                for (int j = city->tabConstruction[Batiment].coordonneeX - 3;
                     j < city->tabConstruction[Batiment].coordonneeX; ++j) {
                    if (city->terrain[j][city->tabConstruction[Batiment].coordonneeY + 4].typeBloc == 2) {
                        city->terrain[j][city->tabConstruction[Batiment].coordonneeY + 4].eau = true;
                        fileEau[derniereCase].y = city->tabConstruction[Batiment].coordonneeY + 4;
                        fileEau[derniereCase].x = j;
                        fileEau[derniereCase].pred = -1;
                        fileEau[derniereCase].distance = distance;
                        derniereCase++;
                    }
                }
                for (int j = city->tabConstruction[Batiment].coordonneeY;
                     j < city->tabConstruction[Batiment].coordonneeY + 3; ++j) {
                    if (city->terrain[city->tabConstruction[Batiment].coordonneeX + 1][j].typeBloc == 2) {
                        city->terrain[city->tabConstruction[Batiment].coordonneeX + 1][j].eau = true;
                        fileEau[derniereCase].y = j;
                        fileEau[derniereCase].x = city->tabConstruction[Batiment].coordonneeX + 1;
                        fileEau[derniereCase].pred = -1;
                        fileEau[derniereCase].distance = distance;
                        derniereCase++;
                    }
                }
                for (int j = city->tabConstruction[Batiment].coordonneeY;
                     j < city->tabConstruction[Batiment].coordonneeY + 3; ++j) {
                    if (city->terrain[city->tabConstruction[Batiment].coordonneeX - 3][j].typeBloc == 2) {
                        city->terrain[city->tabConstruction[Batiment].coordonneeY - 3][j].eau = true;
                        fileEau[derniereCase].y = j;
                        fileEau[derniereCase].x = city->tabConstruction[Batiment].coordonneeX - 3;
                        fileEau[derniereCase].pred = -1;
                        fileEau[derniereCase].distance = distance;
                        derniereCase++;
                    }
                }
            }
            nbChateauEauPlein--;
            etape=derniereCase-1;
            distance++;
            while (fileEau[caseExplorer].x == -1) {
                if(caseExplorer==etape){
                    etape=derniereCase-1;
                    distance++;
                }
                if (fileEau[caseExplorer].y != 0 && //case en haut
                    city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y - 1].eau == false) {
                    if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y - 1].typeBloc == 2) {
                        city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y - 1].eau = true;
                        fileEau[derniereCase].y = fileEau[caseExplorer].y - 1;
                        fileEau[derniereCase].x = fileEau[caseExplorer].x;
                        fileEau[derniereCase].distance = distance;
                        fileEau[derniereCase].pred=caseExplorer;
                        derniereCase++;
                    } else if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y - 1].typeBloc == 6) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau >
                            (city->cabane.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                          1].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x][
                                    fileEau[caseExplorer].y - 1].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau = city->cabane.nbHabitant;
                            for (int j = fileEau[caseExplorer].x - 2; j < fileEau[caseExplorer].x + 2; ++j) {
                                for (int k = fileEau[caseExplorer].y - 3; k < fileEau[caseExplorer].y + 1; ++k) {
                                    if (city->terrain[j][k].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                               1].nbBatiment) {
                                        city->terrain[j][k].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y - 1].typeBloc == 7) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau >
                            (city->maison.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                          1].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x][
                                    fileEau[caseExplorer].y - 1].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau = city->maison.nbHabitant;
                            for (int j = fileEau[caseExplorer].x - 2; j < fileEau[caseExplorer].x + 2; ++j) {
                                for (int k = fileEau[caseExplorer].y - 3; k < fileEau[caseExplorer].y + 1; ++k) {
                                    if (city->terrain[j][k].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                               1].nbBatiment) {
                                        city->terrain[j][k].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y - 1].typeBloc == 8) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau >
                            (city->immeuble.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                          1].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x][
                                    fileEau[caseExplorer].y - 1].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau = city->immeuble.nbHabitant;
                            for (int j = fileEau[caseExplorer].x - 2; j < fileEau[caseExplorer].x + 2; ++j) {
                                for (int k = fileEau[caseExplorer].y - 3; k < fileEau[caseExplorer].y + 1; ++k) {
                                    if (city->terrain[j][k].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                               1].nbBatiment) {
                                        city->terrain[j][k].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y - 1].typeBloc == 9) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau >
                            (city->gratteCiel.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                          1].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x][
                                    fileEau[caseExplorer].y - 1].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau = city->gratteCiel.nbHabitant;
                            for (int j = fileEau[caseExplorer].x - 2; j < fileEau[caseExplorer].x + 2; ++j) {
                                for (int k = fileEau[caseExplorer].y - 3; k < fileEau[caseExplorer].y + 1; ++k) {
                                    if (city->terrain[j][k].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                               1].nbBatiment) {
                                        city->terrain[j][k].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                                         1].nbBatiment].eau = capaciterRestante;
                        }
                    }
                    if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y - 1].typeBloc >5) {
                        for (int j = fileEau[caseExplorer].x - 2; j < fileEau[caseExplorer].x + 2; ++j) {
                            for (int k = fileEau[caseExplorer].y - 3; k < fileEau[caseExplorer].y + 1; ++k) {
                                if (city->terrain[j][k].nbBatiment ==
                                    city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                           1].nbBatiment) {
                                    eauCity[j][k] = true;
                                }
                            }
                        }
                        int cheminInverce=caseExplorer;
                        while (cheminInverce==-1){
                            eauCity[fileEau[cheminInverce].x][fileEau[cheminInverce].y]=true;
                            cheminInverce=fileEau[cheminInverce].pred;
                        }
                    }
                }
                if (fileEau[caseExplorer].y != 45 && //case en bas
                    city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y + 1].eau == false) {
                    if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y + 1].typeBloc == 2) {
                        city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y + 1].eau = true;
                        fileEau[derniereCase].y = fileEau[caseExplorer].y + 1;
                        fileEau[derniereCase].x = fileEau[caseExplorer].x;
                        fileEau[derniereCase].distance = distance;
                        fileEau[derniereCase].pred=caseExplorer;
                        derniereCase++;
                    } else if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y + 1].typeBloc == 6) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau >
                            (city->cabane.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                          1].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x][
                                    fileEau[caseExplorer].y + 1].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau = city->cabane.nbHabitant;
                            for (int j = fileEau[caseExplorer].x - 2; j < fileEau[caseExplorer].x + 2; ++j) {
                                for (int k = fileEau[caseExplorer].y - 1; k < fileEau[caseExplorer].y + 3; ++k) {
                                    if (city->terrain[j][k].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                               1].nbBatiment) {
                                        city->terrain[j][k].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y + 1].typeBloc == 7) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau >
                            (city->maison.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                          1].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x][
                                    fileEau[caseExplorer].y + 1].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau = city->maison.nbHabitant;
                            for (int j = fileEau[caseExplorer].x - 2; j < fileEau[caseExplorer].x + 2; ++j) {
                                for (int k = fileEau[caseExplorer].y - 1; k < fileEau[caseExplorer].y + 3; ++k) {
                                    if (city->terrain[j][k].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                               1].nbBatiment) {
                                        city->terrain[j][k].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y + 1].typeBloc == 8) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau >
                            (city->immeuble.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                          1].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x][
                                    fileEau[caseExplorer].y + 1].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau = city->immeuble.nbHabitant;
                            for (int k = fileEau[caseExplorer].y - 1; k < fileEau[caseExplorer].y + 3; ++k) {
                                for (int j = fileEau[caseExplorer].x - 2; j < fileEau[caseExplorer].x + 2; ++j) {
                                    if (city->terrain[k][j].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                               1].nbBatiment) {
                                        city->terrain[k][j].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y + 1].typeBloc == 9) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau >
                            (city->gratteCiel.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                          1].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x][
                                    fileEau[caseExplorer].y + 1].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau = city->gratteCiel.nbHabitant;
                            for (int j = fileEau[caseExplorer].x - 2; j < fileEau[caseExplorer].x + 2; ++j) {
                                for (int k = fileEau[caseExplorer].y - 1; k < fileEau[caseExplorer].y + 3; ++k) {
                                    if (city->terrain[k][j].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                               1].nbBatiment) {
                                        city->terrain[k][j].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y +
                                                                                         1].nbBatiment].eau = capaciterRestante;
                        }
                    }
                    if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y + 1].typeBloc >5) {
                        for (int j = fileEau[caseExplorer].x - 2; j < fileEau[caseExplorer].x + 2; ++j) {
                            for (int k = fileEau[caseExplorer].y - 1; k < fileEau[caseExplorer].y + 3; ++k) {
                                if (city->terrain[j][k].nbBatiment ==
                                    city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                           1].nbBatiment) {
                                    eauCity[j][k] = true;
                                }
                            }
                        }
                        int cheminInverce=caseExplorer;
                        while (cheminInverce==-1){
                            eauCity[fileEau[cheminInverce].x][fileEau[cheminInverce].y]=true;
                            cheminInverce=fileEau[cheminInverce].pred;
                        }
                    }
                }
                if (fileEau[caseExplorer].x != 0 &&// case à gauche
                    city->terrain[fileEau[caseExplorer].x - 1][fileEau[caseExplorer].y].eau == false) {
                    if (city->terrain[fileEau[caseExplorer].x - 1][fileEau[caseExplorer].y].typeBloc == 2) {
                        city->terrain[fileEau[caseExplorer].x - 1][fileEau[caseExplorer].y].eau = true;
                        fileEau[derniereCase].y = fileEau[caseExplorer].y;
                        fileEau[derniereCase].x = fileEau[caseExplorer].x - 1;
                        fileEau[derniereCase].distance = distance;
                        fileEau[derniereCase].pred=caseExplorer;
                        derniereCase++;
                    } else if (city->terrain[fileEau[caseExplorer].x - 1][fileEau[caseExplorer].y].typeBloc == 6) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau >
                            (city->cabane.nbHabitant - city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                                           1][fileEau[caseExplorer].y].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                                     1][fileEau[caseExplorer].y].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = city->cabane.nbHabitant;
                            for (int k = fileEau[caseExplorer].x - 3; k < fileEau[caseExplorer].x + 1; ++k) {
                                for (int j = fileEau[caseExplorer].y - 2; j < fileEau[caseExplorer].y + 2; ++j) {
                                    if (city->terrain[k][j].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x -
                                                      1][fileEau[caseExplorer].y].nbBatiment) {
                                        city->terrain[k][j].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x - 1][fileEau[caseExplorer].y].typeBloc == 7) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau >
                            (city->maison.nbHabitant - city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                                           1][fileEau[caseExplorer].y].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                                     1][fileEau[caseExplorer].y].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = city->maison.nbHabitant;
                            for (int k = fileEau[caseExplorer].x - 3; k < fileEau[caseExplorer].x + 1; ++k) {
                                for (int j = fileEau[caseExplorer].y - 2; j < fileEau[caseExplorer].y + 2; ++j) {
                                    if (city->terrain[k][j].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x -
                                                      1][fileEau[caseExplorer].y].nbBatiment) {
                                        city->terrain[k][j].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x - 1][fileEau[caseExplorer].y].typeBloc == 8) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau >
                            (city->immeuble.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                 1][fileEau[caseExplorer].y].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                                     1][fileEau[caseExplorer].y].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = city->immeuble.nbHabitant;
                            for (int k = fileEau[caseExplorer].x - 3; k < fileEau[caseExplorer].x + 1; ++k) {
                                for (int j = fileEau[caseExplorer].y - 2; j < fileEau[caseExplorer].y + 2; ++j) {
                                    if (city->terrain[k][j].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x -
                                                      1][fileEau[caseExplorer].y].nbBatiment) {
                                        city->terrain[k][j].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x - 1][fileEau[caseExplorer].y].typeBloc == 9) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau >
                            (city->gratteCiel.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                 1][fileEau[caseExplorer].y].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                                     1][fileEau[caseExplorer].y].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = city->gratteCiel.nbHabitant;
                            for (int k = fileEau[caseExplorer].x - 3; k < fileEau[caseExplorer].x + 1; ++k) {
                                for (int j = fileEau[caseExplorer].y - 2; j < fileEau[caseExplorer].y + 2; ++j) {
                                    if (city->terrain[k][j].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x -
                                                      1][fileEau[caseExplorer].y].nbBatiment) {
                                        city->terrain[k][j].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = capaciterRestante;
                        }
                    }
                    if (city->terrain[fileEau[caseExplorer].x - 1][fileEau[caseExplorer].y].typeBloc >5) {
                        for (int j = fileEau[caseExplorer].x - 3; j < fileEau[caseExplorer].x + 1; ++j) {
                            for (int k = fileEau[caseExplorer].y - 2; k < fileEau[caseExplorer].y + 2; ++k) {
                                if (city->terrain[j][k].nbBatiment ==
                                    city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                           1].nbBatiment) {
                                    eauCity[j][k] = true;
                                }
                            }
                        }
                        int cheminInverce=caseExplorer;
                        while (cheminInverce==-1){
                            eauCity[fileEau[cheminInverce].x][fileEau[cheminInverce].y]=true;
                            cheminInverce=fileEau[cheminInverce].pred;
                        }
                    }
                }
                if (fileEau[caseExplorer].x != 35 && //case à droite
                    city->terrain[fileEau[caseExplorer].x + 1][fileEau[caseExplorer].y].eau == false) {
                    if (city->terrain[fileEau[caseExplorer].x + 1][fileEau[caseExplorer].y].typeBloc == 2) {
                        city->terrain[fileEau[caseExplorer].x + 1][fileEau[caseExplorer].y].eau = true;
                        fileEau[derniereCase].y = fileEau[caseExplorer].y;
                        fileEau[derniereCase].x = fileEau[caseExplorer].x + 1;
                        fileEau[derniereCase].distance = distance;
                        fileEau[derniereCase].pred=caseExplorer;
                        derniereCase++;
                    } else if (city->terrain[fileEau[caseExplorer].x + 1][fileEau[caseExplorer].y].typeBloc == 6) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau >
                            (city->cabane.nbHabitant - city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                                           1][fileEau[caseExplorer].y].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                                     1][fileEau[caseExplorer].y].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = city->cabane.nbHabitant;
                            for (int k = fileEau[caseExplorer].x - 1; k < fileEau[caseExplorer].x + 3; ++k) {
                                for (int j = fileEau[caseExplorer].y - 2; j < fileEau[caseExplorer].y + 2; ++j) {
                                    if (city->terrain[k][j].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x +
                                                      1][fileEau[caseExplorer].y].nbBatiment) {
                                        city->terrain[k][j].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x - 1][fileEau[caseExplorer].y].typeBloc == 7) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau >
                            (city->maison.nbHabitant - city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                                           1][fileEau[caseExplorer].y].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                                     1][fileEau[caseExplorer].y].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = city->maison.nbHabitant;
                            for (int k = fileEau[caseExplorer].x - 1; k < fileEau[caseExplorer].x + 3; ++k) {
                                for (int j = fileEau[caseExplorer].y - 2; j < fileEau[caseExplorer].y + 2; ++j) {
                                    if (city->terrain[k][j].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x +
                                                      1][fileEau[caseExplorer].y].nbBatiment) {
                                        city->terrain[k][j].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x + 1][fileEau[caseExplorer].y].typeBloc == 8) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau >
                            (city->immeuble.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                 1][fileEau[caseExplorer].y].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x -
                                                                                     1][fileEau[caseExplorer].y].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = city->immeuble.nbHabitant;
                            for (int k = fileEau[caseExplorer].x - 1; k < fileEau[caseExplorer].x + 3; ++k) {
                                for (int j = fileEau[caseExplorer].y - 2; j < fileEau[caseExplorer].y + 2; ++j) {
                                    if (city->terrain[k][j].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x +
                                                      1][fileEau[caseExplorer].y].nbBatiment) {
                                        city->terrain[k][j].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = capaciterRestante;
                        }
                    } else if (city->terrain[fileEau[caseExplorer].x + 1][fileEau[caseExplorer].y].typeBloc == 9) {
                        if (city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau >
                            (city->gratteCiel.nbHabitant -
                             city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                 1][fileEau[caseExplorer].y].nbBatiment].eau)) {
                            capaciterRestante -= city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                                     1][fileEau[caseExplorer].y].nbBatiment].eau;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = city->gratteCiel.nbHabitant;
                            for (int k = fileEau[caseExplorer].x - 1; k < fileEau[caseExplorer].x + 3; ++k) {
                                for (int j = fileEau[caseExplorer].y - 2; j < fileEau[caseExplorer].y + 2; ++j) {
                                    if (city->terrain[k][j].nbBatiment ==
                                        city->terrain[fileEau[caseExplorer].x +
                                                      1][fileEau[caseExplorer].y].nbBatiment) {
                                        city->terrain[k][j].eau = true;
                                    }
                                }
                            }
                        } else if (capaciterRestante > 0) {
                            capaciterRestante = 0;
                            city->tabConstruction[city->terrain[fileEau[caseExplorer].x +
                                                                1][fileEau[caseExplorer].y].nbBatiment].eau = capaciterRestante;
                        }
                    }
                    if (city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y - 1].typeBloc >5) {
                        for (int j = fileEau[caseExplorer].x - 2; j < fileEau[caseExplorer].x + 2; ++j) {
                            for (int k = fileEau[caseExplorer].y - 3; k < fileEau[caseExplorer].y + 1; ++k) {
                                if (city->terrain[j][k].nbBatiment ==
                                    city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                           1].nbBatiment) {
                                    eauCity[j][k] = true;
                                }
                            }
                        }
                        int cheminInverce=caseExplorer;
                        while (cheminInverce==-1){
                            eauCity[fileEau[cheminInverce].x][fileEau[cheminInverce].y]=true;
                            cheminInverce=fileEau[cheminInverce].pred;
                        }
                    }
                    if (city->terrain[fileEau[caseExplorer].x + 1][fileEau[caseExplorer].y].typeBloc >5) {
                        for (int j = fileEau[caseExplorer].x - 1; j < fileEau[caseExplorer].x + 3; ++j) {
                            for (int k = fileEau[caseExplorer].y - 2; k < fileEau[caseExplorer].y + 2; ++k) {
                                if (city->terrain[j][k].nbBatiment ==
                                    city->terrain[fileEau[caseExplorer].x][fileEau[caseExplorer].y -
                                                                           1].nbBatiment) {
                                    eauCity[j][k] = true;
                                }
                            }
                        }
                        int cheminInverce=caseExplorer;
                        while (cheminInverce==-1){
                            eauCity[fileEau[cheminInverce].x][fileEau[cheminInverce].y]=true;
                            cheminInverce=fileEau[cheminInverce].pred;
                        }
                    }
                }
                caseExplorer++;
            }
        }
        Batiment++;
    }
}