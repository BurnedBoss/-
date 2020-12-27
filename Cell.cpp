#include "Cell.h"

Cell::Cell() : value(-1)
{
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
