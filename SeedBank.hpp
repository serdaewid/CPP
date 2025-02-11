#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "Plant.hpp"
#include "ISeedBank.hpp"

class SeedBank : public ISeedBank
{
    std::map<std::string, int> _speciesSeeds;

public:

    void AddSeeds(const std::shared_ptr<IPlant>& plant) override;

    void AddSeeds(const std::string& species, int seeds) override;

    bool GetSeed(const std::string& species) override;

    int CountSeeds(const std::string& species) override;

    void ReduceSeedsStorage() override;
};
