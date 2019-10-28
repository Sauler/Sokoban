#include "Level.h"
#include <filesystem>
#include <iostream>
#include <fstream>

void Level::SetWidth(int width) {
	this->width = width;
}

void Level::SetHeight(int height) {
	this->height = height;
}

void Level::Draw(sf::RenderWindow window) {

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

	while (file >> line) {
		auto tilesArray = LineToTilesArray(line);

		for (int i = 0; i < tilesArray.size(); i++) {
			tiles.tiles[i] = tilesArray[i];
		}
	}

	file.close();
}

std::vector<TileType> Level::LineToTilesArray(std::string line) {
	std::vector<TileType> result;
	for (auto c: line) {
		switch (c) {
			case 'E':
				result.push_back(TileType::Empty);
				break;
			case '=':
				result.push_back(TileType::Wall);
				break;
			case '.':
				result.push_back(TileType::Floor);
				break;
			case 'X':
				result.push_back(TileType::Target);
				break;
			case 'R':
				result.push_back(TileType::Rock);
				break;
			case 'P':
				result.push_back(TileType::Player);
				break;
			case 'N':
				return result;
		}


	}

	return result;
}
