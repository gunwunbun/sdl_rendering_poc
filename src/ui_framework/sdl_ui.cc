#include "sdl_ui.h"

SdlUi::SdlUi(int window_width, int window_height, const char* window_title, bool is_centered, bool is_fullscreen)
        : window_{nullptr}, renderer_{nullptr}, window_width_ {window_width}, window_height_ {window_height} {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        auto flags = is_fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
        int windowPos = is_centered ? SDL_WINDOWPOS_CENTERED : SDL_WINDOWPOS_UNDEFINED;

      window_ = SDL_CreateWindow(window_title, windowPos, windowPos, window_width, window_height, flags);

        if (window_) {
          renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
            if (renderer_) {
                SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
            }
        }
    }
}

void SdlUi::StartRender() {
    SDL_RenderClear(renderer_);
}

void SdlUi::EndRender() {
    SDL_RenderPresent(renderer_);
}

void SdlUi::DrawRectangle(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Rect rect = {x, y, width, height};

    SDL_SetRenderDrawColor(renderer_, r, g, b, a);
    SDL_RenderFillRect(renderer_, &rect);
    SDL_SetRenderDrawColor(renderer_, 1, 23, 47, 255);
}

SdlUi::~SdlUi() {
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
}

void SdlUi::StartFrame() {
  frame_start_ = SDL_GetTicks();
}

void SdlUi::EndFrame() {
  current_frame_time_ = SDL_GetTicks() - frame_start_;
    if (kFrameTime > current_frame_time_) SDL_Delay(kFrameTime - current_frame_time_);
}

int SdlUi::WindowWidth() {
  return window_width_;
}

int SdlUi::WindowHeight() {
  return window_height_;
}
