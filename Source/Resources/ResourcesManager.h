#pragma once

#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <map>

class ResourcesManager {
public:
	const sf::Texture& GetTexture(const std::string& name);
	void UnloadTexture(const sf::Texture &texture);
	void UnloadTexture(const std::string &filename);
    void UnloadAllTextures();
    void AddSearchPath(const std::string &directory);
    void RemoveSearchPath(const std::string &directory);
private:
	std::map<std::string, sf::Texture> textures;
	std::vector<std::string> searchPaths;
	const bool SearchInMainDirectory = true;
};


