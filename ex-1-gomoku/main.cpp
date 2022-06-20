#include "Game.h"

#include <iostream>



int main() 
{

	Game game = Game(10, 10);
	game.get_board().display_the_board();
	std::cout << std::endl;
	game.get_ui().make_move(game.get_board());

	return 0;
}