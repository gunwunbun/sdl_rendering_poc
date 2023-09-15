#ifndef SDL_RENDERING_POC_BUILDING_H
#define SDL_RENDERING_POC_BUILDING_H

#include "BuildingConfig.h"

class Building {
private:
    int pos_x_{};
    int pos_y_{};
    int width_{};
    int height_{};

    const BuildingConfig config_;
public:
    explicit Building(int min_width, int min_height, int max_width, int max_height, int max_pos_x, int layer);

    void move();
    void reset_at_start();

    // Getters
    int width() const;
    int height() const;
    int pos_x() const;
    int pos_y() const;
    int layer() const;
};


#endif //SDL_RENDERING_POC_BUILDING_H
