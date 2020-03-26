#include "Executive.h"

Executive::Executive()
{
	bst= new BST();
	std::ifstream inFile("data.txt");
	int value = 0;
	while(inFile>>value)
	{
		std::cout<<"Adding value: "<<value<<std::endl;
		bst->add(value);
	}
	bst->print();
}

Executive::~Executive()
{
	delete bst;
}

void Executive::run()
{

}
