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
	resourcesManager->LoadTexture("floor.png");
	resourcesManager->LoadTexture("player.png");
	resourcesManager->LoadTexture("rock.png");
	resourcesManager->LoadTexture("rock_done.png");
	resourcesManager->LoadTexture("target.png");
	resourcesManager->LoadTexture("wall.png");

    Level lvl;
    lvl.LoadFromFile("../Assets/Levels/level0.lvl");

	while (window.isOpen()) {
		eventHandler->HandleEvents(window);
		window.clear();
        lvl.DrawStaticLevel(&window, resourcesManager);
		window.display();
	}
}

void Game::Cleanup() {
    resourcesManager->UnloadAllTextures();
}
