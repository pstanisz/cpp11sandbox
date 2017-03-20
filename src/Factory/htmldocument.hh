#pragma once

#include <string>

#include "factory.hh"

using namespace std;

class HtmlDocument : public Document
{
public:
    typedef shared_ptr<HtmlDocument> Ptr;

    HtmlDocument( const string aFilePath );
    virtual ~HtmlDocument();

    Reader::Ptr getReader();
    Writer::Ptr getWriter();
};
