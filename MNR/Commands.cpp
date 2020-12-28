#include "Commands.h"
#include<iostream>
#include<fstream>
#include<stdexcept>

using std::cout;
using std::ifstream;
void Commands::addOperator(const string& line)
{
	string name;
	string argument;
	vector<string> args;
	int i = 0;
	while (line[i] != ' ')
	{
		name[i] = line[i];
		i++;
	}
	i++;
	while (line[i] != '\0')
	{
		int k = 0;
		while (line[i] != ' ')
		{
			argument[k] = line[i];
			k++;
			i++;
		}
		args.push_back(argument);
		i++;
		k = 0;
	}
	currentProgram.addOperand(Operator(name, args));
}
void Commands::executeInstruction(const vector<string>& v)
{
	if (v[0] == "ZERO")
	{
		mech.setValue(stoi(v[1]), 0);
	}
	else if (v[0] == "INC")
	{
		mech.setValue(stoi(v[1]), stoi(v[1]) + 1);
	}
	else if (v[0] == "MOVE")
	{
		mech.move(stoi(v[1]), stoi(v[2]));
	}
	else if (v[0] == "JUMP")
	{
		if (v.size() == 2)
		{
			currentProgram.jump(stoi(v[1]));
		}
		else
		{
			currentProgram.jump(stoi(v[1]), stoi(v[2]), stoi(v[3]));
		}
	}
}
void Commands::executeCommand(const vector<string>& v)
{
	if (v[0] == "/zero")
	{
		int x = stoi(v[1]);
		int y = stoi(v[2]);
		zero(x, y);
	}
	else if (v[0] == "/set")
	{
		int x = stoi(v[1]);
		int y = stoi(v[2]);
		set(x, y);
	}
	else if (v[0] == "/copy")
	{
		int x = stoi(v[1]);
		int y = stoi(v[2]);
		int z = stoi(v[3]);
		copy(x, y, z);
	}
	else if (v[0] == "/mem")
	{
		int x = stoi(v[1]);
		int y = stoi(v[2]);
		print(x, y);
	}
	else if (v[0] == "/load")
	{
		load(v[1]);
	}
	else if (v[0] == "/run")
	{
		currentProgram.moveToNextLine();
	}
	else if (v[0] == "/add")
	{
		add(v[1]);
	}
	else if (v[0] == "/quote")
	{
		quote(v[1]);
	}
	else if (v[0] == "/code")
	{
		printCode();
	}
	else if (v[0] == "/comment")
	{
		comment(v[1]);
	}
	else if (v[0] == "/set")
	{
		int x = stoi(v[1]);
		int y = stoi(v[2]);
		set(x, y);
	}
}
bool Commands::isItOperator(const string& op)
{

	return op[0] == 'M' || op[0] == 'I' || op[0] == 'J' || op[0] == 'Z' || op[0] == '/';


}
Commands::Commands(): mech(), currentProgram(), running(false),currentLine(0)
{

}
Commands::Commands(const Commands& other)
{
	mech = other.mech;
	currentProgram = other.currentProgram;
	running = other.running;
	currentLine = other.currentLine;
}
Commands& Commands::operator=(const Commands& other)
{
	if (this != &other)
	{
		mech = other.mech;
		currentProgram = other.currentProgram;
		running = other.running;
		currentLine = other.currentLine;
	}
	return *this;
}
void Commands::zero(int from, int to)
{
	for (int i = from; i <= to; i++)
	{
		mech.setValue(i, 0);
	}
}

void Commands::set(int from, int to)
{
	mech.setValue(to, mech.getValue(from));
}

void Commands::copy(int x, int y, int z)
{
	mech.copy(x, y, z);
}

void Commands::print(int from, int to) const
{
	for (int i = from; i <= to; i++)
	{
		cout << " Printing... " << mech.getValue(i) << " ";
	}
}

void Commands::load(const string& path)
{

	if (running)
	{
		running = false;
	}
	currentProgram.readFromFile(path);
}

void Commands::quote(const string& q)
{
	if (isItOperator(q))
		currentProgram.addLine(q);
	else
		throw  std::invalid_argument("It's not operator");


}

void Commands::printCode() const
{
	currentProgram.printLines();
}

void Commands::comment(const string& com)
{
	currentProgram.addLine("/comment " + com);
}

void Commands::run()
{
	if (running)
	{
		currentLine = 0;
	}
	else
	{
		running = true;
		currentProgram.setCurrentLine(0);
		while (running)
		{
			if (currentProgram.getCurrentLine() == -1)
			{
				return;
			}

			vector<string> v = currentProgram.parseLine(currentProgram.getCurrentLine());
			if (v.empty())
			{
				running = false;
				break;
			}
			if (v[0][0] == '/')
			{
				executeCommand(v);
			}
			else
			{
				executeInstruction(v);
			}
			currentProgram.moveToNextLine();
		}

	}
}

void Commands::add(const string& filename)
{
	ifstream in;
	in.open(filename);
	string line;
	vector<string> operators;

	Program  p;

	p.readFromFile(filename);
	p.moveCells(currentProgram.cellsSize());
	while (!in.eof())
	{
		int i = 0;
		getline(in, line);

		operators.push_back(line);
		i++;
	}
	in.close();
	int length = operators.size();
	for (int j = 0; j < length; j++)
	{
		addOperator(operators[j]);
	}
}
