CC=g++ -std=c++11 -g
EXE=wumpus

$(EXE): main.cpp event.o game.o gold.o pool.o room.o stalactites.o wumpus.o exit.o
	$(CC) main.cpp event.o game.o gold.o pool.o room.o stalactites.o wumpus.o exit.o -o $(EXE)

event.o: event.cpp 
	$(CC) -c event.cpp 

game.o: game.cpp 
	$(CC) -c game.cpp 

gold.o: gold.cpp 
	$(CC) -c gold.cpp 

pool.o: pool.cpp 
	$(CC) -c pool.cpp

room.o: room.cpp 
	$(CC) -c room.cpp

stalactites.o: stalactites.cpp 
	$(CC) -c stalactites.cpp

wumpus.o: wumpus.cpp 
	$(CC) -c wumpus.cpp

exit.o: exit.cpp
	$(CC) -c exit.cpp

clean: 
	rm -f *.o $(EXE) *.gch

