#include "Game.h"
#include "iostream"

Game::Game()
{
	ui = UI();
	int board_size_x, board_size_y, how_many;

	system("cls");
	std::cout << "WIDTH OF THE BOARD:" << std::endl;
	board_size_x = ui.get_int();
	system("cls");
	std::cout << "HEIGHT OF THE BOARD:" << std::endl;
	board_size_y = ui.get_int();
	system("cls");
	std::cout << "HOW MANY MARKS IT TAKES TO WIN:" << std::endl;
	how_many = ui.get_int();
	while (how_many > board_size_x && how_many > board_size_y)
	{
		std::cout << "That number is too big... Take into account the size of the board you just provided" << std::endl;
		how_many = ui.get_int();
	}


	board = Board(board_size_x, board_size_y);
	board.clear_the_board();
	how_many_marks = how_many;
}

Game::Game(int board_size_x, int board_size_y, int how_many)
{
	board = Board(board_size_x, board_size_y);
	ui = UI();
	how_many_marks = how_many;
	// TODO: throw an exception when how_many_marks is too large
}

void Game::start()
{
	bool is_on = true;
	int* users_move_p;
	int x, y;
	int current_player = 1;

	while (is_on)
	{
		system("cls");
		ui.print_board(board);

		std::cout << "Player " << current_player << ":" << std::endl;
		users_move_p = ui.make_move(board);

		x = *users_move_p;
		if (x == -1)
		{
			is_on = false;
		}
		else
		{
			users_move_p++;
			y = *users_move_p;
			mark(x, y, current_player);

			system("cls");
			ui.print_board(board);
			if (board.is_full())
			{
				ui.print_result(0);
				is_on = false;
			}
			else if (has_won(current_player))
			{
				ui.print_result(current_player);
				is_on = false;
			}
			current_player = current_player % 2 + 1; // switch to the next player
		}
	}
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

	has_won = (check_rows(player) || check_columns(player) || check_diagonals_downhill(player) || check_diagonals_uphill(player));
	// TODO: do a class out of it (according to what has been said during the cc workshop)

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
			if (temp_marks_in_row > how_many_marks - 1)
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

	for (int i = 0; i < board.get_board_size_x() && !has_won; i++) // x loop
	{
		temp_marks_in_row = 1;
		for (int j = 1; j < board.get_board_size_y() && !has_won; j++) // y loop
		{
			if (board.get_cell(i, j) == board.get_cell(i, j - 1) && board.get_cell(i, j) == player)
			{
				temp_marks_in_row++;
			}
			else
			{
				temp_marks_in_row = 1;
			}
			if (temp_marks_in_row > how_many_marks - 1)
			{
				has_won = true;
			}
		}
	}

	return has_won;
}

bool Game::check_diagonals_downhill(int player)
{
	bool has_won = false;

	int temp_marks_in_row = 1;
	int temp_x, temp_y;
	for (int i = 0; i <= board.get_board_size_y() - how_many_marks; i++)
	{
		// main diagonal and below it
		temp_marks_in_row = 1;
		temp_x = 1;
		temp_y = i + 1;
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
			if (temp_marks_in_row > how_many_marks - 1)
			{
				has_won = true;
			}
			temp_x++;
			temp_y++;
		}
	}
	for (int i = 0; i <= board.get_board_size_x() - how_many_marks; i++)
	{
		// above main diagonal
		temp_marks_in_row = 1;
		temp_x = i + 1;
		temp_y = 1;
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
			if (temp_marks_in_row > how_many_marks - 1)
			{
				has_won = true;
			}
			temp_x++;
			temp_y++;
		}
	}

	return has_won;
}

bool Game::check_diagonals_uphill(int player)
{
	bool has_won = false;

	int temp_marks_in_row = 1;
	int temp_x, temp_y;
	for (int i = 0; i <= board.get_board_size_y() - how_many_marks; i++)
	{
		// main diagonal and above it
		temp_marks_in_row = 1;
		temp_x = 1;
		temp_y = board.get_board_size_y() - 2 - i;
		while (temp_x < board.get_board_size_x() && temp_y >= 0)
		{
			if (board.get_cell(temp_x, temp_y) == board.get_cell(temp_x - 1, temp_y + 1) && board.get_cell(temp_x, temp_y) == player)
			{
				temp_marks_in_row++;
			}
			else
			{
				temp_marks_in_row = 1;
			}
			if (temp_marks_in_row > how_many_marks - 1)
			{
				has_won = true;
			}
			temp_x++;
			temp_y--;
		}
	}
	for (int i = 0; i <= board.get_board_size_x() - how_many_marks; i++)
	{
		// below main diagonal
		temp_marks_in_row = 1;
		temp_x = i + 1;
		temp_y = board.get_board_size_y() - 2;
		while (temp_x < board.get_board_size_x() && temp_y >= 0)
		{
			if (board.get_cell(temp_x, temp_y) == board.get_cell(temp_x - 1, temp_y + 1) && board.get_cell(temp_x, temp_y) == player)
			{
				temp_marks_in_row++;
			}
			else
			{
				temp_marks_in_row = 1;
			}
			if (temp_marks_in_row > how_many_marks - 1)
			{
				has_won = true;
			}
			temp_x++;
			temp_y--;
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
