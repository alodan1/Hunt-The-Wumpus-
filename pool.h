#ifndef POOL_H
#define POOL_H 
#include "event.h"
//Pool Interface

class Pool: public Event
{
private: 
	
public:

    /**************************************************
     * Name: Pool()
     * Description: Constructor for the Pool class. Initializes the symbol of the pool.
     * Parameters: None
     * Pre-conditions: None
     * Post-conditions: The Pool object is created and initialized.
     ***********************************************/
    Pool();

    /**************************************************
     * Name: ~Pool()
     * Description: Destructor for the Pool class.
     * Parameters: None
     * Pre-conditions: The Pool object exists.
     * Post-conditions: The Pool object is destroyed.
     ***********************************************/
    ~Pool();

    /**************************************************
     * Name: print_percept() const
     * Description: Prints the percept associated with the pool.
     * Parameters: None
     * Pre-conditions: The Pool object exists.
     * Post-conditions: The percept associated with the pool is printed.
     ***********************************************/
    void print_symbol() const;

    /**************************************************
     * Name: print_symbol() const
     * Description: Prints the symbol of the pool.
     * Parameters: None
     * Pre-conditions: The Pool object exists.
     * Post-conditions: The symbol of the pool is printed.
     ***********************************************/
    void print_percept() const;

    /**************************************************
     * Name: get_all_symbols()
     * Description: Returns the symbol of the pool.
     * Parameters: None
     * Pre-conditions: The Pool object exists.
     * Post-conditions: Returns the symbol of the pool.
     ***********************************************/
    string get_all_symbols();
};
#endif
