all: runMovies tests

runMovies: main.cpp movies.cpp
	g++ -std=c++11 -o runMovies main.cpp movies.cpp

tests: tests.cpp movies.cpp
	g++ -std=c++11 -o tests tests.cpp movies.cpp