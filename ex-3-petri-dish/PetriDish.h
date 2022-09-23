#pragma once
#include <vector>
#include "Bacterium.h"
#include "Bacillus.h"
#include "Coccus.h"
#include "Spirillum.h"

class PetriDish {
public:
	PetriDish(int xSize, int ySize, int noBacteria);
	~PetriDish();
	
	void init();
	void step();
	std::vector<Bacterium*> getBacteria() const { return bacteria; };
	int getXSize() const { return xSize; };
	int getYSize() const { return ySize; };

private:
	std::vector<Bacterium*> bacteria; // TODO: Should I store bacteria in a vector instead 
									  // (of storing only pointers to heap locations?)
	const int X_SIZE_MAX{ 1000 }; // maximum size of the vessel [divided by 0.1mm]
	const int Y_SIZE_MAX{ 1000 };
	const int NO_TYPES{ 3 }; // number of different species 
	int xSize, ySize; // size of the vessel [divided by 0.1mm] TODO: Should it be int instead of float?
	int noBacteria;
	
	Bacterium* getBacteriumByCoordinates(int x, int y);
	bool isNearby(Bacterium* theBacterium, Bacterium* theOtherOne);
	double distanceBetweenPoints(int xA, int yA, int xB, int yB);
};

