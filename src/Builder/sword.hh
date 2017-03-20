#pragma once

#include <stdio.h>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Sword
{
public:
    typedef std::unique_ptr<Sword> SwordPtr;

public:
    Sword();
    virtual ~Sword();

    void setHelve( string );
    string helve() const;

    void setBlade( string );
    string blade() const;

    void setAdornment( string );
    string adornment() const;

    void setSpell( string );
    string spell() const;

    friend std::ostream &operator<< ( std::ostream &aStream, Sword &aSword )
    {
        aStream << "Helve: " << aSword.helve() << ", blade: " << aSword.blade() << ", adornment: " << aSword.adornment() << ", spell: " << aSword.spell() << endl;
        return aStream;
    }

private:
    string mHelve;
    string mBlade;
    string mAdornment;
    string mSpell;
};
