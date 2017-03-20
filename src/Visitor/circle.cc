#include "circle.hh"

std::string Circle::iType = "Circle";

std::ostream& operator<<( std::ostream &aStream, Circle &aCircle )
{
    aStream << "[" << aCircle.iType << ", r=" << aCircle.radius() << "]";
    return aStream;
}

Circle::Circle( double aRadius ) : iRadius( aRadius )
{

}

void Circle::accept( IVisitor &aVisitor )
{
    aVisitor.visit( this );
}
