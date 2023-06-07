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

void initJoueurSprite(SDL_Renderer* renderer, Joueur* Joueur){
    setJoueurTexture(Joueur, loadSprite(renderer, "joueur/joueur.bmp"));
}

/* ==================================================================================================================================  */
/* ============================================================  Dessins ============================================================  */
/* ==================================================================================================================================  */


void drawSprite(SDL_Renderer* renderer, int x, int y, int w, int h, int spriteIndex, SDL_Texture* textureSprite){

    // Rectangle source
    SDL_Rect src = {w*spriteIndex,0,w,h};

    // Rectangle destination
    SDL_Rect dest = {x, y, w, h};

    SDL_RenderCopy(renderer,textureSprite,&src,&dest);
}

void drawJoueur(SDL_Renderer* renderer, Joueur* Joueur){
    drawSprite(renderer, (int) getJoueurX(Joueur), (int) getJoueurY(Joueur), getJoueurWidth(Joueur), getJoueurHeight(Joueur), 0,getJoueurTexture(Joueur));
}

void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}