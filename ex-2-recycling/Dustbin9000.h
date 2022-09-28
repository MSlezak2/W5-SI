#pragma once
#include "Dustbin.h"
#include "MetalGarbage.h"
#include "BottleCap.h"

class Dustbin9000 :
    public Dustbin {
public:
    void throwOutMetalGarbage(MetalGarbage metalGarbage);
    void throwOutBottleCap(BottleCap bottleCap);
    int getMetalContentSize() { return metalContent.size(); };
    int getBottleCapContentSize() { return bottleCapContent.size(); };

private:
    std::vector<MetalGarbage> metalContent;
    std::vector<BottleCap> bottleCapContent;
};

