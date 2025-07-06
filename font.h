#pragma once
#include <SDL2/SDL_ttf.h>

extern TTF_Font* Font;                // biến toàn cục
bool LoadFont(const char* path, int size);
void FreeFont();