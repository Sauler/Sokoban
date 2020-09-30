#include "Game.h"

int main() {
	Game game("Sokoban");
	game.Run();
    game.Cleanup();
    return 0;
}