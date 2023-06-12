#include "Sprite.h"

/* ===== Getters ===== */

float getSpriteX(Sprite* sprite){
    return sprite->x;
}

float getSpriteY(Sprite* sprite){
    return sprite->y;
}

int getSpriteWidth(Sprite* sprite){
    return sprite->width;
}

int getSpriteHeight(Sprite* sprite){
    return sprite->height;
}

SDL_Texture* getSpriteTexture(Sprite *sprite){
    return sprite->texture;
}

/* ===== Setters ===== */

void setSpriteX(Sprite* sprite, float x){
    sprite->x = x;
}

void setSpriteY(Sprite* sprite, float y){
    sprite->y = y;
}

void setSpriteWidth(Sprite* sprite, int width){
    sprite->width = width;
}

void setSpriteHeight(Sprite* sprite, int height){
    sprite->height = height;
}

void setSpriteTexture(Sprite* sprite, SDL_Texture* texture){
    sprite->texture = texture;
}

/* ===== Fonctions ===== */

void initSprite(Sprite* sprite, float x, float y, int width, int height, SDL_Texture* texture){
    setSpriteX(sprite, x);
    setSpriteY(sprite, y);
    setSpriteWidth(sprite, width);
    setSpriteHeight(sprite, height);
    setSpriteTexture(sprite, texture);
}