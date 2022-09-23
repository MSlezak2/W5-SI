#pragma once
#include <string>
#include <vector>
#include <functional>

class Bacterium {
public:
	virtual ~Bacterium() = default;

	int getX() { return x; };
	int getY() { return y; };
	int getNearby() { return nearby; };
	char getSymbol() { return symbol; };
	static void setIsGoingToSurvive(std::function<bool(std::vector<Bacterium*>)> newOne) { isGoingToSurvive = newOne; };

protected:
	Bacterium(int x, int y) : x{ x }, y{ y } {};
	int x, y, nearby; // coordinates and "nearby" parameter of the bacterium [divided by 0.1mm]
	char symbol; // for UI class to know how to represent it in the console TODO: Is that right approach?
	static std::function<bool(std::vector<Bacterium*>)> isGoingToSurvive; // TODO: Is that the right approach?
};

