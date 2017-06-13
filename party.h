#ifndef PARTY_H
#define PARTY_H

#include <iostream>
#include <string>
using namespace std;

struct party
{
	string name;
	long numvotes;
	int numseats;
	double percent;
	party() { numvotes = numseats = percent = 0; }
	party(string _name, long _numvotes) { name = _name; numvotes = _numvotes; }
	bool operator>(const party& other) { return numvotes > other.numvotes; }
	bool operator<(const party& other) { return numvotes < other.numvotes; }
	bool operator==(const party& other) { return numvotes == other.numvotes; }
	bool operator!=(const party& other) { return numvotes != other.numvotes; }
	friend ostream& operator<<(ostream& s, const party& other)
	{
		s << "Name: " << other.name 
		  << "\tVotes: " << other.numvotes
		  << "\tPercent: " << other.percent
		  << "\tSeats: " << other.numseats;
		return s;
	}
};

#endif
