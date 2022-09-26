#include "PetriDish.h"
#include <stdexcept>
#include <time.h>

PetriDish::PetriDish(int xSize, int ySize, int noBacteriaTotal) {
	
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

	if (0 < noBacteriaTotal && noBacteriaTotal <= xSize*ySize) {
		this->noBacteriaTotal = noBacteriaTotal;
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

	for (int i = 0; i < noBacteriaTotal; i++) {
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
			noBacillus++;
			break;
		case 1:
			newBacterium = new Coccus(x, y);
			noCoccus++;
			break;
		case 2:
			newBacterium = new Spirillum(x, y);
			noSpirillum++;
			break;
		}
		bacteria.push_back(newBacterium);
	}
}

void PetriDish::step() {
	noDeceasedLately = 0;
	noSpawnedLately = 0;

	// determine if they are gonna survive (TODO: extract to the separate method)
	std::vector<Bacterium*> neighborhood; //TODO: If I passed whole "bacteria" vector instead, I wouldn't have to create new vector every time (worse performance?)

	for (Bacterium* bacterium : bacteria) {
		for (Bacterium* otherBacterium : bacteria) {
			if (isNearby(bacterium, otherBacterium)) {
				neighborhood.push_back(otherBacterium);
			}
		}
		bacterium->determineIfIsGoingToSurvive(neighborhood);
		neighborhood.clear();
	}

	// remove those that are not going to survive (remove from vector and delete those objects)
	// TODO: Should I use second vector for the future generation? Appending new elements is probably faster than removing
	// them one by one 
	for (int i = 0; i < bacteria.size(); i++) {
		if (!bacteria[i]->isGoingToSurvive()) {
			decreaseNOBacteria(bacteria[i]);
			delete bacteria[i];
			bacteria.erase(bacteria.begin() + i);
			i--;
		}
	}

	// replicate survivors
	int x, y;
	Bacterium* newOne;
	for (Bacterium* bacterium : bacteria) {
		do {
			x = bacterium->getX() + (rand() % (2 * bacterium->getNearby() + 1) - bacterium->getNearby());
			y = bacterium->getY() + (rand() % (2 * bacterium->getNearby() + 1) - bacterium->getNearby());
			} while (x < 0 || y < 0 || x >= xSize || y >= ySize || isPlaceOccupied(x, y) || !isNearby(bacterium, x, y));
		newOne = bacterium->reproduce(x,y);
		bacteria.push_back(newOne);
		increaseNOBacteria(newOne);
	}
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

	double distance = distanceBetweenPoints(theBacterium->getX(), theBacterium->getY(),
		theOtherOne->getX(), theOtherOne->getY());
	if (distance <= theBacterium->getNearby() && distance != 0) {
		isNearby = true;
	}

	return isNearby;
}

bool PetriDish::isNearby(Bacterium* theBacterium, int x, int y) {
	bool isNearby{ false };

	double distance = distanceBetweenPoints(theBacterium->getX(), theBacterium->getY(),
		x, y);
	if (distance <= theBacterium->getNearby() && distance != 0) {
		isNearby = true;
	}

	return isNearby;
}

double PetriDish::distanceBetweenPoints(int xA, int yA, int xB, int yB) {
	return sqrt( (xB-xA)*(xB - xA) + (yB - yA)*(yB - yA) );
}

bool PetriDish::isPlaceOccupied(int x, int y) {
	bool isPlaceOccupied{ false };

	for (Bacterium* bacterium : bacteria) {
		if (bacterium->getX() == x && bacterium->getY() == y) {
			isPlaceOccupied = true;
		}
	}

	return isPlaceOccupied;
}

void PetriDish::decreaseNOBacteria(Bacterium* deceasedBacterium) {
	noBacteriaTotal--;
	noDeceasedLately++;
	switch (deceasedBacterium->getSpecies()) {
	case Bacterium::bacteriaSpecies::Bacillus:
		noBacillus--;
		break;
	case Bacterium::bacteriaSpecies::Coccus:
		noCoccus--;
		break;
	case Bacterium::bacteriaSpecies::Spirillum:
		noSpirillum--;
		break;
	}
}

void PetriDish::increaseNOBacteria(Bacterium* newOne) {
	noSpawnedLately++;
	noBacteriaTotal++;
	switch (newOne->getSpecies()) {
	case Bacterium::bacteriaSpecies::Bacillus:
		noBacillus++;
		break;
	case Bacterium::bacteriaSpecies::Coccus:
		noCoccus++;
		break;
	case Bacterium::bacteriaSpecies::Spirillum:
		noSpirillum++;
		break;
	}
}
