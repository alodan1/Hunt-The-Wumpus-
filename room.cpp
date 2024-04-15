#include "room.h"
#include "wumpus.h"
#include "gold.h"
#include "exit.h"
using namespace std;
#include <iostream>

//Room Implementation

Room::Room()
{
    this->e=NULL; //initialize e as NULL
    this->has_player=false; //initialize has_player to false
}

Room::~Room()
{

}
void Room::set_event(Event* event) {
        this->e = event; //make it possible to set the event
    }
void Room::set_has_player(bool hp)
{
    this->has_player = hp; //make it possible to set has_player
}
Event* Room::get_e() const
{
    return this->e; //return e
}
bool Room::get_has_player() const
{
    return this->has_player; //return if the location has a player
}

bool Room::is_not_empty() const
{
    return (this->e !=nullptr); //returns true if it's not empty

}

void Room::print_symbol() const {
        if (this->e) {
            this->e->print_symbol(); //print symbol
        } else {
            cout << "."; //else don't
        }
    }

string Room::get_symbol() const
{
    if (this->e) {
        Wumpus* w = (Wumpus*)(this->e);
            return w->get_symbol(); //print symbol
        } else {
            return "."; //else don't
        }
}

bool Room::get_win() const
{
    if(this->e)
    {
        Gold* g = (Gold*)(this->e);
        return g->get_win(); //get if the player has won
    } else {
        return false; //else return false
    }
}

string Room::get_all_symbols() const
{
    if(this->e)
    {
        return e->get_all_symbols(); //get the symbol
    }
    else
        return "."; //else don't
}

void Room::print_percept() const {
        if (this->e) {
            this->e->print_percept(); //print the percept
        } else {
            cout << "."; //else don't
        }
    }

void Room::set_dead_or_alive(bool da)
{
    if(get_symbol() == "W")
    {
        Wumpus* w = (Wumpus*)(this->e);
        
        w->set_dead_or_alive(da); //set dead or alive to what I choose
    }
}

void Room::set_win(bool w)
{
    if(get_all_symbols() == "G")
    {
        Gold* g = (Gold*)(this->e);
        g->set_win(w); //set win to what I choose
    }
}
    
    
