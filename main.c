#include <stdlib.h>
#include <stdio.h>
#include "joueur/Joueur.h"
#include "graphismes/Graphismes.h"
#include "monde/Monde.h"
#include "systemes/EventHandler.h"
#include "systemes/Fps.h"
#include "systemes/constantes.h"

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
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &fenetre, &renderer)){
        printf(" Error : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_SetRenderDrawColor(renderer, 32, 34, 37, SDL_ALPHA_OPAQUE);
    SDL_Event event;

    Joueur joueur;          // Initialisation du joueur
    initJoueur(&joueur);
    initJoueurSprite(renderer, &joueur);

    ListeBloc blocs;        // Initialisation des blocs
    initListeBloc(&blocs);

    Monde monde;            // Initialisation du monde
    initMonde(&monde);
    setMondeJoueur(&monde, &joueur);
    setListeBlocs(&monde, &blocs);
    startRunning(&monde);

    Uint32 framecount = 0;     // Initialisation des compteurs de FPS
    int framerate = 1;
    Uint32 startTick = SDL_GetTicks();
    Uint32 previousSecond = startTick;
    Uint32 currentTick;
    float dt;

    // Boucle de jeu
    while(isRunning(&monde)){
        currentTick = SDL_GetTicks();   // Mise à jour du compteur du tick actuel
        if (fpsCap(startTick, &currentTick, 60)) continue; // Si le nombre de FPS doit être limité, on passe à la frame suivante

        dt = (currentTick - startTick) / 1000.;         // Calcul du delta t

        handleEvents(&monde, &event, dt);   // Gestion des évènements
        SDL_RenderClear(renderer);
        drawJoueur(renderer, getMondeJoueur(&monde));  // Dessin du joueur
        SDL_RenderPresent(renderer);

        framecount++;                   // Mise à jour du compteur de frames
        startTick = currentTick;        // Mise à jour du compteur du tick de départ
        fpsUpdate(&framecount, &framerate, &previousSecond); // Mise à jour du compteur de FPS
    }

    // Nettoyage du code
    endSDL(fenetre, renderer);
    return 0;
}