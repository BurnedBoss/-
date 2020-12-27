#include "Operator.h"

void Operator::execute()
{
}

void Operator::parse(const string& line)
{

}

Operator::Operator() : name(), args()
{
	
}

Operator::Operator(const string& name, const vector<string>& args)
{
	this->name = name;
	this->args = args;
}
