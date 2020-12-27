#include<iostream>
#include"Commands.h"

int main()
{
	string filename;
	std::cin >> filename;
	Commands object;
	object.add(filename);
	
	return 0;
}