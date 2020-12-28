#include "Cell.h"

Cell::Cell() : value(-1)
{
}

Cell::Cell(const Cell& other)
{
    value = other.getValue();
}

Cell& Cell::operator=(const Cell& other)
{
    if (this!=&other)
    {
        value = other.value;

    }
    return *this;
}

int Cell::getValue() const
{
    return value;
}

void Cell::setValue(int value)
{
    this->value = value;
}

void Cell::makeZero()
{
    this->value = 0;
}

void Cell::increment()
{
    this->value++;
}
