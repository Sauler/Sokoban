#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Enums.h"

class Level {
private:
	struct Tiles {
		std::vector<TileType> tiles;
		int columns;

		TileType *operator[] (int i) { return &tiles[0] + i * columns; };
	};

	int width;
	int height;
	Tiles tiles;

	std::vector<TileType> LineToTilesArray(std::string line);

public:
	void SetWidth(int width);
	void SetHeight(int height);
	void LoadFromFile(std::string path);
	void Draw(sf::RenderWindow window);
};


