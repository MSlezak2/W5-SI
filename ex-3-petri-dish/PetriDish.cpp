#include "PetriDish.h"
#include <stdexcept>
#include <time.h>

PetriDish::PetriDish(int xSize, int ySize, int noBacteria) {
	
	if (0 < xSize && xSize <= X_SIZE_MAX) {
		this->xSize = xSize;
	} else {
		throw std::domain_error("size (x) of the Petri Dish is too large (max: )" + std::to_string(X_SIZE_MAX));
	}
	
	if (0 < ySize && ySize <= Y_SIZE_MAX) {
		this->ySize = ySize;
	} else {
		throw std::domain_error("size (y) of the Petri Dish is too large (max: )" + std::to_string(Y_SIZE_MAX));
	}

	if (0 < noBacteria && noBacteria <= xSize*ySize) {
		this->noBacteria = noBacteria;
	} else {
		throw std::domain_error("incorrect number of bacteria");
	}

	//Coccus::setIsGoingToSurvive([](std::vector<Bacterium*> bacteria) { return true; });
}

PetriDish::~PetriDish() {
	for (Bacterium* bacterium : bacteria) {
		delete bacterium;
	}
}

void PetriDish::init() {
	std::srand(time(0));
	int x, y, type;
	Bacterium* newBacterium;

	for (int i = 0; i < noBacteria; i++) {
		// determine coordinates of the bacterium
		do {
			x = rand() % xSize;
			y = rand() % ySize;
		} while ( getBacteriumByCoordinates(x,y) != nullptr );

		// determine the type of the bacterium
		type = rand() % NO_TYPES;
		switch (type) {
		case 0:
			newBacterium = new Bacillus(x, y);
			break;
		case 1:
			newBacterium = new Coccus(x, y);
			break;
		case 2:
			newBacterium = new Spirillum(x, y);
			break;
		}
		bacteria.push_back(newBacterium);
	}
}

void PetriDish::step() {
	
}

Bacterium* PetriDish::getBacteriumByCoordinates(int x, int y) {
	//Returns nullptr if no bacterium was found at the given place

	Bacterium* bacterium = nullptr;

	for (Bacterium* currentBacterium : bacteria) {
		if ((*currentBacterium).getX() == x && (*currentBacterium).getY() == y) {
			bacterium = currentBacterium; //TODO: Should I stop looking at this point?
		}
	}

	return bacterium;
}

bool PetriDish::isNearby(Bacterium* theBacterium, Bacterium* theOtherOne) {
	bool isNearby{ false };

	if (distanceBetweenPoints(theBacterium->getX(), theBacterium->getY(),
		theOtherOne->getX(), theOtherOne->getY()) <= theBacterium-> getNearby()) {
		isNearby = true;
	}

	return isNearby;
}

double PetriDish::distanceBetweenPoints(int xA, int yA, int xB, int yB) {
	return sqrt( (xB-xA)*(xB - xA) + (yB - yA)*(yB - yA) );
}
