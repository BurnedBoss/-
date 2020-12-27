#pragma once

class Cell
{
	int value;
public:
	Cell();
	int getValue() const;
	void setValue(int value);
	void makeZero();
	void increment();
};