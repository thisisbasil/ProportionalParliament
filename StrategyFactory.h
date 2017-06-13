#ifndef STRATEGYFACTORY_H
#define STRATEGYFACTORY_H

#include "circprop.h"
#include "strategy.h"
#include <algorithm>
#include <cctype>
class StrategyFacory
{
public:
	StrategyBase* getStrategy(string);
};

#endif