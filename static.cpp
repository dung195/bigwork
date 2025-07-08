#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "font.h"
#include "welcome.h"
#include "Event.h"
// in ra số tăng dần
void print_and_increase(SDL_Renderer* renderer, const std::string& message, int x, int y, TTF_Font* font, SDL_Color color, int val,int increase){
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    string need= message + to_string(val);
    printToSDLWindow(renderer, need, x, y, Font, color);
    SDL_RenderPresent(renderer); 
    val+=increase;
    need= message + to_string(val);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    printToSDLWindow(renderer,need,x,y,font,color);
    SDL_RenderPresent(renderer); 
    }
}