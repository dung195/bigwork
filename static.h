#ifndef STATIC_H
#define STATIC_H
#include<SDL2/SDL.h>
#include<bits/stdc++.h>
#include <SDL2/SDL_ttf.h>
using namespace std;
void print_and_increase(SDL_Renderer* renderer, const std::string& message, int x, int y, TTF_Font* font, SDL_Color color, int val,int increase);
#endif