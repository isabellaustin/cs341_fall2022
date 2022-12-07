// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "DoublyLinkedList.h"
#include "HashEntry.h"
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
		if(getLength() == 0 && head_ != nullptr)
		{
		//	std::cout << "TEST 1" << std::endl;
			std::cout << current->getValue();
		}
		else if(head_ != nullptr)
		{		
			std::cout << current->getValue();
			current = current->getNextLinkedNode();
			if(current != tail_ )
			{
				std::cout << "<-->";
			}
			if (current == tail_)
			{
				std::cout << "<-->" << tail_->getValue();
			} 
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
	
	//std::cout << "Inserting " << data << "..." << std::endl;

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

void DoublyLinkedList::removeLinkedNode(int key)
{
	if(key == getHead()->getValue() && getHead() == getTail())
	{	
		setHead(nullptr);
	}
	else if(key == getHead()->getValue())
	//if(key == LinkedList::getHead()->getValue().getKey())
	{
	//	std::cout << "HERE" << std::endl;
		LinkedNode * currentHead = getHead();
		LinkedNode * nextNode = currentHead->getNextLinkedNode();
		setHead(nextNode);
		nextNode->setPrevLinkedNode(nullptr);
		currentHead->setNextLinkedNode(nullptr);
		delete currentHead;
	}
	else if(key == getTail()->getValue())
	//else if (key == LinkedList::getTail()->getValue((LinkedList::getHead()->getKey())))
	{
		LinkedNode * currentTail = getTail();
		LinkedNode * prevNode = currentTail->getPrevLinkedNode();
		setTail(prevNode);
		prevNode->setNextLinkedNode(nullptr);
		currentTail->setPrevLinkedNode(nullptr);
		delete currentTail;
	}
	else
	{
		LinkedNode * currentNode = getHead();
		bool isFound(false);
		
		while (currentNode->hasNextLinkedNode())
		{
			currentNode = currentNode->getNextLinkedNode();
			
			if(currentNode->getValue() == key)
			//if(currentNode->getValue((LinkedList::getHead()->getKey()) == key))
			{
				isFound = true;
				break;
			}
		}
		
		if(isFound)
		{
			currentNode->getPrevLinkedNode()->setNextLinkedNode(currentNode->getNextLinkedNode());
			currentNode->getNextLinkedNode()->setPrevLinkedNode(currentNode->getPrevLinkedNode());
			currentNode->setPrevLinkedNode(nullptr);
			currentNode->setPrevLinkedNode(nullptr);
			delete currentNode;
		}
		else
		{
			std::cout << "Key " << key << " not found!" << std::endl;
		}
	}
	
	if(getLength() >0)
		length--;
}

int DoublyLinkedList::find(int key)
{
	LinkedNode * current = head_;
	
	int i=0;
	
	do{
		if(current == nullptr)
		{
			break;
		}
		else if(current->getValue() == key)
		{
			return current->getValue();
		}
		else
		{
			if(current->getNextLinkedNode() != nullptr)
			{
				current = current->getNextLinkedNode();
			}
		}
		i++;

	}while(getLength() >= i);
	
	return -1;
}