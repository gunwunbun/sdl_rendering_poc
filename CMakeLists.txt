cmake_minimum_required(VERSION 3.26)
project(sdl_rendering_poc)

set(CMAKE_CXX_STANDARD 20)

add_executable(sdl_rendering_poc src/main.cc
        src/game.cc
        src/game.h
        src/building/building.cc
        src/building/building.h
        src/building/building_manager.cc
        src/building/building_manager.h
        src/building/building_config.h
        src/ui/layer_manager.cc
        src/ui/layer_manager.h
        src/ui/layer.cc
        src/ui/layer.h
        src/ui/color.h
        src/ui_framework/ui.h
        src/ui_framework/sdl_ui.cc
        src/ui_framework/sdl_ui.h
)

# SDL2
find_package(SDL2 REQUIRED)
include_directories (${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
