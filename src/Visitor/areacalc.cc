#include <iostream>
#include <cmath>

#include "areacalc.hh"
#include "circle.hh"
#include "triangle.hh"

void AreaCalc::visit( Circle *aCircle )
{
    iResult = M_PI * aCircle->radius();
    std::cout << *aCircle << " area=" << iResult << std::endl;
}

void AreaCalc::visit( Triangle *aTriangle )
{
    double lCircumference = ( aTriangle->a() + aTriangle->b() + aTriangle->c() ) / 2.0;
    iResult = sqrt( lCircumference * ( lCircumference - aTriangle->a() ) * ( lCircumference - aTriangle->b() ) * ( lCircumference - aTriangle->c() ) );
    std::cout << *aTriangle << " area=" << iResult << std::endl;
}


