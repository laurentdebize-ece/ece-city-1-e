#ifndef ECE_CITY_1_E_STRUCTURES_H
#define ECE_CITY_1_E_STRUCTURES_H
#define colonnes 45 //case
#define ligne 35 //case
#define hauteurResolution 1024 //pixel
#define LargeurResolution 768 //pixel
#define case 20 //pixel
#define routeTaille 1 //case
#define habitationTaille 3 //case
#define batimentHauteur 4 //case
#define batimentLargeur 6 //case
#define capaciterAlimentation 5000 //pixel
#define sommeInitiale 500000 //ECE-flouz
#define cycle 15 //seconde
#define terrainVague 0 //habitants
#define ruine 0 //habitants
#define cabane 10 //habitants
#define maison 50 //habitants
#define immeuble 100 //habitants
#define gratteCiel 1000 //habitants
#define prixCentrale 100000 //ECE-flouz
#define prixChâteauDEau 100000 //ECE-flouz
#define prixRoute 10 //ECE-flouz
#define prixTerrainVague 1000 //ECE-flouz
#define impots 10 //ECE-flouz
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


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
    int nhHabitant;
    int tailleX, tailleY;
    int capacite;
    int matriceX, matriceY;
} Batiment;

typedef struct {
//Allegro allegro;// Contient tous les éléments ALLEGRO, plus facile pour les free etc.
    Batiment ruine;
    Batiment cabane;
    Batiment maison;
    Batiment imeuble;
    Batiment gratteCiel;
    Batiment centrale;
    Batiment chateauEau;
    Batiment route;
    Batiment decor;

    Pages page;

    int cycle; //15 secondes
    int argent; // solde du joueur
    bool capitaliste;
} City;
#endif
