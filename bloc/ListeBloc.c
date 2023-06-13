#include "ListeBloc.h"
#include "../systemes/constantes.h"

/* ===== Getters ===== */

Bloc* getBloc(ListeBloc* liste, int indice){
    return &liste->blocs[indice];
}

int getNbBlocs(ListeBloc* liste){
    return liste->nbBlocs;
}

/* ===== Setters ===== */

void setBloc(ListeBloc* liste, int indice, Bloc* bloc){
    liste->blocs[indice] = *bloc;
}

/* ===== Fonctions ===== */

void initListeBloc(ListeBloc* liste, int nbBlocs){
    liste->blocs = malloc(nbBlocs * sizeof(Bloc));
    liste->nbBlocs = nbBlocs;
    for (int i = 0; i < nbBlocs; i++){
        initBloc(&liste->blocs[i], (i*BLOC_WIDTH)%WINDOW_WIDTH,((i*BLOC_WIDTH)/WINDOW_WIDTH)*BLOC_HEIGHT, BLOC_WIDTH, BLOC_HEIGHT, NULL);
    }
}

void ajouterBloc(ListeBloc* liste, Bloc* bloc){
    liste->nbBlocs++;
    liste->blocs = realloc(liste->blocs, liste->nbBlocs * sizeof(Bloc));
    liste->blocs[liste->nbBlocs - 1] = *bloc;
}

void supprimerBloc(ListeBloc* liste, int indice){
    for(int i = indice; i < liste->nbBlocs - 1; i++){
        liste->blocs[i] = liste->blocs[i + 1];
    }
    liste->nbBlocs--;
    liste->blocs = realloc(liste->blocs, liste->nbBlocs * sizeof(Bloc));
}

void viderListeBloc(ListeBloc* liste){
    free(liste->blocs);
    liste->blocs = NULL;
    liste->nbBlocs = 0;
}

void creerMurs(ListeBloc* liste){
    for(int x = 0; x < WINDOW_WIDTH/BLOC_WIDTH; x++){
        for(int y = 0; y < WINDOW_HEIGHT/BLOC_HEIGHT; y++){
            // Si le bloc est sur le bord de l'écran
            if(x == 0 || x == WINDOW_WIDTH/BLOC_WIDTH - 1 || y == 0 || y == WINDOW_HEIGHT/BLOC_HEIGHT - 1){
                setBlocObstacle(getBloc(liste, y*WINDOW_WIDTH/BLOC_WIDTH + x));
            }
        }
    }
}