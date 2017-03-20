#pragma once

#include "factory.hh"

class HtmlWriter : public Writer
{
public:
    HtmlWriter( const string aFilePath );
    virtual ~HtmlWriter() {}

    bool write();
};
