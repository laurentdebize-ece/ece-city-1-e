#ifndef ECE_CITY_1_E_STRUCTURES_H
#define ECE_CITY_1_E_STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "raylib.h"

#define COLONNES 45 //case X
#define LIGNES 35 //case Y

#define MAX_BATIMENT LIGNES*COLONNES


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
    int type;
    int nbHabitant;
    int tailleX, tailleY;
    int capacite, capaciteTotal, flot;
    int matriceX, matriceY;
    char *nomBlock;
    int numeroBatiment;
    // UN TABLEAU QUI DIS QUELLES BATIMENT EST RELIER A QUEL BATIMENT

    // UN TABLEAU QUI DIT LA DISTANCE ENTRE LES BATIMENTS DIT DANS LE TAB PRECEDENT
    int laCoordonneX, laCoordonneY; // Permet de lire la coordonnée en 6 fois 4 si elle est posée en 4 fois 6
} Batiment;

typedef struct {
    int typeBloc;       // Provient du fichier map.txt
    bool eau;           // Affichage niveau -1
    bool electricite;   // Affichage niveau -2
    bool obstacle;      // savoir si c'est un obstacle ou pas

} Terrain;

typedef struct {
    int numeroDesConstructions;
    int typeDeConstruction; // route ruine...
    int coordonneeX, coordonneeY;
    bool horizontale;
} Construction;

typedef struct {
    int source;
    int destination;
    int longueur;
    bool plusCourt;
    int indiceParcours;
} Parcours;

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

    Parcours tabParcoursConstruction[MAX_BATIMENT];
    Parcours tabParcoursLongueur[MAX_BATIMENT];

    Terrain terrain[LIGNES][COLONNES];
    int cycle;  // 15 secondes
    int argent; // solde du joueur
    int nombreHabitation;
    int nombreConstruction;

    Construction tabConstruction[MAX_BATIMENT];

    int nbHabitant;
    bool capitaliste;
} City;

#endif
