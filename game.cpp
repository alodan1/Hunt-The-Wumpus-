#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "pool.h"
#include "wumpus.h"
#include "exit.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


//Game Implementation

Game::Game(){
	//Game constructor
	 

	
}


Game::~Game(){
	for(int i =0; i<side; i++)
	{
		for(int j=0; j<side; j++)
		{
			if(cave[i][j].is_not_empty())
			{
				delete cave[i][j].get_e();
				cave[i][j].set_event(NULL); //if the cave is not empty delete the cave and set it to NULL
			}
		}
	}
	
	
}


void Game::set_up(int s){
	//set up the game
	this->side = s;

	this->num_arrows = 3; 	//start with 3 arrows
	this->oxygen = 2*s; //start with 2*sides amount of oxygen
	// Finish the remaining...
	 
	vector <Room> r;
	Room r1;
	// Create the game board: 2D vector of Room objects
	for(int i = 0; i < s; i++)
	{
		r.push_back(r1);
		
	}
	for(int i = 0; i < s; i++)
	{
		this->cave.push_back(r);
		
	}
	
	// randomly insert events (2 pool accesses, 2 stalactites, 1 wumpus, 1 gold)
	// into the board
	 // Place two pool accesses
    place_events(2, "Pool");

    // Place two stalactites
    place_events(2, "Stalactites" );

    // Place one wumpus
    place_events(1, "Wumpus");

    // Place one gold
    place_events(1, "Gold");

	//initialize the player's start position
	Game::player_start_pos();
	

}

void Game::place_events(int num, string class_used){
    for(int i = 0; i < num; i++) {
        int x, y;
        do {
            x = rand() % this->side; //random x
            y = rand() % this->side; //random y
        } while (this->cave[x][y].is_not_empty());
		if(class_used == "Stalactites"){
        	this->cave[x][y].set_event(new Stalactites); 
		} else if(class_used == "Pool"){
        	this->cave[x][y].set_event(new Pool);
		}else if(class_used == "Wumpus"){
        	this->cave[x][y].set_event(new Wumpus);
			this->cave[x][y].set_dead_or_alive(true);
		}else if(class_used == "Gold"){
			this->cave[x][y].set_win(false);
        	this->cave[x][y].set_event(new Gold);
		}

    }
}

void Game::display_game() const{
	cout << endl << endl;
	//print the arrows
	cout << "Arrows remaining: " << this->num_arrows << endl;

	//print oxygen level:
	cout << "Oxygen remaining: " << this->oxygen << endl;
	string line = "";
	for (int i = 0; i < this->side; ++i)
		line += "-----";

	for (int i = 0; i < this->side; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->side; ++j)
		{
			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " "

			if (this->cave[i][j].get_has_player()) {
                cout << "*";
            } else {
                cout << " ";
            }
			
			if (this->cave[i][j].is_not_empty()) {
                if (this->debug_view) {
                    this->cave[i][j].get_e()->print_symbol();
					cout << " |";
                } else {
                    cout << "  |";
                }
            } else {
                cout << "  |";
            }
            cout << "|";
		}
		cout << endl;
	}
	cout << line << endl;

	//example output (when finished): 
	// --------------------
	//  P || G || P ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------
}

bool Game::check_win() const{
	//check if game over/win
	
		
	
	if((cave[player_x][player_y].get_has_player())==false)
	{
		
		return true; //if the cave does not have the player end the game
	}
	else if (cave[player_x][player_y].get_symbol() == "R" && this->won==true ){
		cout << "Congrats you won!!" << endl; //if the player has won end the game
		return true;
	}
	return false; //if the player has yet to win continue the game

	
}

void Game::death()
{		
	int kill = rand()&2;
	if(cave[player_x][player_y].get_symbol() == "S" && this->underwater == false)
	{
		if(kill == 0)
		{
			cave[player_x][player_y].set_has_player(false);
			cout << "\nyou've been killed by falling stalectites" << "\nGame Over!"; //if they die to stalectites set has_player to false
		} else
		{
			cave[player_x][player_y].set_has_player(true); //else nothing happens
		}
	}
	if(cave[player_x][player_y].get_symbol() == "W" && this->underwater == false)
	{
		cave[player_x][player_y].set_has_player(false);
		cout << "\nyou've been killed by the wumpus" << "\nGame Over!!"; //if they die to the wumpus set has_player to false
	}
	if(this->oxygen == 0 && this->underwater == true)
	{
		cave[player_x][player_y].set_has_player(false);
		cout << "\nyou've been killed by running out of oxygen" << "\nGame Over!!"; //if they die from running out of oxygen set has_player to false
	}
}

void Game::win_condition()
{
	if(cave[player_x][player_y].get_symbol() == "G" && this->underwater == false) //let the player pick up the gold if they are in the gold room
	{
		cout << "\nYou have picked up the gold\n";
		this->cave[player_x][player_y].set_win(true);
		delete cave[player_x][player_y].get_e();
		cave[player_x][player_y].set_event(NULL);
		this->won = true;
	}
}

void Game::move_up() {
	//move player up
	 
	// Move the player up
    if (player_x > 0) {
        // Clear current position
        cave[player_x][player_y].set_has_player(false);
        // Update player's y-coordinate
        player_x--;
        // Update new position
        cave[player_x][player_y].set_has_player(true);
		
	
        
    } else {
        cout << "Cannot move up. Reached the top edge of the cave!" << endl; 
    }
		
	Game::room_checker(); //prints the percepts

	if(this->underwater)
	{
		this->oxygen--; //if they are underwater decrease the amount of oxygen by one each turn
	}
}



void Game::move_down() {
	//move player down
	

	if (player_x < side-1) {
        // Clear current position
        cave[player_x][player_y].set_has_player(false);
        // Update player's y-coordinate
        player_x++;
        // Update new position
        cave[player_x][player_y].set_has_player(true);
        // // Display the updated game board
        // display_game();
    } else {
        cout << "Cannot move up. Reached the top edge of the cave!" << endl;
    }
	Game::room_checker(); //prints the percepts

	if(this->underwater)
	{
		this->oxygen--; //if they are underwater decrease the amount of oxygen by one each turn
	}
	}
	

void Game::move_left() {
	//move player left
	 

	    if (player_y > 0) {
        // Clear current position
        cave[player_x][player_y].set_has_player(false);
        // Update player's y-coordinate
        player_y--;
        // Update new position
        cave[player_x][player_y].set_has_player(true);
        // // Display the updated game board
        // display_game();
    } else {
        cout << "Cannot move up. Reached the top edge of the cave!" << endl;
    }

	Game::room_checker();//prints the percepts

	if(this->underwater)
	{
		this->oxygen--; //if they are underwater decrease the amount of oxygen by one each turn
	}

}

void Game::move_right() {
	//move player right
	 

	if (player_y < side-1) {
        // Clear current position
        cave[player_x][player_y].set_has_player(false);
        // Update player's y-coordinate
        player_y++;
        // Update new position
        cave[player_x][player_y].set_has_player(true);
        // // Display the updated game board
        // display_game();
    } else {
        cout << "Cannot move up. Reached the top edge of the cave!" << endl;
    }
	Game::room_checker(); //prints the percepts

	if(this->underwater)
	{
		this->oxygen--; //if they are underwater decrease the amount of oxygen by one each turn
	}
}



void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room
	int move = rand()%4;
    // Check if the wumpus should move (75% chance)
    if (move != 0) {
        for(int i=0; i<this->side; i++)
		{
			for(int j=0; j<this->side; j++)
			{	
				if(cave[i][j].get_symbol()=="W") //if the shot missed 75% chance the wumpus moves to a random spot
				{
					cave[i][j].set_dead_or_alive(false);
					place_events(1, "Wumpus");
				}
			}
		}
    }
	else
	{
		cave[player_x][player_y].set_has_player(false); //if the player gets unlucky and misses the wumpus they die
		cout << "\nyou've been killed by the wumpus" << "\nGame Over!!";
	}
}

void Game::diving()
{
	char yes_or_no;
	if(cave[player_x][player_y].get_symbol() == "P") //if they are in the pool automatically make them underwater if they go to the pool again auto exit them
	{
		if(this->underwater == false)
		{
			this->underwater = true;
			cout << "\nyou are now underwater\n";
		}else 
		{
			this->underwater = false;
			this->oxygen = 2*this->side;
			cout << "\n You exited the pool\n";
		}
			
	}
}
void Game::fire_arrow(){
	// The player may fire arrow...
if(num_arrows>0)
{
	char dir;
	do{
		dir = get_dir();
	}while(dir != 'w' && dir != 'a' && dir != 's' && dir != 'd' && dir != 'f' ); //continue propmting until they choose a correct char value
	 
	
	//shoot in the direction they chose up to three spots
	if(dir == 'w')
	{
		Game::shot_up(); 
	} else if(dir == 's')
	{
		Game::shot_down();
	} else if(dir == 'd')
	{
		Game::shot_right();
	} else if(dir == 'a')
	{
		Game::shot_left();
	}

	//remove one arrow after each shot
	this->num_arrows--;
	
}else
	{
		cout << "\nYou have no more arrows to shoot\n"; //if the player runs out of arrows
	}
}


void Game::shot_up() //w
{
	if(player_x-1 < side && player_x-1>0 && cave[player_x-1][player_y].get_symbol()=="W")
	{
		cave[player_x-1][player_y].set_dead_or_alive(false);
		delete cave[player_x-1][player_y].get_e();
		cave[player_x-1][player_y].set_event(NULL);
	} else if(player_x-2 < side && player_x-2>0 && cave[player_x-2][player_y].get_symbol()=="W")
	{
		cave[player_x-2][player_y].set_dead_or_alive(false);
		delete cave[player_x-2][player_y].get_e();
		cave[player_x-2][player_y].set_event(NULL);
	}else if(player_x-3 < side && player_x-3>0 && cave[player_x-3][player_y].get_symbol()=="W")
	{
		cave[player_x-3][player_y].set_dead_or_alive(false);
		delete cave[player_x-3][player_y].get_e();
		cave[player_x-3][player_y].set_event(NULL);
	}else {
		Game::wumpus_move();
		cout << "\nshot missed\n";
	}
}
void Game::shot_down(){ //s
	if(player_x+1 < side && player_x+1>0 && cave[player_x+1][player_y].get_symbol()=="W")
	{
		cave[player_x+1][player_y].set_dead_or_alive(false);
		delete cave[player_x+1][player_y].get_e();
		cave[player_x+1][player_y].set_event(NULL);
		

	} else if(player_x+2 < side && player_x+2>0 && cave[player_x+2][player_y].get_symbol()=="W")
	{
		cave[player_x+2][player_y].set_dead_or_alive(false);
		delete cave[player_x+2][player_y].get_e();
		cave[player_x+2][player_y].set_event(NULL);
	}else if(player_x+3 < side && player_x+3>0 && cave[player_x+3][player_y].get_symbol()=="W")
	{
		cave[player_x+3][player_y].set_dead_or_alive(false);
		delete cave[player_x+3][player_y].get_e();
		cave[player_x+3][player_y].set_event(NULL);
	}else {
		Game::wumpus_move();
		cout << "\nshot missed\n";
	}
}
void Game::shot_left() //a
{
	if(player_y-1>0 && player_y-1 < side && cave[player_x][player_y-1].get_symbol()=="W")
	{
		cave[player_x][player_y-1].set_dead_or_alive(false);
		delete cave[player_x][player_y-1].get_e();
		cave[player_x][player_y-1].set_event(NULL);
	} else if(player_y-2>0 && player_y-2 < side && cave[player_x][player_y-2].get_symbol()=="W")
	{
		cave[player_x][player_y-2].set_dead_or_alive(false);
		delete cave[player_x][player_y-2].get_e();
		cave[player_x][player_y-2].set_event(NULL);
	}else if(player_y-3>0 && player_y-3 < side && cave[player_x][player_y-3].get_symbol()=="W")
	{
		cave[player_x][player_y-3].set_dead_or_alive(false);
		delete cave[player_x][player_y-3].get_e();
		cave[player_x][player_y-3].set_event(NULL);
	}else {
		Game::wumpus_move();
		cout << "\nshot missed\n";
	}
} 
void Game::shot_right() //d
{
	if(player_y+1>0 && player_y+1 < side && cave[player_x][player_y+1].get_symbol()=="W")
	{
		cave[player_x][player_y+1].set_dead_or_alive(false);
		delete cave[player_x][player_y+1].get_e();
		cave[player_x][player_y+1].set_event(NULL);
	} else if(player_y+2>0 && player_y+2 < side && cave[player_x][player_y+2].get_symbol()=="W" )
	{
		cave[player_x][player_y+2].set_dead_or_alive(false);
		delete cave[player_x][player_y+2].get_e();
		cave[player_x][player_y+2].set_event(NULL);
	}else if(player_y+3>0 && player_y+3 < side && cave[player_x][player_y+3].get_symbol()=="W" )
	{
		cave[player_x][player_y+3].set_dead_or_alive(false);
		delete cave[player_x][player_y+3].get_e();
		cave[player_x][player_y+3].set_event(NULL);
	}else {
		Game::wumpus_move();
		cout << "\nshot missed\n";
	}
}




void Game::play_game(int s, bool d){

	
	Game::set_up(s);
	this->debug_view = d;

	char input, arrow_input;

	while (Game::check_win() == false){
		//print game board
		Game::display_game();

		//display percerts around player's location
		 

		//Player move...
		//1. get input
		do 
		{
			input = Game::get_input();
		} while(input != 'f' && input != 'w' && input != 'a' && input != 's' && input != 'd');
		

		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		Game::diving(); //if the player is in the pool position make theem enter
		Game::win_condition(); //if the gets the gold and returns to the entrance
		Game::death();	//if the player dies
		 

	}
	
	
	return;

}
void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	
	if (c == 'f'){ //fire the arrow
		Game::fire_arrow();
		return;
	}
	
	switch(c){ //move however the player pleases
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
	}
}

char Game::get_input(){
	//get action, move direction or firing an arrow

	
	 
	char c;
		
	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');
	
	
	return c;
}
int Game::random_start_point_x() const {
    int x;
    if (side <= 0) {
        return 0; // Return a default value or handle the error appropriately
    }
    x = rand() % this->side; //returns a random start point for x
    return x;
}

int Game::random_start_point_y() const {
    int y;
    if (side <= 0) {
        return 0; // Return a default value or handle the error appropriately
    }
    y = rand() % this->side; //returns a random start point for y
    return y;
}

void Game::room_checker()
{
	if(player_x+1>=0 && player_y >= 0 && player_x+1 < side && player_y < side) //bootom room
	{
		if(cave[player_x + 1][player_y].is_not_empty())
		{
			this->cave[player_x + 1][player_y].print_percept();
		}
	}
	if(player_x-1>=0 && player_y >= 0 && player_x-1 < side && player_y < side) // top room
	{
		if(cave[player_x - 1][player_y].is_not_empty())
		{
			this->cave[player_x - 1][player_y].print_percept();
		}
	}
	if(player_x>=0 && player_y+1 >= 0 && player_x < side && player_y+1 < side) //right room
	{
		if(cave[player_x][player_y+1].is_not_empty())
		{
			this->cave[player_x][player_y+1].print_percept();
		}
	}
	if(player_x>=0 && player_y-1 >= 0 && player_x < side && player_y-1 < side) //left room
	{
		if(cave[player_x][player_y-1].is_not_empty())
		{
			this->cave[player_x][player_y-1].print_percept();
		}
	}
	
}

void Game::player_start_pos()
{
	// Set player's initial position
	
    do {
        this->player_x = random_start_point_x(); //returns a random start point for x
        this->player_y = random_start_point_y(); //returns a random start point for y
    } while (this->cave[player_x][player_y].is_not_empty()); //continue until an empty location is chosen
    
    // Set player's position using the obtained coordinates
    this->cave[player_x][player_y].set_has_player(true); //set that the location has the player
	this->cave[player_x][player_y].set_event(new Rope); // place the rop in the start location of the player
	Game::room_checker(); //prints the percepts at the start

}
bool Game::is_valid_position(int x, int y) const {
    return x >= 0 && x < side && y >= 0 && y < side; //checks if the location is valid in the map
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;

	 
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');
	
	return dir;
}

