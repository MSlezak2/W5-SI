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
	bool isAnythingStillGoingOn();
	int getXSize() const { return xSize; };
	int getYSize() const { return ySize; };
	int getNOBacteriaTotal() const { return noBacteriaTotal; };
	int getNOBacillus() const { return noBacillus; };
	int getNOCoccus() const { return noCoccus; };
	int getNOSpirillum() const { return noSpirillum; };
	int getNODeceasedLately() const { return noDeceasedLately; };
	int getNOSpawnedLately() const { return noSpawnedLately; };

private:
	std::vector<Bacterium*> bacteria; // TODO: Should I store bacteria in a vector instead 
									  // (of storing only pointers to heap locations?)
	const int X_SIZE_MAX{ 1000 }; // maximum size of the vessel [divided by 0.1mm]
	const int Y_SIZE_MAX{ 1000 };
	const int NO_TYPES{ 3 }; // number of different species 
	int xSize, ySize; // size of the vessel [divided by 0.1mm] TODO: Should it be int instead of float?
	int noBacteriaTotal, noBacillus, noCoccus, noSpirillum, noDeceasedLately, noSpawnedLately;
	// TODO: I should probably extract above variables into class called SimDetails or something...

	void replicateSurvivors();
	void removeDeceased();
	void determineSurvivors();
	Bacterium* getBacteriumByCoordinates(int x, int y);
	bool isNearby(Bacterium* theBacterium, Bacterium* theOtherOne);
	bool isNearby(Bacterium* theBacterium, int x, int y);
	double distanceBetweenPoints(int xA, int yA, int xB, int yB);
	// TODO: Should I move 3 of the above methods to separate a class Spot or something? Along with Bacterium's
	// x and y attributes...
	bool isPlaceOccupied(int x, int y);
	void decreaseNOBacteria(Bacterium* deceasedBacterium);
	void increaseNOBacteria(Bacterium* newOne);
	
};

