#ifndef EVENT_H
#define EVENT_H 

using namespace std;
#include <string>
//Event Interface
//Note: this must be an abstract class!

class Event
{	
protected:
    string symbol;
public:

    /**************************************************
     * Name: Event()
     * Description: Default constructor for the Event class. Initializes the symbol to a space character.
     * Parameters: None
     * Pre-conditions: None
     * Post-conditions: The Event object is created with a space symbol.
     ***********************************************/
    Event();

    /**************************************************
     * Name: Event(string s)
     * Description: Parameterized constructor for the Event class. Initializes the symbol to the provided string.
     * Parameters: string s - The symbol to be set for the Event.
     * Pre-conditions: None
     * Post-conditions: The Event object is created with the provided symbol.
     ***********************************************/
    Event(string );

    /**************************************************
     * Name: ~Event()
     * Description: Destructor for the Event class.
     * Parameters: None
     * Pre-conditions: The Event object exists.
     * Post-conditions: The Event object is destroyed.
     ***********************************************/
    virtual ~Event();

    /**************************************************
     * Name:  print_percept()
     * Description: Abstract virtual function declaration for printing the percept of an event.
     * Parameters: None
     * Pre-conditions: None
     * Post-conditions: The function is declared as abstract and must be implemented by derived classes.
     ***********************************************/
    virtual void print_percept() const = 0;

    /**************************************************
     * Name: print_symbol()
     * Description: Prints the symbol associated with the Event.
     * Parameters: None
     * Pre-conditions: The Event object exists.
     * Post-conditions: The symbol associated with the Event is printed.
     ***********************************************/
    virtual void print_symbol();

    /**************************************************
     * Name: get_all_symbols()
     * Description: Returns the symbol associated with the Event.
     * Parameters: None
     * Pre-conditions: The Event object exists.
     * Post-conditions: Returns the symbol associated with the Event.
     ***********************************************/
    virtual string get_all_symbols();
};
#endif