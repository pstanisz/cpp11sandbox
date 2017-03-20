#pragma once

#include <stdio.h>
#include <iostream>
#include <memory>
#include <vector>

#include "sword.hh"

using namespace std;

class IManufacturer
{
public:
    typedef std::unique_ptr<IManufacturer> ManufacturerPtr;

public:
    IManufacturer() { }
    virtual ~IManufacturer()
    {
        cout << "Manufacturer destructor called" << endl;
    }

    void prepareSword()
    {
        mSword.reset( new Sword() );
    }

    Sword::SwordPtr getSword()
    {
        return std::move( mSword );
    }

    string manufacturerId() const
    {
        return mManufacturerId;
    }

public:
    virtual void buildHelve() = 0;
    virtual void buildBlade() = 0;
    virtual void drawAdornment() = 0;
    virtual void castSpell() = 0;

protected:
    Sword::SwordPtr mSword;
    string  mManufacturerId;
};
