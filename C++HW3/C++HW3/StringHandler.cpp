#include "StringHandler.h"
#include "QueryStringParser.h"
StringHandler::StringHandler()
{
	range.rangeStart = 0;
	range.rangeEnd = 0;
}

StringHandler::StringHandler(list<string> names)
{
	this->names = names;
	range.rangeEnd = names.size() - 1;
}


StringHandler::~StringHandler()
{
}

void StringHandler::executeQuery(string queryString)
{
	Query* q = QueryStringParser(queryString).parse();
	q->execute(*this);
}

void StringHandler::setRange(int start, int end)
{
	this->range.rangeStart = start;
	this->range.rangeEnd = end;
}

Range StringHandler::getRage()
{
	return range;
}

list<string> StringHandler::getNames() const
{
	return names;
}
