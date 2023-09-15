#ifndef SDL_RENDERING_POC_UI_H
#define SDL_RENDERING_POC_UI_H

#include <SDL.h>

class UI {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    const int fps = 60;
    const int secondInMilliseconds = 1000;
    const int frameTime = secondInMilliseconds / fps;

    Uint32 frameStart;
    int currentFrameTime;
public:
    UI(int windowWidth, int windowHeight, const char *window_title, bool is_centered, bool is_fullscreen);
    ~UI();
    void DrawRectangle(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void StartRender();
    void EndRender();

    void StartFrame();
    void EndFrame();
};

#endif //SDL_RENDERING_POC_UI_H
