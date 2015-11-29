#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	Matrix m = Matrix(x, y);
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			char type;
			cin >> type;
			m.addCell(i, j, type);
		}
	}
	int startCellX = 0, startCellY = 0;
	cin >> startCellX >> startCellY;
	m.setStartCell(startCellX, startCellY);
	std::list<Cell> cells = m.findAvailableCells();
	while (!cells.empty())
	{
		Cell c = cells.front();
		cells.pop_front();
		cout << c.print() << " ";
	}
	cout << endl;
	m.findRoutesForAvailableCells();
	system("pause");
	return 0;
}