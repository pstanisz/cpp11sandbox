#include "plaintextreader.hh"

PlainTextReader::PlainTextReader( const string aFilePath ) : Reader( aFilePath )
{
    std::cout << "PlainTextReader created" << std::endl;
}

bool PlainTextReader::read()
{
    std::cout << "PlainTextReader specific read" << std::endl;
    return Reader::read();
}

