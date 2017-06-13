#ifndef STRATEGY_H
#define STRATEGY_H

#include "party.h"
#include <vector>
#include <string>
using namespace std;

class StrategyBase
{
protected:
	string name;
	double threashold;
	long totalvotes;
	int numseats;
	vector<party> parties;

public:
	virtual vector<party> run() = 0;
	vector<party> getResults();
	void setThreashold(double);
	void setParties(vector<party>);
	void setNumSeats(int);
	string getName();
};

class Nothing : public StrategyBase
{
public:
		Nothing() { name = "nothing"; }
		vector<party> run() { cout << "No such strategy!" << endl; return parties; }
};

#endif
