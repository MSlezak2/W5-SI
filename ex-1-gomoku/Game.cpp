#include "Game.h"

Game::Game(int board_size_x, int board_size_y, int how_many)
{
	board = Board(board_size_x, board_size_y);
	ui = UI();
	how_many_marks = how_many;
	// TODO: throw an exception when how_many_marks is too large
}

void Game::mark(int x, int y, int which_player)
{
	if (board.get_cell(x, y) == 0) // is that spot empty?
	{
		board.set_cell(x, y, which_player);
	}
}

bool Game::has_won(int player)
{
	bool has_won = false;

	has_won = (check_rows(player) || check_columns(player) || check_diagonals(player));

	return has_won;
}

bool Game::check_rows(int player)
{
	bool has_won = false;

	int temp_marks_in_row = 1; // it starts with 1, because when the following loop detects consecutive marks, there are 2 of them already

	for (int i = 0; i < board.get_board_size_y() && !has_won; i++) // y loop
	{
		temp_marks_in_row = 1;
		for (int j = 1; j < board.get_board_size_x() && !has_won; j++) // x loop
		{
			if (board.get_cell(j, i) == board.get_cell(j - 1, i) && board.get_cell(j, i) == player)
			{
				temp_marks_in_row++;
			}
			else
			{
				temp_marks_in_row = 1;
			}
			if (temp_marks_in_row > 4)
			{
				has_won = true;
			}
		}
	}

	return has_won;
}

bool Game::check_columns(int player)
{
	bool has_won = false;

	int temp_marks_in_row = 1; // it starts with 1, because when the following loop detects consecutive marks, there are 2 of them already

	for (int i = 0; i < board.get_board_size_y() && !has_won; i++) // y loop
	{
		temp_marks_in_row = 1;
		for (int j = 1; j < board.get_board_size_x() && !has_won; j++) // x loop
		{
			if (board.get_cell(i, j) == board.get_cell(i, j - 1) && board.get_cell(i, j) == player)
			{
				temp_marks_in_row++;
			}
			else
			{
				temp_marks_in_row = 1;
			}
			if (temp_marks_in_row > 4)
			{
				has_won = true;
			}
		}
	}

	return has_won;
}

bool Game::check_diagonals(int player)
{
	bool has_won = false;

	int temp_marks_in_row = 1;
	int temp_x, temp_y;
	// first direction ("downhill")

	for (int i = 0; i <= board.get_board_size_y() - how_many_marks; i++)
	{
		int temp_marks_in_row = 1;
		temp_x = 1;
		temp_y = i+1;
		while (temp_x < board.get_board_size_x() && temp_y < board.get_board_size_y())
		{
			if (board.get_cell(temp_x, temp_y) == board.get_cell(temp_x - 1, temp_y - 1) && board.get_cell(temp_x, temp_y) == player)
			{
				temp_marks_in_row++;
			}
			else
			{
				temp_marks_in_row = 1;
			}
			if (temp_marks_in_row > 4)
			{
				has_won = true;
			}
			temp_x++;
			temp_y++;
		}
	}


	return has_won;
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

int Game::get_how_many_marks()
{
	return how_many_marks;
}
