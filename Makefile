output: Main.o Critter.o
	g++ -std=c++11 Main.o Critter.o -o run

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

Critter.o: Critter.cpp
	g++ -std=c++11  -c Critter.cpp

clean: 
	rm *.o run
