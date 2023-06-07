#include "Joueur.h"

/* ===== Getters ===== */

float getJoueurX(Joueur* joueur){
    return joueur->x;
}

float getJoueurY(Joueur* joueur){
    return joueur->y;
}

int getJoueurWidth(Joueur* joueur){
    return joueur->width;
}

int getJoueurHeight(Joueur* joueur){
    return joueur->height;
}

float getJoueurSpeed(Joueur* joueur){
    return joueur->speed;
}

SDL_Texture* getJoueurTexture(Joueur *joueur){
    return joueur->texture;
}

/* ===== Setters ===== */

void setJoueurX(Joueur* joueur, float x){
    joueur->x = x;
}

void setJoueurY(Joueur* joueur, float y){
    joueur->y = y;
}

void setJoueurWidth(Joueur* joueur, int width){
    joueur->width = width;
}

void setJoueurHeight(Joueur* joueur, int height){
    joueur->height = height;
}

void setJoueurSpeed(Joueur* joueur, float speed){
    joueur->speed = speed;
}

void setJoueurTexture(Joueur* joueur, SDL_Texture* texture){
    joueur->texture = texture;
}

/* ===== Fonctions ===== */

void initJoueur(Joueur* joueur){
    setJoueurX(joueur, 0);
    setJoueurY(joueur, 0);
    setJoueurWidth(joueur, JOUEUR_WIDTH);
    setJoueurHeight(joueur, JOUEUR_HEIGHT);
    setJoueurSpeed(joueur, JOUEUR_SPEED);
    setJoueurTexture(joueur, NULL);
}

