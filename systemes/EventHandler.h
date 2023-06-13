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

/**
 * Indique si deux sprites sont en collision
 * @param s1 Le premier sprite
 * @param s2 Le second sprite
 * @return Vrai si les deux sprites sont en collision, faux sinon
 */
SDL_bool estEnCollision(Sprite* s1, Sprite* s2);

/**
 * Indique si un joueur est en collision avec des blocs du monde qui sont des obstacles
 * @param joueur Le joueur
 * @param liste La liste des blocs du monde
 * @return Vrai si le joueur est en collision avec un bloc, faux sinon
 */
SDL_bool joueurEnCollisionBlocs(Joueur* joueur, ListeBloc* liste);

#endif //PROJECT_R_EVENTHANDLER_H
