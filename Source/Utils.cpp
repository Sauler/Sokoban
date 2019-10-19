#include "Utils.h"

Direction Utils::KeyToDirection(sf::Keyboard::Key key) {
	switch (key) {
		case sf::Keyboard::Key::W:
		case sf::Keyboard::Key::Up:
			return Up;

		case sf::Keyboard::Key::S:
		case sf::Keyboard::Key::Down:
			return Down;

		case sf::Keyboard::Key::A:
		case sf::Keyboard::Key::Left:
			return Left;

		case sf::Keyboard::Key::D:
		case sf::Keyboard::Key::Right:
			return Right;
	}

	return None;
}
