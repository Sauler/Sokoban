#include <SFML/Window/Event.hpp>
#include "EventHandler.h"

void EventHandler::HandleEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
		}
	}
}