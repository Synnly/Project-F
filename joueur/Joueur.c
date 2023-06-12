#include "Joueur.h"

/* ===== Getters ===== */

float getJoueurX(Joueur* joueur){
    return getSpriteX(&(joueur->sprite));
}

float getJoueurY(Joueur* joueur){
    return getSpriteY(&(joueur->sprite));
}

int getJoueurWidth(Joueur* joueur){
    return getSpriteWidth(&(joueur->sprite));
}

int getJoueurHeight(Joueur* joueur){
    return getSpriteHeight(&(joueur->sprite));
}

float getJoueurSpeed(Joueur* joueur){
    return joueur->speed;
}

SDL_Texture* getJoueurTexture(Joueur *joueur){
    return getSpriteTexture(&(joueur->sprite));
}

/* ===== Setters ===== */

void setJoueurX(Joueur* joueur, float x){
    setSpriteX(&(joueur->sprite), x);
}

void setJoueurY(Joueur* joueur, float y){
    setSpriteY(&(joueur->sprite), y);
}

void setJoueurWidth(Joueur* joueur, int width){
    setSpriteWidth(&(joueur->sprite), width);
}

void setJoueurHeight(Joueur* joueur, int height){
    setSpriteHeight(&(joueur->sprite), height);
}

void setJoueurSpeed(Joueur* joueur, float speed){
    joueur->speed = speed;
}

void setJoueurTexture(Joueur* joueur, SDL_Texture* texture){
    setSpriteTexture(&(joueur->sprite), texture);
}

/* ===== Fonctions ===== */

void initJoueur(Joueur* joueur){
    initSprite(&(joueur->sprite), 0, 0, JOUEUR_WIDTH, JOUEUR_HEIGHT, NULL);
    setJoueurSpeed(joueur, JOUEUR_SPEED);
}

