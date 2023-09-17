#include <iostream>
#include "game.h"
#include "ui_framework/ui.h"
#include "ui_framework/sdl_ui.h"

int main(int argc, char *args[]) {
  std::unique_ptr<UI> ui = std::make_unique<SdlUi>(500, 500, "Rendering PoC",
                                                   true, false);

  Game game(std::move(ui));
  game.Run();

  return 0;
}
