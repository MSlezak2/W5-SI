#pragma once
#include "Bacterium.h"

class Coccus :
    public Bacterium {
public:
    Coccus(int x, int y);


    // Inherited via Bacterium
    virtual void determineIfIsGoingToSurvive(std::vector<Bacterium*> neighborhood) override;
    virtual Bacterium* reproduce(int x, int y) override;

};

