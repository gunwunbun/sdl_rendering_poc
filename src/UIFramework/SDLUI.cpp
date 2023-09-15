//
// Created by JVH on 15/09/2023.
//

#include "SDLUI.h"

SDLUI::SDLUI(int windowWidth, int windowHeight, const char* windowTitle, bool isCentered, bool isFullscreen)
        : window{nullptr}, renderer{nullptr} {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        auto flags = isFullscreen ? SDL_WINDOW_FULLSCREEN : 0;
        int windowPos = isCentered ? SDL_WINDOWPOS_CENTERED : SDL_WINDOWPOS_UNDEFINED;

        window = SDL_CreateWindow(windowTitle, windowPos, windowPos, windowWidth, windowHeight, flags);

        if (window) {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
        }
    }
}

void SDLUI::StartRender() {
    SDL_RenderClear(renderer);
}

void SDLUI::EndRender() {
    SDL_RenderPresent(renderer);
}

void SDLUI::DrawRectangle(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Rect rect = {x, y, width, height};

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

SDLUI::~SDLUI() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void SDLUI::StartFrame() {
    frameStart = SDL_GetTicks();
}

void SDLUI::EndFrame() {
    currentFrameTime = SDL_GetTicks() - frameStart;
    if (frameTime > currentFrameTime) SDL_Delay(frameTime - currentFrameTime);
}
