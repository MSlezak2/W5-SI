#include "Game.h"

Game::Game(int board_size_x, int board_size_y)
{
	board = Board(board_size_x, board_size_y);
}

Board Game::get_board()
{
	return board;
}

void Game::set_board(Board board)
{
	this->board = board;
}
