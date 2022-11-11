#include "eau.h"
void capaciteTotalEau(City* city){
    city->chateauEau.capaciteTotal = city->chateauEau.numeroBatiment * city->chateauEau.capacite;
}

void alimenteEau(City* city){
    nbConstruction(city);
    capaciteTotalEau(city);
    if(city->chateauEau.capaciteTotal >= city->nbHabitant){
        printf("Toute les maissons sont alimenter\n");
    }else{
        int capaciterFestante = city->chateauEau.capaciteTotal;

    }
}