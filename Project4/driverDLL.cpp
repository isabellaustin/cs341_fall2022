// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

//driverDLL.cpp

#include "Node.h"
#include "LinkedNode.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"

#include <iostream>
//#include <fstream>

int main()
{
	/** Phase I ----------------------------------
	std::cout << "Phase I ----------------" << std::endl;
	
	Node node(4);
	std::cout << node.getValue() << std::endl;
	
	node.setValue(7);
	
	std::cout << node.getValue() << std::endl;
	
	// Phase II ---------------------------------
	std::cout << "Phase II ---------------" << std::endl;
	
	//LinkedNode * link_ = new LinkedNode(4, nullptr, nullptr); 

	LinkedNode LNode(3, link_, nullptr);
	std::cout << LNode.getValue() << std::endl;

	LinkedNode LNode2(5, LNode.getNextLinkedNode(),LNode.getPrevLinkedNode());
	std::cout << LNode2.getValue() << std::endl;
	
	// Phase III --------------------------------
	std::cout << "Phase III --------------" << std::endl;
	LinkedList list;
	
	list.insert(2);	
	list.insert(5);
	list.insert(7);
		
	//list.printList();
	
	std::cout << "Length: " << list.getLength() << std::endl; */
	
	// Phase IV ---------------------------------
	std::cout << "Phase IV ---------------" << std::endl;

	LinkedNode * link_ = new LinkedNode(5, nullptr, nullptr);
	
	DoublyLinkedList Dlist;
	
	Dlist.insertNode(link_, 9);
	Dlist.insertNode(link_->getNextLinkedNode(), 12);
	Dlist.insertNode(link_->getNextLinkedNode()->getNextLinkedNode(), 3);
	
	Dlist.insertAfterLinkedNode(link_, 7);
	Dlist.insertBeforeLinkedNode(link_->getNextLinkedNode(), 2);

	Dlist.printList();
	
	link_ = Dlist.getHead();
	
	while(link_ != Dlist.getTail())
	{
		link_ = link_->getNextLinkedNode();
		delete link_->getPrevLinkedNode();
	}
	
	delete link_;
	
	return 0;
}