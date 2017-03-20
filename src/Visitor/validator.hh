#pragma once

#include "visitor.hh"

class IVisitable;

class Validator : public IVisitor
{
public:
    void visit( Circle *aCircle );
    void visit( Triangle *aTriangle );
    bool isValid() const { return iIsValid; }

private:
    bool iIsValid;
};
