#include "gmock/gmock.h"
#include "MockSeedBank.hpp"
#include "MockGarden.hpp"
#include "Garden.hpp"
#include "MockPlant.hpp"

struct GardenTests : public ::testing::Test 
{
	std::shared_ptr<MockPlant> mockPlant = std::make_shared<MockPlant>();//("Plant", "Species");
	std::shared_ptr<MockSeedBank> mockSeedBank = std::make_shared<MockSeedBank>();
	
	Garden garden{ mockSeedBank };

	//void SetUp() override
	//{
	//	//garden = Garden{ mockSeedBank };

	//}
};

TEST_F(GardenTests, PlantNewTest)
{
	EXPECT_CALL(*mockSeedBank, GetSeed("Species"))
		.Times(1)
		.WillOnce(::testing::Return(true));

	garden.PlantNew("Plant", "Species");
}

TEST_F(GardenTests, GrowTest)
{
	// Setup: ustawiamy wartoœci zwracane przez mockPlant
	ON_CALL(*mockPlant, GetName())
		.WillByDefault(::testing::Return("Plant"));
	ON_CALL(*mockPlant, GetSpecies())
		.WillByDefault(::testing::Return("Species"));//nie trzeba by jesli w konstruktorze MockPlant w make_shared by sie dalo to dac
	ON_CALL(*mockSeedBank, GetSeed(::testing::_))//moze nie trzeba bo to po AddSeeds powinno dzialac
		.WillByDefault(::testing::Return(true));

	mockSeedBank->AddSeeds(mockPlant);
	garden.PlantNew(mockPlant);

	EXPECT_CALL(*mockSeedBank, AddSeeds(std::static_pointer_cast<IPlant>(mockPlant)))
		.Times(1);

	EXPECT_CALL(*mockPlant, Water())
		.Times(1);

	EXPECT_CALL(*mockPlant, Grow())
		.Times(1);

	//jeszcze mozna dodac te co wywoluje AddSeeds

	garden.Grow();
}