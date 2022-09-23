#include "SimpleConsoleUI.h"
#include <iostream>

void SimpleConsoleUI::printPetriDish(const PetriDish& petriDish) {

	char symbol{ 'X' };
	std::vector<std::vector<char>> dishModel(petriDish.getYSize(), std::vector<char>(petriDish.getXSize(), 'O'));

	for (Bacterium* bacterium : petriDish.getBacteria()) {
		dishModel[bacterium->getY()][bacterium->getX()] = bacterium->getSymbol();
	}

	for (int y = 0; y < dishModel.size(); y++) {
		for (int x = 0; x < dishModel[0].size(); x++) {
			std::cout << dishModel[y][x];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
