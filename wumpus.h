#ifndef WUMPUS_H
#define WUMPUS_H 

#include "event.h"

//Wumpus Interface
class Wumpus: public Event
{
private: 
	bool dead_or_alive;
public:

	/**************************************************
	 * Name: Wumpus()
	 * Description: Constructor for the Wumpus class. Initializes the Wumpus as alive and sets its symbol.
	 * Parameters: None
	 * Pre-conditions: None
	 * Post-conditions: The Wumpus object is created and initialized.
	 ***********************************************/
	Wumpus();

	/**************************************************
	 * Name: ~Wumpus()
	 * Description: Destructor for the Wumpus class.
	 * Parameters: None
	 * Pre-conditions: The Wumpus object exists.
	 * Post-conditions: The Wumpus object is destroyed.
	 ***********************************************/
	~Wumpus();

	/**************************************************
	 * Name: print_symbol()
	 * Description: Prints the symbol of the Wumpus if it's alive, otherwise prints an empty space.
	 * Parameters: None
	 * Pre-conditions: The Wumpus object exists.
	 * Post-conditions: The symbol of the Wumpus is printed.
	 ***********************************************/
	void print_symbol();

	/**************************************************
	 * Name: print_percept() const
	 * Description: Prints the percept associated with the Wumpus if it's alive.
	 * Parameters: None
	 * Pre-conditions: The Wumpus object exists.
	 * Post-conditions: The percept associated with the Wumpus is printed.
	 ***********************************************/
	void print_percept() const;

	/**************************************************
	 * Name: get_dead_or_alive()
	 * Description: Returns whether the Wumpus is dead or alive.
	 * Parameters: None
	 * Pre-conditions: The Wumpus object exists.
	 * Post-conditions: Returns true if the Wumpus is alive, false if it's dead.
	 ***********************************************/
	string get_symbol();

	/**************************************************
	 * Name: get_symbol()
	 * Description: Returns the symbol of the Wumpus.
	 * Parameters: None
	 * Pre-conditions: The Wumpus object exists.
	 * Post-conditions: Returns the symbol of the Wumpus.
	 ***********************************************/
	bool get_dead_or_alive();

	/**************************************************
	 * Name: set_dead_or_alive(bool da)
	 * Description: Sets the state of the Wumpus (alive or dead).
	 * Parameters: 
	 *      - bool: A boolean indicating whether the Wumpus is dead or alive.
	 * Pre-conditions: The Wumpus object exists.
	 * Post-conditions: The state of the Wumpus is updated.
	 ***********************************************/
	void set_dead_or_alive(bool);

	/**************************************************
	 * Name: get_all_symbols()
	 * Description: Returns the symbol of the Wumpus.
	 * Parameters: None
	 * Pre-conditions: The Wumpus object exists.
	 * Post-conditions: Returns the symbol of the Wumpus.
	 ***********************************************/
	string get_all_symbols();
};
#endif
