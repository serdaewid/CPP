#include "gmock/gmock.h"
#include "MockPlant.hpp"
#include "Plant.hpp"

struct PlantTests : public ::testing::Test
{
	MockPlant mockPlant;
};

TEST_F(PlantTests, IsAliveTest)
{
	EXPECT_CALL(mockPlant, IsAlive())
		.Times(1)
		.WillOnce(::testing::Return(true));

	ASSERT_TRUE(mockPlant.IsAlive());
}

TEST_F(PlantTests, GetSizeTest)
{
	EXPECT_CALL(mockPlant, GetSize())
		.Times(1)
		.WillOnce(::testing::Return(10));

	ASSERT_EQ(10, mockPlant.GetSize());
}

TEST_F(PlantTests, GetSeedsTest)
{
	EXPECT_CALL(mockPlant, GetSeeds())
		.Times(1)
		.WillOnce(::testing::Return(1));

	ASSERT_EQ(1, mockPlant.GetSeeds());
}

TEST_F(PlantTests, GetFruitsTest)
{
	EXPECT_CALL(mockPlant, GetFruits())
		.Times(1)
		.WillOnce(::testing::Return(1));

	ASSERT_EQ(1, mockPlant.GetFruits());
}

TEST_F(PlantTests, GetNameTest)
{
	EXPECT_CALL(mockPlant, GetName())
		.Times(1)
		.WillOnce(::testing::Return("Plant"));

	ASSERT_EQ("Plant", mockPlant.GetName());
}

TEST_F(PlantTests, GetSpeciesTest)
{
	EXPECT_CALL(mockPlant, GetSpecies())
		.Times(1)
		.WillOnce(::testing::Return("Species"));

	ASSERT_EQ("Species", mockPlant.GetSpecies());
}

TEST_F(PlantTests, WaterTest)
{
	EXPECT_CALL(mockPlant, Water())
		.Times(1);

	mockPlant.Water();
}

TEST_F(PlantTests, GrowTest)
{
	EXPECT_CALL(mockPlant, Grow())
		.Times(1);

	mockPlant.Grow();
}

TEST_F(PlantTests, DieTest)
{
	EXPECT_CALL(mockPlant, Die())
		.Times(1);

	mockPlant.Die();
}
