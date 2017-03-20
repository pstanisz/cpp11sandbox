#pragma once

#include "manufacturer.hh"

class Dwarf : public IManufacturer
{
public:
    Dwarf() : IManufacturer()
    {
        mManufacturerId = string( "dwarf" );
        cout << "Manufacturer created: " << mManufacturerId << endl;
    }

    void buildHelve()
    {
        mSword->setHelve( string( "straight" ) );
    }

    void buildBlade()
    {
        mSword->setBlade( string( "short steel" ) );
    }

    void drawAdornment()
    {
        mSword->setAdornment( string( "skulls" ) );
    }

    void castSpell()
    {
        mSword->setSpell( string( "not filled with any magic" ) );
    }
};
