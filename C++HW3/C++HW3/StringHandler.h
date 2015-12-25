#pragma once

#include <vector>
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
	vector<string> names;
public:
	StringHandler();
	StringHandler(vector<string> names);
	~StringHandler();
	void executeQuery(string queryString);
	void setRange(int start, int end);
	Range getRage() const;
	vector<string> getNames() const;
};

