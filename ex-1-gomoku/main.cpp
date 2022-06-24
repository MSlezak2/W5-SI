#include "Game.h"

#include <iostream>



int main() 
{

	Game game = Game(10, 10, 5);
	//int users_move[2];
	//int* users_move_p = users_move;
	//*users_move_p = *game.get_ui().make_move(game.get_board());

	//game.mark(7, 1, 1);
	//game.mark(2, 1, 1);
	//game.mark(2, 1, 1);
	//game.mark(3, 1, 1);
	//game.mark(4, 1, 1);
	//game.mark(5, 3, 1);
	//game.mark(6, 4, 1);
	//game.mark(7, 1, 1);
	//game.mark(8, 6, 1);
	//game.mark(9, 7, 1);

	//game.mark(2, 8, 1);
	//game.mark(3, 7, 1);
	//game.mark(4, 6, 1);
	//game.mark(5, 5, 1);
	//game.mark(6, 4, 1);

	//game.mark(4, 8, 1);
	//game.mark(5, 7, 1);
	//game.mark(6, 6, 1);
	//game.mark(7, 5, 1);
	//game.mark(8, 4, 1);

	game.mark(0, 5, 1);
	game.mark(1, 4, 1);
	game.mark(2, 3, 1);
	game.mark(3, 2, 1);
	game.mark(4, 1, 1);

	game.get_board().display_the_board();
	std::cout << game.has_won(1);

	return 0;
}