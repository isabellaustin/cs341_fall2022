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

LinkedList::~LinkedList()
{	
    if (head_ != nullptr)
    {
        delete head_;
    }
	
	if (tail_ != nullptr)
    {
        delete tail_;
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
bool LinkedList::isEmpty()
{ 
	if(head_ == nullptr)
    {	return 1; }
    else
    {	return 0; }
}

int LinkedList::getLength()
{	
    return length;
}