#pragma once
#include "Bacterium.h"

class Bacillus :
    public Bacterium {
public:
    Bacillus(int x, int y);

    // Inherited via Bacterium
    virtual void determineIfIsGoingToSurvive(std::vector<Bacterium*, std::allocator<Bacterium*>> neighborhood) override;
    virtual Bacterium* reproduce(int x, int y) override;
};

