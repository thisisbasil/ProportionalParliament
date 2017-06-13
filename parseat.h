#ifndef PARSEAT_H
#define PARSEAT_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <algorithm>
#include "party.h"
#include "strategy.h"
using namespace std;

class parseat
{
private:
	double threashold;
	vector<party> parties;
	int numseats;
	StrategyBase* strategy;

public:
	parseat(double);
	parseat(int);
	parseat(double, int);
	parseat();

	void add(string,long);
	void clear();
	void printResults();

	void setNumSeats(int);
	int getNumSeats();
	double getThreashold();
	void setThreashold(double);
	bool setStrategy(StrategyBase*);
	void runModel();
	int getNumParties() { return parties.size(); }
};

#endif
