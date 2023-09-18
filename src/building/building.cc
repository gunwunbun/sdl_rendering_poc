#include <cstdlib>
#include "building.h"

Building::Building(int min_width, int min_height, int max_width, int max_height, int max_pos_x, int layer, int layer_shade) :
          config_(max_pos_x, min_width, min_height, max_width, max_height, layer, layer_shade) {
  ResetAtStart();
  pos_x_ = rand()%((max_pos_x - 0) + 1) + 0;
}

void Building::Move() {
  pos_x_ += config_.kLayer == 0 ? 3 : (config_.kLayer == 1 ? 3 : 1);
  if (pos_x_ > config_.kMaxPosX) ResetAtStart();
}

void Building::ResetAtStart() {
  pos_x_ = 0;
  pos_y_ = 100;
  width_ = rand()%((config_.kMaxWidth - config_.kMinWidth) + 1) + config_.kMinWidth + config_.kLayer * 10;
  height_ = rand()%((config_.kMaxHeight - config_.kMinHeight) + 1) + config_.kMinHeight + config_.kLayer * 45;
}

int Building::Width() const {
  return width_;
}

int Building::Height() const {
  return height_;
}

int Building::PosX() const {
  return pos_x_;
}

int Building::PosY() const {
    return pos_y_;
}

int Building::Layer() const {
    return config_.kLayer;
}

int Building::Shade() const {
  return config_.kLayerShade;
}
