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

std::vector<TileType> Utils::LineToTilesArray(std::string line) {
    std::vector<TileType> result;
    for (auto c : line) {
        switch (c) {
            case 'E':
                result.push_back(TileType::Empty);
                break;
            case '=':
                result.push_back(TileType::Wall);
                break;
            case '.':
                result.push_back(TileType::Floor);
                break;
            case 'X':
                result.push_back(TileType::Target);
                break;
            case 'R':
                result.push_back(TileType::Rock);
                break;
            case 'P':
                result.push_back(TileType::Player);
                break;
            case 'N':
                return result;
        }
    }

    return result;
}

std::string Utils::TileToTextureName(TileType tileType) {
    switch (tileType) {
        case Empty:
            return std::string();
        case Floor:
            return "floor.png";
        case Wall:
            return "wall.png";
        case Rock:
            return "rock.png";
        case RockDone:
            return "rock_done.png";
        case Target:
            return "target.png";
        case Player:
            return "player.png";
        default:
            return std::string();
    }
}

bool Utils::IsStaticLevelTile(TileType tileType) {
    switch (tileType) {
        case Empty:
        case Rock:
        case RockDone:
        case Player:
            return false;
        case Floor:
        case Wall:
        case Target:
            return true;
    }
}


