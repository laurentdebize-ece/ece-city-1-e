#include "Structures/structures.h"
#include "Fonctions/Map/map.h"

void test (City* city){
    initDataMap(city);
}

int main () {
    City city = {0};
    test(&city);
    return 0;
}