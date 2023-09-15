#include <iostream>
#include "Game.h"
#include "UIFramework/UI.h"
#include "UIFramework/SDLUI.h"

int main(int argc, char *args[]) {

    std::unique_ptr<UI> ui = std::make_unique<SDLUI>(
            500, 500, "Hello World!", true, false);

    Game game(std::move(ui));

    game.run();

    return 0;
}
