#include "PetriDish.h"
#include <iostream>
#include "SimpleConsoleUI.h"

int main() {
	PetriDish petriDish(10,10,5);
	petriDish.init();

	UIInterface* ui = new SimpleConsoleUI();
	ui->printPetriDish(petriDish);

	delete ui;
	return 0;
}