#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "SeedBank.hpp"
#include "IPlant.hpp"
#include "IGarden.hpp"
//#include "ISeedBank.hpp"

class Garden : public IGarden
{
    std::vector<std::shared_ptr<IPlant>> _plants;
    std::shared_ptr<ISeedBank> _bank;

public:

    Garden(const std::shared_ptr<ISeedBank>& bank);

    bool PlantNew(const std::string& name, const std::string& species) override;

	bool PlantNew(std::shared_ptr<IPlant> plant) override;

    void Grow() override;
};
