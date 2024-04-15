# Hunt-The-Wumpus-

Description:

Welcome to hunt the wumpus!! You can move though the map to find the gold then leave in order to win.
However be careful since you could die if you hit the room with the wumpus, and have a 50% of death if you hit a room with a stalectite.
To help avoid this you've been equiped with 3 arrows that can shoot and kill the wumpus. (you find out where the wumpus is based on the percepts)
But beware if you miss your shot the wumpus has a 75% chance of moving (it could even be where you stand) and a 25% chance of killing you.
Know this, you can enter a pool to go underwater. You may ask why this is such a great thing, it's because percepts will still be printed and you can't die,
so as long as you're underwater you can find where the gold is while avoiding death. Beware you can drown if you run out of oxygen.


Instructions:

3a) Compile the program with

the make command

3b) Run the program with

./wumpus

3c) You start the game in a random room within the cave. 
Your goal is to guide the adventurer through the cave to find the gold and make it back to the escape rope unharmed. 

You have the following actions to choose from:
Move: Navigate through the cave by typing "w" (up), "a" (left), "s" (down), or "d" (right).
Fire an Arrow: Eliminate the Wumpus by typing "f" followed by a direction ("w", "a", "s", or "d").
The cave layout is displayed eah turn while nearby events are hideen. Pay attention to percepts to avoid hazards and locate the gold.

The adventurer's stats are displayed before each turn:

Oxygen Level: 2 *side (the side being the length of your choice)
Arrows Remaining: 3 (each shot will remove an arrow)

The game ends under the following conditions:
The adventurer is eaten by the Wumpus.
The adventurer runs out of oxygen.
The adventurer dies to falling stalectites
The adventurer successfully collects the gold and reaches the escape rope.
