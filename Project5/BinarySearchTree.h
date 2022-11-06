// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include "TreeNode.h"

class BinarySearchTree
{
	public:
		BinarySearchTree();
		//BinarySearchTree(const BinarySearchTree & tree);
		virtual ~BinarySearchTree();
		
		TreeNode::Color black = TreeNode::BLACK;
		TreeNode::Color red = TreeNode::RED;
		
		void setRoot(TreeNode * root);
		TreeNode * getRoot();
		
		virtual void insert(int data);
		
	protected:
		TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
		
	private:
		TreeNode * root_;
};
#endif