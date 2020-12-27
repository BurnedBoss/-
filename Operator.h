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
	void execute();
	void parse(const string& line);
	Operator();
	Operator(const string& name, const vector<string>& args);

	string getName() const {
		return name;
	}
};


