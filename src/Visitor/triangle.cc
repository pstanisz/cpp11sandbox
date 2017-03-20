#include "triangle.hh"

std::string Triangle::iType = "Triangle";

std::ostream& operator<<( std::ostream &aStream, Triangle &aTriangle )
{
    aStream << "[" << aTriangle.iType << ", a=" << aTriangle.a() << ", b=" << aTriangle.b() << ", c=" << aTriangle.c() << "]";
    return aStream;
}

Triangle::Triangle( double aA, double aB, double aC ) : iA( aA ), iB( aB ), iC( aC )
{

}

void Triangle::accept( IVisitor &aVisitor )
{
    aVisitor.visit( this );
}
