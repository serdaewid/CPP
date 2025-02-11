#pragma once

#include "SeedBank.hpp"
#include "ISeedBank.hpp"
#include "gmock/gmock.h"

class MockSeedBank : public ISeedBank
{
public:
	MOCK_METHOD(void, AddSeeds, (const std::shared_ptr<IPlant>& plant), (override));
	MOCK_METHOD(void, AddSeeds, (const std::string& species, int seeds), (override));
	MOCK_METHOD(bool, GetSeed, (const std::string& species), (override));
	MOCK_METHOD(int, CountSeeds, (const std::string& species), (override));
	MOCK_METHOD(void, ReduceSeedsStorage, (), (override));
};