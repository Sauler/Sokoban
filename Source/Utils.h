#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "Enums.h"


class Utils {
public:
	static Direction KeyToDirection(sf::Keyboard::Key key);

private:
	Utils() {}
};


