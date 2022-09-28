#pragma once
#include "Garbage.h"

class PaperGarbage :
    public Garbage {
public:
    PaperGarbage();
    void squeeze();
    bool getIsSqueezed() { return isSqueezed; };

private:
    bool isSqueezed;
};

