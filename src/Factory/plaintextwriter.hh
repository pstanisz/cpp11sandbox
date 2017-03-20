#pragma once

#include "factory.hh"

class PlainTextWriter : public Writer
{
public:
    PlainTextWriter( const string aFilePath );
    virtual ~PlainTextWriter() {}

    bool write();
};
