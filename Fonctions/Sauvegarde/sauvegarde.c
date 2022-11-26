#include "sauvegarde.h"

void sauvegarderPartie (City *city, char* nomFichier) {
    FILE *file = fopen(nomFichier, "w");
    if (!file) {
        printf("Erreur d'écriture dans le fichier\n");
        exit(-1);
    }
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            fprintf(file, " %d", (city->terrain[i][j].typeBloc));
        }
        fprintf(file, "\n");
    }
    fprintf(file, " %d\n", city->nbHabitant);
    fprintf(file, " %d\n", city->argent);
    fclose(file);
}
