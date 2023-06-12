#ifndef PROJECT_R_EVENTHANDLER_H
#define PROJECT_R_EVENTHANDLER_H

#include "../monde/Monde.h"

/**
 * Gère les évènements (appui de touches, ...)
 * @param monde Le monde du jeu
 * @param events Les évènements du monde
 * @param dt Le delta t
 */
void handleEvents(Monde* monde, SDL_Event* events, float dt);

#endif //PROJECT_R_EVENTHANDLER_H
