#include <iostream>
#include "ResourcesManager.h"

const sf::Texture &ResourcesManager::GetTexture(const std::string &name) {
	// Check, whether the texture already exists
	for (auto it = textures.begin(); it != textures.end(); ++it) {
		if (name == it->first) {
			std::cout << "DEBUG_MESSAGE: " << name << " using existing texture.\n";
			return it->second;
		}
	}

	sf::Texture texture;

	// Search project's main directory
	if (texture.loadFromFile(name)) {
		textures[name] = texture;
		std::cout << "DEBUG_MESSAGE: " << name << " loading texture.\n";
		return textures[name];
	}

	// If the texture has still not been found, search all registered directories
	for (auto it = searchPaths.begin(); it != searchPaths.end(); ++it) {
		if (texture.loadFromFile((*it) + name)) {
			textures[name] = texture;
			std::cout << "DEBUG_MESSAGE: " << name << " loading texture.\n";
			return textures[name];
		}

	}

	std::cout << "GAME_ERROR: Texture was not found. It is filled with an empty texture.\n";
	textures[name] = texture;
	return textures[name];
}

void ResourcesManager::DeleteTexture(const sf::Texture &texture) {
	for (auto it = textures.begin(); it != textures.end(); ++it) {
		if (&texture == &it->second) {
			textures.erase(it);
			return;
		}
	}
}

void ResourcesManager::DeleteTexture(const std::string &filename) {
	auto it = textures.find(filename);
	if (it != textures.end())
		textures.erase(it);
}

void ResourcesManager::AddSearchPath(const std::string &directory) {
	for (auto it = searchPaths.begin(); it != searchPaths.end(); ++it) {
		// If path is already in search paths then we can return
		if (directory == (*it))
			return;
	}

	searchPaths.push_back(directory);
}

void ResourcesManager::RemoveSearchPath(const std::string &directory) {
	for (auto it = searchPaths.begin(); it != searchPaths.end();) {

		if (directory == (*it))
			it = searchPaths.erase(it);
		else
			++it;
	}
}
