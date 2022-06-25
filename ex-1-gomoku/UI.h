#pragma once
#include "Board.h"
#include <string>


class UI
{
public:
	int* make_move(Board board); // TODO: Maybe I should create function in class Game that invokes that function? (that would prevent from passing argument game.get_board() in main)
	//void print_board(Board board);


private:
	//std::string decimal_to_hexavigesimal(int decimal_number);
	void map_and_validate(std::string& user_input, int users_move[], const Board& board);
	bool is_of_incorrect_format(std::string user_input);
	void map_input_to_indexes(std::string user_input, int users_move[]);
	void parse_input(std::string& user_input, std::string& first_part, std::string& second_part);
	int letters_to_int_index(std::string letters);
	bool is_out_of_range(Board board, int users_move[]);
	bool is_already_taken(Board board, int users_move[]);
};


