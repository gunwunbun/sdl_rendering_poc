#include <cstdlib>
#include "Building.h"

Building::Building(int min_width, int min_height, int max_width, int max_height, int max_pos_x, int layer) :
        config_(max_pos_x, min_width, min_height, max_width, max_height, layer) {
    reset_at_start();
    pos_x_ = rand()%((max_pos_x - 0) + 1) + 0;
}

void Building::move() {
    pos_x_ += 5;
    if (pos_x_ > config_.max_pos_x_) reset_at_start();
}

void Building::reset_at_start() {
    pos_x_ = 0;
    pos_y_ = 100;
    width_ = rand()%((config_.max_width_ - config_.min_width_) + 1) + config_.min_width_;
    height_ = rand()%((config_.max_height_ - config_.min_height_) + 1) + config_.min_height_;
}

int Building::width() const {
    return width_;
}

int Building::height() const {
    return height_;
}

int Building::pos_x() const {
    return pos_x_;
}

int Building::pos_y() const {
    return pos_y_;
}

int Building::layer() const {
    return config_.layer_;
}