#include "EnterQuery.h"
EnterQuery::EnterQuery()
{
	start = 0;
	end = 0;
}

EnterQuery::EnterQuery(int a, int b)
{
	this->start = a;
	this->end = b;
}

EnterQuery::~EnterQuery()
{
	start = end = 0;
}

void EnterQuery::execute(StringHandler& handler)
{
	if (start < 0 || start > end || end >= handler.getNames().size())
	{
		throw exception("The range is not valid!");
	}
	handler.setRange(start, end);
}
