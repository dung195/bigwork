#include <SDL2/SDL.h>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long long double
const int SCREEN_WIDTH=800;
const int SCREEN_HEIGHT=600;
SDL_Window* initSDL(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
}
int main(){
    SDL_Window* window=initSDL();
    SDL_Renderer* renderer=createRenderer();


}