#include <iostream>
#include <filesystem>
#include "ResourcesManager.h"

bool ResourcesManager::LoadTexture(const std::string &name) {
//    std::cout << "DEBUG: Loading texture: " << name << std::endl;

    // Check, whether the texture is already loaded
    auto exists = textures.find(name) != textures.end();
    if (exists)
        return true;

    sf::Texture texture;

    // Search project's main directory
    if (this->SearchInMainDirectory) {
        auto fileExists = std::filesystem::exists(name);
        if (fileExists && texture.loadFromFile(name)) {
            textures[name] = texture;
            return true;
        }
    }

    // If the texture has still not been found, search all registered directories
    for (auto path : searchPaths) {
        auto fullPath = path + name;
        auto fileExists = std::filesystem::exists(fullPath);
        if (fileExists && texture.loadFromFile(fullPath)) {
            textures[name] = texture;
            return true;
        }
    }

    std::cout << "ERROR: Failed to load texture: " << name << std::endl;
    textures[name] = texture;
    return false;
}

const sf::Texture &ResourcesManager::GetTexture(const std::string &name) {
	// If texture is not found then we will get empty texture here
	auto textureLoaded = LoadTexture(name);
	if (!textureLoaded)
        return textures[name];

	return textures[name];
}

void ResourcesManager::UnloadTexture(const sf::Texture &texture) {
	for (auto it = textures.begin(); it != textures.end(); ++it) {
		if (&texture == &it->second) {
			textures.erase(it);
			return;
		}
	}
}

void ResourcesManager::UnloadTexture(const std::string &filename) {
	auto it = textures.find(filename);
	if (it != textures.end())
		textures.erase(it);
}

void ResourcesManager::UnloadAllTextures() {
    textures.clear();
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
