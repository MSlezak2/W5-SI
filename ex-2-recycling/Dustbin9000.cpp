#include "Dustbin9000.h"
#include "BottleCapException.h"

void Dustbin9000::throwOutMetalGarbage(MetalGarbage metalGarbage) {
	metalContent.push_back(metalGarbage);
}

void Dustbin9000::throwOutBottleCap(BottleCap bottleCap) {
	if (bottleCap.getColor() == BottleCap::colors::PINK) {
		bottleCapContent.push_back(bottleCap);
	} else {
		throw BottleCapException("Dustbin accepts only pink ones");
	}
}
