#include "htmlwriter.hh"

HtmlWriter::HtmlWriter( const string aFilePath ) : Writer( aFilePath )
{
    std::cout << "HtmlWriter created" << std::endl;
}

bool HtmlWriter::write()
{
    std::cout << "HtmlWriter specific write" << std::endl;
    return Writer::write();
}
