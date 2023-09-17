#ifndef SDL_RENDERING_POC_GAME_H
#define SDL_RENDERING_POC_GAME_H
#include <vector>
#include "Building/building.h"
#include "Building/building_manager.h"
#include "ui/layer_manager.h"
#include "ui_framework/ui.h"

class Game {
private:
  BuildingManager building_manager_;
  LayerManager layer_manager_;
  const int kBaseLayerPosY = 250;
  const int kLayerPosYModifier = 50;
  std::unique_ptr<UI> ui_;
  bool is_running_ = false;
public:
  explicit Game(std::unique_ptr<UI> ui);
  ~Game();

  void Run();
  void HandleEvents();
  void Update();
  void Render();
};

#endif //SDL_RENDERING_POC_GAME_H
