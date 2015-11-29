#include "Cell.h"

Cell::Cell()
{
	this->p.x = 0;
	this->p.y = 0;
}

Cell::~Cell()
{
	this->p.x = 0;
	this->p.y = 0;
}

Cell::Cell(Cell const & other) {
	copyFromOther(other);
}

Cell& Cell::operator=(Cell const & other) {
	if (&other != this)
	{
		copyFromOther(other);
	}
	return *this;
}

void Cell::copyFromOther(Cell const & other) {
	this->available = other.available;
	this->found = other.found;
	this->p.x = other.p.x;
	this->p.y = other.p.y;
}

Cell::Cell(int x, int y, char cellType) {
	p = Point(x, y);
	available = cellType == '#' ? false : (cellType == '.') ? true : throw std::exception("The symbol is not supported");
}

bool Cell::isAvailable() const {
	return available;
}

int Cell::getX() const {
	return p.x;
}
int Cell::getY() const {
	return p.y;
}
bool Cell::isFound() const {
	return found;
}

void Cell::isFound(bool value) {
	found = value;
}
std::string Cell::print() const {
	return "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
}
