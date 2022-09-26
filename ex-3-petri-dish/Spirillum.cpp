#include "Spirillum.h"

Spirillum::Spirillum(int x, int y) : Bacterium(x, y) {
	nearby = 2;
	/*symbol = 'S';*/
	species = bacteriaSpecies::Spirillum;
}

void Spirillum::determineIfIsGoingToSurvive(std::vector<Bacterium*> neighborhood) {
	bool isThereBacillus{ false };

	for (Bacterium* bacterium : neighborhood) {
		if (bacterium->getSpecies() == Bacterium::bacteriaSpecies::Bacillus) {
			isThereBacillus = true;
		}
	}

	if (!isThereBacillus) {
		goingToSurvive = true;
	} else {
		goingToSurvive = false;
	}
}

Bacterium* Spirillum::reproduce(int x, int y) {
	return new Spirillum(x, y);
}
