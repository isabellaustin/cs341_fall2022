// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "LinkedNode.h"
#include <iostream>


LinkedNode::LinkedNode(int data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode) : Node(data), nextLinkedNode_(nextLinkedNode), prevLinkedNode_(prevLinkedNode)
{
	//LinkedNode * nextLinkedNode_ = new LinkedNode(data, nextLinkedNode);
	//Node LN(data);
	//nextLinkedNode_ = nextLinkedNode;
}

LinkedNode::~LinkedNode() 
{ 
    if(nextLinkedNode_ != nullptr)
    {
        delete nextLinkedNode_;
    }
	
	// Dr. R: Wouldn't the previous node already be deleted here?
	if(prevLinkedNode_ != nullptr)
    {
        delete prevLinkedNode_;
    }
} 

LinkedNode * LinkedNode::getNextLinkedNode()
{
	return nextLinkedNode_;
}

LinkedNode * LinkedNode::getPrevLinkedNode()
{
	return prevLinkedNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode * nextLinkedNode)
{
	nextLinkedNode_ = nextLinkedNode;
}

void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode)
{
	prevLinkedNode_ = prevLinkedNode;
}

bool LinkedNode::hasNextLinkedNode()
{
	if(nextLinkedNode_ == nullptr)
	{	return 0;	}
	else
	{	return 1;	}
}

bool LinkedNode::hasPrevLinkedNode()
{
	if(prevLinkedNode_ == nullptr)
	{	return 0;	}
	else
	{	return 1;	}
}