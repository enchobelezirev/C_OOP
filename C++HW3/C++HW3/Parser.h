#pragma once
#include <string>
#include <list>
#include "Query.h"
#include "EnterQuery.h"
#include "StringQuery.h"

using namespace std;
class Parser
{
protected:
	string input;
	string consumeFirstArgument(list<string>& args);
	list<string> split(char delimiter);
	void removeFromArgList(list<string>& list);
public:
	Parser();
	Parser(string input);
	~Parser();
	Query* parseStringQuery();
	vector<string> parseNamesList();
};

