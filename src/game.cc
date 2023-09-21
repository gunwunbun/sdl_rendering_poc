#include <iostream>
#include "game.h"

Game::Game(std::unique_ptr<UI> ui)
: layer_manager_(), ui_ (std::move(ui)), building_manager_() {
  building_manager_.SetMaxPosX(ui_->WindowWidth());

  const int amount_per_layer = 15;

  for (int layer = 2; layer >= 0; layer--) {
    int num_buildings = static_cast<int>(amount_per_layer * (layer == 2 ? 1.2 : 0.9));

    for (int i = 0; i < num_buildings; i++) {
      int type = layer;
      int position = rand() % 4;
      building_manager_.AddBuilding(type, position);
    }
  }
}

Game::~Game() = default;

void Game::HandleEvents() {
  // Handle window close event
  // NOTE: Not part of this PoC, ignore.
  SDL_Event event;
  SDL_PollEvent(&event);
  if (event.type == SDL_QUIT) is_running_ = false;
}

void Game::Update() {
  building_manager_.MoveBuildings();
}

void Game::Render() {
  ui_->StartRender();

  for (const Building& building : building_manager_.Buildings()) {
    auto z = layer_manager_.layers_[building.Layer()].GetColor(building.Shade());

    int yPos = kBaseLayerPosY - (kLayerPosYModifier * building.Layer()) - building.Height();

    yPos = std::max(yPos, kBaseLayerPosY - (kLayerPosYModifier * 0) - building.Height());

    ui_->DrawRectangle(building.PosX(), yPos, building.Width(), building.Height(),
                       z.red, z.green, z.blue, 255);
  }

  ui_->EndRender();
}

void Game::Run() {
  is_running_ = true;

  while (is_running_) {
    ui_->StartFrame();

    HandleEvents();
    Update();
    Render();

    ui_->EndFrame();
  }
}
