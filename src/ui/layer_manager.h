#ifndef SDL_RENDERING_POC_LAYER_MANAGER_H
#define SDL_RENDERING_POC_LAYER_MANAGER_H

#include "layer.h"

class LayerManager {
public:
  explicit LayerManager();
  const Layer layers_[3];
};

#endif //SDL_RENDERING_POC_LAYER_MANAGER_H
