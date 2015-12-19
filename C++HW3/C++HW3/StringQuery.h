#pragma once
#include "Query.h"
#include <string>
#include <iostream>

using namespace std;
class StringQuery : public Query
{
private:
	string str;
public:
	StringQuery();
	StringQuery(string str);
	~StringQuery();
	void execute(StringHandler&);
};

