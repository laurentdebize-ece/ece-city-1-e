#include "affichage.h"

// FONCTION SON

// Music musique = LoadMusicStream("../Music/..")
// PlayMusicStream(musique)
// Pause Resume STop

int savoirAffichageRoute(City *city, int i, int j) {
    bool haut = false, bas = false, gauche = false, droite = false;
    if (city->terrain[i][j - 1].typeBloc == 2) {
        gauche = true;
    }
    if (city->terrain[i][j + 1].typeBloc == 2) {
        droite = true;
    }
    if (city->terrain[i - 1][j].typeBloc == 2) {
        haut = true;
    }
    if (city->terrain[i + 1][j].typeBloc == 2) {
        bas = true;
    }
    if (bas && droite && !gauche && !haut) { //Angle bas droit
        return 0;
    }
    if ((!bas && droite && gauche && !haut) || (!bas && !droite && gauche && !haut) ||
        (!bas && droite && !gauche && !haut)) { // Route_Horizontale
        return 1;
    }
    if ((bas && !droite && !gauche && haut) || (bas && !droite && !gauche && !haut) ||
        (!bas && !droite && !gauche && haut)) {
        return 2;
    }
    if (bas && !droite && gauche && !haut) {
        return 3;
    }
    if (!bas && !droite && gauche && haut) {
        return 4;
    }
    if (!bas && droite && !gauche && haut) {
        return 5;
    }
    if (!bas && droite && gauche && haut) {
        return 6;
    }
    if (bas && droite && !gauche && haut) {
        return 7;
    }
    if (bas && droite && gauche && !haut) {
        return 8;
    }
    if (bas && !droite && gauche && haut) {
        return 9;
    }
    return 10;
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

void initBitmap(City *city) {
    //IMAGE
    city->tabBitmapImage[DecorHerbeImage] = LoadImage("../Images/Decor/land_1.png");
    city->tabBitmapImage[DecorObstacleCaillouImage] = LoadImage("../Images/Bordure/stones_1.png");

    city->tabBitmapImage[Croix] = LoadImage("../Images/Croix.png");

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
    city->tabBitmapImage[PageMenuJeu] = LoadImage("../Images/Pages/PageMenuJeu.png");
    city->tabBitmapImage[PageQuitterSauvegarde] = LoadImage("../Images/Pages/PageQuitterSauvegarde.png");
    city->tabBitmapImage[PageSauvegardeEffectuer] = LoadImage("../Images/Pages/PageSauvegardeEffectuer.png");
    city->tabBitmapImage[PageRouteSelectionner] = LoadImage("../Images/Pages/PageRouteSelectionner.png");
    city->tabBitmapImage[PageHabitationSelectionner] = LoadImage("../Images/Pages/PageHabitationSelectionner.png");
    city->tabBitmapImage[PageChateauSelectionner] = LoadImage("../Images/Pages/PageChateauSelectionner.png");
    city->tabBitmapImage[PageCentraleSelectionner] = LoadImage("../Images/Pages/PageCentraleSelectionner.png");
    city->tabBitmapImage[Niveau0] = LoadImage("../Images/Pages/Niveau0.png");
    city->tabBitmapImage[Niveau1] = LoadImage("../Images/Pages/Niveau-1.png");
    city->tabBitmapImage[Niveau2] = LoadImage("../Images/Pages/Niveau-2.png");



    // TEXTURE
    city->tabBitmapTexture[DecorHerbeImage] = LoadTextureFromImage(city->tabBitmapImage[DecorHerbeImage]);
    city->tabBitmapTexture[DecorObstacleCaillouImage] = LoadTextureFromImage(
            city->tabBitmapImage[DecorObstacleCaillouImage]);

    city->tabBitmapTexture[Croix] = LoadTextureFromImage(city->tabBitmapImage[Croix]);

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

    city->tabBitmapTexture[PageRouteSelectionner] = LoadTextureFromImage(city->tabBitmapImage[PageRouteSelectionner]);
    city->tabBitmapTexture[PageHabitationSelectionner] = LoadTextureFromImage(
            city->tabBitmapImage[PageHabitationSelectionner]);
    city->tabBitmapTexture[PageChateauSelectionner] = LoadTextureFromImage(
            city->tabBitmapImage[PageChateauSelectionner]);
    city->tabBitmapTexture[PageCentraleSelectionner] = LoadTextureFromImage(
            city->tabBitmapImage[PageCentraleSelectionner]);
    city->tabBitmapTexture[PageChargementImage] = LoadTextureFromImage(city->tabBitmapImage[Building3]);
    city->tabBitmapTexture[PageMenuPrincip] = LoadTextureFromImage(city->tabBitmapImage[PageMenuPrincip]);
    city->tabBitmapTexture[PageChoixMode] = LoadTextureFromImage(city->tabBitmapImage[PageChoixMode]);
    city->tabBitmapTexture[PageMap] = LoadTextureFromImage(city->tabBitmapImage[PageMap]);
    city->tabBitmapTexture[PagePrincipaleToolBox] = LoadTextureFromImage(city->tabBitmapImage[PagePrincipaleToolBox]);
    city->tabBitmapTexture[PageMenuJeu] = LoadTextureFromImage(city->tabBitmapImage[PageMenuJeu]);
    city->tabBitmapTexture[PageQuitterSauvegarde] = LoadTextureFromImage(city->tabBitmapImage[PageQuitterSauvegarde]);
    city->tabBitmapTexture[PageSauvegardeEffectuer] = LoadTextureFromImage(
            city->tabBitmapImage[PageSauvegardeEffectuer]);
    city->tabBitmapTexture[Niveau0] = LoadTextureFromImage(city->tabBitmapImage[Niveau0]);
    city->tabBitmapTexture[Niveau1] = LoadTextureFromImage(city->tabBitmapImage[Niveau1]);
    city->tabBitmapTexture[Niveau2] = LoadTextureFromImage(city->tabBitmapImage[Niveau2]);

    //UNLOAD IMAGE
    UnloadImage(city->tabBitmapImage[DecorHerbeImage]);
    UnloadImage(city->tabBitmapImage[DecorObstacleCaillouImage]);

    UnloadImage(city->tabBitmapImage[Croix]);

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

    UnloadImage(city->tabBitmapImage[PageRouteSelectionner]);
    UnloadImage(city->tabBitmapImage[PageHabitationSelectionner]);
    UnloadImage(city->tabBitmapImage[PageChateauSelectionner]);
    UnloadImage(city->tabBitmapImage[PageCentraleSelectionner]);
    UnloadImage(city->tabBitmapImage[PageChargementImage]);
    UnloadImage(city->tabBitmapImage[PageMenuPrincip]);
    UnloadImage(city->tabBitmapImage[PageChoixMode]);
    UnloadImage(city->tabBitmapImage[PageMap]);
    UnloadImage(city->tabBitmapImage[PagePrincipaleToolBox]);
    UnloadImage(city->tabBitmapImage[PageMenuJeu]);
    UnloadImage(city->tabBitmapImage[PageQuitterSauvegarde]);
    UnloadImage(city->tabBitmapImage[PageSauvegardeEffectuer]);
    UnloadImage(city->tabBitmapImage[Niveau0]);
    UnloadImage(city->tabBitmapImage[Niveau1]);
    UnloadImage(city->tabBitmapImage[Niveau2]);

}

void unloadTexture(City *city) {
    UnloadTexture(city->tabBitmapTexture[DecorHerbeImage]);
    UnloadTexture(city->tabBitmapTexture[DecorObstacleCaillouImage]);

    UnloadTexture(city->tabBitmapTexture[Croix]);

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
    UnloadTexture(city->tabBitmapTexture[PageMenuJeu]);
    UnloadTexture(city->tabBitmapTexture[PageQuitterSauvegarde]);
    UnloadTexture(city->tabBitmapTexture[PageSauvegardeEffectuer]);
    UnloadTexture(city->tabBitmapTexture[PageRouteSelectionner]);
    UnloadTexture(city->tabBitmapTexture[PageHabitationSelectionner]);
    UnloadTexture(city->tabBitmapTexture[PageChateauSelectionner]);
    UnloadTexture(city->tabBitmapTexture[PageCentraleSelectionner]);
    UnloadTexture(city->tabBitmapTexture[Niveau0]);
    UnloadTexture(city->tabBitmapTexture[Niveau1]);
    UnloadTexture(city->tabBitmapTexture[Niveau2]);

}

void gestionCliqueSouris(City *city) {
    //Bouton lvl0
    if ((city->mouseX > 963 && city->mouseX < 1028 && city->mouseY > 169 && city->mouseY < 231) &&
        IsMouseButtonDown(0)) {
        city->page.pageJeux.pageJeu = true;
        city->page.pageJeux.menu = false;
        city->page.pageJeux.aide = false;
        city->page.pageJeux.sauvegarde = false;
        city->page.pageJeux.quitter = false;
        city->page.pageReseauEau.pageEau = false;
        city->page.pageReseauElec.pageElectricite = false;
        city->page.pageJeux.BatimentRoute = false;
        city->page.pageJeux.BatimentHabitation = false;
        city->page.pageJeux.BatimentEau = false;
        city->page.pageJeux.BatimentElec = false;
        city->page.pageJeux.menu = false;
        city->page.pageJeux.croix = false;
    }
    //Bouton lvl -1
    if ((city->mouseX > 1042 && city->mouseX < 1107 && city->mouseY > 169 && city->mouseY < 231) &&
        IsMouseButtonDown(0)) {
        city->page.pageJeux.pageJeu = false;
        city->page.pageJeux.menu = false;
        city->page.pageJeux.aide = false;
        city->page.pageJeux.sauvegarde = false;
        city->page.pageJeux.quitter = false;
        city->page.pageReseauEau.pageEau = true;
        city->page.pageReseauElec.pageElectricite = false;
        city->page.pageJeux.BatimentRoute = false;
        city->page.pageJeux.BatimentHabitation = false;
        city->page.pageJeux.BatimentEau = false;
        city->page.pageJeux.BatimentElec = false;
        city->page.pageJeux.menu = false;
        city->page.pageJeux.croix = false;
    }
    //Bouton lvl -2
    if ((city->mouseX > 1120 && city->mouseX < 1185 && city->mouseY > 169 && city->mouseY < 231) &&
        IsMouseButtonDown(0)) {
        city->page.pageJeux.pageJeu = false;
        city->page.pageJeux.menu = false;
        city->page.pageJeux.aide = false;
        city->page.pageJeux.sauvegarde = false;
        city->page.pageJeux.quitter = false;
        city->page.pageReseauEau.pageEau = false;
        city->page.pageReseauElec.pageElectricite = true;
        city->page.pageJeux.BatimentRoute = false;
        city->page.pageJeux.BatimentHabitation = false;
        city->page.pageJeux.BatimentEau = false;
        city->page.pageJeux.BatimentElec = false;
        city->page.pageJeux.menu = false;
        city->page.pageJeux.croix = false;
    }
    //Bouton Déroulant menu
    if ((city->mouseX > 19 && city->mouseX < 92 && city->mouseY > 13 && city->mouseY < 85) &&
        IsMouseButtonDown(0)) {
        city->page.pageJeux.pageJeu = false;
        city->page.pageJeux.menu = true;
        city->page.pageJeux.aide = false;
        city->page.pageJeux.sauvegarde = false;
        city->page.pageJeux.quitter = false;
        city->page.pageReseauEau.pageEau = false;
        city->page.pageReseauElec.pageElectricite = false;
        city->page.pageJeux.BatimentRoute = false;
        city->page.pageJeux.BatimentHabitation = false;
        city->page.pageJeux.BatimentEau = false;
        city->page.pageJeux.BatimentElec = false;
        city->page.pageJeux.menu = false;
        city->page.pageJeux.croix = false;
    }
    //Bouton retour du menu déroulant
    if ((city->mouseX > 9 && city->mouseX < 103 && city->mouseY > 25 && city->mouseY < 116) &&
        IsMouseButtonDown(0)) {
        if (city->page.pageJeux.menu) {
            city->page.pageJeux.pageJeu = true;
            city->page.pageJeux.menu = false;
            city->page.pageJeux.aide = false;
            city->page.pageJeux.sauvegarde = false;
            city->page.pageJeux.quitter = false;
            city->page.pageReseauEau.pageEau = false;
            city->page.pageReseauElec.pageElectricite = false;
            city->page.pageJeux.BatimentRoute = false;
            city->page.pageJeux.BatimentHabitation = false;
            city->page.pageJeux.BatimentEau = false;
            city->page.pageJeux.BatimentElec = false;
            city->page.pageJeux.menu = false;
            city->page.pageJeux.croix = false;
        }
    }
    //PAS ENCORE FAIT
    //Bouton AIDE pageMenuJeu
    if ((city->mouseX > 126 && city->mouseX < 584 && city->mouseY > 10 && city->mouseY < 130) &&
        IsMouseButtonDown(0)) {
        if (city->page.pageJeux.menu) {
            city->page.pageJeux.pageJeu = false;
            city->page.pageJeux.aide = true;
            city->page.pageJeux.sauvegarde = false;
            city->page.pageJeux.quitter = false;
            city->page.pageReseauEau.pageEau = false;
            city->page.pageReseauElec.pageElectricite = false;
            city->page.pageJeux.BatimentRoute = false;
            city->page.pageJeux.BatimentHabitation = false;
            city->page.pageJeux.BatimentEau = false;
            city->page.pageJeux.BatimentElec = false;
            city->page.pageJeux.menu = false;
            city->page.pageJeux.croix = false;
        }
    }
    //Bouton SAUVEGARDE pageMenuJeu
    if ((city->mouseX > 126 && city->mouseX < 584 && city->mouseY > 151 && city->mouseY < 270) &&
        IsMouseButtonDown(0)) {
        if (city->page.pageJeux.menu) {
            city->page.pageJeux.pageJeu = false;
            city->page.pageJeux.aide = false;
            city->page.pageJeux.sauvegarde = true;
            city->page.pageJeux.quitter = false;
            city->page.pageReseauEau.pageEau = false;
            city->page.pageReseauElec.pageElectricite = false;
            city->page.pageJeux.BatimentRoute = false;
            city->page.pageJeux.BatimentHabitation = false;
            city->page.pageJeux.BatimentEau = false;
            city->page.pageJeux.BatimentElec = false;
            city->page.pageJeux.menu = false;
            city->page.pageJeux.croix = false;
        }
    }
    //Bouton QUITTER pageMenuJeu
    if ((city->mouseX > 126 && city->mouseX < 584 && city->mouseY > 290 && city->mouseY < 410) &&
        IsMouseButtonDown(0)) {
        if (city->page.pageJeux.menu) {
            city->page.pageJeux.pageJeu = false;
            city->page.pageJeux.aide = false;
            city->page.pageJeux.sauvegarde = false;
            city->page.pageJeux.quitter = true;
            city->page.pageReseauEau.pageEau = false;
            city->page.pageReseauElec.pageElectricite = false;
            city->page.pageJeux.BatimentRoute = false;
            city->page.pageJeux.BatimentHabitation = false;
            city->page.pageJeux.BatimentEau = false;
            city->page.pageJeux.BatimentElec = false;
            city->page.pageJeux.menu = false;
            city->page.pageJeux.croix = false;
        }
    }
    //Bouton route
    if ((city->mouseX > 970 && city->mouseX < 1068 && city->mouseY > 470 && city->mouseY < 567) &&
        IsMouseButtonDown(0)) {
        if (city->page.pageJeux.pageJeu) {
            city->page.pageJeux.menu = false;
            city->page.pageJeux.aide = false;
            city->page.pageJeux.sauvegarde = false;
            city->page.pageJeux.quitter = false;
            city->page.pageReseauEau.pageEau = false;
            city->page.pageReseauElec.pageElectricite = false;
            city->page.pageJeux.BatimentRoute = true;
            city->page.pageJeux.BatimentHabitation = false;
            city->page.pageJeux.BatimentEau = false;
            city->page.pageJeux.BatimentElec = false;
            city->page.pageJeux.menu = false;
            city->page.pageJeux.croix = false;
        }
    }
    //Bouton Habitation
    if ((city->mouseX > 1083 && city->mouseX < 1180 && city->mouseY > 470 && city->mouseY < 567) &&
        IsMouseButtonDown(0)) {
        if (city->page.pageJeux.pageJeu) {
            city->page.pageJeux.menu = false;
            city->page.pageJeux.aide = false;
            city->page.pageJeux.sauvegarde = false;
            city->page.pageJeux.quitter = false;
            city->page.pageReseauEau.pageEau = false;
            city->page.pageReseauElec.pageElectricite = false;
            city->page.pageJeux.BatimentRoute = false;
            city->page.pageJeux.BatimentHabitation = true;
            city->page.pageJeux.BatimentEau = false;
            city->page.pageJeux.BatimentElec = false;
            city->page.pageJeux.menu = false;
            city->page.pageJeux.croix = false;
        }
    }
    //Bouton centrale
    if ((city->mouseX > 1083 && city->mouseX < 1180 && city->mouseY > 606 && city->mouseY < 703) &&
        IsMouseButtonDown(0)) {
        if (city->page.pageJeux.pageJeu) {
            city->page.pageJeux.menu = false;
            city->page.pageJeux.aide = false;
            city->page.pageJeux.sauvegarde = false;
            city->page.pageJeux.quitter = false;
            city->page.pageReseauEau.pageEau = false;
            city->page.pageReseauElec.pageElectricite = false;
            city->page.pageJeux.BatimentRoute = false;
            city->page.pageJeux.BatimentHabitation = false;
            city->page.pageJeux.BatimentEau = false;
            city->page.pageJeux.BatimentElec = true;
            city->page.pageJeux.menu = false;
            city->page.pageJeux.croix = false;
        }
    }
    //Bouton chateau eau
    if ((city->mouseX > 970 && city->mouseX < 1068 && city->mouseY > 606 && city->mouseY < 703) &&
        IsMouseButtonDown(0)) {
        if (city->page.pageJeux.pageJeu) {
            city->page.pageJeux.menu = false;
            city->page.pageJeux.aide = false;
            city->page.pageJeux.sauvegarde = false;
            city->page.pageJeux.quitter = false;
            city->page.pageReseauEau.pageEau = false;
            city->page.pageReseauElec.pageElectricite = false;
            city->page.pageJeux.BatimentRoute = false;
            city->page.pageJeux.BatimentHabitation = false;
            city->page.pageJeux.BatimentEau = true;
            city->page.pageJeux.BatimentElec = false;
            city->page.pageJeux.menu = false;
            city->page.pageJeux.croix = false;
        }
    }
    //Bouton croix
    if ((city->mouseX > 1050 && city->mouseX < 1100 && city->mouseY > 400 && city->mouseY < 450) &&
        IsMouseButtonDown(0)) {
        city->page.pageJeux.pageJeu = true;
        city->page.pageJeux.BatimentRoute = false;
        city->page.pageJeux.BatimentHabitation = false;
        city->page.pageJeux.BatimentEau = false;
        city->page.pageJeux.BatimentElec = false;
        city->page.pageReseauEau.pageEau = false;
        city->page.pageReseauElec.pageElectricite = false;
    }

    // Repérage colonnes et lignes
    for (int i = 0; i < COLONNES; i++) {
        for (int j = 0; j < LIGNES; j++) {
            if ((i * 20 < city->mouseX && i * 20 + 20 > city->mouseX) &&
                (j * 20 < city->mouseY - 100 && j * 20 + 20 > city->mouseY - 100)) {
                city->ligneSurMap = j;
                city->colonneSurMap = i;
                //printf("(%d,%d)\n", city->ligneSurMap, city->colonneSurMap);
            }
        }
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

        if (city->page.pageJeux.menu) {
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

void fonction_Nino_ROUTE(City *city, int nbConstru) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (city->terrain[i][j].typeBloc == 1) {
                DrawTexture(city->tabBitmapTexture[DecorObstacleCaillouImage], j * 20, i * 20 + 100, WHITE);
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 2) {
                if (savoirAffichageRoute(city, i, j) == 0) {
                    DrawTexture(city->tabBitmapTexture[Route_Angle_Droite_Bas], j * 20, i * 20 + 100, WHITE);
                } else if (savoirAffichageRoute(city, i, j) == 1) {
                    DrawTexture(city->tabBitmapTexture[Route_Horizontale], j * 20, i * 20 + 100, WHITE);
                } else if (savoirAffichageRoute(city, i, j) == 2) {
                    DrawTexture(city->tabBitmapTexture[Route_Verticale], j * 20, i * 20 + 100, WHITE);
                } else if (savoirAffichageRoute(city, i, j) == 3) {
                    DrawTexture(city->tabBitmapTexture[Route_Angle_Gauche_Bas], j * 20, i * 20 + 100, WHITE);
                } else if (savoirAffichageRoute(city, i, j) == 4) {
                    DrawTexture(city->tabBitmapTexture[Route_Angle_Gauche_Haut], j * 20, i * 20 + 100, WHITE);
                } else if (savoirAffichageRoute(city, i, j) == 5) {
                    DrawTexture(city->tabBitmapTexture[Route_Angle_Droite_Haut], j * 20, i * 20 + 100, WHITE);
                } else if (savoirAffichageRoute(city, i, j) == 6) {
                    DrawTexture(city->tabBitmapTexture[Route_Croisement_Haut], j * 20, i * 20 + 100, WHITE);
                } else if (savoirAffichageRoute(city, i, j) == 7) {
                    DrawTexture(city->tabBitmapTexture[Route_Croisement_Droite], j * 20, i * 20 + 100, WHITE);
                } else if (savoirAffichageRoute(city, i, j) == 8) {
                    DrawTexture(city->tabBitmapTexture[Route_Croisement_Bas], j * 20, i * 20 + 100, WHITE);
                } else if (savoirAffichageRoute(city, i, j) == 9) {
                    DrawTexture(city->tabBitmapTexture[Route_Croisement_Gauche], j * 20, i * 20 + 100, WHITE);
                } else if (savoirAffichageRoute(city, i, j) == 10) {
                    DrawTexture(city->tabBitmapTexture[Route_Carrefour], j * 20, i * 20 + 100, WHITE);
                }
                /*else {
                    DrawTexture(city->tabBitmapTexture[Route], j * 20, i * 20 + 100, BLACK);
                    city->terrain[i][j].obstacle = true;
                }*/
            }
            if (city->terrain[i][j].typeBloc == 3 && city->terrain[i - 1][j].typeBloc != 3 &&
                city->terrain[i][j - 1].typeBloc != 3) {
                DrawTexture(city->tabBitmapTexture[House2], j * 20, i * 20 + 100, WHITE);
                nbConstru++;
            }
            if (city->terrain[i][j].typeBloc == 4 && city->terrain[i - 1][j].typeBloc != 4 &&
                city->terrain[i][j - 1].typeBloc != 4) {
                DrawTexture(city->tabBitmapTexture[House4], j * 20, i * 20 + 100, WHITE);
                nbConstru++;
            }
            if (city->terrain[i][j].typeBloc == 5 && city->terrain[i - 1][j].typeBloc != 5 &&
                city->terrain[i][j - 1].typeBloc != 5) {
                DrawTexture(city->tabBitmapTexture[Ruine], j * 20, i * 20 + 100, WHITE);
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 6 && city->terrain[i - 1][j].typeBloc != 6 &&
                city->terrain[i][j - 1].typeBloc != 6) {
                DrawTexture(city->tabBitmapTexture[Cabanne1], j * 20, i * 20 + 100, WHITE);
                nbConstru++;
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 7 && city->terrain[i - 1][j].typeBloc != 7 &&
                city->terrain[i][j - 1].typeBloc != 7) {
                DrawTexture(city->tabBitmapTexture[House6], j * 20, i * 20 + 100, WHITE);
                nbConstru++;
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 8 && city->terrain[i - 1][j].typeBloc != 8 &&
                city->terrain[i][j - 1].typeBloc != 8) {
                DrawTexture(city->tabBitmapTexture[Immeuble1], j * 20, i * 20 + 100, WHITE);
                nbConstru++;
                city->terrain[i][j].obstacle = true;
            }
            if (city->terrain[i][j].typeBloc == 9 && city->terrain[i - 1][j].typeBloc != 9 &&
                city->terrain[i][j - 1].typeBloc != 9) {
                DrawTexture(city->tabBitmapTexture[Building2], j * 20, i * 20 + 100, WHITE);
                nbConstru++;
                city->terrain[i][j].obstacle = true;
            }
        }
    }
}

void affichageBoucle(City *city) {
    InitWindow(LARGEUR_ECRAN, HAUTEUR_ECRAN, "ECE-City");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    initBitmap(city);

    SetTargetFPS(1080);

    while (!WindowShouldClose()) {
        //ClearBackground(RAYWHITE);
        BeginDrawing();

        city->mouseX = GetMouseX();
        city->mouseY = GetMouseY();

        int nbConstru = 0;
        int sec = 0, min = 0, hour = 0;

        city->temps = GetTime();

        sec = ((int) city->temps % 3600) % 60;
        min = ((int) city->temps % 3600) / 60;
        hour = (int) city->temps / 3600;

        gestionCliqueSouris(city);
        DrawTexture(city->tabBitmapTexture[PageMap], 0, 0, WHITE);
        DrawTexture(city->tabBitmapTexture[Niveau0], 963, 169, WHITE);
        DrawRectangle(932, 5, 75, 20, WHITE);
        if (hour > 0) {
            DrawText(TextFormat("Temps de jeu : %dh %dmin %dsec", hour, min, sec), 870, 5, 20, BLACK);
        }
        if (min > 0 && hour == 0) {
            DrawText(TextFormat("Temps de jeu : %dmin %dsec", min, sec), 870, 5, 20, BLACK);
        }
        if (sec > 0 && min == 0 && hour == 0) {
            DrawText(TextFormat("Temps de jeu : %dsec", sec), 870, 5, 20, BLACK);
        }
        DrawText(TextFormat("%d", city->nbHabitant), 1010, 48, 25, BLACK);
        DrawText(TextFormat("%d", city->argent), 1010, 107, 25, BLACK);
        DrawText("ece", 1149, 102, 15, DARKGRAY);
        DrawText("flouz", 1143, 117, 15, DARKGRAY);
        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLONNES; j++) {
                DrawTexture(city->tabBitmapTexture[DecorHerbeImage], j * 20, i * 20 + 100, WHITE);
            }
        }
        dessinerGrille();

        fonction_Nino_ROUTE(city, nbConstru);

        if (city->page.pageJeux.pageJeu) {
            //Afficher map
            if (city->page.pageJeux.BatimentRoute) {
                DrawTexture(city->tabBitmapTexture[Route_Horizontale], city->mouseX - 10, city->mouseY - 10, WHITE);
                DrawTexture(city->tabBitmapTexture[PageRouteSelectionner], 968, 466, WHITE);
                if (!city->terrain[city->ligneSurMap][city->colonneSurMap].obstacle &&
                    viabiliteeRoutiereGraphique(city, 2)) {
                    DrawTexture(city->tabBitmapTexture[Route_Horizontale], city->mouseX - 10, city->mouseY - 10, GREEN);
                    if (IsMouseButtonDown(0)) {
                        city->terrain[city->ligneSurMap][city->colonneSurMap].typeBloc = 2;
                        city->terrain[city->ligneSurMap][city->colonneSurMap].obstacle = true;
                    }
                } else if (!city->terrain[city->ligneSurMap][city->colonneSurMap].obstacle &&
                           !viabiliteeRoutiereGraphique(city, 2)) {
                    DrawTexture(city->tabBitmapTexture[Route_Horizontale], city->mouseX - 10, city->mouseY - 10,
                                ORANGE);
                    if (IsMouseButtonDown(0)) {
                        city->terrain[city->ligneSurMap][city->colonneSurMap].typeBloc = 2;
                        city->terrain[city->ligneSurMap][city->colonneSurMap].obstacle = true;
                    }
                } else {
                    DrawTexture(city->tabBitmapTexture[Route_Horizontale], city->mouseX - 10, city->mouseY - 10, RED);
                }
            }
            if (city->page.pageJeux.BatimentHabitation) {
                DrawTexture(city->tabBitmapTexture[PageHabitationSelectionner], 968, 466, WHITE);
                DrawTexture(city->tabBitmapTexture[Ruine], city->mouseX, city->mouseY, WHITE);
                if (obstacleHabitation(city)) {
                    if (!viabiliteeRoutiereGraphique(city, 5)) {
                        DrawTexture(city->tabBitmapTexture[Ruine], city->mouseX, city->mouseY, DARKGRAY);
                    } else if (!viabiliteeElectriqueGraphique(city, 5)) {
                        DrawTexture(city->tabBitmapTexture[Ruine], city->mouseX, city->mouseY, YELLOW);
                    } else if (!viabiliteeEauGraphique(city, 5)) {
                        DrawTexture(city->tabBitmapTexture[Ruine], city->mouseX, city->mouseY, BLUE);
                    } else if (viabiliteeRoutiereGraphique(city, 5) && viabiliteeElectriqueGraphique(city, 5) &&
                               viabiliteeEauGraphique(city, 5)) {
                        DrawTexture(city->tabBitmapTexture[Ruine], city->mouseX, city->mouseY, GREEN);
                    }
                    if (IsMouseButtonDown(0)) {
                        city->terrain[city->ligneSurMap][city->colonneSurMap].typeBloc = 5;
                        mettreAJObstacleHabitation(city);
                        mettreAJHabitationMap(city, 5);
                    }
                } else {
                    DrawTexture(city->tabBitmapTexture[Ruine], city->mouseX, city->mouseY, RED);
                }
            }
            if (city->page.pageJeux.BatimentEau) {
                DrawTexture(city->tabBitmapTexture[PageChateauSelectionner], 968, 466, WHITE);
            }
            if (city->page.pageJeux.BatimentElec) {
                DrawTexture(city->tabBitmapTexture[PageCentraleSelectionner], 968, 466, WHITE);
            }
        }
        if (city->page.pageJeux.menu) {
            DrawTexture(city->tabBitmapTexture[PageMenuJeu], 0, 0, WHITE);
            if (city->page.pageJeux.aide) {

            }
            if (city->page.pageJeux.sauvegarde) {
                DrawTexture(city->tabBitmapTexture[PageSauvegardeEffectuer], 0, 0, GREEN);
            }
            if (city->page.pageJeux.quitter) {
                DrawTexture(city->tabBitmapTexture[PageQuitterSauvegarde], 100, 338, RED);
            }
            DrawRectangle(0, 99, 900, 701, WHITE);
            //Afficher le menu quitter
        }
        if (city->page.pageReseauEau.pageEau) {
            DrawTexture(city->tabBitmapTexture[Niveau1], 963, 169, WHITE);
            DrawRectangle(0, 99, 900, 701, WHITE);
            //Afficher réseau
            dessinerGrille();
        }
        if (city->page.pageReseauElec.pageElectricite) {
            DrawTexture(city->tabBitmapTexture[Niveau2], 963, 169, WHITE);
            DrawRectangle(0, 99, 900, 701, WHITE);
            //Afficher réseau
            dessinerGrille();
        }
        if (city->page.pageJeux.BatimentRoute || city->page.pageJeux.BatimentHabitation ||
            city->page.pageJeux.BatimentEau || city->page.pageJeux.BatimentElec || city->page.pageReseauEau.pageEau ||
            city->page.pageReseauElec.pageElectricite) {
            DrawTexture(city->tabBitmapTexture[Croix], 1050, 400, RED);
        }

        EndDrawing();
    }
    unloadTexture(city);
    CloseWindow();
}
