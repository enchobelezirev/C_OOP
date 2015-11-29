#pragma once
#include <string>
#include <stack>
#include "Symbol.h"

using namespace std;

class StringParserer {
private:
	string inputString;
	string decompress(stack<Symbol>);
	Symbol getSymbolType(char);
	void validate(Symbol);
	string multiply(int, string);
public:
	StringParserer();
	StringParserer(string);
	string parse();
};
