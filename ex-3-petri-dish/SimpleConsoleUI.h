#pragma once
#include "UIInterface.h"
class SimpleConsoleUI :
    public UIInterface {
public:
   
    // Inherited via UIInterface
    virtual void printPetriDish(const PetriDish& petriDish) override;

};

