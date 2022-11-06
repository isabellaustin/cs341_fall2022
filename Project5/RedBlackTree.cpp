// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "RedBlackTree.h"
#include "TreeNode.h"
#include <iostream>

RedBlackTree::RedBlackTree() : BinarySearchTree()
{	
	numNodes = 0;
}

void RedBlackTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);
	
	if(newNode->getColor() == 0) // RED
    {
		BinarySearchTree::setRoot(BinarySearchTree::insertNode(BinarySearchTree::getRoot(), newNode));
		TreeNode * root = BinarySearchTree::getRoot();
        balanceColor(root, newNode);
    }
	
	numNodes++;
}

void RedBlackTree::printRedNodes(TreeNode * root)
{ //INORDER: left, parent, right
	if(root != nullptr)
	{
		printRedNodes(root->getLeftChild());
		if (root->getColor() == 0)
		{
			std::cout << root->getData() << " ";
		}
		printRedNodes(root->getRightChild());
	}

}

void RedBlackTree::printBlackNodes(TreeNode * root)
{ //PREORDER: parent, left, right
	if (root != nullptr)
    {
        if (root->getColor() == 1)
        {
            std::cout << root->getData() << " ";
        }
        printBlackNodes(root->getLeftChild());
        printBlackNodes(root->getRightChild());
    }
}

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& N2)
{	

/*		1							1
		 \							 \
		  2           --->            4
		   \                         / \
			4                       2   5
		   / \                       \
          3   5                       3				*/

	TreeNode * N4 = N2->getRightChild(); //Create Node4
	
	N2->setRightChild(N4->getLeftChild()); //Set Node2 Right Child to Node3
	if(N2->getRightChild() != nullptr)
	{
		N2->getRightChild()->setParent(N2); //Set Node3 Parent to Node2
	}
	
	N4->setParent(N2->getParent()); //Set Node4 Parent to Node1
	if(N2->getParent() == nullptr) //If Node2 is the Root
	{
		root = N4;
		BinarySearchTree::setRoot(root);
	}
	else if(N2->getParent() == N2->getParent()->getLeftChild())
	{
		N2->getParent()->setLeftChild(N4);	//Set Node5 Left Child to Node2
		
	}
	else
	{
		N2->getParent()->setRightChild(N4); //Set Node5 Left Child to Node2
	}
	
	N2->setParent(N4); //Set Node2 Parent to Node4
	N4->setLeftChild(N2); //Set Node4 Left Child to Node2
}	
		
void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& N4)
{	
/*	  		  5					     5
		     /					    /
		    4					   2
		   /         --->		  / \
		  2                      1   4
	     / \						/
	    1   3					   3			*/
		
	TreeNode * N2 = N4->getLeftChild(); //Create Node2
	
	N4->setLeftChild(N2->getRightChild()); //Set Node4 Left Child to Node3
	if(N4->getLeftChild() != nullptr)
	{
		N4->getLeftChild()->setParent(N4); //Set Node3 Parent to Node4
	}
	
	N2->setParent(N4->getParent()); //Set Node2 Parent to Node5
	if(N4->getParent() == nullptr) //If Node4 is the Root
	{
		root = N2;
		BinarySearchTree::setRoot(root);
	}
	else if(N4->getParent() == N4->getParent()->getLeftChild())
	{
		N4->getParent()->setLeftChild(N2);	//Set Node5 Left Child to Node2
		
	}
	else
	{
		N4->getParent()->setRightChild(N2); //Set Node5 Left Child to Node2
	}
	
	N4->setParent(N2); //Set Node4 Parent to Node2
	N2->setRightChild(N4); //Set Node2 Right Child to Node4
}

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode * parent = nullptr; //Will be used in Right and Left Rotations
	TreeNode * gParent = nullptr; //Will be used in Right and Left Rotations
	TreeNode * uncle = nullptr;	//Will need to be Recolored
	
	while(newNode != root && newNode->getColor() != 1 && newNode->getParent()->getColor() == 0)
	{
		parent = newNode->getParent();
		gParent = parent->getParent();
	
	// CASE 1: Parent is Right Child
		if(parent == gParent->getRightChild())
		{
			uncle = gParent->getLeftChild();
		
		// CASE 1A: Uncle is Red
			if(uncle != nullptr && uncle->getColor() == 0)
			{
				//-----RECOLORING-----
				parent->setColor(black);
				uncle->setColor(black);
				gParent->setColor(red);
			
				newNode = gParent; //Ready for Recursion
			}
			else
			{
			// CASE 1B: Child is Right Child of Parent
				if(newNode == parent->getRightChild())
				{
					rotateLeft(root, gParent);
				
					//----------RECOLORING----------
					bool pTemp = parent->getColor();
					if(gParent->getColor() == 0)
					{	parent->setColor(red);		}
					else
					{	parent->setColor(black);	}
					if(pTemp == 0)
					{	gParent->setColor(red);		}
					else
					{	gParent->setColor(black);	}
			
					newNode = gParent; //Ready for Recursion
				}
			// CASE 1C: Child is Left Child of Parent
				else
				{
					rotateRight(root, parent);
					newNode = parent; //Ready for Recursion
				}
			}
		}
	
	// CASE 2: Parent is Left Child
		else
		{
			uncle = gParent->getRightChild();
		
		// CASE 2A: Uncle is Red
			if(uncle != nullptr && uncle->getColor() == 0)
			{
				//-----RECOLORING-----
				parent->setColor(black);
				uncle->setColor(black);
				gParent->setColor(red);
			
				newNode = gParent; //Ready for Recursion
			}
			else
			{
			// CASE 2B: Child is Right Child of Parent
				if(newNode == parent->getRightChild())
				{
					rotateLeft(root, parent);
					newNode = parent; //Ready for Recursion
				}
			// CASE 2C: Child is Left Child of Parent
				else
				{
					rotateRight(root, gParent);
				
					//----------RECOLORING----------
					bool pTemp = parent->getColor();
					if(gParent->getColor() == 0)
					{	parent->setColor(red);		}
					else
					{	parent->setColor(black);	}
					if(pTemp == 0)
					{	gParent->setColor(red);		}
					else
					{	gParent->setColor(black);	}
			
					newNode = gParent; //Ready for Recursion
				}
			}
		}
	
	}
	
	root->setColor(black);
}

int RedBlackTree::getHeight()
{
	int height = 2*log2(numNodes + 1);
	return height;
}