#pragma once
#include "UIInterface.h"
class SimpleConsoleUI :
    public UIInterface {
public:
   
    // Inherited via UIInterface
    virtual void printPetriDish(const PetriDish& petriDish, int stepNumber) override;

    void printBoard(const PetriDish& petriDish);

    void prepareModel(const PetriDish& petriDish);

private:
    std::vector<std::vector<char>> dishModel;

    void printDetails(const PetriDish& petriDish, int stepNumber);
};

