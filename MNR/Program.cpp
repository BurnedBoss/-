#include "Program.h"
#include<iostream>
#include<sstream>

using std::cout;
using std::endl;
using std::stringstream;

Program::Program() : operators(),machine(),currentLine(0),lines(),firstCell(0), lastCell(0)
{
}

Program::Program(const Program& other)
{
	operators = other.operators;
	setMachine(other.machine);
	currentLine = other.currentLine;
	lines = lines;
	firstCell = other.firstCell;
	lastCell = other.lastCell;
}

Program& Program::operator=(const Program& other)
{
	if (this  != &other)
	{
		operators = other.operators;
		setMachine(other.machine);
		currentLine = other.currentLine;
		lines = lines;
		firstCell = other.firstCell;
		lastCell = other.lastCell;
	}
	return *this;
}

void Program::setCurrentLine(int currentLine)
{
	this->currentLine = currentLine;
}

void Program::moveToNextLine()
{
	this->currentLine++;
}

int Program::getCurrentLine() const
{
	return currentLine;
}

int Program::lineOfInstruction(int z) const
{
	int instrcutionsFound = 0;
	for (int i = 0; i < operators.size(); i++) {
		if (operators[i].getName()[0] != '/') {
			instrcutionsFound++;

			if (instrcutionsFound > z) {
				return i;
			}
		}
	}
	return -1;
}

void Program::jump(int x, int y, int z)
{
	if (machine->getValue(x) == machine->getValue(y))
	{
		jump(z);
	}
}

void Program::jump(int z)
{
	if (z < operators.size())
	{
		currentLine = lineOfInstruction(z);
	}
	else
	{
		currentLine = -1;
	}

}

void Program::addOperand(const Operator& operand)
{
	operators.push_back(operand);
}

void Program::setMachine(Machine* machine)
{
	this->machine = machine;
}

void Program::readFromFile(const string& path)
{
	ifstream in;
	in.open(path);
	string curr;
	while (!in.eof())
	{
		getline(in, curr);
		lines.push_back(curr);
	}
}

void Program::addLine(const string& newLine)
{
	lines.push_back(newLine);
}

void Program::printLines() const
{
	int length = lines.size();
	for (int i = 0; i < length; i++)
	{
		cout << lines[i] << endl;
	}
}

void Program::moveCells(int number)
{
	machine->moveCells(number);
}

int Program::cellsSize() const
{
	return machine->size();
}

vector<string> Program::parseLine(int n)
{
	vector<string> result;
	string curr = lines[n];
	stringstream s(curr);

	while (!s.str().empty())
	{
		string arg;
		s >> arg;
		result.push_back(arg);
	}

	return result;
}


