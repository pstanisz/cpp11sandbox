#include "sword.hh"

Sword::Sword()
{
    cout << "Sword constructor called" << endl;
}

Sword::~Sword()
{
    cout << "Sword destructor called" << endl;
}

void Sword::setHelve( string aHelve )
{
    mHelve = aHelve;
}

string Sword::helve() const
{
    return mHelve;
}

void Sword::setBlade( string aBlade )
{
    mBlade = aBlade;
}

string Sword::blade() const
{
    return mBlade;
}

void Sword::setAdornment( string aAdornment )
{
    mAdornment = aAdornment;
}

string Sword::adornment() const
{
    return mAdornment;
}

void Sword::setSpell( string aSpell )
{
    mSpell = aSpell;
}

string Sword::spell() const
{
    return mSpell;
}
