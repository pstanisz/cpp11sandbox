#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

using namespace std;

#include "cpp11config.hh"
#include "Builder/builder.hh"
#include "Builder/dwarf.hh"
#include "Builder/elf.hh"
#include "Builder/human.hh"
#include "Builder/witcher.hh"
#include "Singleton/threadsafesingleton.hh"
#include "Factory/factory.hh"
#include "Factory/plaintextdocument.hh"
#include "Visitor/circle.hh"
#include "Visitor/triangle.hh"
#include "Visitor/validator.hh"
#include "Visitor/areacalc.hh"

enum Pattern
{
    None = 0,
    SafeSingleton = 1,
    Builder = 2,
    AbstractFactory = 3,
    Visitor = 4,
    Last
};

typedef pair<string, string> PatternDescription;
typedef list< pair<string, string> > InputParamList;
typedef list< pair<Pattern, PatternDescription > > PatternList;

const InputParamList INPUT_PARAM_LIST = {
    { string( "-h" ), string( "Prints the usage of application" ) },
    { string( "-v" ), string( "Prints the version of application" ) },
    { string( "-l" ), string( "Lists all the examples with their IDs" ) },
    { string( "-r" ), string( "Runs the example with given ID" ) }
};

const PatternList PATTERN_LIST = {
    { SafeSingleton,
      {
          string( "creational" ),
          string( "thread-safe singleton" )
      }
    },
    { Builder,
      {
          string( "creational" ),
          string( "builder, smart pointers" )
      }
    },
    { AbstractFactory,
      {
          string( "creational" ),
          string( "abstract factory" )
      }
    },
    { Visitor,
      {
          string( "behavioral" ),
          string( "visitor" )
      }
    }
};

void printHelp( string );
void runExample( Pattern );

int main( int argc, const char* argv[] )
{
    if ( argc < 2 )
    {
        cout << "Check usage using " << argv[0] << " -h" << endl;
    }
    else if ( argc < 3 )
    {
        string lFirstArg( argv[1] );
        if ( lFirstArg == "-v" )
        {
            cout << argv[0] << " " << Cpp11_VERSION_MAJOR << "." << Cpp11_VERSION_MINOR << endl;
        }
        else if ( lFirstArg == "-h" )
        {
            printHelp( string( argv[0] ) );
        }
        else if ( lFirstArg == "-l" )
        {
            PatternList::const_iterator lIt;
            for ( lIt = PATTERN_LIST.begin(); lIt != PATTERN_LIST.end(); ++lIt )
            {
                cout << (*lIt).first << ")\t[" << (*lIt).second.first << "]\t" << (*lIt).second.second << endl;
            }
        }
        else
        {
            printHelp( string( argv[0] ) );
        }
    }
    else if ( argc < 4 )
    {
        string lFirstArg( argv[1] );
        Pattern lPatternId = Pattern( atoi(argv[2]) );
        if ( ( lFirstArg == "-r" ) && ( lPatternId < Last ) )
        {
            runExample( lPatternId );
        }
        else
        {
            printHelp( string( argv[0] ) );
        }
    }
    else
    {
        printHelp( string( argv[0] ) );
    }

    return 0;
}

void printHelp(  string aAppName )
{
    cout << "Usage:" << endl;
    cout << aAppName << " [params]" << endl;
    cout << "Parameters:" << endl;

    InputParamList::const_iterator lIt;
    for ( lIt = INPUT_PARAM_LIST.begin(); lIt != INPUT_PARAM_LIST.end(); ++lIt )
    {
        cout << (*lIt).first << "\t" << (*lIt).second << endl;
    }
}

void fun( std::shared_ptr < Sword >& lSwordPtr1 )
{
    if ( lSwordPtr1 )
    {
        cout << "Is not empty?" << endl;
    }
    else
    {
        cout << "Is empty?" << endl;
    }
}

void runExample( Pattern aPatternId )
{
    switch ( aPatternId )
    {
    case None:
    {
        cout << "Such a pattern is not defined" << endl;
    } break;

    case SafeSingleton:
    {
        cout << "Running thread-safe singleton example" << endl;
        vector < thread > lVector;
        int lThreadCount = 32;
        for ( int i = 0; i < lThreadCount; ++i )
        {
            lVector.push_back( thread( []()
            {
                // Simulate operation
                this_thread::sleep_for(chrono::milliseconds(10));
                ThreadSafeSingleton::getInstance().interfaceFun();
            } ) );
        }
        std::for_each( lVector.begin(), lVector.end(), mem_fn( &thread::join ) );
    } break;

    case Builder:
    {
        cout << "Running builder example with smart pointers" << endl;
        Armory lArmory;
        vector < IManufacturer::ManufacturerPtr > lManufacturers;
        vector < Sword::SwordPtr > lSwords;
        lManufacturers.push_back( IManufacturer::ManufacturerPtr( new Human() ) );
        lManufacturers.push_back( IManufacturer::ManufacturerPtr( new Elf() ) );
        lManufacturers.push_back( IManufacturer::ManufacturerPtr( new Dwarf() ) );
        lManufacturers.push_back( IManufacturer::ManufacturerPtr( new Witcher() ) );

        // create few swords
        transform( lManufacturers.begin(),
                   lManufacturers.end(),
                   back_inserter( lSwords ),
                   bind<Sword::SwordPtr>( &Armory::buildWeapon, ref( lArmory ), placeholders::_1 )
                   );
        for_each( lSwords.begin(), lSwords.end(), [](Sword::SwordPtr &aPtr) { cout << *aPtr; } );

        // and even more swords
        transform( lManufacturers.begin(),
                   lManufacturers.end(),
                   back_inserter( lSwords ),
                   bind<Sword::SwordPtr>( &Armory::buildWeapon, ref( lArmory ), placeholders::_1 )
                   );
        for_each( lSwords.begin(), lSwords.end(), [](Sword::SwordPtr &aPtr) { cout << *aPtr; } );
    } break;

    case AbstractFactory:
    {
        cout << "Running abstract factory example" << endl;
        DocumentFactory lDocFactory;

        // Creating and handling PlainTextDocument
        Document::Ptr lDocument = lDocFactory.getDocument( "example.txt", DocumentFactory::PlainText );

        Writer::Ptr lWriter = lDocument->getWriter();
        lWriter->setContent( "This is a content of example text file\nAnd it is second line\n" );
        lWriter->write();
        lWriter.reset();

        Reader::Ptr lReader = lDocument->getReader();
        if ( lReader->read() )
        {
            cout << lReader->getContent();
        }
        lReader.reset();
        lDocument->remove();
        lDocument.reset();

        // Creating and handling HtmlDocument
        lDocument = lDocFactory.getDocument( "example.html", DocumentFactory::Html );

        lWriter = lDocument->getWriter();
        lWriter->setContent( "This is a content of example text file<br>And it is second line<br>\n" );
        lWriter->write();

        lReader = lDocument->getReader();
        if ( lReader->read() )
        {
            cout << lReader->getContent();
        }

        lDocument->remove();
    } break;

    case Visitor:
    {
        std::cout << "Running visitor example - validator and area calculator" << std::endl;

        Validator lValidator;
        AreaCalc lAreaCalculator;

        std::vector< IVisitable * > lVisitableItems;
        lVisitableItems.push_back( new Circle( 1.0 ) );
        lVisitableItems.push_back( new Circle( -5.0 ) );
        lVisitableItems.push_back( new Circle( 39.5 ) );
        lVisitableItems.push_back( new Triangle( 1.0, 1.2, 1.4 ) );
        lVisitableItems.push_back( new Triangle( 31.8, 1.5, 6.9 ) );
        lVisitableItems.push_back( new Triangle( 3.0, 5.0, 4.0 ) );

        std::for_each( lVisitableItems.begin(), lVisitableItems.end(),
                       [&lValidator, &lAreaCalculator]( IVisitable *aVisitable ) {
            aVisitable->accept( lValidator );
            aVisitable->accept( lAreaCalculator );
        } );
    } break;
    }
}
