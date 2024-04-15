/******************************************************
** Program: wumpus.cpp
** Author: Almog Danziger
** Date: 3/14/2024
** Description: The game allows the player to navigate through a cave, find gold, and avoid hazards such as the Wumpus and stalactites.
** Input:       User inputs for navigating the cave and firing arrows.
** Output:      Visual representation of the cave, along with messages indicating nearby hazards or gold.
******************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

/**************************************************
 * Name: true_or_false() 
 * Description: Prompts the user whether they want to enable debug mode or not and returns true or false accordingly.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Returns true if the user chooses to enable debug mode, false otherwise.
 ***********************************************/
bool true_or_false();

int main()
{
	//set the random seed
	srand(time(NULL)); 
	
	//side length: hardcoded value for now
	int side_len;
	
	Game g;

	//get one input: side length of the cave between 4 and 50
	do
	{
		cout << "what do you want the size of the map to be? ";
		cin >> side_len;
	} while (!(side_len >=4 && side_len <=50));
	

	//get the 2nd input --> debug mode or not
	bool debug = true_or_false();

	//Play game
	g.play_game(side_len, debug);


	return 0;
}

bool true_or_false() 
{
	int trueFalse;
	//prmpting the user if they want to play again or not
	cout << endl << "Do you want to to be in debug mode? (1-yes, 0-no): ";
	cin >> trueFalse;
	cin.ignore();
	cout << endl;
	while (trueFalse != 1 && trueFalse != 0) //using a while loop to ensure that the correct integer is given.and if it's not then continue prompting until it is
	{
		cout << "\nSorry, that is not a valid input." << endl;
		cout << "Do you want to to be in debug mode? (1-yes, 0-no): ";
		cin >> trueFalse;
		cin.ignore();
	}
	if(trueFalse == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
	
	
}