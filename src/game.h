#ifndef SDL_RENDERING_POC_GAME_H
#define SDL_RENDERING_POC_GAME_H
#include <vector>
#include "building/building.h"
#include "building/building_manager.h"
#include "ui/layer_manager.h"
#include "ui_framework/ui.h"

class Game {
private:
  BuildingManager building_manager_;
  LayerManager layer_manager_;
  std::unique_ptr<UI> ui_;
  const int kBaseLayerPosY = ui_->WindowHeight();
  const int kLayerPosYModifier = 50;
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
