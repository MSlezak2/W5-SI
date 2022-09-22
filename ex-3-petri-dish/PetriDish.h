#pragma once
#include <vector>
#include "Bacterium.h"

class PetriDish {
public:
	PetriDish(float xSize, float ySize, int noBacteria);
	
	void init();
	Bacterium* getBacteriumByCoordinates(float x, float y);

private:
	std::vector<Bacterium*> bacteria;
	const float xSizeMax{ 100 };
	const float ySizeMax{ 100 };
	int xSize, ySize; // size of the vessel [0.1mm] TODO: Should it be int instead of float?
	int noBacteria;
};

