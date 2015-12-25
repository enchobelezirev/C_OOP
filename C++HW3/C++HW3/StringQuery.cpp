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
	vector<string> names = handler.getNames();
	for (size_t i = handler.getRage().rangeStart; i <= handler.getRage().rangeEnd; i++)
	{
		string currentName = names[i];
		if (currentName.substr(0,str.size()) == str)
		{
			matchedWords++;
		}
	}
	cout << matchedWords << endl;
}
