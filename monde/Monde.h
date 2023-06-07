#ifndef PROJECT_F_MONDE_H
#define PROJECT_F_MONDE_H

#include "../joueur/Joueur.h"
#include <stdbool.h>

struct Monde{
    Joueur* joueur;
    bool running;
};

typedef struct Monde Monde;

/* ===== Getters ===== */

/**
 * Renvoie le joueur du monde
 * @param monde Le monde
 * @return Le joueur du monde
 */
Joueur* getMondeJoueur(Monde* monde);

/**
 * Renvoie si le monde est en cours d'exécution
 * @param monde Le monde
 * @return Si le monde est en cours d'exécution
 */
bool isRunning(Monde* monde);

/* ===== Setters ===== */

/**
 * Modifie le joueur du monde
 * @param monde Le monde
 * @param joueur Le nouveau joueur
 */
void setMondeJoueur(Monde* monde, Joueur* joueur);

/**
 * Indique que le monde est en cours d'exécution
 * @param monde Le monde
 */
void startRunning(Monde* monde);

/**
 * Indique que le monde n'est plus en cours d'exécution
 * @param monde Le monde
 */
void stopRunning(Monde* monde);

/* ===== Fonctions ===== */

/**
 * Initialise le monde. Le monde est initialisé avec un joueur et n'est pas en cours d'exécution
 * @param monde Le monde
 */
void initMonde(Monde* monde);

#endif //PROJECT_F_MONDE_H
