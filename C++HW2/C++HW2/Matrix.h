#pragma once
#include "Cell.h"
#include <list>
#include <set>
#include <queue>

class Matrix
{
private:
	struct StringLengthComparator {
		bool operator () (const std::string & firstString, const std::string& secondString) {
			const size_t firstStringLength = firstString.length();
			const size_t secondStringLength = secondString.length();

			if (firstStringLength == secondStringLength)
			{
				return (firstString < secondString);
			}
			return (firstStringLength < secondStringLength);
		}
	};

private:
	int rows, cols;
	Cell** matrix;
	Cell startCell;

private:
	std::list<Cell> availableCells;
	std::set<std::string, StringLengthComparator> routes;

private:
	void findRoutes(int startPointX, int startPointY, int endPointX, int endPointY, std::string);
	void initCells();
	bool isCellPassable(int, int);
	void assertCell(int, int, std::queue<Cell>&);
public:
	Matrix();
	Matrix(int rows, int cols);
	~Matrix();
	void addCell(int x, int y, char cellType);
	void setStartCell(int x, int y);
	void findRoutesForAvailableCells();
	Cell getStartCell() const;
	std::list<Cell> findAvailableCells();
};

