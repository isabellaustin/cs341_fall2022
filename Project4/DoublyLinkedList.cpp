// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "DoublyLinkedList.h"
#include <cstddef>
#include <iostream>
#include <ostream>


//------------------*STRUCTORS--------------------------------------
DoublyLinkedList::DoublyLinkedList() //: LinkedList()
{
	head_ = nullptr;
    tail_ = nullptr;
}
//---------------------------GETTERS&SETTERS-------------------------
LinkedNode * DoublyLinkedList::getHead()
{
    return head_;
}

LinkedNode * DoublyLinkedList::getTail()
{
    return tail_;
}

void DoublyLinkedList::setHead(LinkedNode* node)
{
    head_ = node;
}

void DoublyLinkedList::setTail(LinkedNode* node)
{
    tail_ = node;
}
//--------------------------------------------------------------------
int DoublyLinkedList::getLength()
{	
    return length;
}

void DoublyLinkedList::printList() //virtual
{
	LinkedNode * current = head_;
	
	int i=0;
	
	do{
		std::cout << current->getValue();
		current = current->getNextLinkedNode();
		if(current != tail_)
		{
			std::cout << "<-->";
		}
		if (current == tail_)
		{
			std::cout << "<-->" << tail_->getValue();
		}
		i++;
	}while(getLength() > i);
	
	std::cout << std::endl;
	
}

void DoublyLinkedList::insertNode(LinkedNode * node, int data)
{	
	LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr);
	
	if(getLength()==0)
	{
		setHead(node);
		setTail(node);
	}
	
	// node is the end of the list
	if(node == getTail())
	{	
		node->setNextLinkedNode(newNode);
		newNode->setPrevLinkedNode(tail_);
		setTail(newNode);
	}
	// node is somewhere in the list
	else if(node != getTail())
	{
		while(node->getNextLinkedNode() != nullptr)
		{	
			node = node->getNextLinkedNode(); // Will traverse the list to the final node
		}
	
		node->setNextLinkedNode(newNode);
		newNode->setPrevLinkedNode(node);
		setTail(newNode);
	}
	
	std::cout << "Inserting " << data << "..." << std::endl;
	
	length++;
	
	//delete newNode;
}

void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, int data)
{
	LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr);
	
	if(getLength()== 0)
	{
		setHead(node);
		setTail(node);
	}
	
	// node is the end of the list
	if(node == getTail())
	{	
		node->setNextLinkedNode(newNode);
		newNode->setPrevLinkedNode(tail_);
		setTail(newNode);
	}
		
	// node is somewhere in the list
	else if(node != getTail())
	{	
		newNode->setNextLinkedNode(node->getNextLinkedNode());	// newNode points to next node
		node->getNextLinkedNode()->setPrevLinkedNode(newNode); // next node points back to newNode
		newNode->setPrevLinkedNode(node); // newNode points back to node
		node->setNextLinkedNode(newNode); // node points to newNode
	}

	std::cout << "Inserting " << data << "..." << std::endl;
	
	length++;
	
	//delete newNode;
	
}

void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data)
{
	LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr);
	
	if(getLength()==0)
	{
		setHead(node);
		setTail(node);
	}
	
	// node is the front of the list
	if(node == getHead())
	{	
		node->setPrevLinkedNode(newNode);
		newNode->setNextLinkedNode(node);
		setHead(newNode);
	}
	// node is somewhere in the list
	else if(node != getHead())
	{
		newNode->setPrevLinkedNode(node->getPrevLinkedNode()); // newNode points to previous node
		node->getPrevLinkedNode()->setNextLinkedNode(newNode); // previous node points to newNode
		node->setPrevLinkedNode(newNode); // node points to newNode
		newNode->setNextLinkedNode(node); // newNode points to node
	}
	
	std::cout << "Inserting " << data << "..." << std::endl;	
	
	length++;
	
	//delete newNode;

}
