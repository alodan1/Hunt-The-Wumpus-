#include "pool.h"

#include <iostream>

using namespace std;

//Pool Implementation

Pool::Pool():Event("P")
{
    //initialize the symbol as P
}
Pool::~Pool()
{

}

void Pool::print_percept() const{
    cout << "You hear wind blowing.\n"; //print the percept
}

void Pool::print_symbol() const{
    cout << this->symbol; //print the symbol
}
string Pool::get_all_symbols()
{
    return this->symbol; //get the symbol
}