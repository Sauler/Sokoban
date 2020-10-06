#include "Level.h"
#include "../Utils.h"
#include <filesystem>
#include <iostream>
#include <fstream>

void Level::SetWidth(int width) {
	this->width = width;
}

void Level::SetHeight(int height) {
	this->height = height;
}

void Level::DrawStaticLevel(sf::RenderWindow* window, std::unique_ptr<ResourcesManager>& resourcesManager) {
    auto staticLevel = GetLevel(resourcesManager);

    for (auto drawable : staticLevel) {
        window->draw(drawable.sprite);
    }
}

std::vector<Drawable> Level::GetLevel(std::unique_ptr<ResourcesManager>& resourcesManager) {
    std::vector<Drawable> result;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            auto tile = tiles.GetTile(x, y);
            if (!Utils::IsStaticLevelTile(tile)) {
                if (tile == TileType::Empty )
                    continue;

                tile = TileType::Floor;
            }

            auto textureName = Utils::TileToTextureName(tile);
            if (textureName.empty())
                continue;

            auto texture = resourcesManager->GetTexture(textureName);
            Drawable drawable;
            drawable.position = sf::Vector2f(x * 32, y * 32);
            drawable.texture = texture;
            result.push_back(drawable);
        }
    }
    return result;
}

void Level::LoadFromFile(std::string path) {
	if (!std::filesystem::exists(path)) {
		std::cout << "Failed to load level at path '" << path << " ' \n";
		return;
	}

	std::fstream file;
	file.open(path);
	if (!file.is_open()) {
		std::cout << "Cannot open file '" << path << " ' \n";
		return;
	}

	int w;
	int h;

	// Read width
	file >> w;

	if (w < 0 || w > 16) {
		std::cout << "Level width is wrong: " << w << "\n";
		file.close();
		return;
	}

	// Read height
	file >> h;

	if (h < 0 || h > 16) {
		std::cout << "Level height is wrong: " << h << "\n";
		file.close();
		return;
	}

	SetHeight(h);
	SetWidth(w);

	std::string line;
	tiles.columns = height;

	int y = 0;
	while (file >> line) {
		auto tilesArray = Utils::LineToTilesArray(line);

		for (int x = 0; x < tilesArray.size(); x++) {
			tiles.SetTile(x, y, tilesArray[x]);
		}
		y++;
	}

	file.close();
}

sf::Vector2<int> Level::GetPlayerPositionOnLevel() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            auto tile = tiles.GetTile(x, y);
            if (tile == TileType::Player)
                return sf::Vector2<int>(x, y);
        }
    }

    return sf::Vector2<int>(0, 0);
}

std::vector<sf::Vector2<int>> Level::GetRocksPositionOnLevel() {
    std::vector<sf::Vector2<int>> result;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            auto tile = tiles.GetTile(x, y);
            if (tile == TileType::Rock)
                result.emplace_back(x, y);
        }
    }

    if (result.empty())
        result.emplace_back(0, 0);

    return std::vector<sf::Vector2<int>>();
}


