#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

//Room Interface


class Room
{
private: 
	Event *e;
    bool has_player;
public:
    /**************************************************
     * Name: Room()
     * Description: Constructor for the Room class. Initializes the event pointer to nullptr and sets has_player to false.
     * Parameters: None
     * Pre-conditions: None
     * Post-conditions: The Room object is created and initialized.
     ***********************************************/
	Room();

    /**************************************************
     * Name: ~Room()
     * Description: Destructor for the Room class.
     * Parameters: None
     * Pre-conditions: The Room object exists.
     * Post-conditions: The Room object is destroyed.
     ***********************************************/
    ~Room();


    /**************************************************
     * Name: get_symbol() const
     * Description: Returns the symbol associated with the event in the room, or "." if the room is empty.
     * Parameters: None
     * Pre-conditions: The Room object exists.
     * Post-conditions: Returns the symbol associated with the event in the room.
     ***********************************************/
    string get_symbol() const;

    /**************************************************
     * Name: set_dead_or_alive(bool da)
     * Description: Sets the dead or alive status of the wumpus event in the room if present.
     * Parameters: bool da - The new dead or alive status.
     * Pre-conditions: The Room object exists and contains a wumpus event.
     * Post-conditions: The dead or alive status of the wumpus event in the room is updated.
     ***********************************************/
    void set_dead_or_alive(bool da);
   
    /**************************************************
     * Name: set_event(Event* event)
     * Description: Sets the event pointer of the room to the given event pointer.
     * Parameters: Event* event - Pointer to the event to be set in the room.
     * Pre-conditions: The Room object exists, and the given event pointer is valid.
     * Post-conditions: The event pointer of the room is updated.
     ***********************************************/ 
    void set_event(Event* event);   

    /**************************************************
     * Name: set_has_player(bool hp)
     * Description: Sets the has_player status of the room.
     * Parameters: bool hp - The new has_player status.
     * Pre-conditions: The Room object exists.
     * Post-conditions: The has_player status of the room is updated.
     ***********************************************/
    void set_has_player(bool );
    

    /**************************************************
     * Name: get_e() const
     * Description: Returns the event pointer of the room.
     * Parameters: None
     * Pre-conditions: The Room object exists.
     * Post-conditions: Returns the event pointer of the room.
     ***********************************************/
    Event* get_e() const;

    /**************************************************
     * Name: get_has_player() const
     * Description: Returns the has_player status of the room.
     * Parameters: None
     * Pre-conditions: The Room object exists.
     * Post-conditions: Returns the has_player status of the room.
     ***********************************************/
    bool get_has_player() const;

    /**************************************************
     * Name: is_not_empty() const
     * Description: Checks if the room is not empty.
     * Parameters: None
     * Pre-conditions: The Room object exists.
     * Post-conditions: Returns true if the room is not empty, false otherwise.
     ***********************************************/
    bool is_not_empty() const;

    /**************************************************
     * Name: print_symbol() const
     * Description: Prints the symbol associated with the event in the room, or "." if the room is empty.
     * Parameters: None
     * Pre-conditions: The Room object exists.
     * Post-conditions: The symbol associated with the event in the room is printed.
     ***********************************************/
    void print_symbol() const;

    /**************************************************
     * Name: print_percept() const
     * Description: Prints the percept associated with the event in the room, or "." if the room is empty.
     * Parameters: None
     * Pre-conditions: The Room object exists.
     * Post-conditions: The percept associated with the event in the room is printed.
     ***********************************************/
    void print_percept() const;


    /**************************************************
     * Name: get_all_symbols() const
     * Description: Returns the symbol associated with the event in the room, or "." if the room is empty.
     * Parameters: None
     * Pre-conditions: The Room object exists.
     * Post-conditions: Returns the symbol associated with the event in the room.
     ***********************************************/
    string get_all_symbols() const;

    /**************************************************
     * Name: set_win(bool w)
     * Description: Sets the win status of the gold event in the room if present.
     * Parameters: bool w - The new win status.
     * Pre-conditions: The Room object exists and contains a gold event.
     * Post-conditions: The win status of the gold event in the room is updated.
     ***********************************************/
    void set_win(bool w);

    /**************************************************
     * Name: get_win() const
     * Description: Returns the win status of the gold event in the room, or false if the room is empty or does not contain gold.
     * Parameters: None
     * Pre-conditions: The Room object exists.
     * Post-conditions: Returns the win status of the gold event in the room.
     ***********************************************/
    bool get_win() const;
};

#endif
