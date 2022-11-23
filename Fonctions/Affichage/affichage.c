#include "affichage.h"

void affichage(){
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "ECE-City");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Image DecorHerbeImage = LoadImage("../Images/land_1.png");
    Texture2D DecorHerbeTexture = LoadTextureFromImage(DecorHerbeImage);
    UnloadImage(DecorHerbeImage);

    SetTargetFPS(1080);
    while (!WindowShouldClose()) {
        float f = (float)GetScreenWidth() / (float)GetScreenHeight();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLONNES; j++) {
                DrawTexture(DecorHerbeTexture, j*20, i*20+100, WHITE);
            }
        }

        EndDrawing();
    }
    UnloadTexture(DecorHerbeTexture);

    CloseWindow();
}