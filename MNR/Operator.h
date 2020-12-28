#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class Operator
{
	string name;
	vector<string> args;

public:
	Operator();
	Operator(const string& name, const vector<string>& args);

	string getName() const;
};


