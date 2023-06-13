#ifndef PROJECT_F_MONDE_H
#define PROJECT_F_MONDE_H

#include "../joueur/Joueur.h"
#include "../bloc/ListeBloc.h"

struct Monde{
    Joueur* joueur;
    SDL_bool running;
    ListeBloc* blocs;
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
SDL_bool isRunning(Monde* monde);

/**
 * Renvoie la liste des blocs du monde
 * @param monde Le monde
 * @return La liste des blocs du monde
 */
ListeBloc* getListeBlocs(Monde* monde);

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

/**
 * Modifie la liste des blocs du monde
 * @param monde Le monde
 * @param liste La nouvelle liste des blocs
 */
void setListeBlocs(Monde* monde, ListeBloc* liste);

/* ===== Fonctions ===== */

/**
 * Initialise le monde. Le monde est initialisé avec un joueur et n'est pas en cours d'exécution
 * @param monde Le monde
 */
void initMonde(Monde* monde);

#endif //PROJECT_F_MONDE_H
