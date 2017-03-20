#pragma once

#include <string>

#include "factory.hh"

using namespace std;

class PlainTextDocument : public Document
{
public:
    typedef shared_ptr<PlainTextDocument> Ptr;

    PlainTextDocument( const string aFilePath );
    virtual ~PlainTextDocument();

    Reader::Ptr getReader();
    Writer::Ptr getWriter();
};
