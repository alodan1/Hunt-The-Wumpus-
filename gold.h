#ifndef GOLD_H
#define GOLD_H 
#include "event.h"

//Gold Interface
class Gold: public Event
{
private: 
	bool win;
public:

	/**************************************************
	 * Name: Gold()
	 * Description: Constructor for the Gold class. Initializes the symbol and win status of the gold.
	 * Parameters: None
	 * Pre-conditions: None
	 * Post-conditions: The Gold object is created and initialized.
	 ***********************************************/
	Gold();

	/**************************************************
	 * Name: ~Gold()
	 * Description: Destructor for the Gold class.
	 * Parameters: None
	 * Pre-conditions: The Gold object exists.
	 * Post-conditions: The Gold object is destroyed.
	 ***********************************************/
	~Gold();

	/**************************************************
	 * Name: print_symbol()
	 * Description: Prints the symbol of the gold.
	 * Parameters: None
	 * Pre-conditions: The Gold object exists.
	 * Post-conditions: If the win status is false, the symbol of the gold is printed. Otherwise, nothing is printed.
	 ***********************************************/	
	void print_symbol();

	/**************************************************
	 * Name: print_percept() const
	 * Description: Prints the percept associated with the gold.
	 * Parameters: None
	 * Pre-conditions: The Gold object exists.
	 * Post-conditions: If the win status is false, the percept associated with the gold is printed. Otherwise, nothing is printed.
	 ***********************************************/
	void print_percept() const;

	/**************************************************
	 * Name: get_all_symbols()
	 * Description: Returns the symbol of the gold.
	 * Parameters: None
	 * Pre-conditions: The Gold object exists.
	 * Post-conditions: Returns the symbol of the gold.
	 ***********************************************/
	string get_all_symbols();

	/**************************************************
	 * Name: get_win()
	 * Description: Returns the win status of the gold.
	 * Parameters: None
	 * Pre-conditions: The Gold object exists.
	 * Post-conditions: Returns the win status of the gold.
	 ***********************************************/
	bool get_win();

	/**************************************************
	 * Name: set_win(bool w)
	 * Description: Sets the win status of the gold.
	 * Parameters: bool w - The new win status.
	 * Pre-conditions: The Gold object exists.
	 * Post-conditions: The win status of the gold is updated.
	 ***********************************************/
	void set_win(bool w);

};
#endif
