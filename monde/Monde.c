#include "Monde.h"

/* ===== Getters ===== */

Joueur* getMondeJoueur(Monde* monde){
    return monde->joueur;
}

SDL_bool isRunning(Monde* monde){
    return monde->running;
}

ListeBloc* getListeBlocs(Monde* monde){
    return monde->blocs;
}

/* ===== Setters ===== */

void setMondeJoueur(Monde* monde, Joueur* joueur){
    monde->joueur = joueur;
}

void startRunning(Monde* monde){
    monde->running = SDL_TRUE;
}

void stopRunning(Monde* monde){
    monde->running = SDL_FALSE;
}

void setListeBlocs(Monde* monde, ListeBloc* liste){
    monde->blocs = liste;
}

/* ===== Fonctions ===== */

void initMonde(Monde* monde){
    monde->joueur = NULL;
    monde->running = SDL_FALSE;
    monde->blocs = NULL;
}