#include "initialisation.h"


void initialisationHabitation(City * city){

    /////Terrain Vague////////////////

    city->ruine.prix = 1000; // 1000 ECE flouz et apèrs plus de prix car augmente avec compteur
    city->ruine.nhHabitant = 0;
    //city->ruine.capacite = ;
    //city->ruine.matriceX = ;
    //city->ruine.matriceY = ;
    //city->ruine.tailleX = ;
    //city->ruine.tailleY = ;

    ////Cabane///////////////

    //city->cabane.prix = ;
    city->cabane.nhHabitant = 10;
    //city->cabane.capacite = ;
    //city->cabane.matriceX = ;
    //city->cabane.matriceY = ;
    //city->cabane.tailleX = ;
    //city->cabane.tailleY = ;

    /////Maison//////

    //city->maison.prix = ;
    city->maison.nhHabitant = 50;
    //city->maison.capacite = ;
    //city->maison.matriceX = ;
    //city->maison.matriceY = ;
    //city->maison.tailleX = ;
    //city->maison.tailleY = ;

    //////Immeuble////////

    //city->ruine.prix = ;
    city->immeuble.nhHabitant = 100;
    //city->immeuble.capacite = ;
    //city->immeuble.matriceX = ;
    //city->immeuble.matriceY = ;
    //city->immeuble.tailleX = ;
    //city->immeuble.tailleY = ;


    //////Gratte Ciel///////////

    //city->gratteCiel.prix = ;
    city->gratteCiel.nhHabitant = 1000;
    //city->gratteCiel.capacite = ;
    //city->gratteCiel.matriceX = ;
    //city->gratteCiel.matriceY = ;
    //city->gratteCiel.tailleX = ;
    //city->gratteCiel.tailleY = ;

    ////Prix Autre Batiment///
    city->centrale.prix = 100000;
    city->chateauEau.prix =100000;
    city->route.prix= 10; // par unité de grille


    city->chateauEau.capacite = 5000; // alimente 5000 habitants par chateau
    city->centrale.capacite = 5000;// alimente 5000 habitants par centrale


}