#include "sauvegarde.h"

void sauvegarderPartie (City *city, char* nomFichier) {
    FILE *file = fopen(nomFichier, "w");
    if (!file) {
        printf("Erreur d'écriture dans le fichier\n");
        exit(-1);
    }
    for (int i = 1; i < LIGNES-1; i++) {
        for (int j = 1; j < COLONNES-1; j++) {
            fprintf(file, " %d", (city->terrain[i][j].typeBloc));
        }
        fprintf(file, "\n");
    }
    fclose(file);
}
