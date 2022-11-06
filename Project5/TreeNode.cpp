// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "TreeNode.h"
#include <iostream>

//---------------*STRUCTORS---------------
TreeNode::TreeNode(int data) : Node(data)
{
	parent_ = nullptr;
	leftChild_ = nullptr;
	rightChild_ = nullptr;
	color_ = RED; // NODES ARE RED WHEN FIRST ADDED
	
}

TreeNode::~TreeNode()
{
	if(leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	
	if(rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}


//---------------COLOR FUNCTIONS---------------
 void TreeNode::setColor(Color color)
{
	 color_ = color;
}

void TreeNode::printColor(TreeNode * node)
{
	if(node->getColor() == 0)
	{	std::cout << "RED" << std::endl;	}
	if(node->getColor() == 1)
	{	std::cout << "BLACK" << std::endl;	}
}

bool TreeNode::getColor()
{
	if(color_ == RED)
	{	return 0;	}
	else
	{	return 1;	}
}


//---------------GETTERS---------------
TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}

TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}

TreeNode * TreeNode::getParent()
{
	return parent_;
}


//--------------SETTERS---------------
void TreeNode::setLeftChild(TreeNode * child)
{
	leftChild_ = child;
}

void TreeNode::setRightChild(TreeNode * child)
{
	rightChild_ = child;
}

void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}

