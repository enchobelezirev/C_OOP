#include "Parser.h"

string Parser::consumeFirstArgument(list<string>& args)
{
	string firstArg = args.front();
	args.pop_front();
	return firstArg;
}

list<string> Parser::split(char delimiter)
{
	list<string> args;
	/*int start = 0;
	int delimiterPos = input.find(delimiter);
	while (delimiterPos != -1)
	{
		args.push_back(input.substr(start, delimiterPos));
		start = ++delimiterPos;
		delimiterPos = input.find(delimiter, delimiterPos);
	}
	args.push_back(input.substr(start, input.length()));*/

	string name;
	int delimiterPos = input.find(delimiter);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i != delimiterPos)
		{
			name += input[i];
		}
		else {
			args.push_back(name);
			name = string();
			delimiterPos++;
			delimiterPos = input.find(delimiter, delimiterPos);
		}
	}
	args.push_back(name);
	return args;
}

void Parser::removeFromArgList(list<string>& list)
{
	try {
		list.pop_front();
	}
	catch (std::exception& e) {
		throw exception("Insuficient number of arguments!");
	}
}

Parser::Parser()
{
	input = nullptr;
}

Parser::Parser(string input)
{
	this->input = input;
}

Parser::~Parser()
{
}

Query* Parser::parseStringQuery()
{
	list<string> queryArgs = split(' ');
	string queryName = consumeFirstArgument(queryArgs);
	if (queryName == "ENTER")
	{
		string startRange = queryArgs.front();
		removeFromArgList(queryArgs);
		string endRange = queryArgs.front();
		removeFromArgList(queryArgs);
		if (queryArgs.size() > 0)
		{
			throw exception("Too many arguments for query ENTER!");
		}
		return new EnterQuery(stoi(startRange), stoi(endRange));
	}
	else if (queryName == "QUERY") {
		string str = queryArgs.front();
		removeFromArgList(queryArgs);
		if (queryArgs.size() > 0)
		{
			throw exception("Too many arguments for query QUERY!");
		}
		return new StringQuery(str);
	}
	throw exception("Unsupported query type!");
}

vector<string> Parser::parseNamesList()
{
	list<string> namesList = split(' ');
	vector<string> v(begin(namesList), end(namesList));
	return v;
}
