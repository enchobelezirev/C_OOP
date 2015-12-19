#pragma once
#include "StringHandler.h"
class Query
{
public:
	virtual void execute(StringHandler&) = 0;
};
