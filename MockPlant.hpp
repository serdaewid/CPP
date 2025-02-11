#pragma once

#include "Plant.hpp"
#include "IPlant.hpp"
#include "gmock/gmock.h"

class MockPlant : public IPlant
{
public:
	MOCK_METHOD(bool, IsAlive, (), (override));
	MOCK_METHOD(int, GetSize, (), (override));
	MOCK_METHOD(int, GetSeeds, (), (override));
	MOCK_METHOD(int, GetFruits, (), (override));
	MOCK_METHOD(std::string, GetName, (), (override));
	MOCK_METHOD(std::string, GetSpecies, (), (override));
	MOCK_METHOD(void, Water, (), (override));
	MOCK_METHOD(void, Grow, (), (override));
	MOCK_METHOD(void, Die, (), (override));
};