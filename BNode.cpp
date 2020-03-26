#include "BNode.h"


template <typename ItemType>
BNode<ItemType>::BNode()
{
	m_entry = nullptr;
	m_left = nullptr;
	m_right = nullptr;
}

template <typename ItemType>
BNode<ItemType>::BNode(ItemType entry)
{
	m_entry= entry;
	m_left= nullptr;
	m_right= nullptr;
}

template <typename ItemType>
BNode<ItemType>::~BNode()
{

}

template <typename ItemType>
ItemType BNode<ItemType>::getEntry() const
{
	return m_entry;
}

template <typename ItemType>
BNode<ItemType>* BNode<ItemType>::getLeft() const
{
	return m_left;
}

template <typename ItemType>
BNode<ItemType>* BNode<ItemType>::getRight() const
{
	return m_right;
}

template <typename ItemType>
void BNode<ItemType>::setEntry(ItemType entry)
{
	m_entry= entry;
}

template <typename ItemType>
void BNode<ItemType>::setLeft(BNode<ItemType>* left)
{
	m_left= left;
}

template <typename ItemType>
void BNode<ItemType>::setRight(BNode<ItemType>* right)
{
	m_right= right;
}
