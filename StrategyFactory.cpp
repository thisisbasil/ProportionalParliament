#include "StrategyFactory.h"

StrategyBase* StrategyFacory::getStrategy(string _strategy)
{
	StrategyBase* retval;

	for(int i=0; i< _strategy.length(); i++)
	{
		char c = _strategy[i];
		c = toupper(c);
		_strategy[i] = c;
	}

	if (_strategy == "CIRCPROP")
		retval = new CircProp;
	else
		retval = new Nothing;
	
	return retval;
}