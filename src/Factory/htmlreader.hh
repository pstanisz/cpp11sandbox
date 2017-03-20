#pragma once

#include "factory.hh"

class HtmlReader : public Reader
{
public:
    HtmlReader( const string aFilePath );
    virtual ~HtmlReader() {}

    bool read();
};
