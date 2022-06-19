#include "Game.h"

#include <iostream>



int main() 
{

	Game game = Game(10, 10);
	game.get_board().display_the_board();

	std::cout << "test";

	return 0;
}