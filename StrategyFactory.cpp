#include "StrategyFactory.h"

shared_ptr<StrategyBase> StrategyFacory::getStrategy(string _strategy)
{
	shared_ptr<StrategyBase> retval;
	for(auto i=0; i< _strategy.length(); i++)
	{
		auto c = _strategy[i];
		c = toupper(c);
		_strategy[i] = c;
	}

	if (_strategy == "CIRCPROP")
		retval.reset(new CircProp);
	else
		retval.reset(new Nothing);
	
	return retval;
}
