#include "htmlreader.hh"

HtmlReader::HtmlReader( const string aFilePath ) : Reader( aFilePath )
{
    std::cout << "HtmlReader created" << std::endl;
}

bool HtmlReader::read()
{
    std::cout << "HtmlReader specific read" << std::endl;
    return Reader::read();
}

