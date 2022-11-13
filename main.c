#include "Structures/structures.h"
#include "Fonctions/Map/map.h"
#include "Fonctions/Construction/construction.h"
#include "Fonctions/Initialisation/initialisation.h"
#include "Fonctions/Electricite/electriciter.h"
#include "Fonctions/Eau/eau.h"

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
    //nbHabitant(city);
    //detecterConstruction(city);
    /*printf("Il y a %d centrale, %d chateau eau et %d habitations\n", city->centrale.numeroBatiment, city->chateauEau.numeroBatiment, city->nombreConstruction - city->centrale.numeroBatiment - city->chateauEau.numeroBatiment);
    printf("il y a %d centrales\n", city->centrale.numeroBatiment);
    printf("La coordonnee de la centrale est (%d,%d)\n", city->centrale.laCoordonneX, city->centrale.laCoordonneY);
    printf("La coordonnee du chateau d'eau est (%d,%d)\n", city->chateauEau.laCoordonneX, city->chateauEau.laCoordonneY);
    for (int p = 1 ; p <= city->nombreConstruction ; p++) {
        printf("n°%d : %d\n", p, city->nombreConstruction);
    }
    printf("La ville possède %d de capacité électrique\n", city->centrale.capacite);
    printf("La ville possède %d de capacité d'eau\n", city->chateauEau.capacite);
    }*/

    //printf("Il y a %d contructions\n", city->nombreConstruction);
    /*for (int i = 0; i < city->nombreConstruction; i++) {
        printf("Construction n°%d est de type %d et de coordonnées (%d,%d)\n",
               city->tabConstruction[i].numeroDesConstructions + 1, city->tabConstruction[i].typeDeConstruction,
               city->tabConstruction[i].coordonneeX, city->tabConstruction[i].coordonneeY);
    }*/

    // ------- FLOT CENTRALE ET EAU ------- //
    consommationEau(city);
    consommationElectrique(city);
    /*printf("Il y a %d chateau d'eau pour une capacité total de %d\n", city->chateauEau.numeroBatiment, city->chateauEau.capacite);
    printf("Il y a %d centrale élecrtrique pour une capacité total de %d\n", city->centrale.numeroBatiment, city->centrale.capacite);
    printf("Il y a %d batiments qui consomme %d électricité et %d eau\n", city->nombreConstruction,
             (city->centrale.capacite - city->centrale.flot), (city->chateauEau.capacite - city->chateauEau.flot));
    */
    //printf("Flot électrique : %d\nFlot d'eau : %d\n", city->centrale.flot, city->chateauEau.flot);

    /*if (viabiliteeRoute(city,) == true) {
        printf("OUI route");
    } else if (viabiliteeRoute(city, ) == false) {
        printf("NON route");
    }*/

    //constructionViable(city);


    int p = 0;

    if (viabiliteeRoutiere(city, p)) {
        printf("La construction n°%d (type : %d) est viable ROUTE\n", p, city->tabConstruction[p].typeDeConstruction);
    } else {
        printf("La construction n°%d (type : %d) est non viable ROUTE\n", p,
               city->tabConstruction[p].typeDeConstruction);
    }
    p++;
    if (viabiliteeRoutiere(city, p)) {
        printf("La construction n°%d (type : %d) est viable ROUTE\n", p, city->tabConstruction[p].typeDeConstruction);
    } else {
        printf("La construction n°%d (type : %d) est non viable ROUTE\n", p,
               city->tabConstruction[p].typeDeConstruction);
    }
    p++;
    if (viabiliteeRoutiere(city, p)) {
        printf("La construction n°%d (type : %d) est viable ROUTE\n", p, city->tabConstruction[p].typeDeConstruction);
    } else {
        printf("La construction n°%d (type : %d) est non viable ROUTE\n", p,
               city->tabConstruction[p].typeDeConstruction);
    }

    p++;
    if (viabiliteeRoutiere(city, p)) {
        printf("La construction n°%d (type : %d) est viable ROUTE\n", p, city->tabConstruction[p].typeDeConstruction);
    } else {
        printf("La construction n°%d (type : %d) est non viable ROUTE\n", p,
               city->tabConstruction[p].typeDeConstruction);
    }

    p = 0;

    for (int i = city->tabConstruction[p].coordonneeX - 1;
         i <= city->tabConstruction[p].coordonneeX + 4; i++) {
        for (int j = city->tabConstruction[p].coordonneeY - 1;
             j <= city->tabConstruction[p].coordonneeY + 6; j++) {
            if ((i == city->tabConstruction[p].coordonneeX - 1 && j == city->tabConstruction[p].coordonneeY - 1) ||
                (i == city->tabConstruction[p].coordonneeX - 1 && j == city->tabConstruction[p].coordonneeY + 6) ||
                (i == city->tabConstruction[p].coordonneeX + 4 && j == city->tabConstruction[p].coordonneeY - 1) ||
                (i == city->tabConstruction[p].coordonneeX + 4 && j == city->tabConstruction[p].coordonneeY + 6)) {
            } else {
                //printf("(%d,%d)\n", i, j);
            }
        }
    }
    p = 0;
    printf("(%d,%d)\n", city->tabConstruction[p].coordonneeX - 1, city->tabConstruction[p].coordonneeY - 1);
    printf("(%d,%d)\n", city->tabConstruction[p].coordonneeX - 1, city->tabConstruction[p].coordonneeY + 6);
    printf("(%d,%d)\n", city->tabConstruction[p].coordonneeX + 4, city->tabConstruction[p].coordonneeY - 1);
    printf("(%d,%d)\n", city->tabConstruction[p].coordonneeX + 4, city->tabConstruction[p].coordonneeY + 6);


    /*printf("n°%d coordonnées(%d,%d)\n", p, city->tabConstruction[p].coordonneeX, city->tabConstruction[p].coordonneeY);

    printf("coordonnée X MIN %d\n", city->tabConstruction[p].coordonneeX - 1);
    printf("coordonnée Y MIN %d\n", city->tabConstruction[p].coordonneeY - 1);
    printf("coordonnée X MAX %d\n", city->tabConstruction[p].coordonneeX + 4);
    printf("coordonnée Y MAX %d\n", city->tabConstruction[p].coordonneeY + 6);
    for (int i = city->tabConstruction[p].coordonneeX - 1;
         i <= city->tabConstruction[p].coordonneeX + 4; i++) {
        for (int j = city->tabConstruction[p].coordonneeY - 1;
             j <= city->tabConstruction[p].coordonneeY + 6; j++) {
            //printf("(%d,%d)\n", i,j);
        }
    }
    p++;
    printf("\n");
    printf("n°%d coordonnées(%d,%d)\n", p, city->tabConstruction[p].coordonneeX, city->tabConstruction[p].coordonneeY);

    printf("coordonnée X MIN %d\n", city->tabConstruction[p].coordonneeX - 1);
    printf("coordonnée Y MIN %d\n", city->tabConstruction[p].coordonneeY - 4);
    printf("coordonnée X MAX %d\n", city->tabConstruction[p].coordonneeX + 6);
    printf("coordonnée Y MAX %d\n", city->tabConstruction[p].coordonneeY + 1);
    for (int i = city->tabConstruction[p].coordonneeX - 1;
         i <= city->tabConstruction[p].coordonneeX + 6; i++) {
        for (int j = city->tabConstruction[p].coordonneeY - 4;
             j <= city->tabConstruction[p].coordonneeY + 1; j++) {
            //printf("(%d,%d)\n", i,j);
        }
    }

    // ---------- NOMBRE BATIMENTS SUR LA MAP ---------- //
    /*printf("%d ruines\t%d cabannes\t%d maisons\t%d immeubles\t%d gratte-ciel\n", city->ruine.numeroBatiment,
           city->cabane.numeroBatiment, city->maison.numeroBatiment, city->immeuble.numeroBatiment,
           city->gratteCiel.numeroBatiment);*/

    // ------- VIABILITE ROUTE ------- //
    p = 0;

    /*if (viabiliteeRoutiere(city, p)) {
        printf("La construction n°%d (type : %d) est viable ROUTE\n", p, city->tabConstruction[p].typeDeConstruction);
    } else {
        printf("La construction n°%d (type : %d) est non viable ROUTE\n", p,
               city->tabConstruction[p].typeDeConstruction);
    }
    p++;
    if (viabiliteeRoutiere(city, p)) {
        printf("La construction n°%d (type : %d) est viable ROUTE\n", p, city->tabConstruction[p].typeDeConstruction);
    } else {
        printf("La construction n°%d (type : %d) est non viable ROUTE\n", p,
               city->tabConstruction[p].typeDeConstruction);
    }*/

    // ------- VIABILITE ELECTRIQUE ------- //
    /*printf("\n");
    p--;

    if (viabiliteeElectrique(city, p)) {
        printf("La construction n°%d (type : %d) est viable ELECTRIQUE\n", p,
               city->tabConstruction[p].typeDeConstruction);
    } else {
        printf("La construction n°%d (type : %d) est non viable ELECTRIQUE\n", p,
               city->tabConstruction[p].typeDeConstruction);
    }
    p++;
    if (viabiliteeElectrique(city, p)) {
        printf("La construction n°%d (type : %d) est viable ELECTRIQUE\n", p,
               city->tabConstruction[p].typeDeConstruction);
    } else {
        printf("La construction n°%d (type : %d) est non viable ELECTRIQUE\n", p,
               city->tabConstruction[p].typeDeConstruction);
    }*/

    // ------- VIABILITE EAU ------- //
    /*printf("\n");
    p--;

    if (viabiliteeEau(city, p)) {
        printf("La construction n°%d (type : %d) est viable EAU\n", p, city->tabConstruction[p].typeDeConstruction);
    } else {
        printf("La construction n°%d (type : %d) est non viable EAU\n", p, city->tabConstruction[p].typeDeConstruction);
    }
    p++;
    if (viabiliteeEau(city, p)) {
        printf("La construction n°%d (type : %d) est viable EAU\n", p, city->tabConstruction[p].typeDeConstruction);
    } else {
        printf("La construction n°%d (type : %d) est non viable EAU\n", p, city->tabConstruction[p].typeDeConstruction);
    }*/

    // ------- Trouver nbHabitant dans la ville ------- //
    //printf("Il y a %d habitations\n", city->nombreHabitation);
    //printf("Dans la ville il y a %d habitants\n", city->nbHabitant);
}

int main() {
    City city = {0};
    mainPL(&city);
    //mainAurelien(&city);
    //mainNino(&city);
    //mainTrystan(&city);
    return 0;
}