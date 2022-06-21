#include "Game.h"

Game::Game(int board_size_x, int board_size_y)
{
	board = Board(board_size_x, board_size_y);
	ui = UI();
}

void Game::mark(int x, int y, int which_player)
{
	if (board.get_cell(x, y) == 0) // is that spot empty?
	{
		board.set_cell(x, y, which_player);
	}
}

Board Game::get_board()
{
	return board;
}

//void Game::set_board(Board board)
//{
//	this->board = board;
//}

UI Game::get_ui()
{
	return ui;
}
