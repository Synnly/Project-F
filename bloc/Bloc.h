#ifndef PROJECT_F_BLOC_H
#define PROJECT_F_BLOC_H
#include "../sprite/Sprite.h"

struct Bloc {
    Sprite* sprite;
    SDL_bool estObstacle;
    int face;               // Quatre blocs adjacents ==> 0
                            // Trois blocs adjacents ==> 1: haut, 2: droite, 3: bas, 4: gauche
                            // Deux blocs adjacents ==> 5: haut gauche, 6: haut droite, 7: bas gauche, 8: bas droite
                            // Un bloc adjacent ==> 9: haut, 10: droite, 11: bas, 12: gauche
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

/**
 * Renvoie le sprite du bloc
 * @param bloc Le bloc
 * @return Le sprite du bloc
 */
Sprite* getBlocSprite(Bloc* bloc);

/**
 * Renvoie la face du bloc. Valeurs possibles :\n
 * \n Quatre blocs adjacents ou dans le coin des bordures ==> 0
 * \n Trois blocs adjacents ou en bordure ==> 1: gauche, 2: droite, 3: haut, 4: bas
 * \n Deux blocs adjacents ==> 5: haut gauche, 6: haut droite, 7: bas gauche, 8: bas droite
 * \n Un bloc adjacent ==> 9: gauche, 10: droite, 11: haut, 12: bas
 * @param bloc Le bloc
 * @return La face du bloc
 */
int getBlocFace(Bloc* bloc);

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

/**
 * Modifie la face du bloc. Valeurs possibles :\n
 * \n Quatre blocs adjacents ou dans le coin des bordures ==> 0
 * \n Trois blocs adjacents ou en bordure ==> 1: gauche, 2: droite, 3: haut, 4: bas
 * \n Deux blocs adjacents ==> 5: haut gauche, 6: haut droite, 7: bas gauche, 8: bas droite, 13: vertical, 14: horizontal
 * \n Un bloc adjacent ==> 9: gauche, 10: droite, 11: haut, 12: bas
 * @param bloc Le bloc
 * @param face La nouvelle face du bloc
 */
void setBlocFace(Bloc* bloc, int face);

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
