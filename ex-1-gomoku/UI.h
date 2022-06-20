#pragma once
#include "Board.h"
#include <string>


class UI
{
private:
	bool is_of_incorrect_format(std::string user_input);
	void map_input_to_indexes(std::string user_input, int* first_index, int* second_index);
	void parse_input(std::string& user_input, std::string& first_part, std::string& second_part);
	int letters_to_int_index(std::string letters);
	bool is_out_of_range(Board board, int users_move_x, int users_move_y);
	bool is_already_taken(Board board, int users_move_x, int users_move_y);

public:
	void make_move(Board board); // TODO: Maybe I should create function in class Game that invokes that function? (that would prevent from passing argument game.get_board() in main)
	
};


