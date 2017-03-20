#pragma once

#include "visitor.hh"

class IVisitable;

class AreaCalc : public IVisitor
{
public:
    void visit( Circle *aCircle );
    void visit( Triangle *aTriangle );
    double getArea() const { return iResult; }

private:
    double iResult;
};
