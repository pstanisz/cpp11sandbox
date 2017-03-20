#pragma once

#include "factory.hh"

class PlainTextReader : public Reader
{
public:
    PlainTextReader( const string aFilePath );
    virtual ~PlainTextReader() {}

    bool read();
};
