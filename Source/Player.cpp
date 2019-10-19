#include "Player.h"
#include "Utils.h"

bool Player::HandleInput(sf::Event::KeyEvent keyEvent) {
	auto direction = Utils::KeyToDirection(keyEvent.code);

	if (direction != None) {
		MovePlayer(direction);
		return true;
	}

	return false;
}

void Player::MovePlayer(Direction direction) {

}
