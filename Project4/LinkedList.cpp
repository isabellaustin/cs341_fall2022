// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "LinkedList.h"

LinkedList::LinkedList() 
{
    head_ = nullptr;
    tail_ = nullptr;    
}

LinkedList::~LinkedList()
{
    if (head_ != nullptr)
    {
        delete head_;
    }
}

bool LinkedList::isEmpty()
{
	if(head_ == nullptr) //if head is null, no node in list
    {	return 1; }
    else
    {	return 0; }
}

LinkedNode * LinkedList::getHead()
{
    return head_;
}

int LinkedList::getLength()
{
	int length = 0;
	
	LinkedNode * ptrNum = getHead(); 
    while(ptrNum!= nullptr)
    {
        length++;
       // ptrNum = ptrNum->nextLinkedNode_;
    }

    return length;
}

void LinkedList::insert(int element)
{
	
}

void LinkedList::printList()
{
	
}