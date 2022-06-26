#include "UI.h"
#include "Board.h"

#include <iostream>
#include <regex>
#include <string>

int* UI::make_move(Board board)
{
	static int users_move[2]; // 0-th element -> x, 1st element -> y
	/*int users_move_x = -1;
	int users_move_y = -1;*/
	
	// read user's input 
	std::string user_input;
	std::cout << "Enter coordinates:\t";
	std::cin >> user_input;
	std::cin.clear(); // flush the input buffer

	if (user_input.compare("quit") == 0)
	{
		users_move[0] = -1;
	}
	else
	{
		// validate and map to the indexes
		map_and_validate(user_input, users_move, board);
	}
	std::cout << std::endl;

	return users_move;
	// TODO: Test the already taken scenario
}

void UI::print_board(Board board)
{

	std::cout << "";
	for (int i = 0; i < board.get_board_size_x(); i++)
	{
		std::cout << " " << i + 1;
	}
	std::cout << std::endl;
	for (int i = 0; i < board.get_board_size_y(); i++) // y loop
	{
		// display a letter
		std::cout << decimal_to_quasi_hexavigesimal(i);
		for (int j = 0; j < board.get_board_size_x(); j++) // x loop
		{
			std::cout << " ";
			switch (board.get_cell(j, i)) 
			{
			case 0: // empty
				std::cout << ".";
				break;
			case 1: // player 1
				std::cout << "X";
				break;
			case 2: // player 2
				std::cout << "O";
				break;
			}
		}
		std::cout << std::endl;
	}

}

/// <param name="which_player_won"> - 0 if there's a tie</param>
void UI::print_result(int which_player_won)
{
	if (which_player_won != 0)
	{
		switch (which_player_won)
		{
		case 1:
			std::cout << "X won!" << std::endl;
			break;
		case 2:
			std::cout << "O won!" << std::endl;
			break;
		}
	}
	else
	{
		std::cout << "It's a tie!" << std::endl;
	}
}

int UI::get_int()
{
	int number = -1;
	std::string users_input;

	while (number == -1)
	{
		//std::cout << "Please enter the number:" << std::endl;
		std::cin >> users_input;

		try
		{
			number = std::stoi(users_input);
		}
		catch (const std::exception&)
		{
			std::cout << "Something went wrong. Try again..." << std::endl;
		}
	}


	return number;
}

std::string UI::decimal_to_quasi_hexavigesimal(int decimal_number)
{
	// TODO: Find more professional (clean) way to do it...
	if (decimal_number > 25)
	{
		decimal_number = decimal_number;
	}
	int quotient = decimal_number;
	int reminder;
	std::string hexavigesimal_number;

	int iter_number = 0;
	if (decimal_number >= 26)
	{
		while (quotient > 0)
		{
			if (quotient / 26 == 0)
			{
				reminder = quotient % 27;
				quotient = quotient / 27;
				hexavigesimal_number.insert(0, 1, (char)reminder + 64);
			}
			else
			{
				reminder = quotient % 26;
				quotient = quotient / 26;
				hexavigesimal_number.insert(0, 1, (char)reminder + 65);
			}
			iter_number++;
		}
	}
	else if (decimal_number > 0 && decimal_number <= 25)
	{
		hexavigesimal_number.insert(0, 1, (char)decimal_number + 65);
	}
	else
	{
		hexavigesimal_number = "A";
	}

	return hexavigesimal_number;
}

void UI::map_and_validate(std::string& user_input, int users_move[], const Board& board)
{
	bool is_valid = false;

	while (!is_valid)
	{
		// validate based on formatting
		is_valid = true;
		if (!is_of_incorrect_format(user_input))
		{
			// map input from letters-digits format into couple of int indexes
			map_input_to_indexes(user_input, users_move);
		}
		else
		{
			is_valid = false;
			std::cout << "Incorrect format, please try again..." << std::endl;
			std::cin >> user_input;
			std::cin.clear(); // flush the input buffer
		}
		// validate based on range
		if (is_valid && is_out_of_range(board, users_move))
		{
			is_valid = false;
			std::cout << "Those coordinates are out of range, please try again..." << std::endl;
			std::cin >> user_input;
			std::cin.clear(); // flush the input buffer
		}
		// validate based on is it already taken
		if (is_valid && is_already_taken(board, users_move))
		{
			is_valid = false;
			std::cout << "That place is already taken, please try again..." << std::endl;
			std::cin >> user_input;
			std::cin.clear(); // flush the input buffer
		}
	}
}

bool UI::is_of_incorrect_format(std::string user_input) 
{
	bool is_of_incorrect_format = true;

	std::regex correct_format("^[a-zA-Z]+[1-9][0-9]*$"); // pattern of the correct format (without ^ and $ it would also work... ;) )

	if (std::regex_match(user_input, correct_format)) {
		is_of_incorrect_format = false;
	}

	return is_of_incorrect_format;
}

void UI::map_input_to_indexes(std::string user_input, int users_move[])
{
	std::string first_part, second_part;

	// parse the input 
	parse_input(user_input, first_part, second_part);

	// map to int values
	users_move[0] = stoi(second_part) - 1;
	users_move[1] = letters_to_int_index(first_part);
}

void UI::parse_input(std::string& user_input, std::string& first_part, std::string& second_part)
{
	std::regex first_part_pattern("[a-zA-Z]+");
	std::regex second_part_pattern("[0-9]+");

	std::smatch match; // to hold actual value that has been parsed with pattern

	std::regex_search(user_input, match, first_part_pattern);
	first_part = match.str();
	std::regex_search(user_input, match, second_part_pattern);
	second_part = match.str();
}

int UI::letters_to_int_index(std::string letters)
{
	char temp_letter;
	int index = 0;

	// transform to uppercase (to obtain case insensivity)
	std::transform(letters .begin(), letters.end(), letters.begin(), ::toupper);

	// letter to int (for example: A (ASCII 65) -> 0, C -> 2 etc.)
	for (int i = 0; i < letters.size(); i++)
	{
		temp_letter = letters.at(i);
		if (i == letters.size() - 1) // last letter (A -> 0 * 26^0, B -> 1 * 26^0)
		{
			index += (temp_letter - 65) * (int)std::pow((float)('Z' - 'A' + 1), (float)letters.size() - i - 1); // system of 26 digits
		}
		else // not last letters (A -> 1 * 26^(size - i), A -> 2 * 26^(size - i) )
		{
			index += (temp_letter - 65 + 1) * (int)std::pow((float)('Z' - 'A' + 1), (float)letters.size() - i - 1); // system of 26 digits
		}
		
	}

	return index;
}

bool UI::is_out_of_range(Board board, int users_move[])
{
	bool is_out_of_range = false;

	if (users_move[0] >= board.get_board_size_x())
	{
		is_out_of_range = true;
	}
	else if (users_move[1] >= board.get_board_size_y())
	{
		is_out_of_range = true;
	}

	return is_out_of_range;
}

bool UI::is_already_taken(Board board, int users_move[])
{
	bool is_already_taken = false;

	if (board.get_cell(users_move[0], users_move[1]) != 0)
	{
		is_already_taken = true;
	}

	return is_already_taken;
}
