#pragma once

#include "manufacturer.hh"

class Witcher : public IManufacturer
{
public:
    Witcher() : IManufacturer()
    {
        mManufacturerId = string( "witcher" );
        cout << "Manufacturer created: " << mManufacturerId << endl;
    }

    void buildHelve()
    {
        mSword->setHelve( string( "gemmed" ) );
    }

    void buildBlade()
    {
        mSword->setBlade( string( "long silver" ) );
    }

    void drawAdornment()
    {
        mSword->setAdornment( string( "wolf's sign" ) );
    }

    void castSpell()
    {
        mSword->setSpell( string( "casting stunning spell" ) );
    }
};
