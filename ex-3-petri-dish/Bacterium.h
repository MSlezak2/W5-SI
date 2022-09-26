#pragma once
#include <string>
#include <vector>
#include <functional>

class Bacterium {
public:

	enum class bacteriaSpecies {
		Bacillus,
		Coccus,
		Spirillum
	};
	virtual ~Bacterium() = default;

	int getX() { return x; };
	int getY() { return y; };
	int getNearby() { return nearby; };
	bool isGoingToSurvive() { return goingToSurvive; };
	bacteriaSpecies getSpecies() { return species; };
	//char getSymbol() { return symbol; };
	virtual void determineIfIsGoingToSurvive(std::vector<Bacterium*> neighborhood ) = 0;
	//static void setIsGoingToSurvive(std::function<bool(std::vector<Bacterium*>)> newOne) { isGoingToSurvive = newOne; };
	virtual Bacterium* reproduce(int x, int y) = 0;

protected:
	Bacterium(int x, int y) : x{ x }, y{ y } {};
	int x, y, nearby; // coordinates and "nearby" parameter of the bacterium [divided by 0.1mm]
	//char symbol;
	bacteriaSpecies species; // for UI class to know how to represent it in the console TODO: Is that right approach?
	//static std::function<bool(std::vector<Bacterium*>)> isGoingToSurvive; // TODO: Is that the right approach?
	bool goingToSurvive;
};

