#pragma once
#include"Cell.h"
#include"Vector.h"
class Machine
{
	Vector<Cell> cells;
	
public:
	
	void add(const Cell& cell);
	void createCellsUntil( int number);
	void setValue(int number, int value);
	void move(int from, int to);
	int getValue(int n) const;
	void moveCells(int number);
	int size() const;
	void copy(int x, int y, int z);
};