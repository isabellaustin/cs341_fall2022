// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

#include "BinarySearchTree.h"
#include <cmath>

class RedBlackTree : public BinarySearchTree
{
	public:
	//-----*STRUCTORS-----
		RedBlackTree();
        virtual ~RedBlackTree(){};
	
        virtual void insert(int data);
		int getHeight();
		
	//------TRAVERSALS------
		void printRedNodes(TreeNode * root);
		void printBlackNodes(TreeNode * root);
	
	//----------COLOR----------
		enum Color { RED, BLACK };
				
	private:
	//-----RECURSIVE FUNCTIONS-----
		void rotateLeft(TreeNode *& root, TreeNode *& newNode);
		void rotateRight(TreeNode *& root, TreeNode *& newNode);
		void balanceColor(TreeNode *& root, TreeNode *& newNode);
		
		int numNodes;

};
#endif