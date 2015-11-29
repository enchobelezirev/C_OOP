#include "Matrix.h"
#include <queue>


void Matrix::findRoutes(int startPointX, int startPointY, int endPointX, int endPointY, std::string route)
{
	if (isCellPassable(startPointX, startPointY))
	{
		Cell* current = &matrix[startPointX][startPointY];
		current->isFound(true);
		route += current->print();
		if (startPointX == endPointX && startPointY == endPointY)
		{
			routes.insert(route);
			current->isFound(false);
			return;
		}
		findRoutes(current->getX() - 1, current->getY(), endPointX, endPointY, route);
		findRoutes(current->getX(), current->getY() + 1, endPointX, endPointY, route);
		findRoutes(current->getX() + 1, current->getY(), endPointX, endPointY, route);
		findRoutes(current->getX(), current->getY() - 1, endPointX, endPointY, route);
		int index = route.find(current->print());
		if (index != std::string::npos)
		{
			route.erase(index, route.length());
			current->isFound(false);
		}
	}
}

Matrix::Matrix()
{
	rows = cols = 0;
	matrix = NULL;
}


Matrix::~Matrix()
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

Matrix::Matrix(int rows, int cols) {
	matrix = new Cell*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new Cell[cols];
	}
	this->rows = rows;
	this->cols = cols;
	initCells();
}

void Matrix::addCell(int x, int y, char cellType) {
	matrix[x][y] = Cell(x, y, cellType);
}

void Matrix::setStartCell(int x, int y) {
	startCell = matrix[x][y];
}

void Matrix::findRoutesForAvailableCells()
{
	while (!availableCells.empty())
	{
		Cell endCell = availableCells.front();
		std::string route;
		findRoutes(startCell.getX(), startCell.getY(), endCell.getX(), endCell.getY(), route);
		availableCells.pop_front();
		std::cout << endCell.print() << std::endl;
		for (std::set<std::string>::iterator it = routes.begin(); it != routes.end(); ++it)
		{
			std::cout << *it << std::endl;
		}
		routes.clear();
		initCells();
	}
}

std::list<Cell> Matrix::findAvailableCells()
{
	std::queue<Cell> movingPoints;
	movingPoints.push(startCell);
	int x = startCell.getX(), y = startCell.getY();
	matrix[x][y].isFound(true);
	while (!movingPoints.empty())
	{
		//search up
		assertCell(x - 1, y, movingPoints);

		//search left
		assertCell(x, y - 1, movingPoints);

		//search down
		assertCell(x + 1, y, movingPoints);
		
		// search right
		assertCell(x, y + 1, movingPoints);

		movingPoints.pop();
		if (!movingPoints.empty())
		{
			Cell nextCell = movingPoints.front();
			if (&nextCell)
			{
				x = nextCell.getX();
				y = nextCell.getY();
			}
		}
	}
	initCells();
	return availableCells;
}

void Matrix::assertCell(int cellX, int cellY, std::queue<Cell>& movingPoints) {
	if (isCellPassable(cellX, cellY))
	{
		Cell* cell = &matrix[cellX][cellY];
		availableCells.push_back(*cell);
		cell->isFound(true);
		movingPoints.push(*cell);
	}
}


bool Matrix::isCellPassable(int x, int y) {
	if (x < 0 || x >= rows)
	{
		return false;
	}
	if (y <0 || y >= cols)
	{
		return false;
	}
	Cell c = matrix[x][y];
	if (!c.isAvailable() || c.isFound())
	{
		return false;
	}
	return true;
}
Cell Matrix::getStartCell() const {
	return startCell;
}

void Matrix::initCells() {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j].isFound(false);
		}
	}
}
