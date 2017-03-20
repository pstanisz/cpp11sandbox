#pragma once

#include <iostream>

#include "visitable.hh"
#include "visitor.hh"

class Triangle : public IVisitable
{
public:
    static std::string iType;
    friend std::ostream& operator<<( std::ostream &, Triangle & );

public:
    Triangle( double aA, double aB, double aC );
    void accept( IVisitor &aVisitor );

    double a() const { return iA; }
    double b() const { return iB; }
    double c() const { return iC; }
    void setA( double aA ) { iA = aA; }
    void setB( double aB ) { iB = aB; }
    void setC( double aC ) { iC = aC; }

private:
    Triangle() {}

    double iA;
    double iB;
    double iC;
};


