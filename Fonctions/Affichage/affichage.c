#include "affichage.h"

void dessinerGrille() {
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

//CheckCollisionPointRec();

void initBitmap(City *city) {
    //IMAGE
    city->tabBitmapImage[DecorHerbeImage] = LoadImage("../Images/Decor/land_1.png");
    city->tabBitmapImage[DecorObstacleCaillouImage] = LoadImage("../Images/Bordure/stones_1.png");

    city->tabBitmapImage[Route_Verticale] = LoadImage("../Images/Route/Route_Verticale.png");
    city->tabBitmapImage[Route_Horizontale] = LoadImage("../Images/Route/Route_Horizontale.png");
    city->tabBitmapImage[Route_Angle_Droite_Bas] = LoadImage("../Images/Route/Route_Angle_Droite_Bas.png");
    city->tabBitmapImage[Route_Angle_Droite_Haut] = LoadImage("../Images/Route/Route_Angle_Droite_Haut.png");
    city->tabBitmapImage[Route_Angle_Gauche_Bas] = LoadImage("../Images/Route/Route_Angle_Gauche_Bas.png");
    city->tabBitmapImage[Route_Angle_Gauche_Haut] = LoadImage("../Images/Route/Route_Angle_Gauche_Haut.png");
    city->tabBitmapImage[Route_Croisement_Bas] = LoadImage("../Images/Route/Route_Croisement_Bas.png");
    city->tabBitmapImage[Route_Croisement_Droite] = LoadImage("../Images/Route/Route_Croisement_Droite.png");
    city->tabBitmapImage[Route_Croisement_Gauche] = LoadImage("../Images/Route/Route_Croisement_Gauche.png");
    city->tabBitmapImage[Route_Croisement_Haut] = LoadImage("../Images/Route/Route_Croisement_Haut.png");
    city->tabBitmapImage[Route_Carrefour] = LoadImage("../Images/Route/Route_Carrefour.png");
    city->tabBitmapImage[Route] = LoadImage("../Images/Route/Route.png");

    city->tabBitmapImage[Ruine] = LoadImage("../Images/Route/Ruines.png");
    city->tabBitmapImage[Cabanne1] = LoadImage("../Images/Route/Cabanne1.png");
    city->tabBitmapImage[House1] = LoadImage("../Images/Construction/House1.png");
    city->tabBitmapImage[House2] = LoadImage("../Images/Construction/House2.png");
    city->tabBitmapImage[House3] = LoadImage("../Images/Construction/House3.png");
    city->tabBitmapImage[House4] = LoadImage("../Images/Construction/House4.png");
    city->tabBitmapImage[House5] = LoadImage("../Images/Construction/House5.png");
    city->tabBitmapImage[House6] = LoadImage("../Images/Construction/House6.png");
    city->tabBitmapImage[Immeuble1] = LoadImage("../Images/Construction/Immeuble1.png");
    city->tabBitmapImage[Immeuble2] = LoadImage("../Images/Construction/Immeuble2.png");
    city->tabBitmapImage[Building1] = LoadImage("../Images/Construction/building1.png");
    city->tabBitmapImage[Building2] = LoadImage("../Images/Construction/Building2.png");
    city->tabBitmapImage[Building3] = LoadImage("../Images/Construction/Building3.png");



    // TEXTURE
    city->tabBitmapTexture[DecorHerbeImage] = LoadTextureFromImage(city->tabBitmapImage[DecorHerbeImage]);
    city->tabBitmapTexture[DecorObstacleCaillouImage] = LoadTextureFromImage(
            city->tabBitmapImage[DecorObstacleCaillouImage]);

    city->tabBitmapTexture[Route_Verticale] = LoadTextureFromImage(city->tabBitmapImage[Route_Verticale]);
    city->tabBitmapTexture[Route_Horizontale] = LoadTextureFromImage(city->tabBitmapImage[Route_Horizontale]);
    city->tabBitmapTexture[Route_Angle_Droite_Bas] = LoadTextureFromImage(city->tabBitmapImage[Route_Angle_Droite_Bas]);
    city->tabBitmapTexture[Route_Angle_Droite_Haut] = LoadTextureFromImage(
            city->tabBitmapImage[Route_Angle_Droite_Haut]);
    city->tabBitmapTexture[Route_Angle_Gauche_Bas] = LoadTextureFromImage(city->tabBitmapImage[Route_Angle_Gauche_Bas]);
    city->tabBitmapTexture[Route_Angle_Gauche_Haut] = LoadTextureFromImage(
            city->tabBitmapImage[Route_Angle_Gauche_Haut]);
    city->tabBitmapTexture[Route_Croisement_Bas] = LoadTextureFromImage(city->tabBitmapImage[Route_Croisement_Bas]);
    city->tabBitmapTexture[Route_Croisement_Droite] = LoadTextureFromImage(
            city->tabBitmapImage[Route_Croisement_Droite]);
    city->tabBitmapTexture[Route_Croisement_Gauche] = LoadTextureFromImage(
            city->tabBitmapImage[Route_Croisement_Gauche]);
    city->tabBitmapTexture[Route_Croisement_Haut] = LoadTextureFromImage(city->tabBitmapImage[Route_Croisement_Haut]);
    city->tabBitmapTexture[Route_Carrefour] = LoadTextureFromImage(city->tabBitmapImage[Route_Carrefour]);
    city->tabBitmapTexture[Route] = LoadTextureFromImage(city->tabBitmapImage[Route]);

    city->tabBitmapTexture[Ruine] = LoadTextureFromImage(city->tabBitmapImage[Ruine]);
    city->tabBitmapTexture[Cabanne1] = LoadTextureFromImage(city->tabBitmapImage[Cabanne1]);
    city->tabBitmapTexture[House1] = LoadTextureFromImage(city->tabBitmapImage[House1]);
    city->tabBitmapTexture[House2] = LoadTextureFromImage(city->tabBitmapImage[House2]);
    city->tabBitmapTexture[House3] = LoadTextureFromImage(city->tabBitmapImage[House3]);
    city->tabBitmapTexture[House4] = LoadTextureFromImage(city->tabBitmapImage[House4]);
    city->tabBitmapTexture[House5] = LoadTextureFromImage(city->tabBitmapImage[House5]);
    city->tabBitmapTexture[House6] = LoadTextureFromImage(city->tabBitmapImage[House6]);
    city->tabBitmapTexture[Immeuble1] = LoadTextureFromImage(city->tabBitmapImage[Immeuble1]);
    city->tabBitmapTexture[Immeuble2] = LoadTextureFromImage(city->tabBitmapImage[Immeuble2]);
    city->tabBitmapTexture[Building1] = LoadTextureFromImage(city->tabBitmapImage[Building1]);
    city->tabBitmapTexture[Building2] = LoadTextureFromImage(city->tabBitmapImage[Building2]);
    city->tabBitmapTexture[Building3] = LoadTextureFromImage(city->tabBitmapImage[Building3]);

    //UNLOAD IMAGE
    UnloadImage(city->tabBitmapImage[DecorHerbeImage]);
    UnloadImage(city->tabBitmapImage[DecorObstacleCaillouImage]);

    UnloadImage(city->tabBitmapImage[Route_Verticale]);
    UnloadImage(city->tabBitmapImage[Route_Horizontale]);
    UnloadImage(city->tabBitmapImage[Route_Angle_Droite_Bas]);
    UnloadImage(city->tabBitmapImage[Route_Angle_Droite_Haut]);
    UnloadImage(city->tabBitmapImage[Route_Angle_Gauche_Bas]);
    UnloadImage(city->tabBitmapImage[Route_Angle_Gauche_Haut]);
    UnloadImage(city->tabBitmapImage[Route_Croisement_Bas]);
    UnloadImage(city->tabBitmapImage[Route_Croisement_Droite]);
    UnloadImage(city->tabBitmapImage[Route_Croisement_Gauche]);
    UnloadImage(city->tabBitmapImage[Route_Croisement_Haut]);
    UnloadImage(city->tabBitmapImage[Route_Carrefour]);
    UnloadImage(city->tabBitmapImage[Route]);

    UnloadImage(city->tabBitmapImage[Ruine]);
    UnloadImage(city->tabBitmapImage[Cabanne1]);
    UnloadImage(city->tabBitmapImage[House1]);
    UnloadImage(city->tabBitmapImage[House2]);
    UnloadImage(city->tabBitmapImage[House3]);
    UnloadImage(city->tabBitmapImage[House4]);
    UnloadImage(city->tabBitmapImage[House5]);
    UnloadImage(city->tabBitmapImage[House6]);
    UnloadImage(city->tabBitmapImage[Immeuble1]);
    UnloadImage(city->tabBitmapImage[Immeuble2]);
    UnloadImage(city->tabBitmapImage[Building1]);
    UnloadImage(city->tabBitmapImage[Building2]);
    UnloadImage(city->tabBitmapImage[Building3]);

}

void unloadTexture(City *city) {
    UnloadTexture(city->tabBitmapTexture[DecorHerbeImage]);
    UnloadTexture(city->tabBitmapTexture[DecorObstacleCaillouImage]);

    UnloadTexture(city->tabBitmapTexture[Route_Verticale]);
    UnloadTexture(city->tabBitmapTexture[Route_Horizontale]);
    UnloadTexture(city->tabBitmapTexture[Route_Angle_Droite_Bas]);
    UnloadTexture(city->tabBitmapTexture[Route_Angle_Droite_Haut]);
    UnloadTexture(city->tabBitmapTexture[Route_Angle_Gauche_Bas]);
    UnloadTexture(city->tabBitmapTexture[Route_Angle_Gauche_Haut]);
    UnloadTexture(city->tabBitmapTexture[Route_Croisement_Bas]);
    UnloadTexture(city->tabBitmapTexture[Route_Croisement_Droite]);
    UnloadTexture(city->tabBitmapTexture[Route_Croisement_Gauche]);
    UnloadTexture(city->tabBitmapTexture[Route_Croisement_Haut]);
    UnloadTexture(city->tabBitmapTexture[Route_Carrefour]);
    UnloadTexture(city->tabBitmapTexture[Route]);

    UnloadTexture(city->tabBitmapTexture[Ruine]);
    UnloadTexture(city->tabBitmapTexture[Cabanne1]);
    UnloadTexture(city->tabBitmapTexture[House1]);
    UnloadTexture(city->tabBitmapTexture[House2]);
    UnloadTexture(city->tabBitmapTexture[House3]);
    UnloadTexture(city->tabBitmapTexture[House4]);
    UnloadTexture(city->tabBitmapTexture[House5]);
    UnloadTexture(city->tabBitmapTexture[House6]);
    UnloadTexture(city->tabBitmapTexture[Immeuble1]);
    UnloadTexture(city->tabBitmapTexture[Immeuble2]);
    UnloadTexture(city->tabBitmapTexture[Building1]);
    UnloadTexture(city->tabBitmapTexture[Building2]);
    UnloadTexture(city->tabBitmapTexture[Building3]);
}

void affichage(City *city) {
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "ECE-City");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    initBitmap(city);

    SetTargetFPS(1080);
    while (!WindowShouldClose()) {
        ClearBackground(RAYWHITE);
        BeginDrawing();

        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLONNES; j++) {
                DrawTexture(city->tabBitmapTexture[DecorHerbeImage], j * 20, i * 20 + 100, WHITE);
                if ( i == 0 || i == LIGNES - 1 || j == 0 || j == COLONNES - 1) {
                    DrawTexture(city->tabBitmapTexture[DecorObstacleCaillouImage], j * 20, i * 20 + 100 , WHITE);
                    city->terrain[i][j].obstacle = true;
                }
                if ( i == 17 && j == 0) {
                    DrawTexture(city->tabBitmapTexture[Route], j * 20, i * 20 + 100, BLACK);
                    city->terrain[i][j].obstacle = true;
                }
            }
        }
        dessinerGrille();

        DrawTexture(city->tabBitmapTexture[House1], 20, 200, WHITE);
        DrawTexture(city->tabBitmapTexture[House2], 80, 200, WHITE);
        DrawTexture(city->tabBitmapTexture[House3], 140, 200, WHITE);
        DrawTexture(city->tabBitmapTexture[House4], 200, 200, WHITE);
        DrawTexture(city->tabBitmapTexture[House5], 260, 200, WHITE);
        DrawTexture(city->tabBitmapTexture[House6], 320, 200, WHITE);
        DrawTexture(city->tabBitmapTexture[Immeuble1], 380, 200, WHITE);
        DrawTexture(city->tabBitmapTexture[Immeuble2], 440, 200, WHITE);
        DrawTexture(city->tabBitmapTexture[Building1], 500, 200, WHITE);
        DrawTexture(city->tabBitmapTexture[Building2], 560, 200, WHITE);
        DrawTexture(city->tabBitmapTexture[Building3], 620, 200, WHITE);

        EndDrawing();
    }
    unloadTexture(city);
    CloseWindow();
}