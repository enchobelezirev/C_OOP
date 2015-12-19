#include "EnterQuery.h"
EnterQuery::EnterQuery()
{
}

EnterQuery::EnterQuery(int a, int b)
{
	this->start = a;
	this->end = b;
}

EnterQuery::~EnterQuery()
{
}

void EnterQuery::execute(StringHandler& handler)
{
	if (start < 0 || start > end || end > handler.getNames().size())
	{
		throw exception("The range is not valid!");
	}
	handler.setRange(start, end);
}
