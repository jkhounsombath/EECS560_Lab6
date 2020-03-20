#include "BST.h"

template <typename ItemType>
BST<ItemType>::BST()
{
	m_root= nullptr;
}

template <typename ItemType>
BST<ItemType>::~BST()
{
	recDelete(m_root);
}

template <typename ItemType>
void BST<ItemType>::add(ItemType entry)
{
	if(contains(entry, m_root))
	{
		throw(std::runtime_error("The value is already in our tree!\n"));
	}
	if(m_root == nullptr)
	{
		BNode<ItemType>* newNode= new BNode<ItemType>(entry);
		m_root= newNode;
		newNode= nullptr;
		delete newNode;
	}
	else
	{
		recAdd(entry, m_root);
	}
}

template <typename ItemType>
bool BST<ItemType>::contains(ItemType Key, BNode<ItemType>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		return false;
	}
	else if(curSubTree->getEntry() == Key)
	{
		return(true);
	}
	else if(curSubTree->getEntry() > Key)
	{
		return(contains(Key, curSubTree->getLeft()));
	}
	else if (curSubTree->getEntry() < Key)
	{
		return(contains(Key, curSubTree->getRight()));
	}
}

template <typename ItemType>
void BST<ItemType>::recDelete(BNode<ItemType>* curTree)
{
	if(curTree != nullptr)
	{
		recDelete(curTree->getLeft());
		recDelete(curTree->getRight());
		delete curTree;
	}
}

template <typename ItemType>
void BST<ItemType>::recAdd(ItemType entry, BNode<ItemType>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		curSubTree= new BNode<ItemType>(entry);
	}
	else if(curSubTree->getEntry() > entry)
	{
		if(curSubTree->getLeft() == nullptr)
		{
			curSubTree->setLeft(new BNode<ItemType>(entry));
		}
		else
		{
			recAdd(entry, curSubTree->getLeft());
		}
	}
	else if(curSubTree->getEntry() < entry)
	{
		if(curSubTree->getRight() == nullptr)
		{
			curSubTree->setRight(new BNode<ItemType>(entry));
		}
		else
		{
			recAdd(entry, curSubTree->getRight());
		}
	}
}

template <typename ItemType>
void BST<ItemType>::print()
{
	recPrint(m_root);
}

template <typename ItemType>
BNode<ItemType>* BST<ItemType>::recPrint(BNode<ItemType>* curSubTree)
{
	recPrint(curSubTree->getLeft());
	if(curSubTree!= nullptr)
	{
		std::cout<<curSubTree->getEntry().getAmericanName()<< std::endl;
	}
	recPrint(curSubTree->getRight());
	return nullptr;
}


template <typename ItemType>
void BST<ItemType>::remove(ItemType key)
{
	removeHelper(key, m_root);
}

template <typename ItemType>
BNode<ItemType>* BST<ItemType>::removeHelper(ItemType entry, BNode<ItemType>* curSubTree)
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
			BNode<ItemType>* temp = curSubTree->getRight();
			delete curSubTree;
			return(temp);
		}
		else if(curSubTree->getRight() == nullptr)
		{
			BNode<ItemType>* temp = curSubTree->getLeft();
			delete curSubTree;
			return(temp);
		}
		BNode<ItemType>* temp = curSubTree->getRight();
		while(temp->getLeft())
		{
			temp = temp->getLeft();
		}
		curSubTree->setEntry(temp->getEntry());
		curSubTree->setRight(removeHelper(entry, curSubTree->getRight()));
	}
	return(curSubTree);
}

template <typename ItemType>
void BST<ItemType>::addRec(BNode<ItemType>* subTree)
{
	if(subTree->getLeft() != nullptr)
	{
		add(subTree->getLeft()->getEntry());
		addRec(subTree->getLeft());
	}
	if(subTree->getRight() != nullptr)
	{
		add(subTree->getRight()->getEntry());
		addRec(subTree->getRight());
	}
}
