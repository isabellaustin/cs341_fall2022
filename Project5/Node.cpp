// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "Node.h"

Node::Node(int data) : data_(data)// Constructor
{
	
}

Node::~Node() // Destructor
{
	//delete [] node_;
}

void Node::setData(int data)
{
	data_ = data;
}

int Node::getData()
{
	return data_;
}