#include "pch.h"
#include <Dustbin9000.h>

/*TODO:Test following cases:
Dustbin9000:
wrzucam plastik
wrzucam zwykly
wrzucam metal
wrzucam korek rozowy
wrzucam korek zielony
wrzucam plastik do korkow
wrzucam metal do korkow
wrzucam korek do plastikow
*/


class Dustbin9000Test : public ::testing::Test {
protected:
	Dustbin9000Test() { 
		pinkBottleCap = BottleCap(BottleCap::colors::PINK);
		whiteBottleCap = BottleCap(BottleCap::colors::WHITE);
	};
	Dustbin9000 dustbin9000;
	Garbage garbage;
	PlasticGarbage plasticGarbage;
	PaperGarbage paperGarbage;
	MetalGarbage metalGarbage;
	BottleCap pinkBottleCap;
	BottleCap whiteBottleCap;
};

TEST_F(Dustbin9000Test, ThrowNotSqueezedPaperGarbageToPaperContent) {
	int garbageContentSizeBefore = dustbin9000.getPaperContentSize();
	try {
		dustbin9000.throwOutPaperGarbage(paperGarbage);
	} catch (const std::exception&) {
	}
	int garbageContentSizeAfter = dustbin9000.getPaperContentSize();

	EXPECT_EQ(garbageContentSizeAfter - garbageContentSizeBefore, 0);
}

TEST_F(Dustbin9000Test, ThrowSqueezedPaperGarbageToPaperContent) {
	int garbageContentSizeBefore = dustbin9000.getPaperContentSize();
	paperGarbage.squeeze();
	try {
		dustbin9000.throwOutPaperGarbage(paperGarbage);
	} catch (const std::exception&) {
	}
	int garbageContentSizeAfter = dustbin9000.getPaperContentSize();

	EXPECT_EQ(garbageContentSizeAfter - garbageContentSizeBefore, 1);
}

TEST_F(Dustbin9000Test, ThrowMetalGarbageToMetalContent) {
	int garbageContentSizeBefore = dustbin9000.getMetalContentSize();
	try {
		dustbin9000.throwOutMetalGarbage(metalGarbage);
	} catch (const std::exception&) {
	}
	int garbageContentSizeAfter = dustbin9000.getMetalContentSize();

	EXPECT_EQ(garbageContentSizeAfter - garbageContentSizeBefore, 1);
}

TEST_F(Dustbin9000Test, ThrowPinkBottleCapToBottleCapContent) {
	int garbageContentSizeBefore = dustbin9000.getBottleCapContentSize();
	try {
		dustbin9000.throwOutBottleCap(pinkBottleCap);
	} catch (const std::exception&) {
	}
	int garbageContentSizeAfter = dustbin9000.getBottleCapContentSize();

	EXPECT_EQ(garbageContentSizeAfter - garbageContentSizeBefore, 1);
}

TEST_F(Dustbin9000Test, ThrowWhiteBottleCapToBottleCapContent) {
	int garbageContentSizeBefore = dustbin9000.getBottleCapContentSize();
	try {
		dustbin9000.throwOutBottleCap(whiteBottleCap);
	} catch (const std::exception&) {
	}
	int garbageContentSizeAfter = dustbin9000.getBottleCapContentSize();

	EXPECT_EQ(garbageContentSizeAfter - garbageContentSizeBefore, 0);
}