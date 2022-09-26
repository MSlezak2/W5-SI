#include "PetriDish.h"
#include <iostream>
#include "SimpleConsoleUI.h"
#include <Windows.h>
#include <chrono>

int main() {
	PetriDish petriDish(8,8,10);
	UIInterface* ui = new SimpleConsoleUI();
	int stepNumber{ 0 };

	petriDish.init();
	ui->printPetriDish(petriDish, stepNumber);
	std::cout << std::endl << std::endl;

	while (petriDish.getNOBacteriaTotal() > 0) {
		stepNumber++;
		petriDish.step();
		ui->printPetriDish(petriDish, stepNumber);
		std::cout << std::endl << std::endl;
	}

	

	delete ui;
	//std::vector<int> temp;
	//for (int i = 0; i < 30; i++) {
	//	temp.push_back(0/*x0*/ + (rand() % (2 * 4/*nearby*/ + 1) - (4/*nearby*/)));
	//}

	return 0;
}