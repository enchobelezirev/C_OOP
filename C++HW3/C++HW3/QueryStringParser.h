#pragma once
#include<string>
#include <list>
#include "Query.h"

using namespace std;
class QueryStringParser
{
private:
	string queryString;
	string consumeFirstArgument(list<string>& args);
	list<string> split(char);
	void removeFromList(list<string>& list);
public:
	QueryStringParser();
	QueryStringParser(string queryString);
	~QueryStringParser();
	Query* parse();
};

