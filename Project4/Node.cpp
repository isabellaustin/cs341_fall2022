// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "Node.h"

Node::Node(int data) // Constructor
{
	node_ = new int[1];
	node_[0] = data;
}

Node::Node(Node & nodes) // Copy Constructor
{	
	node_ = new int[1];
	data_ = nodes.getValue();
	node_[0] = data_;
}

Node::~Node() // Destructor
{
	delete [] node_;
}

void Node::setValue(int data)
{
	node_[0] = data;
}

int Node::getValue()
{
	return node_[0];
}