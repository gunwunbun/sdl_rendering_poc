#ifndef SDL_RENDERING_POC_SDLUI_H
#define SDL_RENDERING_POC_SDLUI_H

#include "UI.h"

class SDLUI : public UI {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    const int fps = 60;
    const int secondInMilliseconds = 1000;
    const int frameTime = secondInMilliseconds / fps;

    Uint32 frameStart;
    int currentFrameTime;

public:
    SDLUI(int windowWidth, int windowHeight, const char* windowTitle, bool isCentered, bool isFullscreen);
    virtual ~SDLUI() override;

    void StartRender() override;
    void EndRender() override;
    void DrawRectangle(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a) override;
    void StartFrame() override;
    void EndFrame() override;
};

#endif //SDL_RENDERING_POC_SDLUI_H
