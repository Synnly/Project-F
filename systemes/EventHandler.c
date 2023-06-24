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
        float distanceX = 0;
        float distanceY = 0;

        // Déplacement à gauche
        if (keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) {
            distanceX -= ((keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]) == (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])) ? distance : hypotenuse(distance);
        }

        // Déplacement à droite
        if (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) {
            distanceX += ((keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]) == (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])) ? distance : hypotenuse(distance);
        }

        // Déplacement en haut
        if (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]) {
            distanceY -= ((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) == (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D])) ? distance : hypotenuse(distance);
        }

        // Déplacement en bas
        if (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]) {
            distanceY += ((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) == (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D])) ? distance : hypotenuse(distance);
        }

        // Detection de collision avec les blocs
        setJoueurX(getMondeJoueur(monde), SDL_min(WINDOW_WIDTH-JOUEUR_WIDTH, SDL_max(0, getJoueurX(getMondeJoueur(monde)) + distanceX)));
        if (joueurEnCollisionBlocs(getMondeJoueur(monde), getListeBlocs(monde))) {
            setJoueurX(getMondeJoueur(monde), SDL_min(WINDOW_WIDTH-JOUEUR_WIDTH, SDL_max(0, getJoueurX(getMondeJoueur(monde)) - distanceX)));
        }

        setJoueurY(getMondeJoueur(monde), SDL_min(WINDOW_HEIGHT-JOUEUR_HEIGHT, SDL_max(0, getJoueurY(getMondeJoueur(monde)) + distanceY)));
        if (joueurEnCollisionBlocs(getMondeJoueur(monde), getListeBlocs(monde))) {
            setJoueurY(getMondeJoueur(monde), SDL_min(WINDOW_HEIGHT-JOUEUR_HEIGHT, SDL_max(0, getJoueurY(getMondeJoueur(monde)) - distanceY)));
        }
    }
}

SDL_bool estEnCollision(Sprite* s1, Sprite* s2){

    //Coordonnees des coins haut gauche et bas droite du sprite 2
    float x1 = getSpriteX(s2);
    float y1 = getSpriteY(s2);
    float w1 = (float) getSpriteWidth(s2);
    float h1 = (float) getSpriteHeight(s2);

    // Coordonnees des coins du sprite 1
    float pos[4][2] = {{getSpriteX(s1) + 1,getSpriteY(s1)+ 1},
                       {getSpriteX(s1) + getSpriteWidth(s1) - 1, getSpriteY(s1)+ 1},
                       {getSpriteX(s1) + 1,getSpriteY(s1) + getSpriteHeight(s1) - 1 },
                       {getSpriteX(s1) + getSpriteWidth(s1) - 1, getSpriteY(s1) + getSpriteHeight(s1)- 1}
    };

    // Verification pour les 4 coins
    for (int point = 0; point < 4; point++) {
        float x = pos[point][0];
        float y = pos[point][1];

        if ((x > x1 || floatEquals(x, x1)) && (x < x1 + w1 || floatEquals(x, x1 + w1)) &&
            (y > y1 || floatEquals(y, y1)) && (y < y1 + h1 || floatEquals(y, y1 + h1))) {
            return SDL_TRUE;
        }
    }
    return SDL_FALSE;
}

SDL_bool joueurEnCollisionBlocs(Joueur* joueur, ListeBloc* liste){
    for(int i = 0; i < getNbBlocs(liste); i++){
        if(blocEstObstacle(getBloc(liste, i)) && estEnCollision(getJoueurSprite(joueur), getBlocSprite(getBloc(liste, i)))){
            return SDL_TRUE;
        }
    }
    return SDL_FALSE;
}