#pragma once
#include "Bacterium.h"
class Spirillum :
    public Bacterium {
public:
    Spirillum(int x, int y);

    // Inherited via Bacterium
    virtual void determineIfIsGoingToSurvive(std::vector<Bacterium*> neighborhood) override;
    virtual Bacterium* reproduce(int x, int y) override;
};

