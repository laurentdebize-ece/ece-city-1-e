#include "affichage.h"
 void affichage(){
    InitWindow(800, 450, "Raylib > Allegro");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    while (!WindowShouldClose()) {
        float f = (float)GetScreenWidth() / (float)GetScreenHeight();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Raylib > Allegro5", 12 * f, 12 * f, 30 * f, BLACK);
        EndDrawing();
    }
}