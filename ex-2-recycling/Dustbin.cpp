#include "Dustbin.h"
#include "DustbinContentError.h"

void Dustbin::throwOutGarbage(Garbage garbage) {
	houseWasteContent.push_back(garbage);
}

void Dustbin::throwOutPaperGarbage(PaperGarbage paperGarbage) {
	if (paperGarbage.getIsSqueezed()) {
		paperContent.push_back(paperGarbage);
	} else {
		throw DustbinContentError("Paper garbage should be squeezed before throwing out");
	}
}

void Dustbin::throwOutPlasticGarbage(PlasticGarbage plasticGarbage) {
	if (plasticGarbage.getIsClean()) {
		plasticContent.push_back(plasticGarbage);
	} else {
		throw DustbinContentError("Plastic garbage should be cleaned before throwing out");
	}
}

void Dustbin::emptyContents() {
	houseWasteContent.clear();
	paperContent.clear();
	plasticContent.clear();
}
