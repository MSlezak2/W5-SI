#include "Game.h"

#include <iostream>



int main() 
{

	Game game = Game(10, 10);
	game.get_board().display_the_board();
	std::cout << std::endl;
	//int users_move[2];
	//int* users_move_p = users_move;
	//*users_move_p = *game.get_ui().make_move(game.get_board());

	game.mark(1, 1, 1);
	game.mark(1, 1, 2);
	game.get_board().display_the_board();

	return 0;
}