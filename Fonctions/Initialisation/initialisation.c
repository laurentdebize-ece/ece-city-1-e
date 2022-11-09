#include "initialisation.h"


void initialisationVille (City * city) {

    //---------------- Terrain Vague ----------------//

    city->ruine.prix = 1000; // 1000 ECE flouz et apèrs plus de prix car augmente avec compteur
    city->ruine.nbHabitant = 0;
    //city->ruine.capacite = ;
    //city->ruine.matriceX = ;
    //city->ruine.matriceY = ;
    city->ruine.tailleX = 3;
    city->ruine.tailleY = 3;

    //---------------- Cabanne ----------------//

    city->cabane.nbHabitant = 10;
    //city->cabane.capacite = ;
    //city->cabane.matriceX = ;
    //city->cabane.matriceY = ;
    city->cabane.tailleX = 3;
    city->cabane.tailleY = 3;

    //---------------- Maison ----------------//

    city->maison.nbHabitant = 50;
    //city->maison.capacite = ;
    //city->maison.matriceX = ;
    //city->maison.matriceY = ;
    city->maison.tailleX = 3;
    city->maison.tailleY = 3;

    //---------------- Immeuble ----------------//

    city->immeuble.nbHabitant = 100;
    //city->immeuble.capacite = ;
    //city->immeuble.matriceX = ;
    //city->immeuble.matriceY = ;
    city->immeuble.tailleX = 3;
    city->immeuble.tailleY = 3;


    //---------------- Gratte Ciel ----------------//

    city->gratteCiel.nbHabitant = 1000;
    //city->gratteCiel.capacite = ;
    //city->gratteCiel.matriceX = ;
    //city->gratteCiel.matriceY = ;
    city->gratteCiel.tailleX = 3;
    city->gratteCiel.tailleY = 3;

    //---------------- Autre ----------------//
    city->centrale.prix = 100000;
    city->centrale.capacite = 5000;
    city->centrale.tailleX = 4;
    city->centrale.tailleY = 6;

    city->chateauEau.prix = 100000;
    city->chateauEau.capacite = 5000;
    city->chateauEau.tailleX = 4;
    city->chateauEau.tailleY = 6;

    city->route.prix = 10; // par unité de grille
    city->route.tailleX = 1;
    city->route.tailleY = 1;

    /////////////////Argent///////
    city->argent = 500000;
    city->nbHabitant = 0;
}