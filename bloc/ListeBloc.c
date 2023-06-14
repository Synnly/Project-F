#include "ListeBloc.h"
#include "../systemes/constantes.h"
#define GAUCHE 0
#define DROITE 1
#define HAUT 2
#define BAS 3

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

    int index[19] = {220, 219, 218, 221, 222, 180, 179, 181, 182, 140, 260, 259, 261, 300, 100, 340, 217, 223, 301, };

    for(int i = 0; i < 19; i++){
        setBlocObstacle(getBloc(liste, index[i]));
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
    updateFacesBlocs(liste);
}

void updateFacesBlocs(ListeBloc* liste){
    for(int i = 0; i < getNbBlocs(liste); i++){
        if(!blocEstObstacle(getBloc(liste, i))){
            setBlocFace(getBloc(liste, i), 0);
        }
        else {      // Blocs obstacles
            int nbLargeur = WINDOW_WIDTH/BLOC_WIDTH;

            if(i < nbLargeur){                                                      // Bord du haut
                setBlocFace(getBloc(liste, i), (i == 0 || i == nbLargeur-1 ? 0 : 4));
            }
            else if(i%nbLargeur == 0 && i < getNbBlocs(liste)-nbLargeur){            // Bord de gauche
                setBlocFace(getBloc(liste, i), 2);
            }
            else if (i%nbLargeur == nbLargeur-1 && i < getNbBlocs(liste)-nbLargeur){ // Bord de droite
                setBlocFace(getBloc(liste, i), 1);
            }
            else if(i>= getNbBlocs(liste)-nbLargeur){                                 // Bord du bas
                setBlocFace(getBloc(liste, i), (i == getNbBlocs(liste)-nbLargeur || i == getNbBlocs(liste)-1 ? 0 : 3));
            }
            else{   // Blocs au milieu
                int voisins[4] = {blocEstObstacle(getBloc(liste, i-1)),
                                  blocEstObstacle(getBloc(liste, i+1)),
                                  blocEstObstacle(getBloc(liste, i-nbLargeur)),
                                  blocEstObstacle(getBloc(liste, i+nbLargeur))};
                int nbVoisins = voisins[GAUCHE] + voisins[DROITE] + voisins[HAUT] + voisins[BAS]; // 0: gauche, 1: droite, 2: haut, 3: bas

                switch (nbVoisins) {
                    case 0:
                        setBlocFace(getBloc(liste, i), 0);
                        break;

                    case 1:
                        setBlocFace(getBloc(liste, i),
                                    8 + voisins[GAUCHE]*2 + voisins[DROITE] * 1 + voisins[HAUT] * 4 + voisins[BAS] * 3);
                        break;

                    case 2:
                        if (voisins[GAUCHE]) {
                            setBlocFace(getBloc(liste, i), (voisins[HAUT] ? 8 : voisins[BAS] ? 6 : 14));
                        } else if (voisins[DROITE]) {
                            setBlocFace(getBloc(liste, i), (voisins[HAUT] ? 7 : voisins[BAS] ? 5 : 14));
                        } else {
                            setBlocFace(getBloc(liste, i), 13);
                        }
                        break;

                    case 3:
                        setBlocFace(getBloc(liste, i),
                                    0 + !voisins[GAUCHE] + !voisins[DROITE] * 2 + !voisins[HAUT] * 3 + !voisins[BAS] * 4);
                        break;

                    default:
                        setBlocFace(getBloc(liste, i), 0);
                        break;
                }
            }
        }
    }
}