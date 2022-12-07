// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#ifndef LINKED_NODE_H_
#define LINKED_NODE_H_
#include "LinkedNode.h"
#include "Node.h"

class LinkedNode : public Node
{
	public:
		LinkedNode(int data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode);
		~LinkedNode();
		
		LinkedNode * getNextLinkedNode();
		LinkedNode * getPrevLinkedNode();
		
		void setNextLinkedNode(LinkedNode * nextLinkedNode);
		bool hasNextLinkedNode();
		
		void setPrevLinkedNode(LinkedNode * prevLinkedNode);
		bool hasPrevLinkedNode();
		
		LinkedNode();
		
	private:
		LinkedNode * nextLinkedNode_;
		LinkedNode * prevLinkedNode_;
		//LinkedNode();
};   
#endif