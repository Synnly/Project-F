#ifndef PROJECT_F_SPRITE_H
#define PROJECT_F_SPRITE_H

#include <SDL2/SDL.h>

struct Sprite {
    float x, y;             // Position du sprite
    int width, height;      // Dimensions du sprite
    SDL_Texture* texture;   // Texture du sprite
};

typedef struct Sprite Sprite;

/* ===== Getters ===== */

/**
 * Renvoie la position en x du sprite
 * @param sprite Le sprite
 * @return La position en x du sprite
 */
float getSpriteX(Sprite* sprite);

/**
 * Renvoie la position en y du sprite
 * @param sprite Le sprite
 * @return La position en y du sprite
 */
float getSpriteY(Sprite* sprite);

/**
 * Renvoie la largeur du sprite
 * @param sprite Le sprite
 * @return La largeur du sprite
 */
int getSpriteWidth(Sprite* sprite);

/**
 * Renvoie la hauteur du sprite
 * @param sprite Le sprite
 * @return La hauteur du sprite
 */
int getSpriteHeight(Sprite* sprite);

/**
 * Renvoie la texture du sprite
 * @param sprite Le sprite
 * @return La texture du sprite
 */
SDL_Texture* getSpriteTexture(Sprite *sprite);

/* ===== Setters ===== */

/**
 * Modifie la position en x du sprite
 * @param sprite Le sprite
 * @param x La nouvelle position en x du sprite
 */
void setSpriteX(Sprite* sprite, float x);

/**
 * Modifie la position en y du sprite
 * @param sprite Le sprite
 * @param y La nouvelle position en y du sprite
 */
void setSpriteY(Sprite* sprite, float y);

/**
 * Modifie la largeur du sprite
 * @param sprite Le sprite
 * @param width La nouvelle largeur du sprite
 */
void setSpriteWidth(Sprite* sprite, int width);

/**
 * Modifie la hauteur du sprite
 * @param sprite Le sprite
 * @param height La nouvelle hauteur du sprite
 */
void setSpriteHeight(Sprite* sprite, int height);

/**
 * Modifie la texture du sprite
 * @param sprite Le sprite
 * @param texture La nouvelle texture du sprite
 */
void setSpriteTexture(Sprite* sprite, SDL_Texture* texture);

/* ===== Fonctions ===== */

/**
 * Initialise le sprite
 * @param sprite Le sprite
 * @param x La position en x du sprite
 * @param y La position en y du sprite
 * @param width La largeur du sprite
 * @param height La hauteur du sprite
 * @param texture La texture du sprite
 */
void initSprite(Sprite* sprite, float x, float y, int width, int height, SDL_Texture* texture);

#endif //PROJECT_F_SPRITE_H
