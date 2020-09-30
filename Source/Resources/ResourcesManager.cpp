#include <iostream>
#include <filesystem>
#include "ResourcesManager.h"

const sf::Texture &ResourcesManager::GetTexture(const std::string &name) {
	// Check, whether the texture already exists
	for (auto texture : textures) {
        if (name == texture.first) {
            std::cout << "DEBUG_MESSAGE: " << name << " using existing texture.\n";
            return texture.second;
        }
	}

	sf::Texture texture;

	// Search project's main directory
	if (this->SearchInMainDirectory) {
	    auto fileExists = std::filesystem::exists(name);
        if (fileExists && texture.loadFromFile(name)) {
            textures[name] = texture;
            std::cout << "DEBUG_MESSAGE: " << name << " loading texture.\n";
            return textures[name];
        }
    }

	// If the texture has still not been found, search all registered directories
	for (auto path : searchPaths) {
	    auto fullPath = path + name;
        auto fileExists = std::filesystem::exists(fullPath);
        if (fileExists && texture.loadFromFile(fullPath)) {
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
    for (auto path : searchPaths) {
        // If path is already in search paths then we can return
        if (directory == path)
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
