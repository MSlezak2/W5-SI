#include "PetriDish.h"
#include <stdexcept>
#include <time.h>

PetriDish::PetriDish(float xSize, float ySize, int noBacteria) {
	
	if (xSize < 0 || xSize > xSizeMax) {
		this->xSize = xSize;
	} else {
		throw std::domain_error("size (x) of the Petri Dish is too large (max: )" + std::to_string(xSizeMax));
	}
	
	if (ySize < 0 || ySize > ySizeMax) {
		this->ySize = ySize;
	} else {
		throw std::domain_error("size (y) of the Petri Dish is too large (max: )" + std::to_string(ySizeMax));
	}

	if (noBacteria < 0 || noBacteria > xSize*10*ySize*10 ) {
		this->noBacteria = noBacteria;
	} else {
		throw std::domain_error("incorrect number of bacteria");
	}
}

void PetriDish::init() {
	std::srand(time(0));
	float x, y;

	for (int i = 0; i < noBacteria; i++) {
		do {
			x = (rand() % (xSize*10)) / 10;
			y = rand();
		} while ( getBacteriumByCoordinates(x,y) != nullptr );
	}

}

Bacterium* PetriDish::getBacteriumByCoordinates(float x, float y) {
	//Returns nullptr if no bacterium was found at the given place

	Bacterium* bacterium = nullptr;

	for (Bacterium* currentBacterium : bacteria) {
		if ((*currentBacterium).getX() == x && (*currentBacterium).getY() == y) {
			bacterium = bacterium;
		}
	}

	return bacterium;
}
