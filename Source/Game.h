#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Events/EventHandler.h"
#include "Resources/ResourcesManager.h"

class Game {
private:
	const int windowWidth = 800;
	const int windowHeight = 600;

	sf::RenderWindow window;
	std::unique_ptr<EventHandler> eventHandler;
	std::unique_ptr<ResourcesManager> resourcesManager;

	void Init();
	void CreateWindow(std::string windowTitle);
	void CenterWindow();
public:
	Game(std::string windowTitle);
	void Run();
	void Cleanup();
};


