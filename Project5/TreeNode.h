// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include "Node.h"

class TreeNode : public Node
{
	public:
		enum Color { RED, BLACK };
		
	//-----*STRUCTORS-----
		TreeNode(int data);
		virtual ~TreeNode();
		//TreeNode(const TreeNode & node);
		
	//-----COLOR FUNCTIONS-----
		void setColor(Color color);
		bool getColor();
		void printColor(TreeNode * node);
		
	//-----GETTERS-----
		TreeNode * getLeftChild();
		TreeNode * getRightChild();
		TreeNode * getParent();
	
	//-----SETTERS-----
		void setLeftChild(TreeNode * leftChild_);
		void setRightChild(TreeNode * rightChild_);
		void setParent(TreeNode * parent_);
		
	private:
		int data_;
		TreeNode * leftChild_;
		TreeNode * rightChild_;
		TreeNode * parent_;

		Color color_;

};
#endif