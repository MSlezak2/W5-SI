#pragma once
#include "Board.h"
#include "UI.h"

class Game
{
private:
	Board board;
	UI ui;

public:
	Game(int board_size_x = 5, int board_size_y = 5);
	void mark(int x, int y, int which_player);
	Board get_board();
	//void set_board(Board board);
	UI get_ui();
};

