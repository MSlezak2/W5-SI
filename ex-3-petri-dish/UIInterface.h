#pragma once
#include "PetriDish.h"

class UIInterface {
public:
	virtual ~UIInterface() = default;

	virtual void printPetriDish(const PetriDish& petriDish, int stepNumber) = 0;
};

