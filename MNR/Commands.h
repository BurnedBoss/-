#pragma once
#include"Cell.h"
#include"Machine.h"
#include"Program.h"
#include<vector>
#include<string>

using std::vector;
using std::string;

class Commands
{
	Machine mech;
	Program currentProgram;
	bool running;
	int currentLine;
	
	void addOperator(const string& line);
	void executeInstruction(const vector<string>& v);
	void executeCommand(const vector<string>& v);
    bool isItOperator(const string& op);
public:
	Commands();
	Commands(const Commands& other);
	Commands& operator= (const Commands& other);
	void zero(int from, int to);
	void set(int from, int to);
	void copy(int x, int y, int z);
	void print(int from, int to) const;
	void load(const string& path);
	void quote(const string& q);
	void printCode() const;
	void comment(const string& com);
	void run();
	void add(const string& filename);
};