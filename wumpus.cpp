#include "wumpus.h"
#include "event.h"
#include <iostream>
#include <string>
using namespace std;

//Wumpus Implementation
Wumpus::Wumpus(): Event("W")
{
    this->dead_or_alive = true; //initialize the symbol to W and dead_or_alive to true
}

Wumpus::~Wumpus()
{
    
}
void Wumpus::print_symbol()
{
    if(this->dead_or_alive == true) //print the symbol of dead_or_alive is true
        cout << this->symbol;
    else //else print an empty space
        cout << " ";
}

void Wumpus::print_percept() const
{
    if(this->dead_or_alive == true) //print the percept of dead_or_alive is true
        cout << "You smell a terrible stench.\n";
    else //else print nothing
        cout << "";
}

bool Wumpus::get_dead_or_alive()
{
    
    return this->dead_or_alive; //return if dead_or_alive is true/false
}
string Wumpus::get_symbol()
{
    return this->symbol; //get the symbol
}

void Wumpus::set_dead_or_alive(bool da)
{
    this->dead_or_alive = da; //set dead_or_alive to true or false
}

string Wumpus::get_all_symbols()
{
    return this->symbol; //get the symbol
}