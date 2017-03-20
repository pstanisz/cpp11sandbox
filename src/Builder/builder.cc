#include "builder.hh"
#include "sword.hh"

Sword::SwordPtr Armory::buildWeapon( IManufacturer::ManufacturerPtr &aManufacturer )
{
    aManufacturer->prepareSword();
    aManufacturer->buildHelve();
    aManufacturer->buildBlade();
    aManufacturer->drawAdornment();
    aManufacturer->castSpell();
    return aManufacturer->getSword();
}

