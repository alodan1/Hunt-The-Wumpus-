#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

Stalactites::Stalactites():Event("S")
{
    //make the symbol S
}
Stalactites::~Stalactites()
{

}

void Stalactites::print_percept() const{
    cout << "You hear water dripping.\n"; //print the percept
}

void Stalactites::print_symbol() const{
    cout << this->symbol; //print the symbol
}

string Stalactites::get_all_symbols()
{
    return this->symbol; //get the symbol
}