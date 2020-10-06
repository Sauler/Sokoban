#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../Enums.h"
#include "../Resources/ResourcesManager.h"
#include "../Drawable.h"

class Level {
private:
	struct Tiles {
		std::vector<TileType> tiles;
		int columns;

		void SetTile(int x, int y, TileType tileType) {
            auto it = tiles.begin() + (y * columns + x);
		    tiles.insert(it, tileType);
		}

        TileType GetTile(int x, int y) {
            return tiles[y * columns + x];
		}
	};

	int width;
	int height;
	Tiles tiles;

    std::vector<Drawable> GetLevel(std::unique_ptr<ResourcesManager>& resourcesManager);
public:
	void SetWidth(int width);
	void SetHeight(int height);
	void LoadFromFile(std::string path);

	void DrawStaticLevel(sf::RenderWindow* window, std::unique_ptr<ResourcesManager>& resourcesManager);
	sf::Vector2<int> GetPlayerPositionOnLevel();
	std::vector<sf::Vector2<int>> GetRocksPositionOnLevel();
};


