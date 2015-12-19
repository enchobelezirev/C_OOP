#include "QueryStringParser.h"
#include "StringQuery.h"
#include "EnterQuery.h"
string QueryStringParser::consumeFirstArgument(list<string>& args)
{
	string firstArg = args.front();
	args.pop_front();
	return firstArg;
}

list<string> QueryStringParser::split(char delimiter)
{
	list<string> args;
	int start = 0;
	int delimiterPos = queryString.find(delimiter);
	while (delimiterPos != -1)
	{
		args.push_back(queryString.substr(start, delimiterPos));
		start = ++delimiterPos;
		delimiterPos = queryString.find(delimiter, delimiterPos);
	}
	args.push_back(queryString.substr(start, queryString.length()));
	return args;
}

void QueryStringParser::removeFromList(list<string>& list)
{
	try {
		list.pop_front();
	}
	catch (std::exception& e) {
		throw exception("Insuficient number of arguments!");
	}
}

QueryStringParser::QueryStringParser()
{
}

QueryStringParser::QueryStringParser(string queryString)
{
	this->queryString = queryString;
}


QueryStringParser::~QueryStringParser()
{
}

Query* QueryStringParser::parse()
{
	list<string> queryArgs = split(' ');
	string queryName = consumeFirstArgument(queryArgs);
	if (queryName == "ENTER")
	{
		string startRange = queryArgs.front();
		removeFromList(queryArgs);
		string endRange = queryArgs.front();
		removeFromList(queryArgs);
		if (queryArgs.size() > 0)
		{
			throw exception("Too many arguments for query ENTER!");
		}
		return new EnterQuery(stoi(startRange), stoi(endRange));
	}
	else if (queryName == "QUERY") {
		string str = queryArgs.front();
		removeFromList(queryArgs);
		if (queryArgs.size() > 0)
		{
			throw exception("Too many arguments for query QUERY!");
		}
		return new StringQuery(str);
	}
	throw exception("Unsupported query type!");
}
