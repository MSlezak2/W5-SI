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
	

	do {
		stepNumber++;
		petriDish.step();
		ui->printPetriDish(petriDish, stepNumber);
	} while (petriDish.getNOBacteriaTotal() > 0 && petriDish.isAnythingStillGoingOn());
		
	delete ui;

	return 0;
}