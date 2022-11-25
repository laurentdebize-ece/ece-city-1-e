#include "initialisation.h"


void initialisationVille(City *city) {

    //---------------- Terrain Vague _ Ruine ----------------//

    city->ruine.prix = 1000; // 1000 ECE flouz et apèrs plus de prix car augmente avec compteur
    city->ruine.type = 5;
    city->ruine.nbHabitant = 0;
    city->ruine.numeroBatiment = 0;
    //city->ruine.capacite = ;
    //city->ruine.matriceX = ;
    //city->ruine.matriceY = ;
    city->ruine.tailleX = 3;
    city->ruine.tailleY = 3;

    //---------------- Cabanne ----------------//

    city->cabane.nbHabitant = 10;
    city->cabane.type = 6;
    city->cabane.numeroBatiment = 0;
    //city->cabane.capacite = ;
    //city->cabane.matriceX = ;
    //city->cabane.matriceY = ;
    city->cabane.tailleX = 3;
    city->cabane.tailleY = 3;

    //---------------- Maison ----------------//

    city->maison.nbHabitant = 50;
    city->maison.type = 7;
    city->maison.numeroBatiment = 0;
    //city->maison.capacite = ;
    //city->maison.matriceX = ;
    //city->maison.matriceY = ;
    city->maison.tailleX = 3;
    city->maison.tailleY = 3;

    //---------------- Immeuble ----------------//

    city->immeuble.nbHabitant = 100;
    city->immeuble.type = 8;
    city->immeuble.numeroBatiment = 0;
    //city->immeuble.capacite = ;
    //city->immeuble.matriceX = ;
    //city->immeuble.matriceY = ;
    city->immeuble.tailleX = 3;
    city->immeuble.tailleY = 3;


    //---------------- Gratte Ciel ----------------//

    city->gratteCiel.nbHabitant = 1000;
    city->gratteCiel.type = 9;
    city->gratteCiel.numeroBatiment = 0;
    //city->gratteCiel.capacite = ;
    //city->gratteCiel.matriceX = ;
    //city->gratteCiel.matriceY = ;
    city->gratteCiel.tailleX = 3;
    city->gratteCiel.tailleY = 3;

    //---------------- Autre ----------------//
    city->centrale.prix = 100000;
    city->centrale.capacite = 5000;
    city->centrale.capaciteTotal = 0;
    city->centrale.tailleX = 4;
    city->centrale.tailleY = 6;
    city->centrale.numeroBatiment = 0;

    city->chateauEau.prix = 100000;
    city->chateauEau.capacite = 5000;
    city->chateauEau.capaciteTotal = 0;
    city->chateauEau.tailleX = 4;
    city->chateauEau.tailleY = 6;
    city->chateauEau.numeroBatiment = 0;

    city->route.prix = 10; // par unité de grille
    city->route.tailleX = 1;
    city->route.tailleY = 1;
    city->route.numeroBatiment = 0;

    city->page.pageJeux.pageJeu = true;

    for (int i = 0; i < 150; i++) {
    }

    city->nombreConstruction = 0;

    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            city->terrain[i][j].nbBatiment=-1;
        }
    }
    for (int i = 0 ; i < MAX_BATIMENT ; i++) {

        city->tabConstruction[i].numeroDesConstructions = 0;
        city->tabConstruction[i].typeDeConstruction = 0;

        city->tabConstruction[i].source = 0;
        city->tabConstruction[i].destination = 0;
        city->tabConstruction[i].longueur = 0;
        city->tabConstruction[i].indiceParcours = 0;
        city->tabConstruction[i].plusCourt = false;
    }




    /////////////////Argent///////
    city->argent = 500000;
    city->nbHabitant = 0;
}