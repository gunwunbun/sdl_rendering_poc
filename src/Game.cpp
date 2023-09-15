#include <iostream>
#include "Game.h"

Game::Game(std::unique_ptr<UI> ui)
: buildingManager(500), layerManager(), ui_ (std::move(ui)) {
    buildingManager.AddBuilding(1);
    buildingManager.AddBuilding(0);
}

Game::~Game() = default;

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning_ = false;
        default:
            break;
    }
}

void Game::Update() {
    buildingManager.MoveBuildings();
}

void Game::Render() {
    ui_->StartRender();

    for (const Building& building : buildingManager.buildings()) {
        auto z = layerManager.layers_[building.layer()].baseColor;

        ui_->DrawRectangle(building.pos_x(), baseLayerPosY - (layerPosYModifier * building.layer()),
                           building.width(), building.height(),
                           z.red, z.green, z.blue, 255);
    }

    ui_->EndRender();
}

void Game::run() {
    isRunning_ = true;

    while (isRunning_) {
        ui_->StartFrame();

        HandleEvents();
        Update();
        Render();

        ui_->EndFrame();
    }
}
