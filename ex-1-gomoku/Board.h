#pragma once
class Board
{
private:
	int board_size_x, board_size_y;
	int **cells;

public:
	Board(int board_size_x = 5, int board_size_y = 5);
	void clear_the_board();
	void display_the_board();
	bool is_full();
	int get_board_size_x();
	int get_board_size_y();
	int get_cell(int x, int y);
	void set_cell(int x, int y, int which_player);
};

