#ifndef PROJECT_F_LISTEBLOC_H
#define PROJECT_F_LISTEBLOC_H

#include "../bloc/Bloc.h"

struct ListeBloc {
    Bloc* blocs;
    int nbBlocs;
};

typedef struct ListeBloc ListeBloc;

/* ===== Getters ===== */

/**
 * Renvoie le bloc de la liste à l'indice donné
 * @param liste La liste
 * @param indice L'indice
 * @return Le bloc de la liste à l'indice donné
 */
Bloc* getBloc(ListeBloc* liste, int indice);

/**
 * Renvoie le nombre de blocs de la liste
 * @param liste La liste
 * @return Le nombre de blocs de la liste
 */
int getNbBlocs(ListeBloc* liste);

/* ===== Setters ===== */

/**
 * Modifie le bloc de la liste à l'indice donné
 * @param liste La liste
 * @param indice L'indice
 * @param bloc Le nouveau bloc
 */
void setBloc(ListeBloc* liste, int indice, Bloc* bloc);

/* ===== Fonctions ===== */

/**
 * Initialise la liste de blocs
 * @param liste La liste
 * @param nbBlocs Le nombre de blocs
 */
void initListeBloc(ListeBloc* liste, int nbBlocs);

/**
 * Ajoute un bloc à la liste
 * @param liste La liste
 * @param bloc Le bloc à ajouter
 */
void ajouterBloc(ListeBloc* liste, Bloc* bloc);

/**
 * Supprime le bloc de la liste à l'indice donné
 * @param liste La liste
 * @param indice L'indice
 */
void supprimerBloc(ListeBloc* liste, int indice);

/**
 * Vide la liste de blocs
 * @param liste La liste
 */
void viderListeBloc(ListeBloc* liste);

/**
 * Passe tous les blocs de la liste au bord de l'écran en obstacle
 * @param liste La liste
 */
void creerMurs(ListeBloc* liste);

#endif //PROJECT_F_LISTEBLOC_H
