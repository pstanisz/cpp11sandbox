#pragma once

class Circle;
class Triangle;

class IVisitor
{
public:
    virtual void visit( Circle *aCircle ) = 0;
    virtual void visit( Triangle *aTriangle ) = 0;
};
