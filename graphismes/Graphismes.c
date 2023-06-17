#include "Graphismes.h"

SDL_Texture* loadSprite(SDL_Renderer* renderer, const char* file){

    // Creation d'une surface à partir d'une image
    SDL_Surface* sprite = SDL_LoadBMP(file);
    SDL_SetColorKey(sprite, SDL_TRUE, SDL_MapRGB(sprite->format, 255, 0, 255));

    // Creation d'une texture à partir d'une surface
    SDL_Texture* textureSprite = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_FreeSurface(sprite);
    return textureSprite;
}

/* ===== Initialisation ===== */

void initJoueurSprite(SDL_Renderer* renderer, Joueur* Joueur){
    setJoueurTexture(Joueur, loadSprite(renderer, "joueur/joueur.bmp"));
}

void initBlocSprite(SDL_Renderer* renderer, Bloc* bloc){
    setBlocTexture(bloc, loadSprite(renderer, "bloc/bloc.bmp"));
}

void initListeBlocsSprite(SDL_Renderer* renderer, ListeBloc* listeBlocs){
    for(int i = 0; i < getNbBlocs(listeBlocs); i++){
        initBlocSprite(renderer, getBloc(listeBlocs, i));
    }
}

/* ===== Dessin ===== */

void drawSprite(SDL_Renderer* renderer, int x, int y, int w, int h, int spriteColumn, int spriteLine, SDL_Texture* textureSprite){

    // Rectangle source
    SDL_Rect src = {w*spriteColumn,h*spriteLine,w,h};

    // Rectangle destination
    SDL_Rect dest = {x, y, w, h};

    SDL_RenderCopy(renderer,textureSprite,&src,&dest);
}

void drawJoueur(SDL_Renderer* renderer, Joueur* Joueur){
    drawSprite(renderer, (int) getJoueurX(Joueur), (int) getJoueurY(Joueur), getJoueurWidth(Joueur), getJoueurHeight(Joueur), 0, 0, getJoueurTexture(Joueur));
}

void drawBloc(SDL_Renderer* renderer, Bloc* bloc){
    if (getBlocFace(bloc) == 0){
        drawSprite(renderer, (int) getBlocX(bloc), (int) getBlocY(bloc), getBlocWidth(bloc), getBlocHeight(bloc),blocEstObstacle(bloc), 0, getBlocTexture(bloc));
    }
    else if (getBlocFace(bloc) <= 8){
        drawSprite(renderer, (int) getBlocX(bloc), (int) getBlocY(bloc), getBlocWidth(bloc), getBlocHeight(bloc),(getBlocFace(bloc)-1)%4, ((getBlocFace(bloc)-1)/4)+1, getBlocTexture(bloc));
    }
    else if(getBlocFace(bloc) <= 10){
        drawSprite(renderer, (int) getBlocX(bloc), (int) getBlocY(bloc), getBlocWidth(bloc), getBlocHeight(bloc),getBlocFace(bloc)-7, 0, getBlocTexture(bloc));
    }
    else{
        drawSprite(renderer, (int) getBlocX(bloc), (int) getBlocY(bloc), getBlocWidth(bloc), getBlocHeight(bloc), (getBlocFace(bloc)+1)%4, (getBlocFace(bloc)+1)/4, getBlocTexture(bloc));
    }
}

void drawListeBlocs(SDL_Renderer* renderer, ListeBloc* listeBlocs){
    for(int i = 0; i < getNbBlocs(listeBlocs); i++){
        drawBloc(renderer, getBloc(listeBlocs, i));
    }
}

void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}