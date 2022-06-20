#include "Board.h"
#include <iostream>

Board::Board(int board_size_x, int board_size_y) 
{
	this->board_size_x = board_size_x;
	this->board_size_y = board_size_y;

	// alocate? the matrix of cells
	cells = new int* [board_size_y];
	for (int i = 0; i < board_size_y; i++) 
	{
		cells[i] = new int[board_size_x];
	}

	clear_the_board();
}

void Board::clear_the_board() 
{
	for (int i = 0; i < board_size_y; i++) 
	{
		for (int j = 0; j < board_size_x; j++)
		{
			cells[i][j] = 0;
		}
	}
}

void Board::display_the_board()
{
	for (int i = 0; i < board_size_y; i++)
	{
		for (int j = 0; j < board_size_x; j++)
		{
			std::cout << cells[i][j];
		}
		std::cout << std::endl;
	}
}

int Board::get_board_size_x()
{
	return board_size_x;
}

int Board::get_board_size_y()
{
	return board_size_y;
}

int Board::get_cell(int x, int y)
{
	return cells[y][x];
}
