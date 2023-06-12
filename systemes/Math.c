#include "Math.h"
#include <SDL2/SDL.h>

float hypotenuse(float x){
    return SDL_sqrt(SDL_pow(x, 2)/2);
}