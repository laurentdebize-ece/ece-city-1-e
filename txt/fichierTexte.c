#include "fichierTexte.h"

void lireFichierTexte (char *nomFichier, City* city) {
    FILE *file = fopen(nomFichier, "r");
    if (!file) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            fscanf(file, " %d", &(city->terrain[i][j].typeBloc));
        }
    }
    fscanf(file, " %d", &city->nbHabitant);
    fscanf(file, " %d", &city->argent);
    fscanf(file, " %d", &city->mode);
    fclose(file);
}