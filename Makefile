output: Main.o Critter.o Ant.o Doodlebug.o validate.o
	g++ -std=c++11 Main.o Critter.o Ant.o Doodlebug.o validate.o -o run

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

Critter.o: Critter.cpp
	g++ -std=c++11 -c Critter.cpp

Ant.o: Ant.cpp
	g++ -std=c++11  -c Ant.cpp

Doodlebug.o: Doodlebug.cpp
	g++ -std=c++11 -c Doodlebug.cpp

validate.o: validate.cpp
	g++ -std=c++11 -c validate.cpp

clean: 
	rm *.o run
