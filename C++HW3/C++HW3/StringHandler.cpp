#include "StringHandler.h"
#include "Parser.h"
StringHandler::StringHandler()
{
	range.rangeStart = 0;
	range.rangeEnd = 0;
}

StringHandler::StringHandler(vector<string> names)
{
	this->names = names;
	range.rangeEnd = names.size() - 1;
}


StringHandler::~StringHandler()
{
}

void StringHandler::executeQuery(string queryString)
{
	Parser p(queryString);
	Query* q = p.parseStringQuery();
	q->execute(*this);
	delete q;
}

void StringHandler::setRange(int start, int end)
{
	this->range.rangeStart = start;
	this->range.rangeEnd = end;
}

Range StringHandler::getRage() const
{
	return range;
}

vector<string> StringHandler::getNames() const
{
	return names;
}
