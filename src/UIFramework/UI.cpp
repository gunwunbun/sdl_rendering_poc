#include <iostream>
#include "UI.h"

UI::UI(int windowWidth, int windowHeight, const char *window_title, bool is_centered, bool is_fullscreen) : window {nullptr}, renderer {nullptr} {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        auto flags = is_fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
        int window_pos = is_centered ? SDL_WINDOWPOS_CENTERED : SDL_WINDOWPOS_UNDEFINED;

        window = SDL_CreateWindow(window_title, window_pos, window_pos, windowWidth, windowHeight, flags);

        if (window) {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
        }
    }
}

void UI::StartRender() {
    SDL_RenderClear(renderer);
}

void UI::EndRender() {
    SDL_RenderPresent(renderer);
}

void UI::DrawRectangle(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Rect rect = { x, y, width, height };

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

UI::~UI() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "UI destroyed";
}

void UI::StartFrame() {
    frameStart = SDL_GetTicks();
}

void UI::EndFrame() {
    currentFrameTime = SDL_GetTicks() - frameStart;
    if (frameTime > currentFrameTime) SDL_Delay(frameTime - currentFrameTime);
}
