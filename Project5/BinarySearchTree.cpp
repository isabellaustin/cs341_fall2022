// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree()
{
	root_ = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	if (root_ != nullptr)
	{
		delete root_;
	}
}

void BinarySearchTree::setRoot(TreeNode * root)
{
    root_ = root;
}

TreeNode * BinarySearchTree::getRoot()
{
	return root_;
}

void BinarySearchTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);

	root_ = insertNode(root_, newNode);
}

TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * newNode)
{
	if(root == nullptr)
	{
		root = newNode;
	}
	else
	{
		if(newNode->getData() < root->getData())
		{
			root->setLeftChild(insertNode(root->getLeftChild(), newNode));
			root->getLeftChild()->setParent(root);
		}
		else
		{
			root->setRightChild(insertNode(root->getRightChild(), newNode));
			root->getRightChild()->setParent(root);
		}
	}
	return root;
}
