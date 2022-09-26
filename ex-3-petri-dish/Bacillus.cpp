#include "Bacillus.h"

Bacillus::Bacillus(int x, int y) : Bacterium(x, y) {
	nearby = 3;
	//symbol = 'B';
	species = bacteriaSpecies::Bacillus;
}

void Bacillus::determineIfIsGoingToSurvive(std::vector<Bacterium*, std::allocator<Bacterium*>> neighborhood) {
	int noCoccus{ 0 };

	for (Bacterium* bacterium : neighborhood) {
		if (bacterium->getSpecies() == Bacterium::bacteriaSpecies::Coccus) {
			noCoccus++;
		}
	}

	if (noCoccus > 0) {
		goingToSurvive = true;
	} else {
		goingToSurvive = false;
	}
}

Bacterium* Bacillus::reproduce(int x, int y) {
	return new Bacillus(x,y);
}
