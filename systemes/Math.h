#ifndef PROJECT_F_MATH_H
#define PROJECT_F_MATH_H
#include <SDL2/SDL.h>

/**
 * Calcule la longueur du coté d'un carré de diagonale de longueur x
 * @param x La longueur de la diagonale du carré
 * @return Le coté du carré
 */
float hypotenuse(float x);

/**
 * Compare deux flottants
 * @param a Le premier flottant
 * @param b Le second flottant
 * @return Si les deux flottants sont égaux à EPSILON près
 */
SDL_bool floatEquals(float a, float b);

#endif //PROJECT_F_MATH_H
