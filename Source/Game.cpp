#include <iostream>
#include "Game.h"

Game::Game(std::string windowTitle) {
	Init();
	CreateWindow(windowTitle);
	CenterWindow();
}

void Game::Init() {
	eventHandler = std::make_unique<EventHandler>();
	resourcesManager = std::make_unique<ResourcesManager>();
}

void Game::CreateWindow(std::string windowTitle) {
	window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle);
}

void Game::CenterWindow() {
	auto x = (sf::VideoMode::getDesktopMode().width / 2) - (windowWidth / 2);
	auto y = (sf::VideoMode::getDesktopMode().height / 2) - (windowHeight / 2);
	auto screenCenter = sf::Vector2i(x, y);

	window.setPosition(screenCenter);
}

void Game::Run() {
	while (window.isOpen()) {
		eventHandler->HandleEvents(window);

		window.clear();
		window.display();
	}
}
