#ifndef CIRCPROP_H
#define CIRCPROP_H

#include "strategy.h"
#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>
using namespace std;

class CircProp : public StrategyBase
{
private:
	void removeIrrelevantAndSort();
	void getSeats();
	void getTotalVotes();
	void getPercentages();
	
public:
		CircProp() { totalvotes = 0; name = "circprop"; }
		vector<party> run();
};

#endif