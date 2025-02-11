//#include "gtest/gtest.h"
#include "Plant.hpp"

Plant::Plant(const std::string& name, const std::string& species)
{
    _name = name;
    _species = species;
    _waterLevel = _size = 0;
    _isAlive = true;
}

Plant::Plant(std::shared_ptr<IPlant> plant)
{
	_name = plant->GetName();
	_species = plant->GetSpecies();
	_waterLevel = _size = 0;
	_isAlive = true;
}

bool Plant::IsAlive() { return _isAlive; }

int Plant::GetSize() { return _size; }

int Plant::GetSeeds()
{
    if (!_isAlive) return 0;

    int seeds = _size % 3;
    return seeds;
}

int Plant::GetFruits()
{
    if (!_isAlive || _size < 5) return 0;

    int fruits = _size % 5;
    return fruits;
}

std::string Plant::GetName() { return _name; }

std::string Plant::GetSpecies() { return _species; }


void Plant::Water()
{
    if (_isAlive)
        ++_waterLevel;

    if (_waterLevel > 2)
        Die();
}

void Plant::Grow()
{
    if (!_isAlive)
        throw std::exception("Plant is dead.");

    _size += _waterLevel;
    _waterLevel = 0;
}



void Plant::Die()
{
    _isAlive = false;
}