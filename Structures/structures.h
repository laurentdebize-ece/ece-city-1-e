#ifndef ECE_CITY_1_E_STRUCTURES_H
#define ECE_CITY_1_E_STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "raylib.h"

#define COLONNES 45 //case Y
#define LIGNES 35 //case X

#define MAX_BATIMENT LIGNES*COLONNES

enum BITMAP {
    PagePrincipaleToolBox,
    PageChargementImage,
    PageMenuPrincip,
    PageChoixMode,
    PageMap,
    PageRouteSelectionner,
    PageHabitationSelectionner,
    PageChateauSelectionner,
    PageCentraleSelectionner,
    PageMenuJeu,
    Niveau0,
    Niveau1,
    Niveau2,
    PageQuitterSauvegarde,
    PageSauvegardeEffectuer,
    NomSauvegarde,
    Ruine,
    Cabanne1,
    Cabane2,
    House1,
    House2,
    House3,
    House4,
    House5,
    House6,
    Immeuble1,
    Immeuble2,
    Immeuble3,
    Building1,
    Building2,
    Building3,
    Buildingg, // bon building
    CentraleElectrique,
    ChateauEau,
    Croix,
    ModeCapitaliste,
    ModeCommuniste,
    DecorHerbeImage,
    Route,
    DecorObstacleCaillouImage,
    Route_Verticale,
    Route_Horizontale,
    Route_Angle_Droite_Bas,
    Route_Angle_Droite_Haut,
    Route_Angle_Gauche_Bas,
    Route_Angle_Gauche_Haut,
    Route_Croisement_Bas,
    Route_Croisement_Droite,
    Route_Croisement_Gauche,
    Route_Croisement_Haut,
    Route_Carrefour,
    NB_BITMAP
};
enum MUSIQUE {
    BlockPoser, InfraStructure, PagePrincipale, Bouton,BruitElectrique , BruitEau,Building, CentralPark,
    NB_MUSIQUE
};

typedef struct {
    bool boolMenuPrincipal; //permet de rester dans la boucle de cette page
    bool partie;
    bool choix;
    bool sauvegarde;
    bool chargementSauvegarde;
    bool faireSauvegarde;

    bool aide;

    bool quitter;

} PageMenuPrincipale;

typedef struct {
    bool pageElectricite;
} PageReseauElec;

typedef struct {
    bool pageEau;
} PageReseauEau;

typedef struct {

} PageAide;

typedef struct {
    bool pageJeu;
    bool menu;
    bool croix;

    bool aide;
    bool sauvegarde;
    bool quitter;

    bool musiqueJeu;

    bool BatimentRoute;
    bool BatimentHabitation;
    bool BatimentEau;
    bool BatimentElec;
} PageJeux;

typedef struct {
    bool ModeCapitaliste;
    bool ModeCommuniste;
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
    int typeBloc;// Provient du fichier map.txt
    int nbBatiment;
    bool eau;           // Affichage niveau -1
    bool electricite;   // Affichage niveau -2
    bool obstacle;      // savoir si c'est un obstacle ou pas

    //test |
    //int x, y;
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
    bool electricite;//1 alimenter
    int eau;//nombre habitant alimenter

    double compteur;
    double tempsPose;
    bool ameliorerBat
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

    //pour les bitmaps avec raylib
    Image tabBitmapImage[NB_BITMAP];
    Texture2D tabBitmapTexture[NB_BITMAP];
    int nbBitmap;

    Music musique[NB_MUSIQUE];

    Construction tabConstruction[MAX_BATIMENT];
    Construction tabParcoursLongueur[MAX_BATIMENT];

    int nbHabitant;
    bool capitaliste;
    bool communiste;

    int mouseX, mouseY;
    double temps;
    double commencerPartieTemps;
    double compteurTemps3s;

    bool quitter;

    int ligneSurMap, colonneSurMap;
} City;

typedef struct {
    int y,x;
    int pred;
    int distance;
} Case;


#endif
