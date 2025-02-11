#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "IPlant.hpp"

class Plant : public IPlant
{
    std::string _name;
    std::string _species;
    int _waterLevel;
    int _size;
    bool _isAlive;

public:
    Plant(const std::string& name, const std::string& species);
	Plant(std::shared_ptr<IPlant> plant);
    bool IsAlive() override;

    int GetSize() override;
    int GetSeeds() override;
    int GetFruits() override;

    std::string GetName() override;
    std::string GetSpecies() override;

    void Water() override;
    void Grow() override;
    void Die() override;
};
