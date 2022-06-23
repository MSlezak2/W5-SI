#pragma once
#include "Board.h"
#include "UI.h"

class Game
{
private:
	Board board;
	UI ui;
	int how_many_marks; // how many marks player needs to win the game

public:
	Game(int board_size_x = 10, int board_size_y = 10, int how_many = 5);
	void mark(int x, int y, int which_player);
	bool has_won(int player);
	bool check_rows(int player);
	bool check_columns(int player);
	bool check_diagonals(int player);
	Board get_board();
	//void set_board(Board board);
	UI get_ui();
	int get_how_many_marks();
};

