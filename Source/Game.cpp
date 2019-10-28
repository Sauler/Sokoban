#include <iostream>
#include <utility>
#include "Game.h"
#include "SFML/Graphics/Sprite.hpp"
#include "Levels/Level.h"

Game::Game(std::string windowTitle) {
	Init();
	CreateWindow(std::move(windowTitle));
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
	resourcesManager->AddSearchPath("../Assets/Gfx/");
	auto texture = resourcesManager->GetTexture("floor.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);

	Level lvl;
	lvl.LoadFromFile("../Assets/Levels/level0.lvl");

	while (window.isOpen()) {
		eventHandler->HandleEvents(window);

		window.clear();
		window.draw(sprite);
		window.display();
	}
}
