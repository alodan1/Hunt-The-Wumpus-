#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"
//Stalactites Interface
class Stalactites: public Event
{
private: 
	
public:

    /**************************************************
     * Name: Stalactites()
     * Description: Constructor for the Stalactites class. Initializes the symbol of stalactites.
     * Parameters: None
     * Pre-conditions: None
     * Post-conditions: The Stalactites object is created and initialized.
     ***********************************************/
    Stalactites();

    /**************************************************
     * Name: ~Stalactites()
     * Description: Destructor for the Stalactites class.
     * Parameters: None
     * Pre-conditions: The Stalactites object exists.
     * Post-conditions: The Stalactites object is destroyed.
     ***********************************************/
    ~Stalactites();

    /**************************************************
     * Name: print_percept() const
     * Description: Prints the percept associated with the stalactites.
     * Parameters: None
     * Pre-conditions: The Stalactites object exists.
     * Post-conditions: The percept associated with the stalactites is printed.
     ***********************************************/
    void print_symbol() const;

    /**************************************************
     * Name: print_symbol() const
     * Description: Prints the symbol of the stalactites.
     * Parameters: None
     * Pre-conditions: The Stalactites object exists.
     * Post-conditions: The symbol of the stalactites is printed.
     ***********************************************/
    void print_percept() const;

    /**************************************************
     * Name: get_all_symbols()
     * Description: Returns the symbol of the stalactites.
     * Parameters: None
     * Pre-conditions: The Stalactites object exists.
     * Post-conditions: Returns the symbol of the stalactites.
     ***********************************************/
    string get_all_symbols();
};
#endif

