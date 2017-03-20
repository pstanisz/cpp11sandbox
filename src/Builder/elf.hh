#pragma once

#include "manufacturer.hh"

class Elf : public IManufacturer
{
public:
    Elf() : IManufacturer()
    {
        mManufacturerId = string( "elf" );
        cout << "Manufacturer created: " << mManufacturerId << endl;
    }

    void buildHelve()
    {
        mSword->setHelve( string( "encrusted" ) );
    }

    void buildBlade()
    {
        mSword->setBlade( string( "short and light" ) );
    }

    void drawAdornment()
    {
        mSword->setAdornment( string( "elvish runes" ) );
    }

    void castSpell()
    {
        mSword->setSpell( string( "casting fire spell" ) );
    }
};
