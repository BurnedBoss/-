#include "Operator.h"
#include<string>
#include<vector>

using std::string;
using std::vector;
Operator::Operator()
{
	name = string();
	args = vector<string>();
}

Operator::Operator(const string& name, const vector<string>& args)
{
	this->name = name;
	this->args = args;
}

string Operator::getName() const
{
	return name;
}
