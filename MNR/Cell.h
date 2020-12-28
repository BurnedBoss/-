#pragma once

class Cell
{
	int value;
public:
	Cell();
	Cell(const Cell& other);
	Cell& operator= (const Cell& other);
	int getValue() const;
	void setValue(int value);
	void makeZero();
	void increment();
};