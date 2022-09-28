#pragma once
#include <string>
#include <vector>
#include "PaperGarbage.h"
#include "PlasticGarbage.h"

class Dustbin {
public:
	void throwOutGarbage(Garbage garbage);
	void throwOutPaperGarbage(PaperGarbage paperGarbage);
	void throwOutPlasticGarbage(PlasticGarbage plasticGarbage);
	void emptyContents();
	int getPaperContentSize() { return paperContent.size(); };
	int getPlasticContentSize() { return plasticContent.size(); };
	int getHouseWasteContentSize() { return houseWasteContent.size(); };

protected:
	std::string color;
	std::vector<PaperGarbage> paperContent;
	std::vector<PlasticGarbage> plasticContent;
	std::vector<Garbage> houseWasteContent;
};

