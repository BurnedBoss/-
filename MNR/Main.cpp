#include<iostream>
#include"Commands.h"
#include"Machine.h"
#include"Vector.h"

using std::cout;
using std::endl;

int main()
{
	
	string filename;
	std::cin >> filename;
	Commands object;
	object.load(filename);
	object.set(0,9);
	object.run();
	object.print(1,1);
	object.print(0,6);
	object.printMemory();
	return 0;
}