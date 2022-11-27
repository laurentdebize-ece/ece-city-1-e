#include "electriciter.h"

void capaciteTotalElectriciter(City *city) {
    city->centrale.capaciteTotal = city->centrale.numeroBatiment * city->centrale.capacite;
}

void consommationElectrique(City *city) {
    capaciteTotalElectriciter(city);
    city->centrale.flot = city->centrale.capaciteTotal - city->nbHabitant;
}

void alimenteElectricite(City *city) {
    nbConstruction(city);
    capaciteTotalElectriciter(city);
    int cabaneAlimente= city->cabane.numeroBatiment, maisonAlimente=city->maison.numeroBatiment,immeubleAlimente=city->immeuble.numeroBatiment,gratteCielAlimente=city->gratteCiel.numeroBatiment;
    if (city->centrale.capaciteTotal >= city->nbHabitant) {
        printf("Toutes les maisons sont alimentees\n");
    } else {
        int manque = city->nbHabitant - city->centrale.capaciteTotal;
        while (cabaneAlimente != 0 || manque != 0) {
           cabaneAlimente--;
            manque -= 10;
        }
        while (maisonAlimente != 0 || manque != 0) {
            maisonAlimente--;
            manque -= 50;
        }
        while (immeubleAlimente != 0 || manque != 0) {
            immeubleAlimente--;
            manque -= 100;
        }
        while (gratteCielAlimente != 0 || manque != 0) {
            gratteCielAlimente--;
            manque -= 1000;
        }
    }
}