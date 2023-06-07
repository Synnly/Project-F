#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "joueur/Joueur.h"
#include "graphismes/Graphismes.h"

int main(){
    SDL_Window* fenetre;
    SDL_Renderer* renderer;

    // Initialisation du module vidéo
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO)){
        printf("Error : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Création de la fenêtre et du renderer
    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &fenetre, &renderer)){
        printf(" Error : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_SetRenderDrawColor(renderer, 32, 34, 37, SDL_ALPHA_OPAQUE);
    SDL_Event event;

    // Initialisation du joueur
    Joueur joueur;
    initJoueur(&joueur);
    initJoueurSprite(renderer, &joueur);

    // Boucle de jeu
    while(true){
        SDL_RenderClear(renderer);
        drawJoueur(renderer, &joueur);  // Dessin du joueur
        SDL_RenderPresent(renderer);
    }

    // Nettoyage du code
    endSDL(fenetre, renderer);
    return 0;
}