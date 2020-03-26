#include "BST.h"

BST::BST()
{
	size = 0;
	m_root = nullptr;
}

BST::~BST()
{
	recDelete(m_root);
}

void BST::add(int entry)
{
	if(m_root == nullptr)
	{
		BNode* newNode= new BNode(entry);
		m_root= newNode;
		newNode= nullptr;
	}
	else
	{
		recAdd(entry, m_root);
	}
}

void BST::recAdd(int entry, BNode* curSubTree)
{
	if(curSubTree == nullptr)
	{
		curSubTree= new BNode(entry);
	}
	else if(curSubTree->getEntry() > entry)
	{
		if(curSubTree->getLeft() == nullptr)
		{
			curSubTree->setLeft(new BNode(entry));
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
			curSubTree->setRight(new BNode(entry));
		}
		else
		{
			recAdd(entry, curSubTree->getRight());
		}
	}
}

int BST::getHeight(BNode* curSubTree)
{
	if(curSubTree == nullptr)
	{
		return 0;
	}
	else
	{
		int LHeight = getHeight(curSubTree->getLeft());
		int RHeight = getHeight(curSubTree->getRight());
		if(LHeight > RHeight)
		{
			return(LHeight + 1);
		}
		else
		{
			return(RHeight + 1);
		}
	}
}

void BST::printLevelOrder()
{
	for(int i = 0; i < getHeight(m_root); i++)
	{
		recPrintLevelOrder(m_root, i);
		std::cout<<std::endl;
	}
}

void BST::recPrintLevelOrder(BNode* curSubTree, int curLevel)
{
	if(curSubTree == nullptr)
	{
		return;
	}
	else if(curLevel == 0)
	{
		std::cout<<curSubTree->getEntry()<<" ";
	}
	else
	{
		recPrintLevelOrder(curSubTree->getLeft(), curLevel-1);
		recPrintLevelOrder(curSubTree->getRight(), curLevel-1);
	}
}

void BST::printInOrder()
{
	recPrintInOrder(m_root);
}

void BST::recPrintInOrder(BNode* curSubTree)
{
	if(curSubTree != nullptr)
	{
		recPrintInOrder(curSubTree->getLeft());
		std::cout<<curSubTree->getEntry()<<std::endl;
		recPrintInOrder(curSubTree->getRight());
	}
	else
	{
		return;
	}
}

void BST::remove(int key)
{
	removeHelper(key, m_root);
}

BNode* BST::removeHelper(int entry, BNode* curSubTree)
{
	if(curSubTree == nullptr)
	{
		return curSubTree;
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
			BNode* temp = curSubTree->getRight();
			delete curSubTree;
			return(temp);
		}
		else if(curSubTree->getRight() == nullptr)
		{
			BNode* temp = curSubTree->getLeft();
			delete curSubTree;
			return(temp);
		}
		BNode* temp = curSubTree->getRight();
		while(temp != nullptr && temp->getLeft() != nullptr)
		{
			temp = temp->getLeft();
		}
		curSubTree->setEntry(temp->getEntry());
		curSubTree->setRight(removeHelper(entry, curSubTree->getRight()));
	}
	return(curSubTree);
}

void BST::InorderSuccessor(int integer)
{
	std::cout<<"The inorder successor of "<<integer<<" is "<<InorderSuccessorHelper(integer, m_root)->getEntry()<<std::endl;
}

BNode* BST::InorderSuccessorHelper(int integer, BNode* curSubTree)
{
	BNode* temp = search(integer);
	if(temp->getRight() != nullptr)
	{
		temp= temp->getRight();
		while(temp->getLeft() != nullptr)
		{
			temp= temp->getLeft();
		}
		return temp;
	}
	BNode* temp2 = nullptr;
	while (curSubTree != nullptr)
	{
		if(integer < curSubTree->getEntry())
		{
			temp2 = curSubTree;
			curSubTree= curSubTree->getLeft();
		}
		else if(temp->getEntry() > curSubTree->getEntry())
		{
				curSubTree = curSubTree->getRight();
		}
		else
			break;
	}
	return temp2;
}

BNode* BST::search(int integer)
{
	return (searchHelper(integer, m_root));
}

BNode* BST::searchHelper(int integer, BNode* curSubTree)
{
	if(curSubTree == nullptr)
	{
		std::cout<< "The integer is not in the tree!\n";
		return nullptr;
	}
	else if(curSubTree->getEntry() == integer)
	{
		return curSubTree;
	}
	else if(integer < curSubTree->getEntry())
	{
		return(searchHelper(integer, curSubTree->getLeft()));
	}
	else if(integer > curSubTree->getEntry())
	{
		return(searchHelper(integer, curSubTree->getRight()));
	}
	else
	{
		std::cout<<"The integer was not in the tree!\n";
		return nullptr;
	}
}

void BST::recDelete(BNode* curSubTree)
{
	if(curSubTree != nullptr)
	{
		recDelete(curSubTree->getLeft());
		recDelete(curSubTree->getRight());
		delete curSubTree;
	}
}
