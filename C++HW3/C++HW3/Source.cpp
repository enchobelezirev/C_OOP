#include <iostream>
#include <string>
#include "Parser.h"
using namespace std;

int main() {

	int testTries = 0, namesCount = 0, queriesCount = 0;
	cin >> testTries;
	for (size_t i = 0; i < testTries; i++)
	{
		cin >> namesCount >> queriesCount;
		cin.ignore();
		
		string namesLine;
		getline(cin, namesLine);
		Parser p(namesLine);
		vector<string> names = p.parseNamesList();
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