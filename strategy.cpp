#include "strategy.h"

vector<party> StrategyBase::getResults() 
{ 
	return parties; 
}

void StrategyBase::setThreashold(double _threashold) 
{ 
	threashold = _threashold; 
}

void StrategyBase::setParties(vector<party> _parties) 
{ 
	parties = _parties; 
}

void StrategyBase::setNumSeats(int _numseats) 
{ 
	numseats = _numseats; 
}
