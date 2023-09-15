#ifndef SDL_RENDERING_POC_GAME_H
#define SDL_RENDERING_POC_GAME_H
#include <vector>
#include "Building/Building.h"
#include "Building/BuildingManager.h"
#include "UI/LayerManager.h"
#include "UIFramework/UI.h"

class Game {
private:
    BuildingManager buildingManager;
    LayerManager layerManager;
    const int baseLayerPosY = 250;
    const int layerPosYModifier = 50;
    std::unique_ptr<UI> ui_;
public:
    bool isRunning_ = false;

    Game(std::unique_ptr<UI> ui);
    ~Game();
    void run();


    void HandleEvents();
    void Update();
    void Render();

    [[nodiscard]] bool IsRunning() const;
};

#endif //SDL_RENDERING_POC_GAME_H
