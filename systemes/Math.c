#include "Math.h"
#include "constantes.h"

float hypotenuse(float x){
    return SDL_sqrt(SDL_pow(x, 2)/2);
}

SDL_bool floatEquals(float a, float b){
    return SDL_abs(a - b) < EPSILON;
}