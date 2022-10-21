// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "LinkedList.h"
#include <cstddef>
#include <iostream>
#include <ostream>


//------------------*STRUCTORS--------------------------------------
LinkedList::LinkedList() //right
{
	head_ = nullptr;
    tail_ = nullptr;    
}

LinkedList::~LinkedList() //right
{	
    if (head_ != nullptr)
    {
        delete head_;
    }
}
//---------------------------GETTERS&SETTERS-------------------------
LinkedNode * LinkedList::getHead()
{
    return head_;
}

LinkedNode * LinkedList::getTail()
{
    return tail_;
}

void LinkedList::setHead(LinkedNode* node)
{
    head_ = node;
}

void LinkedList::setTail(LinkedNode* node)
{
    tail_ = node;
}
//--------------------------------------------------------------------
bool LinkedList::isEmpty() //right
{ 
	if(head_ == nullptr) //head_ and tail_ == nullptr for doubly linked list?
    {	return 1; }
    else
    {	return 0; }
}

int LinkedList::getLength() //good maybe?
{	
    return length;
}

void LinkedList::insert(int element) //still working on this
{
	LinkedNode * nextNode;
	
	std::cout << "Inserting " << element << "..." << std::endl;
	
	if(head_ == nullptr)
	{	
		nextNode->setValue(element);
		head_ = nextNode;
		tail_ = nextNode;
	}
	
	array[length] = element;
	
	length++;
}

void LinkedList::printList()
{
	LinkedNode * node;
	
	for(int i=0; i<length; i++)
	{
		std::cout << array[i];
		
		if(i != (length-1))
		{
			std::cout << "-->";
		}
	}
	std::cout << std::endl;
}