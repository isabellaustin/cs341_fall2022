// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

//driverDLL.cpp

#include "Node.h"
#include "LinkedNode.h"
#include "LinkedList.h"

#include <iostream>
//#include <fstream>

int main()
{
	// Phase I ----------------------------------
	std::cout << "Phase I ----------------" << std::endl;
	
	Node node(4);
	std::cout << node.getValue() << std::endl;
	
	node.setValue(7);
	
	std::cout << node.getValue() << std::endl;
	
	// Phase II/III -----------------------------
	std::cout << "Phase II/III -----------" << std::endl;
	
	LinkedNode * link_ = new LinkedNode(4, nullptr, nullptr); 

	LinkedNode LNode(3, link_, nullptr);
	std::cout << LNode.getValue() << std::endl;

	LinkedNode LNode2(5, LNode.getNextLinkedNode(),LNode.getPrevLinkedNode());
	std::cout << LNode2.getValue() << std::endl;
	
	
	LinkedList list;
	
	list.insert(2);	
	list.insert(5);
	list.insert(7);
	std::cout << "Length: " << list.getLength() << std::endl;
	
	list.printList();

	//std::cout << "test1" << std::endl;
	return 0; //ask about this
	//std::cout << "test2" << std::endl;
}
