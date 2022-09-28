#pragma once
#include "Garbage.h"

class PlasticGarbage :
    public Garbage {
public:
    PlasticGarbage();
    void clean();
    bool getIsClean() { return isClean; };

private:
    bool isClean;
};

