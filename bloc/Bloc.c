#include "Bloc.h"

/* ===== Getters ===== */

float getBlocX(Bloc* bloc){
    return getSpriteX(&bloc->sprite);
}

float getBlocY(Bloc* bloc){
    return getSpriteY(&bloc->sprite);
}

int getBlocWidth(Bloc* bloc){
    return getSpriteWidth(&bloc->sprite);
}

int getBlocHeight(Bloc* bloc){
    return getSpriteHeight(&bloc->sprite);
}

SDL_Texture* getBlocTexture(Bloc *bloc){
    return getSpriteTexture(&bloc->sprite);
}

SDL_bool blocEstObstacle(Bloc *bloc){
    return bloc->estObstacle;
}

/* ===== Setters ===== */

void setBlocX(Bloc* bloc, float x){
    setSpriteX(&bloc->sprite, x);
}

void setBlocY(Bloc* bloc, float y){
    setSpriteY(&bloc->sprite, y);
}

void setBlocWidth(Bloc* bloc, int width){
    setSpriteWidth(&bloc->sprite, width);
}

void setBlocHeight(Bloc* bloc, int height){
    setSpriteHeight(&bloc->sprite, height);
}

void setBlocTexture(Bloc* bloc, SDL_Texture* texture){
    setSpriteTexture(&bloc->sprite, texture);
}

void setBlocEstObstacle(Bloc* bloc, SDL_bool estObstacle){
    bloc->estObstacle = estObstacle;
}

/* ===== Fonctions ===== */

void initBloc(Bloc *bloc, float x, float y, int width, int height, SDL_Texture *texture){
    initSprite(&bloc->sprite, x, y, width, height, texture);
    bloc->estObstacle = SDL_FALSE;
}

Bloc* initListeBlocs(int nbBlocs){
    Bloc* listeBlocs = malloc(nbBlocs * sizeof(Bloc));
    for (int i = 0; i < nbBlocs; i++) {
        initBloc(&listeBlocs[i], 0, 0, 0, 0, NULL);
    }
    return listeBlocs;
}