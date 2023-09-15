#include "BuildingManager.h"

BuildingManager::BuildingManager(int max_pos_x) : maxPosX {max_pos_x} {}

void BuildingManager::MoveBuildings() {
    for (Building& building : buildings_) building.move();
}

void BuildingManager::AddBuilding(int layer) {
    buildings_.emplace_back(
            min_width_, min_height_, max_width_, max_height_, maxPosX, layer
            );
}

const std::vector<Building>& BuildingManager::buildings() const {
    return buildings_;
}