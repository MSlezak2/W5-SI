#pragma once
#include "Board.h"
#include "UI.h"

class Game
{
public:
	Game();
	Game(int board_size_x, int board_size_y, int how_many);
	void start();
	void mark(int x, int y, int which_player);
	bool has_won(int player);
	Board get_board();
	//void set_board(Board board);
	UI get_ui();
	int get_how_many_marks();

private:
	Board board;
	UI ui;
	int how_many_marks; // how many marks player needs to win the game
	bool check_rows(int player);
	bool check_columns(int player);
	bool check_diagonals_downhill(int player);
	bool check_diagonals_uphill(int player);
};

