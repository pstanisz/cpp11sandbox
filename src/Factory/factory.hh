#pragma once

#include <memory>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

class Reader
{
public:
    typedef shared_ptr<Reader> Ptr;

    Reader( const string aFilePath );
    virtual ~Reader();

    virtual bool read();
    virtual string getContent() const;

protected:
    string  iFilePath;
    string  iContent;
};

class Writer
{
public:
    typedef shared_ptr<Writer> Ptr;

    Writer( const string aFilePath );
    virtual ~Writer();

    virtual bool write();
    virtual void setContent( const string aContent );

protected:
    string  iFilePath;
    string  iContent;
};

class Document
{
public:
    typedef shared_ptr<Document> Ptr;

    Document( const string aFilePath );
    virtual ~Document();

    virtual Reader::Ptr getReader() = 0;
    virtual Writer::Ptr getWriter() = 0;
    virtual void remove();

protected:
    string  iFilePath;
};

class DocumentFactory
{
public:
    enum DocumentType
    {
        PlainText = 0,
        Html
    };

public:
    DocumentFactory();
    virtual ~DocumentFactory();

    Document::Ptr getDocument( const string aFilePath, DocumentType aType = PlainText );
};
