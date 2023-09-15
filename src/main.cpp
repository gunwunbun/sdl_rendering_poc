#include <iostream>
#include "Game.h"
#include "UIFramework/UI.h"

Game* game = nullptr;
UI* ui = nullptr;

int main(int argc, char *args[]) {
    ui = new UI {500, 500, "Hello World!", true, false};

    game = new Game();
    game->ui_ = ui;
    game->isRunning_ = true;

    while (game->IsRunning()) {
        ui->StartFrame();

        game->HandleEvents();
        game->Update();
        game->Render();

        ui->EndFrame();
    }

    delete game;
    return 0;
}
