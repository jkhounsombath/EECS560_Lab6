#ifndef BST_H
#define BST_H

#include<iostream>
#include<string>
#include<stdexcept>
#include<functional>

#include "BNode.h"

class BST
{
	public:
		BST();
		~BST();
		void add(int entry);
		void recAdd(int entry, BNode* curSubTree);
		/*
		void recDelete(BNode<int>* curTree);
		BNode<int>* recPrint(BNode<int>* curSubTree);
		void print();
		void remove(int key); //throws std::runtime_error if not in tree
		BNode<int>* removeHelper(int key, BNode<int>* curSubTree);
*/
	private:
		int size = 0;
		BNode* m_root;
};
#endif
