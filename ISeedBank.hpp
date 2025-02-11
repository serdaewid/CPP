#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

class ISeedBank
{
public:
	~ISeedBank() = default;

	virtual void AddSeeds(const std::shared_ptr<IPlant>& plant) = 0;

	virtual void AddSeeds(const std::string& species, int seeds) = 0;

	virtual bool GetSeed(const std::string& species) = 0;

	virtual int CountSeeds(const std::string& species) = 0;

	virtual void ReduceSeedsStorage() = 0;
};
