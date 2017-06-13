#include "parseat.h"

parseat::parseat(double thr)
{
	threashold = thr;
	numseats = 0;
	strategy = nullptr;
}

parseat::parseat(int ns)
{ 
	threashold = 0.0009;
	numseats = ns;
	strategy = nullptr;
}

parseat::parseat()
{
	threashold = 0.0009;
	numseats = 0;
	strategy = nullptr;
}

void parseat::add(string name, long votes)
{
	party temp(name, votes);
	parties.push_back(temp);			
}

void parseat::clear()
{
	parties.clear();
}

void parseat::printResults()
{
	for(auto i : parties)
		cout << i << endl;
}

void parseat::setNumSeats(int _numseats)
{
	numseats = _numseats;
}

int parseat::getNumSeats()
{
	return numseats;
}

double parseat::getThreashold()
{
	return threashold;
}

void parseat::setThreashold(double _threashold)
{
	threashold = _threashold;
}

void parseat::setStrategy(StrategyBase* _strategy)
{
	strategy = _strategy;
	strategy->setThreashold(threashold);
	strategy->setParties(parties);
	strategy->setNumSeats(numseats);
}

void parseat::runModel()
{
		if (strategy == nullptr)
		{
				cout << "No strategy has been set!" << endl;
				return;
		}
		parties = strategy->run();	
}
