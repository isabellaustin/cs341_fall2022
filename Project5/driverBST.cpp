// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include "TreeNode.h"

#include <iostream>
#include <fstream>

int main()
{
	BinarySearchTree BST;
	RedBlackTree RBT;
	
	TreeNode::Color black = TreeNode::BLACK;
	TreeNode::Color red = TreeNode::RED;

//---------------PHASE I & II---------------

	std::ifstream inputFile("data.txt");

	if(inputFile.is_open())
	{
		int dataVal = 0;

		while(!inputFile.eof())
        {
			inputFile >> dataVal;
			RBT.insert(dataVal);
			std::cout << dataVal << " ";
		}
		
		std::cout << std::endl;
	}
	inputFile.close();
	
	//std::cout << "Root: " << RBT.getRoot()->getData() << std::endl;
	
//---------------PHASE III---------------
/*
	RBT.getRoot()->setColor(black);

	std::cout << "Color: ";
	RBT.getRoot()->printColor(RBT.getRoot());
	
//---------------PHASE IV---------------

	//std::cout << "Height: " << RBT.getHeight() << std::endl;
*/	
//---------------PHASE V----------------
	
	std::cout << "Red Nodes: ";
	RBT.printRedNodes(RBT.getRoot());
	std::cout << std::endl;
	
	std::cout << "Black Nodes: ";
	RBT.printBlackNodes(RBT.getRoot());
	std::cout << std::endl;
	
	std::cout << "Root: " << RBT.getRoot()->getData() << std::endl;

//----------------POINTER GRAVEYARD---------------
//				  NO MEMORY LEAKS!!!
	
	return 0;
}