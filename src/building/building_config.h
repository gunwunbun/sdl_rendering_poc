#ifndef SDL_RENDERING_POC_BUILDINGCONFIG_H
#define SDL_RENDERING_POC_BUILDINGCONFIG_H

struct BuildingConfig {
    const int kMaxPosX;
    const int kMinWidth;
    const int kMinHeight;
    const int kMaxWidth;
    const int kMaxHeight;
    const int kLayer;
    const int kLayerShade;

    explicit BuildingConfig(int max_pos_x, int min_width, int min_height, int max_width, int max_height, int layer,
                            int layer_shade) :
        kMaxPosX {max_pos_x}, kMinWidth {min_width}, kMinHeight {min_height}, kMaxWidth {max_width},
        kMaxHeight {max_height}, kLayer {layer}, kLayerShade {layer_shade} {}
};

#endif //SDL_RENDERING_POC_BUILDINGCONFIG_H
