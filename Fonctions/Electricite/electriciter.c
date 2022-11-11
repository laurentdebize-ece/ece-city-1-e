#include "electriciter.h"


void capaciteTotalElectriciter(City* city){
    city->centrale.capaciteTotal = city->centrale.numeroBatiment * city->centrale.capacite;
}

void alimenteElectricite(City* city){
    nbConstruction(city);
    capaciteTotalElectriciter(city);
    if(city->centrale.capaciteTotal >= city->nbHabitant){
        printf("Toutes les maisons sont alimentees\n");
    }else{
        int manque = city->nbHabitant - city->centrale.capaciteTotal;
        while (city->cabane.numeroBatiment != 0 || manque != 0){
            city->cabane.numeroBatiment--;
            manque-=10;
        }
        while (city->maison.numeroBatiment != 0 || manque != 0){
            city->maison.numeroBatiment--;
            manque-=50;
        }
        while (city->immeuble.numeroBatiment != 0 || manque != 0){
            city->immeuble.numeroBatiment--;
            manque-=100;
        }
        while (city->gratteCiel.numeroBatiment != 0 || manque != 0){
            city->gratteCiel.numeroBatiment--;
            manque-=1000;
        }
    }
}