#include "Machine.h"
#include"Memory.h"
#include"Cell.h"

Machine::Machine() : cells()
{
}

void Machine::add(const Cell& cell)
{
	cells.push_back(cell);
}

void Machine::createCellsUntil(int number)
{
	for (int i = cells.size(); i <= number; i++)
	{
		add(Cell());
	}
}

void Machine::setValue(int number, int value)
{
	createCellsUntil(number);
	cells[number].setValue(value);
}

void Machine::move(int from, int to)
{
	cells[to].setValue(cells[from].getValue());
}

int Machine::getValue(int n) const
{
	return cells[n].getValue();
}

void Machine::moveCells(int number)
{
	Vector<Cell> other = cells;
	cells.clear();
	for (int i = 0; i < number; i++)
	{
		cells[i + number].setValue(other[i].getValue());
	}
}

int Machine::size() const
{
	return cells.size();
}

void Machine::copy(int x, int y, int z)
{
	for (int i = 0; i<z; i++)
	{
		cells[y + i] = cells[x + i];
	}
}
