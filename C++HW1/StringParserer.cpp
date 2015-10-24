#include "StringParserer.h"
#include "SymbolType.h"
#include <iostream>


StringParserer::StringParserer() {
	inputString = string();
}

StringParserer::StringParserer(string inputString) {
	this->inputString = inputString;
}

string StringParserer::decompress(stack<Symbol> parsedString) {
	string resultString;
	while (!parsedString.empty())
	{
		Symbol current = parsedString.top();
		parsedString.pop();
		switch (current.getType())
		{
		case STRING: {
			resultString += current.getValue();
		}break;
		case NUMBER: {
			int numberValue = atoi(current.getValue().c_str());
			resultString = multiply(numberValue, resultString);
		}break;
		}
	}
	return resultString;
}

string StringParserer::parse() {
	if (inputString.empty())
	{
		throw exception("The input string is empty!");
	}

	string tempString;
	stack<Symbol> parsedString;
	for (string::iterator stringIt = inputString.begin(); stringIt < inputString.end(); ++stringIt)
	{
		char current = *stringIt;
		if (current == '(' || current == ')')
		{
			continue;
		}

		Symbol currentSymbol = getSymbolType(current);
		validate(currentSymbol);
		/*tempString = currentSymbol.getValue();
		while (*stringIt != ')' || *stringIt != '(')
		{
		stringIt++;
		Symbol nextSymbol = getSymbolType(*stringIt);
		if (currentSymbol.getType() == STRING)
		{
		tempString += nextSymbol.getValue();
		}
		else {
		break;
		}
		}
		stringIt--;
		*/
		parsedString.push(currentSymbol);
	}
	return decompress(parsedString);
}

void StringParserer::validate(Symbol symbol)
{
	if (symbol.getType() == 2)
	{
		throw exception("Unsupported symbol!");
	}
}

Symbol StringParserer::getSymbolType(char symbol) {
	if (symbol >= 49 && symbol <= 57)
	{
		return Symbol(string(1, symbol), NUMBER);
	}

	if (symbol >= 65 && symbol <= 90)
	{
		return Symbol(string(1, symbol), STRING);
	}

	return Symbol(string(1, '\0'), NOT_DEF);;
}

string StringParserer::multiply(int times, string text) {
	string result;
	for (size_t i = 0; i < times; i++)
	{
		result += text;
	}
	return result;
}