#pragma once

#include <stdio.h>
#include <iostream>
#include <memory>
#include <vector>

#include "manufacturer.hh"

using namespace std;

class Armory
{
public:
    Sword::SwordPtr buildWeapon( IManufacturer::ManufacturerPtr &aManufacturer );
};
