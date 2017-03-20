#include "htmldocument.hh"

#include "htmlreader.hh"
#include "htmlwriter.hh"

HtmlDocument::HtmlDocument( const std::string aFilePath ) : Document( aFilePath )
{
    std::cout << "HtmlDocument opened: " << aFilePath << std::endl;
}

HtmlDocument::~HtmlDocument()
{
}

Reader::Ptr HtmlDocument::getReader()
{
    return Reader::Ptr( new HtmlReader( iFilePath ) );
}

Writer::Ptr HtmlDocument::getWriter()
{
    return Writer::Ptr( new HtmlWriter( iFilePath ) );
}
