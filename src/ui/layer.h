#ifndef SDL_RENDERING_POC_LAYER_H
#define SDL_RENDERING_POC_LAYER_H

#include <vector>
#include "color.h"

class Layer {
public:
    Color base_color_;
    std::vector<Color> shades_;
    explicit Layer(const Color& color);
    const Color& GetColor(int shade) const;
};


#endif //SDL_RENDERING_POC_LAYER_H
