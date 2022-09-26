#pragma once
#include "UIInterface.h"
class SimpleConsoleUI :
    public UIInterface {
public:
   
    // Inherited via UIInterface
    virtual void printPetriDish(const PetriDish& petriDish, int stepNumber) override;

private:
    void printDetails(const PetriDish& petriDish, int stepNumber);
};

