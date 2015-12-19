#pragma once

#include <list>
#include <string>


using namespace std;
struct Range{
	int rangeStart;
	int rangeEnd;
};
class StringHandler
{
private:
	Range range;
	list<string> names;
public:
	StringHandler();
	StringHandler(list<string> names);
	~StringHandler();
	void executeQuery(string queryString);
	void setRange(int start, int end);
	Range getRage();
	list<string> getNames() const;
};

