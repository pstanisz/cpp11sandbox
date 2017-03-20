#pragma once

#include <iostream>

#include "visitable.hh"
#include "visitor.hh"

class Circle : public IVisitable
{
public:
    static std::string iType;
    friend std::ostream& operator<<( std::ostream &, Circle & );

public:
    Circle( double aRadius = 0.0 );
    void accept( IVisitor &aVisitor );

    double radius() const { return iRadius; }
    void setRadius( double aRadius ) { iRadius = aRadius; }

private:
    Circle() {}

    double iRadius;
};


