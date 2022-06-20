#include "Game.h"

Game::Game(int board_size_x, int board_size_y)
{
	board = Board(board_size_x, board_size_y);
	ui = UI();
}

Board Game::get_board()
{
	return board;
}

void Game::set_board(Board board)
{
	this->board = board;
}

UI Game::get_ui()
{
	return ui;
}
