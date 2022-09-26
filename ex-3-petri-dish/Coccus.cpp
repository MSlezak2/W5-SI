#include "Coccus.h"

Coccus::Coccus(int x, int y) : Bacterium(x, y) {
	nearby = 1;
	//symbol = 'C';
	species = bacteriaSpecies::Coccus;
}

void Coccus::determineIfIsGoingToSurvive(std::vector<Bacterium*> neighborhood) {
	int noOtherSpecies{ 0 };

	for (Bacterium* bacterium : neighborhood) {
		if (bacterium->getSpecies() != Bacterium::bacteriaSpecies::Coccus) {
			noOtherSpecies++;
		}
	}

	if (noOtherSpecies >= 2) {
		goingToSurvive = true;
	} else {
		goingToSurvive = false;
	}
}

Bacterium* Coccus::reproduce(int x, int y) {
	return new Coccus(x, y);
}
