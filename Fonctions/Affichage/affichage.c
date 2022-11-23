#include "affichage.h"

int savoirAffichageRoute(City* city, int i, int j){
    bool haut = false,bas = false,gauche= false ,droite = false;
    if(city->terrain[i][j-1].typeBloc==1){
        gauche = true;
    }
    if(city->terrain[i][j+1].typeBloc==1){
        droite = true;
    }
    if(city->terrain[i-1][j].typeBloc==1){
        haut = true;
    }
    if(city->terrain[i+1][j].typeBloc==1){
        bas = true;
    }
    if(bas&&droite&&!gauche&&!haut){ //Anglet bas droit
        return 0;
    }
    if(!bas && droite && gauche && !haut){ // Route_Horizontale
        return 1;
    }
    if(bas && !droite && !gauche && haut){
        return 2;
    }
    if(bas && !droite && gauche && !haut){
        return 3;
    }
    if(!bas && !droite && gauche && haut){
        return 4;
    }
    if(!bas && droite && !gauche && haut){
        return 5;
    }
    if(!bas && !droite && !gauche && haut){
        return 6;
    }
    if(!bas && droite && !gauche && !haut){
        return 7;
    }
    if(bas && !droite && !gauche && !haut){
        return 8;
    }
    if(!bas && !droite && gauche && !haut){
        return 9;
    }
    if(bas && droite && gauche && haut){
        return 10;
    }
    if(!bas && !droite && !gauche && !haut){ //Angle et bas droit
        return 11;
    }
    return 1000;
}

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

    city->tabBitmapImage[Ruine] = LoadImage("../Images/Construction/Ruines.png");
    city->tabBitmapImage[Cabanne1] = LoadImage("../Images/Construction/Cabanne1.png");
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

    city->tabBitmapImage[PageChargementImage] = LoadImage("../Images/Pages/imageAccueilRedim.png");
    city->tabBitmapImage[PageMenuPrincip] = LoadImage("../Images/Pages/imageChoixRedim.png");
    city->tabBitmapImage[PageChoixMode] = LoadImage("../Images/Pages/imageChoixModeRedim.png");
    city->tabBitmapImage[PageMap] = LoadImage("../Images/Pages/imageMapRedim.png");
    city->tabBitmapImage[PagePrincipaleToolBox] = LoadImage("../Images/Pages/ToolBox.png");



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

    city->tabBitmapTexture[PageChargementImage] = LoadTextureFromImage(city->tabBitmapImage[Building3]);
    city->tabBitmapTexture[PageMenuPrincip] = LoadTextureFromImage(city->tabBitmapImage[PageMenuPrincip]);
    city->tabBitmapTexture[PageChoixMode] = LoadTextureFromImage(city->tabBitmapImage[PageChoixMode]);
    city->tabBitmapTexture[PageMap] = LoadTextureFromImage(city->tabBitmapImage[PageMap]);
    city->tabBitmapTexture[PagePrincipaleToolBox] = LoadTextureFromImage(city->tabBitmapImage[PagePrincipaleToolBox]);

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

    UnloadImage(city->tabBitmapImage[PageChargementImage]);
    UnloadImage(city->tabBitmapImage[PageMenuPrincip]);
    UnloadImage(city->tabBitmapImage[PageChoixMode]);
    UnloadImage(city->tabBitmapImage[PageMap]);
    UnloadImage(city->tabBitmapImage[PagePrincipaleToolBox]);

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

    UnloadTexture(city->tabBitmapTexture[PageChargementImage]);
    UnloadTexture(city->tabBitmapTexture[PageMenuPrincip]);
    UnloadTexture(city->tabBitmapTexture[PageChoixMode]);
    UnloadTexture(city->tabBitmapTexture[PageMap]);
    UnloadTexture(city->tabBitmapTexture[PagePrincipaleToolBox]);

}

void gestionCliqueSouris(City *city) {
    if ((city->mouseX > 963 && city->mouseX < 1028 && city->mouseY > 169 && city->mouseY < 231) &&
        IsMouseButtonDown(0)) {
        city->page.pageJeux.pageJeu = true;
        city->page.pageJeux.toolBox = false;
        city->page.pageReseauEau.pageEau = false;
        city->page.pageReseauElec.pageElectricite = false;
    }
    if ((city->mouseX > 1042 && city->mouseX < 1107 && city->mouseY > 169 && city->mouseY < 231) &&
        IsMouseButtonDown(0)) {
        city->page.pageJeux.pageJeu = false;
        city->page.pageJeux.toolBox = false;
        city->page.pageReseauEau.pageEau = true;
        city->page.pageReseauElec.pageElectricite = false;
    }
    if ((city->mouseX > 1120 && city->mouseX < 1185 && city->mouseY > 169 && city->mouseY < 231) &&
        IsMouseButtonDown(0)) {
        city->page.pageJeux.pageJeu = false;
        city->page.pageJeux.toolBox = false;
        city->page.pageReseauEau.pageEau = false;
        city->page.pageReseauElec.pageElectricite = true;
    }
    if ((city->mouseX > 952 && city->mouseX < 1194 && city->mouseY > 242 && city->mouseY < 413) &&
        IsMouseButtonDown(0)) {
        city->page.pageJeux.pageJeu = false;
        city->page.pageJeux.toolBox = true;
        city->page.pageReseauEau.pageEau = false;
        city->page.pageReseauElec.pageElectricite = false;
    }
}

void initAffichage(City *city) {
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "ECE-City");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    initBitmap(city);

    SetTargetFPS(1080);
    while (!WindowShouldClose()) {
        city->mouseX = GetMouseX();
        city->mouseY = GetMouseY();
        BeginDrawing();
        DrawTexture(city->tabBitmapTexture[PagePrincipaleToolBox], 0, 0, WHITE);

        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLONNES; j++) {
                DrawTexture(city->tabBitmapTexture[DecorHerbeImage], j * 20, i * 20 + 100, WHITE);
                if (i == 0 || i == LIGNES - 1 || j == 0 || j == COLONNES - 1) {
                    DrawTexture(city->tabBitmapTexture[DecorObstacleCaillouImage], j * 20, i * 20 + 100, WHITE);
                    city->terrain[i][j].obstacle = true;
                }
                if (i == 17 && j == 0) {
                    DrawTexture(city->tabBitmapTexture[Route], j * 20, i * 20 + 100, BLACK);
                    city->terrain[i][j].obstacle = true;
                }
            }
        }
        dessinerGrille();

        DrawTexture(city->tabBitmapTexture[Ruine], 20, 300, WHITE);
        DrawTexture(city->tabBitmapTexture[Cabanne1], 80, 300, WHITE);
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

        gestionCliqueSouris(city);

        if (city->page.pageJeux.toolBox) {
            DrawTexture(city->tabBitmapTexture[PagePrincipaleToolBox], 0, 0, WHITE);
        }

        if (city->page.pageReseauElec.pageElectricite) {
            DrawRectangle(0, 99, 900, 800, WHITE);
        }

        EndDrawing();
    }
    unloadTexture(city);
    CloseWindow();
}

void affichageBoucle(City *city) {
    int nbConstru =0;
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "ECE-City");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    initBitmap(city);

    SetTargetFPS(1080);
    while (!WindowShouldClose()) {
        ClearBackground(RAYWHITE);
        gestionCliqueSouris(city);
        city->mouseX = GetMouseX();
        city->mouseY = GetMouseY();
        BeginDrawing();
        DrawTexture(city->tabBitmapTexture[PageMap], 0, 0, WHITE);
        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLONNES; j++) {
                DrawTexture(city->tabBitmapTexture[DecorHerbeImage], j * 20, i * 20 + 100, WHITE);
            }
        }
        dessinerGrille();

        if (city->page.pageJeux.toolBox) {
            DrawTexture(city->tabBitmapTexture[PagePrincipaleToolBox], 0, 0, WHITE);
        }

        if (city->page.pageReseauElec.pageElectricite) {
            DrawRectangle(0, 99, 900, 800, WHITE);
        }

        if (city->page.pageJeux.pageJeu) {

        } else if (city->page.pageReseauEau.pageEau) {

        } else if (city->page.pageReseauElec.pageElectricite) {

        }
        dessinerGrille();

        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLONNES; j++) {
                if (city->terrain[i][j].typeBloc == 1) {
                    DrawTexture(city->tabBitmapTexture[DecorObstacleCaillouImage], j * 20, i * 20 + 100, WHITE);
                    city->terrain[i][j].obstacle = true;
                }
                if (city->terrain[i][j].typeBloc==2) {
                    if(savoirAffichageRoute(city,i,j)==0){
                        DrawTexture(city->tabBitmapTexture[Route_Angle_Droite_Bas],j*20,i*20+100,WHITE);
                    }
                    else if(savoirAffichageRoute(city,i,j)==1){
                        DrawTexture(city->tabBitmapTexture[Route_Horizontale],j*20,i*20+100,WHITE);
                    }
                    else if(savoirAffichageRoute(city,i,j)==2){
                        DrawTexture(city->tabBitmapTexture[Route_Verticale],j*20,i*20+100,WHITE);
                    }
                    else if(savoirAffichageRoute(city,i,j)==3){
                        DrawTexture(city->tabBitmapTexture[Route_Angle_Gauche_Bas],j*20,i*20+100,WHITE);
                    }
                    else if(savoirAffichageRoute(city,i,j)==4){
                        DrawTexture(city->tabBitmapTexture[Route_Angle_Gauche_Haut],j*20,i*20+100,WHITE);
                    }
                    else if(savoirAffichageRoute(city,i,j)==5){
                        DrawTexture(city->tabBitmapTexture[Route_Angle_Droite_Haut],j*20,i*20+100,WHITE);
                    }
                    else if(savoirAffichageRoute(city,i,j)==6){
                        DrawTexture(city->tabBitmapTexture[Route_Croisement_Haut],j*20,i*20+100,WHITE);
                    }
                    else if(savoirAffichageRoute(city,i,j)==7){
                        DrawTexture(city->tabBitmapTexture[Route_Croisement_Droite],j*20,i*20+100,WHITE);
                    }
                    else if(savoirAffichageRoute(city,i,j)==8){
                        DrawTexture(city->tabBitmapTexture[Route_Croisement_Bas],j*20,i*20+100,WHITE);
                    }
                    else if(savoirAffichageRoute(city,i,j)==9){
                        DrawTexture(city->tabBitmapTexture[Route_Croisement_Gauche],j*20,i*20+100,WHITE);
                    }
                    else if(savoirAffichageRoute(city,i,j)==10){
                        DrawTexture(city->tabBitmapTexture[Route_Carrefour],j*20,i*20+100,WHITE);
                    }
                    else if(savoirAffichageRoute(city,i,j)==11){
                        DrawTexture(city->tabBitmapTexture[Route],j*20,i*20+100,WHITE);
                    }
                    else {
                        DrawTexture(city->tabBitmapTexture[Route], j * 20, i * 20 + 100, BLACK);
                        city->terrain[i][j].obstacle = true;
                    }
                }
                if (city->terrain[i][j].typeBloc==3 &&  city->terrain[i-1][j].typeBloc!=3 && city->terrain[i][j-1].typeBloc!=3) {
                    DrawTexture(city->tabBitmapTexture[House2], j * 20, i * 20 + 100, WHITE);
                    nbConstru++;
                }
                if (city->terrain[i][j].typeBloc==4 &&  city->terrain[i-1][j].typeBloc!=4 && city->terrain[i][j-1].typeBloc!=4) {
                    DrawTexture(city->tabBitmapTexture[House3], j * 20, i * 20 + 100, WHITE);
                    nbConstru++;
                }
                if (city->terrain[i][j].typeBloc==5 &&  city->terrain[i-1][j].typeBloc!=5 && city->terrain[i][j-1].typeBloc!=5) {
                    DrawTexture(city->tabBitmapTexture[House1],  j * 20,  i * 20 + 100, WHITE);
                    city->terrain[i][j].obstacle = true;
                }
                if (city->terrain[i][j].typeBloc==6 &&  city->terrain[i-1][j].typeBloc!=6 && city->terrain[i][j-1].typeBloc!=6) {
                    DrawTexture(city->tabBitmapTexture[Immeuble2], j * 20, i * 20 + 100, WHITE);
                    nbConstru++;
                    city->terrain[i][j].obstacle = true;
                }
                if (city->terrain[i][j].typeBloc==7 &&  city->terrain[i-1][j].typeBloc!=7 && city->terrain[i][j-1].typeBloc!=7) {
                    DrawTexture(city->tabBitmapTexture[Building3], j * 20, i * 20 + 100, WHITE);
                    nbConstru++;
                    city->terrain[i][j].obstacle = true;
                }
                if (city->terrain[i][j].typeBloc==8 &&  city->terrain[i-1][j].typeBloc!=8 && city->terrain[i][j-1].typeBloc!=8) {
                    DrawTexture(city->tabBitmapTexture[Building2], j * 20, i * 20 + 100, WHITE);
                    nbConstru++;
                    city->terrain[i][j].obstacle = true;
                }
                if (city->terrain[i][j].typeBloc == 9 && city->terrain[i - 1][j].typeBloc != 9 &&
                    city->terrain[i][j - 1].typeBloc != 9) {
                    DrawTexture(city->tabBitmapTexture[Building1], j * 20, i * 20 + 100, WHITE);
                    nbConstru++;
                    city->terrain[i][j].obstacle = true;
                }
            }
        }
        if (city->page.pageReseauElec.pageElectricite) {
            DrawRectangle(0, 99, 900, 800, WHITE);
        }

        EndDrawing();
    }
    unloadTexture(city);
    CloseWindow();
}
