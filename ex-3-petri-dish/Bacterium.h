#pragma once
#include <string>

class Bacterium {
public:
	virtual ~Bacterium() = default;

	int getX() { return x; };
	int getY() { return y; };

protected:
	int x, y;
	float nearby;
};

