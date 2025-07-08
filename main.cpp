#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "font.h"
#include "welcome.h"
#include "static.h"
#include "Event.h"
using namespace std;
int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    if (TTF_Init() < 0) {
        std::cerr << "TTF Init Error: " << TTF_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800, 600,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // ✅ Tạo renderer đúng cách
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // ✅ Load font trước khi dùng
    if (!LoadFont("Aptos.ttf", 32)) {
        std::cerr << "Font load failed!" << std::endl;
        return 1;
    }

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // ✅ Clear screen trước
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // nền đen
        SDL_RenderClear(renderer);

        // ✅ Vẽ text sau khi clear
        SDL_Color white = {255, 255, 255, 255};
        // Đảm bảo file nguồn được lưu UTF-8 và font hỗ trợ Unicode
        printToSDLWindow(renderer, u8"Game mô phỏng bắn B52 của Phi Công Trung Tướng AHLLVTND Phạm Tuân", 400, 10, Font, white);
        SDL_Color color = {255, 255, 255, 255};
        bool clicked= false;
        renderClickableText(renderer, u8"Chơi", 900, 300, Font, color, clicked);
        SDL_RenderPresent(renderer);
        // play
        while (clicked && !quit)
        {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
            }
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            while(!quit){
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
                int height=0;
                int speed=0;
                int increase_height=3;
                int increase_speed=3;
                string a = u8"Độ Cao: ";
                string b = u8"Tốc Độ: ";
                print_and_increase(renderer,a,10,20,Font,color,height,increase_height);
                print_and_increase(renderer,b,10,60,Font,color,height,increase_speed);
                
            }
        }
        
    }

    // Cleanup
    FreeFont();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}