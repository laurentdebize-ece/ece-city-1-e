#include "musique.h"

// FONCTION SON

// Music musique = LoadMusicStream("../Music/..")
// PlayMusicStream(musique)
// Pause Resume STop

void initSon(City *city) {
    InitAudioDevice();
    city->musique[BlockPoser] = LoadMusicStream("../Musique/BlockPoser.wav");
    //city->musique[Building] = LoadMusicStream("../Musique/Building.wav");
    //city->musique[CentralPark] = LoadMusicStream("../Musique/CentralPark.wav");
    city->musique[InfraStructure] = LoadMusicStream("../Musique/InfraStructure.wav");
    city->musique[PagePrincipale] = LoadMusicStream("../Musique/PagePrincipale.wav");
    city->musique[Bouton] = LoadMusicStream("../Musique/music_boutton.wav");
    city->musique[BruitEau] = LoadMusicStream("../Musique/BruitEau.wav");
    city->musique[BruitElectrique] = LoadMusicStream("../Musique/BruitElectrique.wav");
}

void updateMusique(City *city) {
    UpdateMusicStream(city->musique[BlockPoser]);
    UpdateMusicStream(city->musique[Building]);
    UpdateMusicStream(city->musique[CentralPark]);
    UpdateMusicStream(city->musique[InfraStructure]);
    UpdateMusicStream(city->musique[PagePrincipale]);
    UpdateMusicStream(city->musique[BruitEau]);
    UpdateMusicStream(city->musique[BruitElectrique]);
    UpdateMusicStream(city->musique[Bouton]);
}

void jouerSon(City *city) {
    if (city->page.pageMenuPrincipale.boolMenuPrincipal || city->page.pageMenuPrincipale.choix || city->page.pageMenuPrincipale.sauvegarde) {
        PlayMusicStream(city->musique[PagePrincipale]);
    } else {
        StopMusicStream(city->musique[PagePrincipale]);
    }
    if (city->page.pageJeux.musiqueJeu) {
        PlayMusicStream(city->musique[InfraStructure]);
    } else {
        PauseMusicStream(city->musique[InfraStructure]);
    }

    if (IsMouseButtonDown(0)) {
        PlayMusicStream(city->musique[Bouton]);
    } else {
        StopMusicStream(city->musique[Bouton]);
        ResumeMusicStream(city->musique[InfraStructure]);
    }
    if (city->page.pageReseauElec.pageElectricite) {
        PauseMusicStream(city->musique[InfraStructure]);
        PlayMusicStream(city->musique[BruitElectrique]);
    } else {
        PauseMusicStream(city->musique[BruitElectrique]);
        ResumeMusicStream(city->musique[InfraStructure]);
    }
    if (city->page.pageReseauEau.pageEau) {
        PauseMusicStream(city->musique[InfraStructure]);
        PlayMusicStream(city->musique[BruitEau]);
    } else {
        PauseMusicStream(city->musique[BruitEau]);
        ResumeMusicStream(city->musique[InfraStructure]);
    }
    if (city->page.pageJeux.quitter) {
        StopMusicStream(city->musique[InfraStructure]);
    }
    if (city->page.pageJeux.sauvegarde && city->page.pageMenuPrincipale.sauvegarde) {
        StopMusicStream(city->musique[PagePrincipale]);
        ResumeMusicStream(city->musique[InfraStructure]);
    } else {
        StopMusicStream(city->musique[PagePrincipale]);
        ResumeMusicStream(city->musique[InfraStructure]);
    }
}

void stopSon(City *city) {
    StopMusicStream(city->musique[BlockPoser]);
    StopMusicStream(city->musique[Building]);
    StopMusicStream(city->musique[CentralPark]);
    StopMusicStream(city->musique[InfraStructure]);
    StopMusicStream(city->musique[PagePrincipale]);
    StopMusicStream(city->musique[BruitEau]);
    StopMusicStream(city->musique[BruitElectrique]);
    StopMusicStream(city->musique[Bouton]);
}

void arreterSon(City *city) {
    stopSon(city);
    UnloadMusicStream(city->musique[BlockPoser]);
    UnloadMusicStream(city->musique[Building]);
    UnloadMusicStream(city->musique[CentralPark]);
    UnloadMusicStream(city->musique[InfraStructure]);
    UnloadMusicStream(city->musique[PagePrincipale]);
    UnloadMusicStream(city->musique[BruitEau]);
    UnloadMusicStream(city->musique[BruitElectrique]);
    UnloadMusicStream(city->musique[Bouton]);

    CloseAudioDevice();
}
