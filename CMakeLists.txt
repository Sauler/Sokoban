cmake_minimum_required(VERSION 3.15)
project(Sokoban)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sokoban main.cpp)

find_package(SFML REQUIRED graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Sokoban sfml-graphics)
endif()