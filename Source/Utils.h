#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <string>
#include "Enums.h"


class Utils {
public:
    static Direction KeyToDirection(sf::Keyboard::Key key);
    static std::vector<TileType> LineToTilesArray(std::string line);
    static std::string TileToTextureName(TileType tileType);
    static bool IsStaticLevelTile(TileType tileType);
private:
    Utils() {}
};


