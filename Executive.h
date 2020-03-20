#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
#include <algorithm>
#include <functional>

class Executive
{
	public:
		Executive();
		~Executive();
		void run(std::string fileName);
	private:
		BST<int>* bst;
};
#endif
