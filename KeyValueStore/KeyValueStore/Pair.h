#pragma once
#include "MapNode.h"
template <typename E, typename R>
class Pair
{
public:
	E _1;
	R _2;
public:
	Pair(E item1, R item2) {
		_1 = item1;
		_2 = item2;
	}
};

