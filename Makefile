all: parseat

parseat: parseat.cpp
	g++ parseat.cpp -std=c++11 -o parseat

clear:
	rm parseat
