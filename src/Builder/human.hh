#pragma once

#include "manufacturer.hh"

class Human : public IManufacturer
{
public:
    Human() : IManufacturer()
    {
        mManufacturerId = string( "human" );
        cout << "Manufacturer created: " << mManufacturerId << endl;
    }

    void buildHelve()
    {
        mSword->setHelve( string( "simple" ) );
    }

    void buildBlade()
    {
        mSword->setBlade( string( "long and heavy iron" ) );
    }

    void drawAdornment()
    {
        mSword->setAdornment( string( "no adornments" ) );
    }

    void castSpell()
    {
        mSword->setSpell( string( "not filled with any magic" ) );
    }
};
