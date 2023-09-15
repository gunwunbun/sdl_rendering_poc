#ifndef SDL_RENDERING_POC_LAYER_H
#define SDL_RENDERING_POC_LAYER_H

#include <vector>
#include "Color.h"

class Layer {
public:
    Color baseColor;
    std::vector<Color> shades;
    Layer(const Color& color);
};


#endif //SDL_RENDERING_POC_LAYER_H
