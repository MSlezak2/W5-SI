#include "pch.h"
#include "../ex-2-recycling/Dustbin.h"

class DustbinTest : public ::testing::Test {
protected:
	Dustbin dustbin;
	Garbage garbage;
	PlasticGarbage plasticGarbage;
	PaperGarbage paperGarbage;
};

TEST_F(DustbinTest, ThrowGarbageToHouseWasteContent) {
	//TODO: Since I test few cases in this very similar way, should I extract following lines into a method in fixture class?
	int garbageContentSizeBefore = dustbin.getHouseWasteContentSize();
	dustbin.throwOutGarbage(garbage);
	int garbageContentSizeAfter = dustbin.getHouseWasteContentSize();

	EXPECT_EQ(garbageContentSizeAfter - garbageContentSizeBefore, 1);
}

TEST_F(DustbinTest, ThrowNotSqueezedPaperGarbageToPaperContent) {
	int garbageContentSizeBefore = dustbin.getPaperContentSize();
	try {
		dustbin.throwOutPaperGarbage(paperGarbage);
	} catch (const std::exception&) {
	}
	int garbageContentSizeAfter = dustbin.getPaperContentSize();

	EXPECT_EQ(garbageContentSizeAfter - garbageContentSizeBefore, 0);
}

TEST_F(DustbinTest, ThrowSqueezedPaperGarbageToPaperContent) {
	int garbageContentSizeBefore = dustbin.getPaperContentSize();
	paperGarbage.squeeze();
	try {
		dustbin.throwOutPaperGarbage(paperGarbage);
	} catch (const std::exception&) {
	}
	int garbageContentSizeAfter = dustbin.getPaperContentSize();

	EXPECT_EQ(garbageContentSizeAfter - garbageContentSizeBefore, 1);
}

TEST_F(DustbinTest, ThrowDirtyPlasticGarbageToPlasticContent) {
	int garbageContentSizeBefore = dustbin.getPlasticContentSize();
	try {
		dustbin.throwOutPlasticGarbage(plasticGarbage);
	} catch (const std::exception&) {
	}
	int garbageContentSizeAfter = dustbin.getPlasticContentSize();

	EXPECT_EQ(garbageContentSizeAfter - garbageContentSizeBefore, 0);
}

TEST_F(DustbinTest, ThrowCleanPlasticGarbageToPlasticContent) {
	int garbageContentSizeBefore = dustbin.getPlasticContentSize();
	plasticGarbage.clean();
	try {
		dustbin.throwOutPlasticGarbage(plasticGarbage);
	} catch (const std::exception&) {
	}
	int garbageContentSizeAfter = dustbin.getPlasticContentSize();

	EXPECT_EQ(garbageContentSizeAfter - garbageContentSizeBefore, 1);
}