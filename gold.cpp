#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

Gold::Gold():Event("G")
{
    //initialize the symbol to G
}
Gold::~Gold()
{

}

void Gold::print_percept() const{
    if(win == false)
        cout << "You see a glimmer nearby.\n"; //print the percept if the player has not gotten the gold
    else
        cout << ""; //if they did print nothing
}

void Gold::print_symbol(){
    if(win == false)
    {
        cout << this->symbol; //print symbol if the player has not gotten the gold
    }else
        cout << " "; //if thet did print nothing
    
}
string Gold::get_all_symbols()
{
    return this->symbol; //get the symbol
}

bool Gold::get_win()
{
    return this->win; //get if the player has gotten the gold
}
void Gold::set_win(bool w)
{
    this->win = w; //set if the player has gotten the gold
}