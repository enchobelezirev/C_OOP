#include "StringQuery.h"



StringQuery::StringQuery()
{
}

StringQuery::StringQuery(string str)
{
	this->str = str;
}


StringQuery::~StringQuery()
{
}

void StringQuery::execute(StringHandler& handler)
{
	int matchedWords = 0;
	list<string> names = handler.getNames();
	for (list<string>::iterator stringIt = names.begin(); stringIt != names.end(); stringIt++)
	{
		string name = *stringIt;
		if (name.substr(0, str.size()) == str)
		{
			matchedWords++;
		}
	}
	cout << matchedWords << endl;
}
