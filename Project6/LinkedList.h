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
		virtual ~LinkedList();
		
		LinkedNode * getHead(); 
		LinkedNode * getTail(); 
		
		void setHead(LinkedNode* node);
		void setTail(LinkedNode* node);
		
		bool isEmpty();
		int getLength();
		virtual void insertNode(int element) {};
		virtual void printList() {};

	private:
		LinkedNode * head_;
		LinkedNode * tail_;
		
		int length = 0;
};   
#endif