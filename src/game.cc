#include <iostream>
#include "game.h"

Game::Game(std::unique_ptr<UI> ui)
: layer_manager_(), ui_ (std::move(ui)), building_manager_() {
  int amount_per_layer = 15;

  building_manager_.SetMaxPosX(ui_->WindowWidth());

  for (int i = 0; i < amount_per_layer; i++)
    building_manager_.AddBuilding(2, rand()%((4)));

  for (int i = 0; i < amount_per_layer * 0.9; i++)
    building_manager_.AddBuilding(1, rand()%((4)));

  for (int i = 0; i < amount_per_layer; i++)
    building_manager_.AddBuilding(0, rand()%((4)));
}

Game::~Game() = default;

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
          is_running_ = false;
        default:
            break;
    }
}

void Game::Update() {
    building_manager_.MoveBuildings();
}

void Game::Render() {
    ui_->StartRender();

    for (const Building& building : building_manager_.Buildings()) {
      auto z = layer_manager_.layers_[building.Layer()].GetColor(building.Shade());

      int yPos = kBaseLayerPosY - (kLayerPosYModifier * building.Layer()) - building.Height();

      // Make sure yPos is at least the same as layer 0's Y position
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
