#ifndef SDL_RENDERING_POC_LAYERMANAGER_H
#define SDL_RENDERING_POC_LAYERMANAGER_H

#include "Layer.h"

class LayerManager {
public:
    explicit LayerManager();

    const Layer layers_[3];
};


#endif //SDL_RENDERING_POC_LAYERMANAGER_H
