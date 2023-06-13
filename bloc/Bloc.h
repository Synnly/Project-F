#ifndef PROJECT_F_BLOC_H
#define PROJECT_F_BLOC_H
#include "../sprite/Sprite.h"

struct Bloc {
    Sprite sprite;
    SDL_bool estObstacle;
};

typedef struct Bloc Bloc;

/* ===== Getters ===== */

/**
 * Renvoie la position en x du bloc
 * @param bloc Le bloc
 * @return La position en x du bloc
 */
float getBlocX(Bloc* bloc);

/**
 * Renvoie la position en y du bloc
 * @param bloc Le bloc
 * @return La position en y du bloc
 */
float getBlocY(Bloc* bloc);

/**
 * Renvoie la largeur du bloc
 * @param bloc Le bloc
 * @return La largeur du bloc
 */
int getBlocWidth(Bloc* bloc);

/**
 * Renvoie la hauteur du bloc
 * @param bloc Le bloc
 * @return La hauteur du bloc
 */
int getBlocHeight(Bloc* bloc);

/**
 * Renvoie la texture du bloc
 * @param bloc Le bloc
 * @return La texture du bloc
 */
SDL_Texture* getBlocTexture(Bloc *bloc);

/**
 * Renvoie si le bloc est un obstacle
 * @param bloc Le bloc
 * @return Si le bloc est un obstacle
 */
SDL_bool blocEstObstacle(Bloc *bloc);

/* ===== Setters ===== */

/**
 * Modifie la position en x du bloc
 * @param bloc Le bloc
 * @param x La nouvelle position en x du bloc
 */
void setBlocX(Bloc* bloc, float x);

/**
 * Modifie la position en y du bloc
 * @param bloc Le bloc
 * @param y La nouvelle position en y du bloc
 */
void setBlocY(Bloc* bloc, float y);

/**
 * Modifie la largeur du bloc
 * @param bloc Le bloc
 * @param width La nouvelle largeur du bloc
 */
void setBlocWidth(Bloc* bloc, int width);

/**
 * Modifie la hauteur du bloc
 * @param bloc Le bloc
 * @param height La nouvelle hauteur du bloc
 */
void setBlocHeight(Bloc* bloc, int height);

/**
 * Modifie la texture du bloc
 * @param bloc Le bloc
 * @param texture La nouvelle texture du bloc
 */
void setBlocTexture(Bloc *bloc, SDL_Texture *texture);

/**
 * Passe le bloc en obstacle
 * @param bloc Le bloc
 * @param estObstacle Si le bloc est un obstacle
 */
void setBlocObstacle(Bloc *bloc);

/**
 * Passe le bloc en non obstacle
 * @param bloc Le bloc
 * @param estObstacle Si le bloc est un obstacle
 */
void setBlocNonObstacle(Bloc *bloc);

/* ===== Fonctions ===== */

/**
 * Initialise un bloc
 * @param bloc Le bloc
 * @param x La position en x du bloc
 * @param y La position en y du bloc
 * @param width La largeur du bloc
 * @param height La hauteur du bloc
 * @param texture La texture du bloc
 */
void initBloc(Bloc *bloc, float x, float y, int width, int height, SDL_Texture *texture);

/**
 * Initialise une liste de blocs
 * @param nbBlocs Le nombre de blocs
 * @return La liste de blocs
 */
Bloc* initListeBlocs(int nbBlocs);

#endif //PROJECT_F_BLOC_H
