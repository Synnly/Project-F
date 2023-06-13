#include "ListeBloc.h"

/* ===== Getters ===== */

Bloc* getBloc(ListeBloc* liste, int indice){
    return &liste->bloc[indice];
}

int getNbBlocs(ListeBloc* liste){
    return liste->nbBlocs;
}

/* ===== Setters ===== */

void setBloc(ListeBloc* liste, int indice, Bloc* bloc){
    liste->bloc[indice] = *bloc;
}

/* ===== Fonctions ===== */

void initListeBloc(ListeBloc* liste){
    liste->bloc = NULL;
    liste->nbBlocs = 0;
}

void ajouterBloc(ListeBloc* liste, Bloc* bloc){
    liste->nbBlocs++;
    liste->bloc = realloc(liste->bloc, liste->nbBlocs * sizeof(Bloc));
    liste->bloc[liste->nbBlocs - 1] = *bloc;
}

void supprimerBloc(ListeBloc* liste, int indice){
    for(int i = indice; i < liste->nbBlocs - 1; i++){
        liste->bloc[i] = liste->bloc[i + 1];
    }
    liste->nbBlocs--;
    liste->bloc = realloc(liste->bloc, liste->nbBlocs * sizeof(Bloc));
}

void viderListeBloc(ListeBloc* liste){
    free(liste->bloc);
    liste->bloc = NULL;
    liste->nbBlocs = 0;
}