#pragma once

class IVisitable
{
public:
    virtual void accept( class IVisitor &aVisitor ) = 0;
};
