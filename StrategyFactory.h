#ifndef STRATEGYFACTORY_H
#define STRATEGYFACTORY_H

#include "circprop.h"
#include "strategy.h"
#include <algorithm>
#include <memory>
#include <cctype>
class StrategyFacory
{
public:
	shared_ptr<StrategyBase> getStrategy(string);
};

#endif