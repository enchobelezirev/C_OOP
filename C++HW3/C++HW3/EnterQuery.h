#pragma once
#include "Query.h"
class EnterQuery : public Query
{
private :
	int start, end;
public:
	EnterQuery();
	EnterQuery(int, int);
	~EnterQuery();
	void execute(StringHandler&);
};

