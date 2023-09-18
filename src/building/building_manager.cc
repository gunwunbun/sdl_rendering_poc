#include "building_manager.h"

BuildingManager::BuildingManager() {}

void BuildingManager::MoveBuildings() {
  for (Building& building : buildings_) building.Move();
}

void BuildingManager::AddBuilding(int layer, int layer_shade) {
  buildings_.emplace_back(
      min_width_, min_height_, max_width_, max_height_, max_pos_x_,
      layer, layer_shade);
}

const std::vector<Building>& BuildingManager::Buildings() const {
  return buildings_;
}

void BuildingManager::SetMaxPosX(int pos_x) {
  max_pos_x_ = pos_x;
}
