#include "exit.h"
#include <iostream>

using namespace std;

//Rope Implementation

Rope::Rope():Event("R")
{
//make the rop symbol R
}
Rope::~Rope()
{

}

void Rope::print_percept() const{
    cout << ""; //print no percept (since we were not told to print a percept for the rope/exit)
}

void Rope::print_symbol(){
    cout << this->symbol; //print R at the exit/entrance
}
string Rope::get_all_symbols()
{
    return this->symbol; //get the symbol
}