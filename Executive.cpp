#include "Executive.h"

Executive::Executive()
{
	std::ifstream inFile("data.txt");
	int value = 0;
	while(inFile>>value)
	{
		std::cout<<"Adding value: "<<value<<std::endl;
		bst->add(value);
	}
}

Executive::~Executive()
{
	delete bst;
}

void Executive::run()
{

}
