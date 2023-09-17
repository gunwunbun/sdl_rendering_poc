#ifndef SDL_RENDERING_POC_BUILDINGMANAGER_H
#define SDL_RENDERING_POC_BUILDINGMANAGER_H

#include <vector>
#include "building.h"

class BuildingManager {
private:
  std::vector<Building> buildings_;

  const int kMaxPosX;
  int min_width_ = 10;
  int min_height_ = 15;
  int max_width_ = 50;
  int max_height_ = 75;
public:
  explicit BuildingManager(int max_pos_x);

  void AddBuilding(int layer);
  void MoveBuildings();
  const std::vector<Building>& Buildings() const;
};

#endif //SDL_RENDERING_POC_BUILDINGMANAGER_H
