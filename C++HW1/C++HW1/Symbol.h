#pragma once
#include "SymbolType.h"
#include <string>

class Symbol {
private:
	std::string value;
	SymbolType type;

public:
	Symbol();
	Symbol(std::string, SymbolType);
	SymbolType getType() const;
	std::string getValue() const;

};
