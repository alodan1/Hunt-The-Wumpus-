#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"


using namespace std;
//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	vector<vector<Room>> cave;
	//other member variables:
	int side; 				//side of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
    int player_x; // Player's x-coordinate
    int player_y; // Player's y-coordinate
	int oxygen;
	bool underwater;
	bool won = false;

	//feel free to add more variables...

public:


//suggested functions:











/****************************************************
 * Name: Game()
 * Description: Constructor for the Game class
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: A new Game object is created
 ****************************************************/
Game();

/****************************************************
 * Name: ~Game()
 * Description: Destructor for the Game class
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Resources associated with the Game object are deallocated
 ****************************************************/
~Game();



/****************************************************
 * Name: set_up()
 * Description: Set up the game board and initialize game parameters
 * Parameters: int s - Size of the game board
 * Pre-conditions: None
 * Post-conditions: The game board is initialized with events and the player's starting position is set
 ****************************************************/
void set_up(int);

/****************************************************
 * Name: place_events()
 * Description: Place events on the game board
 * Parameters: int num - Number of events to place, string class_used - Type of event to place
 * Pre-conditions: None
 * Post-conditions: The specified number of events of the specified type are randomly placed on the game board
 ****************************************************/
void place_events(int, string);

/****************************************************
 * Name: display_game() const
 * Description: Display the current state of the game board
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: The current state of the game board is printed to the console
 ****************************************************/
void display_game() const;

/****************************************************
 * Name: check_win() const
 * Description: Check if the game is won or over
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Returns true if the game is won or over, false otherwise
 ****************************************************/
bool check_win() const;

/****************************************************
 * Name: death()
 * Description: Handle player's death based on the current game state
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Player's death is handled appropriately based on the game state
 ****************************************************/
void death();

/****************************************************
 * Name: win_condition()
 * Description: Check if the win condition is met
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: If the win condition is met, appropriate actions are taken
 ****************************************************/
void win_condition();

/****************************************************
 * Name: move_up()
 * Description: Move the player character up on the game board
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Player character's position is updated accordingly
 ****************************************************/
void move_up();

/****************************************************
 * Name: move_down()
 * Description: Move the player character down on the game board
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Player character's position is updated accordingly
 ****************************************************/
void move_down();

/****************************************************
 * Name: move_left()
 * Description: Move the player character left on the game board
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Player character's position is updated accordingly
 ****************************************************/
void move_left();

/****************************************************
 * Name: move_right()
 * Description: Move the player character right on the game board
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Player character's position is updated accordingly
 ****************************************************/
void move_right();

/****************************************************
 * Name: wumpus_move()
 * Description: Move the wumpus character on the game board
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Wumpus character's position is updated accordingly
 ****************************************************/
void wumpus_move();

/****************************************************
 * Name: diving()
 * Description: Handle player diving action
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Player's diving action is handled accordingly
 ****************************************************/
void diving();

/****************************************************
 * Name: fire_arrow()
 * Description: Handle player's arrow firing action
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Player's arrow firing action is handled accordingly
 ****************************************************/
void fire_arrow();

/****************************************************
 * Name: shot_up()
 * Description: Handle arrow shot in the upward direction
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Arrow shot in the upward direction is handled accordingly
 ****************************************************/
void shot_up();

/****************************************************
 * Name: shot_down()
 * Description: Handle arrow shot in the downward direction
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Arrow shot in the downward direction is handled accordingly
 ****************************************************/
void shot_down();

/****************************************************
 * Name: shot_left()
 * Description: Handle arrow shot in the left direction
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Arrow shot in the left direction is handled accordingly
 ****************************************************/
void shot_left();

/****************************************************
 * Name: shot_right()
 * Description: Handle arrow shot in the right direction
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Arrow shot in the right direction is handled accordingly
 ****************************************************/
void shot_right();

/****************************************************
 * Name: play_game()
 * Description: Play the game
 * Parameters: int s - Size of the game board, bool d - Debug mode flag
 * Pre-conditions: None
 * Post-conditions: The game is played until it is won or over
 ****************************************************/
void play_game(int, bool);

/****************************************************
 * Name: move()
 * Description: Handle player's movement or arrow firing action
 * Parameters: char c - Input character representing the action
 * Pre-conditions: None
 * Post-conditions: Player's movement or arrow firing action is handled accordingly
 ****************************************************/
void move(char);

/****************************************************
 * Name: get_input()
 * Description: Get user input for player's action
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: User input for player's action is obtained and returned
 ****************************************************/
char get_input();

/****************************************************
 * Name: random_start_point_x() const
 * Description: Generate a random starting x-coordinate for the player
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: A random starting x-coordinate for the player is generated and returned
 ****************************************************/
int random_start_point_x() const;

/****************************************************
 * Name: random_start_point_y() const
 * Description: Generate a random starting y-coordinate for the player
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: A random starting y-coordinate for the player is generated and returned
 ****************************************************/
int random_start_point_y() const;

/****************************************************
 * Name: room_checker()
 * Description: Check the adjacent rooms for events and print percepts
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Percepts for adjacent rooms are printed based on the presence of events
 ****************************************************/
void room_checker();

/****************************************************
 * Name: player_start_pos()
 * Description: Set the player's initial position on the game board
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Player's initial position on the game board is set
 ****************************************************/
void player_start_pos();

/****************************************************
 * Name: is_valid_position(int x, int y) const
 * Description: Check if a given position is valid on the game board
 * Parameters: int x - x-coordinate, int y - y-coordinate
 * Pre-conditions: None
 * Post-conditions: Returns true if the position is valid, false otherwise
 ****************************************************/
bool is_valid_position(int x, int y) const;

/****************************************************
 * Name: get_dir()
 * Description: Get the direction for firing an arrow
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: User input for arrow direction is obtained and returned
 ****************************************************/
char get_dir();
};
#endif