#ifndef PROJECT_F_FPS_H
#define PROJECT_F_FPS_H

#include <SDL2/SDL.h>

/**
 * Indique si le nombre de FPS doit être limité
 * @param startTick Le tick de début
 * @param currentTick Le tick actuel
 */
SDL_bool fpsCap(Uint32 startTick, Uint32 *currentTick, int cap);

/**
 * Mets à jour les compteurs de FPS
 * @param frameCount Le nombre de frames
 * @param framerate Le nombre de frames par seconde
 * @param previousSecond La frame de la seconde précédente
 */
void fpsUpdate(Uint32* frameCount, int* framerate, Uint32* previousSecond);
#endif //PROJECT_F_FPS_H
