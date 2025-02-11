#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

class IPlant
{
public:
    ~IPlant() = default;

    virtual bool IsAlive() = 0;

    virtual int GetSize() = 0;

    virtual int GetSeeds() = 0;

    virtual int GetFruits() = 0;

    virtual std::string GetName() = 0;

    virtual std::string GetSpecies() = 0;

    virtual void Water() = 0;

    virtual void Grow() = 0;

    virtual void Die() = 0;
};