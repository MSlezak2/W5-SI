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
	bacteriaSpecies getSpecies() { return species; };
	bool isGoingToSurvive() { return goingToSurvive; };
	virtual void determineIfIsGoingToSurvive(std::vector<Bacterium*> neighborhood ) = 0;
	virtual Bacterium* reproduce(int x, int y) = 0;
	//char getSymbol() { return symbol; };
	//static void setIsGoingToSurvive(std::function<bool(std::vector<Bacterium*>)> newOne) { isGoingToSurvive = newOne; };

protected:
	Bacterium(int x, int y) : x{ x }, y{ y } {};
	int x, y, nearby; // coordinates and "nearby" parameter of the bacterium [divided by 0.1mm]
	bacteriaSpecies species; // for UI class to know how to represent it in the console (among the other) TODO: Is that right approach?
	bool goingToSurvive;
	//char symbol;
	//static std::function<bool(std::vector<Bacterium*>)> isGoingToSurvive; // TODO: Is that the right approach?
};

