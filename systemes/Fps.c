#include "Fps.h"

SDL_bool fpsCap(Uint32 startTick, Uint32 *currentTick, int cap){
    *currentTick = SDL_GetTicks();
    return *currentTick-startTick < 1000./cap;
}

void fpsUpdate(Uint32* frameCount, int* framerate, Uint32* previousSecond){
    Uint32 currentTick = SDL_GetTicks();
    // Si la milliseconde actuelle dépasse la milliseconde de la seconde actuelle
    if (currentTick > *previousSecond + 1000){
        *previousSecond = currentTick;
        *framerate = *frameCount;
        *frameCount = 0;
        printf("FPS : %d\n", *framerate+1);
    }
}