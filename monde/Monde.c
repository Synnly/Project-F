#include "Monde.h"

/* ===== Getters ===== */

Joueur* getMondeJoueur(Monde* monde){
    return monde->joueur;
}

bool isRunning(Monde* monde){
    return monde->running;
}

/* ===== Setters ===== */

void setMondeJoueur(Monde* monde, Joueur* joueur){
    monde->joueur = joueur;
}

void startRunning(Monde* monde){
    monde->running = true;
}

void stopRunning(Monde* monde){
    monde->running = false;
}

/* ===== Fonctions ===== */

void initMonde(Monde* monde){
    setMondeJoueur(monde, NULL);
    monde->running = false;
}