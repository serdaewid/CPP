//#include "gtest/gtest.h"
#include "Garden.hpp"

Garden::Garden(const std::shared_ptr<ISeedBank>& bank)
{
    _bank = bank;
}

bool Garden::PlantNew(const std::string& name, const std::string& species)
{
    if (!_bank->GetSeed(species)) return false;

    auto plant = std::make_shared<Plant>(name, species);
    _plants.push_back(plant);
    return true;
}

bool Garden::PlantNew(std::shared_ptr<IPlant> plant)
{
	if (!_bank->GetSeed(plant->GetSpecies())) return false;

	_plants.push_back(plant);
	return true;
}

void Garden::Grow()
{
    for (auto& plant : _plants)
    {
        plant->Water();
        plant->Grow();
        _bank->AddSeeds(plant);
    }
}