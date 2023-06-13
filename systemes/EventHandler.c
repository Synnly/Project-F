#include "EventHandler.h"
#include "Math.h"
#include "constantes.h"

void handleEvents(Monde* monde, SDL_Event* events, float dt){


    // On retire tous les évènements sauf l'indication de fermer le jeu
    SDL_FlushEvents(SDL_APP_TERMINATING, SDL_USEREVENT);

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);


    // Bouton quitter
    if(SDL_PollEvent(events) && ((events)->type == SDL_QUIT)){
        stopRunning(monde);
    }
    else{
        float distance = getJoueurSpeed(getMondeJoueur(monde)) * dt;    // Calcul de la distance à parcourir

        // Déplacement en haut-gauche
        if ((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) && (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W])) {
            setJoueurX(getMondeJoueur(monde), SDL_max(getJoueurX(getMondeJoueur(monde)) - hypotenuse(distance), 0));
            setJoueurY(getMondeJoueur(monde), SDL_max(getJoueurY(getMondeJoueur(monde)) - hypotenuse(distance), 0));
        }

        // Déplacement en bas-gauche
        else if ((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) && (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])) {
            setJoueurX(getMondeJoueur(monde), SDL_max(getJoueurX(getMondeJoueur(monde)) - hypotenuse(distance), 0));
            setJoueurY(getMondeJoueur(monde), SDL_min(getJoueurY(getMondeJoueur(monde)) + hypotenuse(distance), WINDOW_HEIGHT-JOUEUR_HEIGHT));
        }

        // Déplacement en haut-droite
        else if ((keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) && (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W])) {
            setJoueurX(getMondeJoueur(monde), SDL_min(getJoueurX(getMondeJoueur(monde)) + hypotenuse(distance), WINDOW_WIDTH-JOUEUR_WIDTH));
            setJoueurY(getMondeJoueur(monde), SDL_max(getJoueurY(getMondeJoueur(monde)) - hypotenuse(distance), 0));
        }

        // Déplacement en bas-droite
        else if ((keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) && (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])) {
            setJoueurX(getMondeJoueur(monde), SDL_min(getJoueurX(getMondeJoueur(monde)) + hypotenuse(distance), WINDOW_WIDTH-JOUEUR_WIDTH));
            setJoueurY(getMondeJoueur(monde), SDL_min(getJoueurY(getMondeJoueur(monde)) + hypotenuse(distance), WINDOW_HEIGHT-JOUEUR_HEIGHT));
        }

        // Déplacement à gauche
        else if (keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) {
            setJoueurX(getMondeJoueur(monde), SDL_max(getJoueurX(getMondeJoueur(monde)) - distance, 0));
        }

        // Déplacement à droite
        else if (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) {
            setJoueurX(getMondeJoueur(monde), SDL_min(getJoueurX(getMondeJoueur(monde)) + distance, WINDOW_WIDTH-JOUEUR_WIDTH));
        }

        // Déplacement en haut
        else if (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]) {
            setJoueurY(getMondeJoueur(monde), SDL_max(getJoueurY(getMondeJoueur(monde)) - distance, 0));
        }

        // Déplacement en bas
        else if (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]) {
            setJoueurY(getMondeJoueur(monde), SDL_min(getJoueurY(getMondeJoueur(monde)) + distance, WINDOW_HEIGHT-JOUEUR_HEIGHT));
        }
    }

}