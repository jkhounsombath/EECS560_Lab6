#ifndef BST_H
#define BST_H

#include<iostream>
#include<string>
#include<stdexcept>
#include<functional>

#include "BNode.h"

template <typename ItemType>
class BST
{
	public:
		BST();
		~BST();
		void add(ItemType entry);
		bool contains(ItemType Key, BNode<ItemType>* curSubTree);
		void recAdd(ItemType entry, BNode<ItemType>* curSubTree);
		void recDelete(BNode<ItemType>* curTree);
		BNode<ItemType>* recPrint(BNode<ItemType>* curSubTree);
		void print();
		void remove(ItemType key); //throws std::runtime_error if not in tree
		BNode<ItemType>* removeHelper(ItemType key, BNode<ItemType>* curSubTree);
	private:
		BNode<ItemType>* m_root;
};
#endif
