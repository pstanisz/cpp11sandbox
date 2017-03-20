#include "plaintextwriter.hh"

PlainTextWriter::PlainTextWriter( const string aFilePath ) : Writer( aFilePath )
{
    std::cout << "PlainTextWriter created" << std::endl;
}

bool PlainTextWriter::write()
{
    std::cout << "PlainTextWriter specific write" << std::endl;
    return Writer::write();
}
