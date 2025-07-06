#ifndef WELCOME_H
#define WELCOME_H

#include <string>      // để dùng std::string
#include <SDL2/SDL.h>    // SDL_Window, SDL_Renderer, SDL_Color
#include <SDL2/SDL_ttf.h>   // TTF_Font

/**
 * Vẽ chuỗi `message` lên renderer tại (x, y)
 */
void printToSDLWindow(SDL_Renderer* renderer,
                      const std::string& message,
                      int x, int y,
                      TTF_Font* font,
                      SDL_Color color);
bool isPointInRect(int px, int py, const SDL_Rect& rect);
void renderClickableText(SDL_Renderer* renderer, const std::string& message, int x, int y, TTF_Font* font, SDL_Color color, bool& clicked);
#endif // WELCOME_H