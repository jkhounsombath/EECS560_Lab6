#include "BST.h"

BST::BST()
{
	m_root= nullptr;
}

BST::~BST()
{
	//recDelete(m_root);
}

void BST::add(int entry)
{
	if(m_root == nullptr)
	{
		std::cout<<"1";
		BNode<int>* newNode= new BNode<int>(entry);
		m_root= newNode;
		newNode= nullptr;
	}
	else
	{
		std::cout <<"2";
		recAdd(entry, m_root);
	}
}
void BST::recAdd(int entry, BNode<int>* curSubTree)
{
	if(curSubTree->getEntry() > entry)
	{
		if(curSubTree->getLeft() == nullptr)
		{
			curSubTree->setLeft(new BNode<int>(entry));
		}
		else
		{
			recAdd(entry, curSubTree->getLeft());
		}
	}
	else if(curSubTree->getEntry() <= entry)
	{
		if(curSubTree->getRight() == nullptr)
		{
			curSubTree->setRight(new BNode<int>(entry));
		}
		else
		{
			recAdd(entry, curSubTree->getRight());
		}
	}
}

/*
void BST::recDelete(BNode<int>* curTree)
{
	if(curTree != nullptr)
	{
		recDelete(curTree->getLeft());
		recDelete(curTree->getRight());
		delete curTree;
	}
}

void BST::print()
{
	recPrint(m_root);
}

BNode<int>* BST::recPrint(BNode<int>* curSubTree)
{
	recPrint(curSubTree->getLeft());
	if(curSubTree!= nullptr)
	{
		std::cout<<curSubTree->getEntry()<< std::endl;
	}
	recPrint(curSubTree->getRight());
	return nullptr;
}


void BST::remove(int key)
{
	removeHelper(key, m_root);
}

BNode<int>* BST::removeHelper(int entry, BNode<int>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		throw std::runtime_error("Value is not in the tree\n");
	}
	if(curSubTree->getEntry() < entry)
	{
		curSubTree->setRight(removeHelper(entry, curSubTree->getRight()));
	}
	else if(curSubTree->getEntry() > entry)
	{
		curSubTree->setLeft(removeHelper(entry, curSubTree->getLeft()));
	}
	else
	{
		if(curSubTree->getLeft() == nullptr)
		{
			BNode<int>* temp = curSubTree->getRight();
			delete curSubTree;
			return(temp);
		}
		else if(curSubTree->getRight() == nullptr)
		{
			BNode<int>* temp = curSubTree->getLeft();
			delete curSubTree;
			return(temp);
		}
		BNode<int>* temp = curSubTree->getRight();
		while(temp->getLeft())
		{
			temp = temp->getLeft();
		}
		curSubTree->setEntry(temp->getEntry());
		curSubTree->setRight(removeHelper(entry, curSubTree->getRight()));
	}
	return(curSubTree);
}
*/
