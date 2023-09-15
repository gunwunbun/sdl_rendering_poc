#ifndef SDL_RENDERING_POC_BUILDINGCONFIG_H
#define SDL_RENDERING_POC_BUILDINGCONFIG_H

struct BuildingConfig {
    const int max_pos_x_;
    const int min_width_;
    const int min_height_;
    const int max_width_;
    const int max_height_;
    const int layer_;

    explicit BuildingConfig(int max_pos_x, int min_width, int min_height, int max_width, int max_height, int layer) :
        max_pos_x_ {max_pos_x}, min_width_ {min_width}, min_height_ {min_height}, max_width_ {max_width}, max_height_ {max_height}, layer_ {layer} {}
};

#endif //SDL_RENDERING_POC_BUILDINGCONFIG_H
