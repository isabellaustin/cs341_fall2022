// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "LinkedNode.h"
#include <iostream>


LinkedNode::LinkedNode(int data, LinkedNode * nextLinkedNode)
{
	Node LN(data);
	//std::cout << LN.getValue() << std::endl;
	nextLinkedNode_ = nextLinkedNode;
	//nextLinkedNode_->setNextLinkedNode(LN.getValue()); // LN.data_
}

/**
LinkedNode::~LinkedNode() 
{ 
    if (nextLinkedNode_!=nullptr)
    {
        delete nextLinkedNode_;
    }
} */

LinkedNode * LinkedNode::getNextLinkedNode()
{
	return nextLinkedNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode * nextLinkedNode)
{
	nextLinkedNode_ = nextLinkedNode;
}

bool LinkedNode::hasNextLinkedNode()
{
	if(nextLinkedNode_ == nullptr)
	{	return 0;	}
	else
	{	return 1;	}
}