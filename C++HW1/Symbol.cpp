#include "Symbol.h"

Symbol::Symbol() {
}
Symbol::Symbol(std::string value, SymbolType type) {
	this->value = value;
	this->type = type;
}
SymbolType Symbol::getType() const {
	return type;
}
std::string Symbol::getValue() const {
	return this->value;
}