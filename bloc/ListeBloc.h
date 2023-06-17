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

/**
 * Met à jour les faces des blocs de la liste
 * @param liste La liste
 */
void updateFacesBlocs(ListeBloc* liste);

/**
 * Génère les clusters de blocs de la liste. Un cluster est un un bloc obstacle qui propage son obstacle aux blocs autour de lui.
 * @param liste La liste
 */
void generateClusters(ListeBloc* liste);

/**
 * Propage la propriété d'obstacle des clusters de la liste. Un cluster propage son obstacle aux 8 blocs autour de lui et ces blocs auront une probabilité
 * de probaBloc - DECROISSANCE_CONTAGION de devenir un obstacle et de propager à leur tour leur obstacle aux 8 blocs autour d'eux.
 * @param liste La liste des blocs
 * @param probaBloc La liste des probabilités de cluster où probaBloc[i] est la probabilité que le cluster i propage son obstacle aux blocs autour de lui
 */
void propagateClusters(ListeBloc* liste, int* probaBloc);


float probaProchainBloc(float probaBloc);
#endif //PROJECT_F_LISTEBLOC_H
