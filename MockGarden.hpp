#pragma once

#include "Garden.hpp"
#include "IGarden.hpp"
#include "gmock/gmock.h"

class MockGarden : public IGarden
{
private:
public:
	MOCK_METHOD(bool, PlantNew, (const std::string& name, const std::string& species), (override));
	MOCK_METHOD(bool, PlantNew, (std::shared_ptr<IPlant> plant), (override));
	MOCK_METHOD(void, Grow, (), (override));
};