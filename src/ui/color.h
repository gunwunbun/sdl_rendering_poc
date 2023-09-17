#ifndef SDL_RENDERING_POC_COLOR_H
#define SDL_RENDERING_POC_COLOR_H

#include <SDL_stdinc.h>

struct Color {
  Uint8 red;
  Uint8 green;
  Uint8 blue;

  Color(Uint8 r, Uint8 g, Uint8 b) : red(r), green(g), blue(b) {}
};

#endif //SDL_RENDERING_POC_COLOR_H
