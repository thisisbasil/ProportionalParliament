#ifndef STRATEGY_H
#define STRATEGY_H

#include "party.h"
#include <vector>
using namespace std;

class StrategyBase
{
protected:
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
};



#endif
