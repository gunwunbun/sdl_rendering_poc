#ifndef SDL_RENDERING_POC_SDLUI_H
#define SDL_RENDERING_POC_SDLUI_H

#include "ui.h"

class SdlUi : public UI {
private:
  SDL_Window* window_;
  SDL_Renderer* renderer_;
  const int kFps = 60;
  const int kSecondInMilliseconds = 1000;
  const int kFrameTime = kSecondInMilliseconds / kFps;

  Uint32 frame_start_;
  int current_frame_time_;

public:
  SdlUi(int window_width, int window_height, const char* window_title, bool is_centered, bool is_fullscreen);
  virtual ~SdlUi() override;

  void StartRender() override;
  void EndRender() override;
  void DrawRectangle(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a) override;
  void StartFrame() override;
  void EndFrame() override;
};

#endif //SDL_RENDERING_POC_SDLUI_H
