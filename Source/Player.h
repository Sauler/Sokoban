#pragma once

#include <SFML/Window/Event.hpp>
#include "Structs.h"
#include "Enums.h"

class Player {
private:
	Position position;
public:
	bool HandleInput(sf::Event::KeyEvent keyEvent);
	void MovePlayer(Direction direction);
};



