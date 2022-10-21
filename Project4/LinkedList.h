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
		
		LinkedNode * getHead(); //could make inline; don't require much implementation
		LinkedNode * getTail(); //could make inline
		
		void setHead(LinkedNode* node);
		void setTail(LinkedNode* node);
		
		bool isEmpty();
		int getLength();
		void insert(int element);
		void printList();

	private:
		LinkedNode * head_;
		LinkedNode * tail_;
		
		int length = 0;
		int array[100];
};   
#endif