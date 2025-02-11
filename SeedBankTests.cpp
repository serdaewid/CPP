#include "gmock/gmock.h"
#include "MockSeedBank.hpp"
#include "Plant.hpp"
#include "MockPlant.hpp"

struct SeedBankTests : public ::testing::Test
{
	MockSeedBank mockSeedBank;
	//MockPlant mockPlant;
	std::shared_ptr<MockPlant> mockPlant = std::make_shared<MockPlant>();
	SeedBank seedBank;
};

TEST_F(SeedBankTests, AddSeedsTest)
{
	// Set up expectation for AddSeeds
	EXPECT_CALL(*mockPlant, GetSpecies())
		.Times(1)
		.WillOnce(::testing::Return(""));
	EXPECT_CALL(*mockPlant, GetSeeds())
		.Times(1)
		.WillOnce(::testing::Return(0));

	seedBank.AddSeeds(mockPlant);
}

//TEST_F(SeedBankTests, AddSeedsTest)
//{
//	//std::shared_ptr<Plant> plant = std::make_shared<Plant>("Plant", "Species");
//	// Set up expectation for AddSeeds
//	EXPECT_CALL(mockSeedBank, AddSeeds(mockPlant))
//		.Times(1)
//		.WillOnce(::testing::Return());
//
//	ASSERT_NO_THROW(mockSeedBank.AddSeeds(mockPlant));
//}

TEST_F(SeedBankTests, AddSeedsSpeciesTest)
{
	// Set up expectation for AddSeeds
	EXPECT_CALL(mockSeedBank, AddSeeds("Species", 10))
		.Times(1)
		.WillOnce(::testing::Return());

	ASSERT_NO_THROW(mockSeedBank.AddSeeds("Species", 10));
}

TEST_F(SeedBankTests, GetSeed)
{
	EXPECT_CALL(mockSeedBank, GetSeed("Plant"))
		.Times(1)
		.WillOnce(::testing::Return(true));

	ASSERT_TRUE(mockSeedBank.GetSeed("Plant"));
}

TEST_F(SeedBankTests, CountSeeds)
{
	EXPECT_CALL(mockSeedBank, CountSeeds("Plant"))
		.Times(1)
		.WillOnce(::testing::Return(10));

	ASSERT_EQ(10, mockSeedBank.CountSeeds("Plant"));
}

TEST_F(SeedBankTests, ReduceSeedsStorage)
{
	EXPECT_CALL(mockSeedBank, ReduceSeedsStorage())
		.Times(1)
		.WillOnce(::testing::Return());

	ASSERT_NO_THROW(mockSeedBank.ReduceSeedsStorage());
}

