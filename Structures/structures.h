#ifndef ECE_CITY_1_E_STRUCTURES_H
#define ECE_CITY_1_E_STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define COLONNES 45 //case X
#define LIGNES 35 //case Y



typedef struct {
    bool boolMenuPrincipal; //permet de rester dans la boucle de cette page
    bool partie;
    bool partieHover;
    bool partieClique;
    bool aide;
    bool aideHover;
    bool aideClique;
    bool quitter;
    bool quitterHover;
    bool quitterClique;
} PageMenuPrincipale;

typedef struct {

} PageReseauElec;

typedef struct {

} PageReseauEau;

typedef struct {

} PageAide;

typedef struct {

} PageJeux;

typedef struct {

} PageMode;

typedef struct {

} PageChargement;

typedef struct {
    PageChargement pageChargement; // page d'entrée du jeux
    PageMenuPrincipale pageMenuPrincipale;
    PageMode pageMode; // mode capitaliste ou communiste
    PageAide pageAide;
    PageReseauElec pageReseauElec;
    PageReseauEau pageReseauEau;
    PageJeux pageJeux;
} Pages;

typedef struct {
    int prix;
    int nbHabitant;
    int tailleX, tailleY;
    int capacite, capaciteTotal;
    int matriceX, matriceY;
    char *nomBlock;
    int numeroBatiment;
    int laCoordonneX, laCoordonneY; //permet de lire la coordonnée en 6 fois 4 si elle est posée en 4 fois 6
} Batiment;

typedef struct {
    int typeBloc; // Provient du fichier .txt
    int decor;
    int numContruction;
    bool eau;
    bool electricite;
    bool blocPlein; // bloc vide ou plein considère si c'est un obstacle ou pas

}Terrain;

typedef struct {
    int numeroConstruction;
    int numeroType; // route ruine...

}Construction;

typedef struct {
    Batiment ruine;
    Batiment cabane;
    Batiment maison;
    Batiment immeuble;
    Batiment gratteCiel;
    Batiment centrale;
    Batiment chateauEau;
    Batiment route;

    Pages page;

    Terrain terrain[LIGNES][COLONNES];
    int cycle; //15 secondes
    int argent; // solde du joueur
    int nombreHabitation;
    int nombreConstruction;

    Construction numeroConstruction[150];

    int nbHabitant;
    bool capitaliste;
} City;

#endif
