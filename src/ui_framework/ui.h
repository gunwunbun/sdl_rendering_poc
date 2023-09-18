#ifndef SDL_RENDERING_POC_UI_H
#define SDL_RENDERING_POC_UI_H

#include <SDL.h>

class UI {
public:
  virtual ~UI() = default;

  virtual void StartRender() = 0;
  virtual void EndRender() = 0;
  virtual void DrawRectangle(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a) = 0;
  virtual void StartFrame() = 0;
  virtual void EndFrame() = 0;

  virtual int WindowWidth() = 0;
  virtual int WindowHeight() = 0;
};

#endif //SDL_RENDERING_POC_UI_H
