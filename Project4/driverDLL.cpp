// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

//driverDLL.cpp

#include "Node.h"
#include "LinkedNode.h"

#include <iostream>
#include <fstream>

int main()
{
	// Phase I ----------------------------------
	Node node(4);
	
	std::cout << node.getValue() << std::endl;
	
	node.setValue(7);
	
	std::cout << node.getValue() << std::endl;
	
	// Phase II ---------------------------------
	
	//Node nextLinkedNode_(4);
	LinkedNode * link_;
	//nextLinkedNode_->setNextLinkedNode();

	LinkedNode LNode(3, link_);
	LNode.setNextLinkedNode(link_);
	std::cout << "test 1" << std::endl;
	//std::cout << LNode.getNextLinkedNode() << std::endl;
	
	LinkedNode LNode2(3, link_);
	std::cout << "test 2" << std::endl;
	LNode2.setNextLinkedNode(link_);
	std::cout << "test 3" << std::endl;	
	std::cout << LNode.getNextLinkedNode() << std::endl; /** */
	
	return 0;
}
