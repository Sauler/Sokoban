#include <iostream>
#include "Game.h"

Game::Game(std::string windowTitle) {
	window.create(sf::VideoMode(200, 200), windowTitle);
	auto screenCenter = sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2);
	std::cout << "Screen center X: " << screenCenter.x << " Y: " << screenCenter.y << std::endl;
	window.setPosition(screenCenter);

	eventHandler = std::make_unique<EventHandler>();
}

void Game::Run() {
	while (window.isOpen()) {
		eventHandler->HandleEvents(window);

		window.clear();
		window.display();
	}
}
