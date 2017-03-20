#include "plaintextdocument.hh"

#include "plaintextreader.hh"
#include "plaintextwriter.hh"

PlainTextDocument::PlainTextDocument( const std::string aFilePath ) : Document( aFilePath )
{
    std::cout << "PlainTextDocument opened: " << aFilePath << std::endl;
}

PlainTextDocument::~PlainTextDocument()
{
}

Reader::Ptr PlainTextDocument::getReader()
{
    return Reader::Ptr( new PlainTextReader( iFilePath ) );
}

Writer::Ptr PlainTextDocument::getWriter()
{
    return Writer::Ptr( new PlainTextWriter( iFilePath ) );
}
