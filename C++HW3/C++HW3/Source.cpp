#include <iostream>
#include <string>
#include <list>
#include "StringHandler.h"
using namespace std;

int main() {

	int testTries = 0, namesCount = 0, queriesCount = 0;
	cin >> testTries;
	for (size_t i = 0; i < testTries; i++)
	{
		cin >> namesCount >> queriesCount;
		list<string> names;
		cin.ignore();
		for (size_t j = 0; j < namesCount; j++)
		{
			string name;
			getline(cin, name);
			names.push_back(name);
		}
		StringHandler handler(names);
		for (size_t j = 0; j < queriesCount; j++)
		{
			string query;
			getline(cin, query);
			handler.executeQuery(query);
		}
	}
	system("PAUSE");
	return 0;
}