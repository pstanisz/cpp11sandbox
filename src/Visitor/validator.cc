#include <iostream>
#include <cmath>

#include "validator.hh"
#include "circle.hh"
#include "triangle.hh"

void Validator::visit( Circle *aCircle )
{
    iIsValid = aCircle->radius() < 0.0 ? false : true;
    std::cout << *aCircle << ( iIsValid ? " is valid" : " is invalid!") << std::endl;
}

void Validator::visit( Triangle *aTriangle )
{
    iIsValid = ( abs( aTriangle->a() ) + abs( aTriangle->b() ) > abs( aTriangle->c() ) ) &&
            ( abs( aTriangle->a() ) + abs( aTriangle->c() ) > abs( aTriangle->b() ) ) &&
            ( abs( aTriangle->b() ) + abs( aTriangle->c() ) > abs( aTriangle->a() ) );
    std::cout << *aTriangle << ( iIsValid ? " is valid" : " is invalid!") << std::endl;
}


