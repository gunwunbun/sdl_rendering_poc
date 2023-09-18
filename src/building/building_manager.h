#ifndef SDL_RENDERING_POC_BUILDINGMANAGER_H
#define SDL_RENDERING_POC_BUILDINGMANAGER_H

#include <vector>
#include "building.h"

class BuildingManager {
private:
  std::vector<Building> buildings_;

  int max_pos_x_;
  int min_width_ = 10;
  int min_height_ = 15;
  int max_width_ = 50;
  int max_height_ = 75;
public:
  explicit BuildingManager();

  void AddBuilding(int layer, int layer_shade);
  void MoveBuildings();
  const std::vector<Building>& Buildings() const;
  void SetMaxPosX(int pos_x);
};


#endif //SDL_RENDERING_POC_BUILDINGMANAGER_H
