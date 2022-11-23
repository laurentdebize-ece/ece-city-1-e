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

enum BITMAP {PageChargementImage, PageMenuPrincip, PageChoixMode, PageMap,Ruine, Cabanne1, House1, House2, House3, House4, House5, House6, Immeuble1, Immeuble2, Building1, Building2, Building3, DecorHerbeImage, Route, DecorObstacleCaillouImage, Route_Verticale, Route_Horizontale, Route_Angle_Droite_Bas, Route_Angle_Droite_Haut, Route_Angle_Gauche_Bas, Route_Angle_Gauche_Haut, Route_Croisement_Bas, Route_Croisement_Droite, Route_Croisement_Gauche, Route_Croisement_Haut, Route_Carrefour, NB_BITMAP};

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

    int source;             // Numero de la construction de départ
    int destination;        // type de la construction d'arrivé
    int longueur;           // taille du chemin
    bool plusCourt;         // C'est le plus court ?
    int indiceParcours;     //pour reconnaitre chaque parcours effectué
} Construction;

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
    int cycle;  // 15 secondes
    int argent; // solde du joueur
    int nombreHabitation;
    int nombreConstruction;

    Image tabBitmapImage[NB_BITMAP];
    Texture2D tabBitmapTexture[NB_BITMAP];
    int nbBitmap;

    Construction tabConstruction[MAX_BATIMENT];
    Construction tabParcoursLongueur[MAX_BATIMENT];

    int nbHabitant;
    bool capitaliste;
} City;

#endif
