#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

class IGarden
{
public:

    ~IGarden() = default;

    virtual bool PlantNew(const std::string& name, const std::string& species) = 0;

    virtual bool PlantNew(std::shared_ptr<IPlant> plant) = 0;

    virtual void Grow() = 0;
};