#include "event.h"

#include <iostream>
#include <string>
using namespace std;

//Event Implementation
Event::Event()
{
    this->symbol = " "; //set the symbol to nothing
}
Event::Event(string s)
{
    this->symbol = s; //set the symbol s
}

Event::~Event()
{
    
}

void Event::print_symbol()
{
    cout << this->symbol;//print the symbol
}

string Event::get_all_symbols()
{
    return this->symbol; //get the symbol
}