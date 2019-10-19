#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Events/EventHandler.h"

class Game {
private:
	sf::RenderWindow window;
	std::unique_ptr<EventHandler> eventHandler;
public:
	Game(std::string windowTitle);
	void Run();
};


