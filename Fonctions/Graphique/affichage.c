#include "affichage.h"

#define LARGEUR_ECRAN 1024
#define HAUTEUR_ECRAN 768

void affichage(){
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "ECE-City");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    while (!WindowShouldClose()) {
        float f = (float)GetScreenWidth() / (float)GetScreenHeight();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Raylib > Allegro5", 12 * f, 12 * f, 30 * f, BLACK);
        EndDrawing();
    }
}