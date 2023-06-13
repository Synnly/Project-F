#ifndef PROJECT_F_JOUEUR_H
#define PROJECT_F_JOUEUR_H

#include <SDL2/SDL.h>
#include "../sprite/Sprite.h"
#include "../systemes/constantes.h"

struct Joueur {
    Sprite sprite;
    float speed;            // Vitesse du joueur
};

typedef struct Joueur Joueur;

/* ===== Getters ===== */
/**
 * Renvoie la position en x du joueur
 * @param joueur Le joueur
 * @return La position en x du joueur
 */
float getJoueurX(Joueur* joueur);

/**
 * Renvoie la position en y du joueur
 * @param joueur Le joueur
 * @return La position en y du joueur
 */
float getJoueurY(Joueur* joueur);

/**
 * Renvoie la largeur du joueur
 * @param joueur Le joueur
 * @return La largeur du joueur
 */
int getJoueurWidth(Joueur* joueur);

/**
 * Renvoie la hauteur du joueur
 * @param joueur Le joueur
 * @return La hauteur du joueur
 */
int getJoueurHeight(Joueur* joueur);

/**
 * Renvoie la vitesse du joueur
 * @param joueur Le joueur
 * @return La vitesse du joueur
 */
float getJoueurSpeed(Joueur* joueur);

/**
 * Renvoie la texture du joueur
 * @param joueur Le joueur
 * @return La texture du joueur
 */
SDL_Texture* getJoueurTexture(Joueur *joueur);

/* ===== Setters ===== */

/**
 * Modifie la position en x du joueur
 * @param joueur Le joueur
 * @param x La nouvelle position en x du joueur
 */
void setJoueurX(Joueur* joueur, float x);

/**
 * Modifie la position en y du joueur
 * @param joueur Le joueur
 * @param y La nouvelle position en y du joueur
 */
void setJoueurY(Joueur* joueur, float y);

/**
 * Modifie la largeur du joueur
 * @param joueur Le joueur
 * @param width La nouvelle largeur du joueur
 */
void setJoueurWidth(Joueur* joueur, int width);

/**
 * Modifie la hauteur du joueur
 * @param joueur Le joueur
 * @param height La nouvelle hauteur du joueur
 */
void setJoueurHeight(Joueur* joueur, int height);

/**
 * Modifie la vitesse du joueur
 * @param joueur Le joueur
 * @param speed La nouvelle vitesse du joueur
 */
void setJoueurSpeed(Joueur* joueur, float speed);

/**
 * Modifie la texture du joueur
 * @param joueur Le joueur
 * @param texture La nouvelle texture du joueur
 */
void setJoueurTexture(Joueur *joueur, SDL_Texture *texture);

/* ===== Fonctions ===== */

/**
 * Initialise un joueur. Les valeurs par défaut sont :
 * \n- x = 0
 * \n- y = 0
 * \n- width = JOUEUR_WIDTH
 * \n- height = JOUEUR_HEIGHT
 * \n- speed = JOUEUR_SPEED
 * @return Le joueur initialisé
 */
void initJoueur(Joueur* joueur);

#endif //PROJECT_F_JOUEUR_H
