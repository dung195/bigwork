#include <string>      // để dùng std::string
#include <SDL2/SDL.h>    // SDL_Window, SDL_Renderer, SDL_Color
#include <SDL2/SDL_ttf.h> 
#include<iostream>
using namespace std;
void printToSDLWindow(SDL_Renderer* renderer, const std::string& message, int x, int y, TTF_Font* font, SDL_Color color) {
    SDL_Surface* textSurface = TTF_RenderUTF8_Solid(font, message.c_str(), color);
    if (!textSurface) return;
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        SDL_FreeSurface(textSurface);
        return;
    }
    SDL_Rect dstRect = { x, y, textSurface->w, textSurface->h };
    SDL_RenderCopy(renderer, textTexture, nullptr, &dstRect);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}

bool isPointInRect(int px, int py, const SDL_Rect& rect) {
    return px >= rect.x && px < rect.x + rect.w && py >= rect.y && py < rect.y + rect.h;
}

void renderClickableText(SDL_Renderer* renderer, const std::string& message, int x, int y, TTF_Font* font, SDL_Color color, bool& clicked) {
    SDL_Surface* textSurface = TTF_RenderUTF8_Solid(font, message.c_str(), color);
    if (!textSurface) return;
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        SDL_FreeSurface(textSurface);
        return;
    }
    SDL_Rect dstRect = { x, y, textSurface->w, textSurface->h };
    SDL_RenderCopy(renderer, textTexture, nullptr, &dstRect);

    SDL_Event e;
    int mx, my;
    SDL_GetMouseState(&mx, &my);
    if (isPointInRect(mx, my, dstRect)) {
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
    } else {
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    }
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            int mx = e.button.x, my = e.button.y;
            if (isPointInRect(mx, my, dstRect)) {
                clicked = true;
                return;
            }
        }
    }
    cout<<123<<endl;
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}