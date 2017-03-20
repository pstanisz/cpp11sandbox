#include <cstdio>

#include "factory.hh"
#include "plaintextdocument.hh"
#include "htmldocument.hh"

Reader::Reader( const string aFilePath ) : iFilePath( aFilePath )
{

}

Reader::~Reader()
{

}

bool Reader::read()
{
    ifstream lInFile( iFilePath, ios::in | ios::binary );
    if ( lInFile )
    {
        lInFile.seekg( 0, std::ios::end );
        iContent.reserve( lInFile.tellg() );
        lInFile.seekg( 0, std::ios::beg );
        std::copy( ( std::istreambuf_iterator<char>( lInFile ) ),
                   std::istreambuf_iterator<char>(),
                   std::back_inserter( iContent ) );
        lInFile.close();
    }
    return !iContent.empty();
}

string Reader::getContent() const
{
    return iContent;
}

Writer::Writer( const string aFilePath ) : iFilePath( aFilePath )
{

}

Writer::~Writer()
{

}

bool Writer::write()
{
    ofstream lOutfile( iFilePath, ios::out | ios::binary );
    lOutfile.write( &iContent[0], iContent.size() );
    lOutfile.close();
}

void Writer::setContent( const string aContent )
{
    iContent = aContent;
}

Document::Document( const string aFilePath ) : iFilePath( aFilePath )
{

}

Document::~Document()
{

}

void Document::remove()
{
    if ( iFilePath.empty() )
    {
        return;
    }
    std::remove( iFilePath.c_str() );
}

DocumentFactory::DocumentFactory()
{

}

DocumentFactory::~DocumentFactory()
{

}

Document::Ptr DocumentFactory::getDocument( const string aFilePath, DocumentType aType )
{
    if ( PlainText == aType )
    {
        return Document::Ptr( new PlainTextDocument( aFilePath ) );
    }
    if ( Html == aType )
    {
        return Document::Ptr( new HtmlDocument( aFilePath ) );
    }
}
