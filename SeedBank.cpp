//#include "gtest/gtest.h"
#include "SeedBank.hpp"

void SeedBank::AddSeeds(const std::shared_ptr<IPlant>& plant)
{
    AddSeeds(plant->GetSpecies(), plant->GetSeeds());
}

void SeedBank::AddSeeds(const std::string& species, int seeds)
{
    auto it = _speciesSeeds.find(species);
    if (it != _speciesSeeds.end())
        it->second += seeds;
    else
        _speciesSeeds.insert(std::make_pair(species, seeds));
}

bool SeedBank::GetSeed(const std::string& species)
{
    auto it = _speciesSeeds.find(species);
    if (it == _speciesSeeds.end() || it->second <= 0)
        return false;

    it->second--;
    return true;
}

int SeedBank::CountSeeds(const std::string& species)
{
    auto it = _speciesSeeds.find(species);
    if (it != _speciesSeeds.end())
        return it->second;

    return 0;
}

void SeedBank::ReduceSeedsStorage()
{
    int avg = 0;
    for (auto it = _speciesSeeds.begin(); it != _speciesSeeds.end(); ++it)
        avg += it->second;

    avg = avg / _speciesSeeds.size();
    avg = static_cast<int>(0.8f * avg);

    for (auto it = _speciesSeeds.begin(); it != _speciesSeeds.end(); ++it)
    {
        if (it->second > avg)
            it->second = avg;
    }
}