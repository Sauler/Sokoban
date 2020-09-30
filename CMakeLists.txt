cmake_minimum_required(VERSION 3.15)
project(Sokoban)

set(CMAKE_CXX_STANDARD 17)

set(SOKOBAN_MAIN Source/main.cpp Source/Game.cpp Source/Game.h)
set(SOKOBAN_EVENTS Source/Events/EventHandler.cpp Source/Events/EventHandler.h)
set(SOKOBAN_RESOURCES Source/Resources/ResourcesManager.cpp Source/Resources/ResourcesManager.h)
set(SOKOBAN_UTILS Source/Utils.cpp Source/Utils.h)
set(SOKOBAN_LEVELS Source/Levels/Level.cpp Source/Levels/Level.h)

add_executable(Sokoban Source/main.cpp Source/Player.cpp Source/Player.h Source/Structs.h Source/Enums.h ${SOKOBAN_MAIN} ${SOKOBAN_EVENTS} ${SOKOBAN_UTILS} ${SOKOBAN_RESOURCES} ${SOKOBAN_LEVELS})

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5.1 COMPONENTS audio graphics window system REQUIRED)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Sokoban sfml-graphics sfml-audio)
endif()

