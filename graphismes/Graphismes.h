#ifndef PROJECT_R_GRAPHISMES_H
#define PROJECT_R_GRAPHISMES_H

#include <SDL2/SDL.h>
#include "../joueur/Joueur.h"
#include "../bloc/ListeBloc.h"

/**
 * Charge la texture d'un sprite
 * @param renderer Le renderer
 * @param file Le fichier contenant les textures
 * @return La texture
 */
SDL_Texture* loadSprite(SDL_Renderer* renderer, const char* file);

/* ===== Initialisation ===== */

/**
 * Initialise la texture du joueur
 * @param renderer Le renderer
 * @param Joueur Le joueur
 */
void initJoueurSprite(SDL_Renderer* renderer, Joueur* Joueur);

/**
 * Initialise la texture du bloc
 * @param renderer Le renderer
 * @param bloc Le bloc
 */
void initBlocSprite(SDL_Renderer* renderer, Bloc* bloc);

/**
 * Initialise la texture des chaque bloc de la liste des blocs
 * @param renderer Le renderer
 * @param listeBlocs La liste des blocs
 */
void initListeBlocsSprite(SDL_Renderer* renderer, ListeBloc* listeBlocs);

/* ===== Dessin ===== */

/**
 * Dessine sur l'écran le sprite aux coordonnées (x, y).
 * @param renderer Le renderer
 * @param x La coordonnée X du sprite
 * @param y La coordonnée X du sprite
 * @param w La largeur du sprite
 * @param h La hauteur du sprite
 * @param spriteIndex L'indice du sprite à récupérer dans le sprite-sheet (si la texture ne contient qu'il seul sprite, mettre 0)
 * @param textureSprite La texture du sprite
 */
void drawSprite(SDL_Renderer* renderer, int x, int y, int w, int h, int spriteIndex, SDL_Texture* textureSprite);

/**
 * Dessine le joueur sur l'écran
 * @param renderer Le renderer
 * @param Joueur Le joueur
 */
void drawJoueur(SDL_Renderer* renderer, Joueur* Joueur);

/**
 * Dessine le bloc sur l'écran
 * @param renderer Le renderer
 * @param bloc Le bloc
 */
void drawBloc(SDL_Renderer* renderer, Bloc* bloc);

/**
 * Dessine chaque bloc de la liste des blocs sur l'écran
 * @param renderer Le renderer
 * @param listeBlocs La liste des blocs
 */
void drawListeBlocs(SDL_Renderer* renderer, ListeBloc* listeBlocs);

/**
 * Nettoie la partie graphique du jeu
 * @param fenetre La fenêtre
 * @param renderer Le renderer
 */
void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer);
#endif //PROJECT_R_GRAPHISMES_H