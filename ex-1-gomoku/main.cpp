#include "Game.h"

#include <iostream>



int main() 
{

	Game game = Game(10, 10, 5);
	//int users_move[2];
	//int* users_move_p = users_move;
	//*users_move_p = *game.get_ui().make_move(game.get_board());

	game.mark(7, 1, 1);
	game.mark(6, 1, 1);
	game.mark(5, 1, 1);
	game.mark(3, 1, 1);
	game.mark(4, 1, 1);
	game.mark(5, 5, 1);
	game.mark(6, 6, 1);
	game.mark(2, 7, 1);
	game.mark(8, 8, 1);
	game.mark(9, 9, 1);
	game.get_board().display_the_board();
	std::cout << game.has_won(1);

	return 0;
}