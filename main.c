#include "Structures/structures.h"
#include "Fonctions/Map/map.h"
#include "Fonctions/Initialisation/initialisation.h"
#include "Fonctions/Affichage/affichage.h"


int main() {
    City city = {0};
    initialisationVille(&city);
    initDataMap(&city);
    affichageBoucle(&city);
    return 0;
}