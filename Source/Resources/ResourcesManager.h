#pragma once

#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <map>

class ResourcesManager {
public:
	const sf::Texture& GetTexture(const std::string& name);
	void DeleteTexture(const sf::Texture &texture);
	void DeleteTexture(const std::string &filename);
	void AddSearchPath(const std::string &directory);
	void RemoveSearchPath(const std::string &directory);

private:
	std::map<std::string, sf::Texture> textures;
	std::vector<std::string> searchPaths;
};


