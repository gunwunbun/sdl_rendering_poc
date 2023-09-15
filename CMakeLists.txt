cmake_minimum_required(VERSION 3.26)
project(sdl_rendering_poc)

set(CMAKE_CXX_STANDARD 20)

add_executable(sdl_rendering_poc src/main.cpp
        src/Game.cpp
        src/Game.h
        src/Building/Building.cpp
        src/Building/Building.h
        src/Building/BuildingManager.cpp
        src/Building/BuildingManager.h
        src/Building/BuildingConfig.h
        src/UI/LayerManager.cpp
        src/UI/LayerManager.h
        src/UI/Layer.cpp
        src/UI/Layer.h
        src/UI/Color.h
        src/UIFramework/UI.h
        src/UIFramework/SDLUI.cpp
        src/UIFramework/SDLUI.h
)

# SDL2
find_package(SDL2 REQUIRED)
include_directories (${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
