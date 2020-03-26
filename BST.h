#ifndef BST_H
#define BST_H

#include<iostream>
#include<string>
#include<stdexcept>
#include<functional>
#include<stack>

#include "BNode.h"

class BST
{
	public:
		BST();
		~BST();
		void add(int entry);
		void recAdd(int entry, BNode* curSubTree);
		int getHeight(BNode* curSubTree);
		void printLevelOrder();
		void recPrintLevelOrder(BNode* curSubTree, int curLevel);
		void leftSideView();
		void leftSideViewHelper(BNode* curSubTree);
		void rightSideView();
		void rightSideViewHelper(BNode* curSubTree);
		void kthSmallestInt(int k);
		BNode* kthSmallestIntHelper(int k, BNode* curSubTree);
		void printInOrder();
		void recPrintInOrder(BNode* curSubTree);
		void remove(int key);
		BNode* removeHelper(int key, BNode* curSubTree);
		void InorderSuccessor(int integer);
		BNode* InorderSuccessorHelper(int integer, BNode* curSubTree);
		void spiralOrder();
		void spiralOrderHelper(BNode* curSubTree, int curLevel, int direction);
		BNode* search(int integer);
		BNode* searchHelper(int integer, BNode* curSubTree);
		void recDelete(BNode* curSubTree);
	private:
		int size = 0;
		BNode* m_root;
};
#endif
