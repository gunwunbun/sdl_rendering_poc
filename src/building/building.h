#ifndef SDL_RENDERING_POC_BUILDING_H
#define SDL_RENDERING_POC_BUILDING_H

#include "building_config.h"

class Building {
private:
    int pos_x_;
    int pos_y_;
    int width_;
    int height_;

    const BuildingConfig config_;
public:
    explicit Building(int min_width, int min_height, int max_width, int max_height, int max_pos_x, int layer, int layer_shade);

    void Move();
    void ResetAtStart();

    int Width() const;
    int Height() const;
    int PosX() const;
    int PosY() const;
    int Layer() const;
    int Shade() const;
};


#endif //SDL_RENDERING_POC_BUILDING_H
