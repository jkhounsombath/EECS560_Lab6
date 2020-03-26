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
	std::cout<<"Inorder print:\n";
	bst->printInOrder();
	std::cout<<"LevelOrder print:\n";
	bst->printLevelOrder();
}

Executive::~Executive()
{
	delete bst;
}

void Executive::run()
{
	int choice;
	std::cout << "WELCOME TO JUSTIN'S LAB 6\n------------------------------\n";
	do{
		std::cout << "Choose an option between 1 and 9\n1.) AddItem\n2.) DeleteItem\n3.) InorderSuccessor\n4.) levelOrder\n5.) SpiralLevelOrder\n6.) LeftSideView\n7.) RightSideView\n8.) KthSmallestItem\n9.) Exit\n\n";
		std::cout << "Choice: ";
		std::cin>>choice;
		if(choice == 1)
		{
			int integer;
			std::cout<<"What integer would you like to add: ";
			std::cin>>integer;
			bst->add(integer);
		}
		else if(choice == 2)
		{
			int integer;
			std::cout<<"What integer would you like to remove: ";
			std::cin>>integer;
			bst->remove(integer);
		}
		else if(choice == 3)
		{
			int integer;
			std::cout<<"What integer would you like to see the inorder successor of: ";
			std::cin>>integer;
			bst->InorderSuccessor(integer);
		}
		else if(choice == 4)
		{
			bst->printLevelOrder();
		}
		else if(choice == 5)
		{
			bst->spiralOrder();
		}
		else if(choice == 6)
		{
			bst->leftSideView();
		}
		else if(choice == 7)
		{
			bst->rightSideView();
		}
		else if(choice == 8)
		{
			int integer;
			std::cout<<"Enter a value for k to find the kth smallest value: ";
			std::cin>>integer;
			bst->kthSmallestInt(integer);
		}
		else if(choice == 9)
		{
			std::cout<<"See you later alligator!\n";
			break;
		}
		else
		{
			std::cout<<"Invalid option! (choose 1-9)\n";
		}
	}while(choice != 9);
}
