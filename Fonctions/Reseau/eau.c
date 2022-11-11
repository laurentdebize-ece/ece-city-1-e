#include "eau.h"
void capaciteTotalEau(City* city){
    city->CapaciteTotalEau = city->chateauEau.numeroBatiment *city->chateauEau.capacite;
}

void alimenteElectricite(City* city){
    nbConstruction(city);
    capaciteTotalEau(city);
    if(city->CapaciteTotalElectriciter >= city->nbHabitant){
        printf("Toute les maisons sont alimenter en eau");
    }else{
        int manque = city->nbHabitant - city->CapaciteTotalElectriciter;

    }
}