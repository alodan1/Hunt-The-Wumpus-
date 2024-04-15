#ifndef EXIT_H
#define EXIT_H 

#include "event.h"

//Rope Interface
class Rope: public Event
{
private: 
	
public:

    /**************************************************
     * Name: Rope::Rope()
     * Description: Constructor for the Rope event.
     * Parameters: None
     * Pre-conditions: None
     * Post-conditions: Initializes the symbol of the event to "R".
     ***********************************************/
    Rope();

    /**************************************************
     * Name: Rope::~Rope()
     * Description: Destructor for the Rope event.
     * Parameters: None
     * Pre-conditions: None
     * Post-conditions: Frees any resources associated with the Rope event.
     ***********************************************/
    ~Rope();

    /**************************************************
     * Name: void Rope::print_symbol()
     * Description: Prints the symbol associated with the Rope event.
     * Parameters: None
     * Pre-conditions: None
     * Post-conditions: Outputs the symbol "R" representing the Rope event.
     ***********************************************/
    void print_symbol();

    /**************************************************
     * Name: void Rope::print_percept() const
     * Description: Prints the percept associated with the Rope event.
     * Parameters: None
     * Pre-conditions: None
     * Post-conditions: Outputs an empty string as there's no percept for a rope.
     ***********************************************/
    void print_percept() const;

    /**************************************************
     * Name: string Rope::get_all_symbols()
     * Description: Returns the symbol associated with the Rope event.
     * Parameters: None
     * Pre-conditions: None
     * Post-conditions: Returns the symbol "R" representing the Rope event.
     ***********************************************/
    string get_all_symbols();
};
#endif
