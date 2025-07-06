#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include "font.h"

TTF_Font* Font =  nullptr;
bool LoadFont(const char* path, int size) {
    if (!Font) Font = TTF_OpenFont(path, size);
    return Font != nullptr;
}
void FreeFont()
{
    if (Font)
    {
        TTF_CloseFont(Font);
        Font = nullptr;
    }
}