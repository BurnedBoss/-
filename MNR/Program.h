#pragma once
#include"Operator.h"
#include"Machine.h"
#include<vector>
#include<string>
#include<fstream>

using std::string;
using std::vector;
using std::ifstream;

class Program
{
	vector<Operator> operators;
	Machine* machine;
	int currentLine;
	vector<string> lines;
	int firstCell;
	int lastCell;
public:
	Program();
	Program(const Program& other);
	Program& operator= (const Program& other);
	void setCurrentLine(int currentLine); 
	void moveToNextLine();
	int getCurrentLine() const;
	int lineOfInstruction(int z) const; 
	void jump(int x, int y, int z);
	void jump(int z);
	void addOperand(const Operator& operand);
	void setMachine(Machine* machine);
	void readFromFile( const string& path);
	void addLine(const string& newLine);
	void printLines() const;
	void moveCells(int number);
	int cellsSize() const;
	vector<string> parseLine(int n);

	int numberOfLines() const {
		return lines.size();
	}
};