// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "LinkedNode.h"

class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		bool isEmpty();
		LinkedNode * getHead();
		int getLength();
		void insert(int element);
		void printList();

	private:
		LinkedNode * head_;
		LinkedNode * tail_;
		LinkedNode * nextLinkedNode_;
};   
#endif