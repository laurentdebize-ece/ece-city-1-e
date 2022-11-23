#include "affichage.h"

void dessinerGrille () {
    int traitX = 0, traitY = 100;

    for (int i = 0; i <= LIGNES; i++) {
        DrawLine(traitX, traitY, traitX + 900, traitY, BLACK);
        traitY += 20;
    }
    traitX = 0;
    traitY = 100;
    for (int i = 0; i <= COLONNES; i++) {
        DrawLine(traitX, traitY, traitX, traitY + 700, BLACK);
        traitX += 20;
    }
}

void affichage(City* city){
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "ECE-City");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Image DecorHerbeImage = LoadImage("../Images/land_1.png");
    Image DecorObstacleImage = LoadImage("../Images/stones_1.png");
    Image DecorRouteImage = LoadImage("../Images/Route_Croisement_Gauche.png");
    Texture2D DecorHerbeTexture = LoadTextureFromImage(DecorHerbeImage);
    Texture2D DecorObstacleTexture = LoadTextureFromImage(DecorObstacleImage);
    Texture2D DecorRouteTexture = LoadTextureFromImage(DecorRouteImage);
    UnloadImage(DecorHerbeImage);
    UnloadImage(DecorObstacleImage);
    UnloadImage(DecorRouteImage);

    SetTargetFPS(1080);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLONNES; j++) {

                if(city->terrain[i][j].typeBloc==0) {
                    DrawTexture(DecorHerbeTexture, j * 20, i * 20 + 100, WHITE);
                }
                if (city->terrain[i][j].typeBloc==1){
                    DrawTexture(DecorObstacleTexture, j*20, i*20+100, WHITE);
                }
                if (city->terrain[i][j].typeBloc==2) {
                    DrawTexture(DecorRouteTexture, j*20, i*20+100, WHITE);
                }
            }
        }
        dessinerGrille();

        EndDrawing();
    }
    UnloadTexture(DecorHerbeTexture);
    UnloadTexture(DecorObstacleTexture);
    UnloadTexture(DecorRouteTexture);

    CloseWindow();
}