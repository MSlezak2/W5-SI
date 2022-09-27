#include "SimpleConsoleUI.h"
#include <iostream>

void SimpleConsoleUI::printPetriDish(const PetriDish& petriDish, int stepNumber) {

	printDetails(petriDish, stepNumber);
	
	prepareModel(petriDish);
	printBoard(petriDish);
}

void SimpleConsoleUI::printBoard(const PetriDish& petriDish) {

	for (int y = 0; y < dishModel.size(); y++) {
		for (int x = 0; x < dishModel[0].size(); x++) {
			std::cout << dishModel[y][x];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
}

void SimpleConsoleUI::prepareModel(const PetriDish& petriDish) {
	char symbol{ '?' };
	// TODO: Does the fact that I had dishModel changed to an attribute (instead of local var) make my it more clean code like?
	dishModel = std::vector<std::vector<char>>(petriDish.getYSize(), std::vector<char>(petriDish.getXSize(), '*'));

	for (Bacterium* bacterium : petriDish.getBacteria()) {
		Bacterium::bacteriaSpecies species = bacterium->getSpecies();
		switch (species) {
		case Bacterium::bacteriaSpecies::Bacillus:
			symbol = 'B';
			break;
		case Bacterium::bacteriaSpecies::Coccus:
			symbol = 'C';
			break;
		case Bacterium::bacteriaSpecies::Spirillum:
			symbol = 'S';
			break;
		}
		dishModel[bacterium->getY()][bacterium->getX()] = symbol;
	}
}

void SimpleConsoleUI::printDetails(const PetriDish& petriDish, int stepNumber) {
	std::cout << "Step number: " << stepNumber <<std::endl;
	std::cout << "Total number of bacteria: " << petriDish.getNOBacteriaTotal() << std::endl;
	std::cout << "Number of Bacilius species: " << petriDish.getNOBacillus() << std::endl;
	std::cout << "Number of Coccus species: " << petriDish.getNOCoccus() << std::endl;
	std::cout << "Number of Spirillum species: " << petriDish.getNOSpirillum() << std::endl;
	std::cout << "Number of lately deceased: " << petriDish.getNODeceasedLately() << std::endl;
	std::cout << "Number of lately spawned: " << petriDish.getNOSpawnedLately() << std::endl;
	std::cout << std::endl;
}
