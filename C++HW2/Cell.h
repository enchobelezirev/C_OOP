#pragma once
#include <iostream>
#include <string>
struct  Point
{
	int x, y;
	Point() {

	}
	Point(int x, int y) : x(x), y(y) {
	}
};
class Cell
{
private:
	Point p;
	bool available;
	bool found = false;
	void copyFromOther(Cell const &);
public:
	Cell();
	Cell(int x, int y, char cellType);
	Cell(Cell const &);
	Cell& operator=( Cell const&);
	~Cell();
	bool isAvailable() const;
	int getX() const;
	int getY() const;
	bool isFound() const;
	void isFound(bool);
	std::string print() const;
};

