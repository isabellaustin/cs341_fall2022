// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include "LinkedList.h"
#include <iostream>
#include <ostream>

class DoublyLinkedList : public LinkedList
{
	public:
		DoublyLinkedList();
		virtual ~DoublyLinkedList() {};
		
		LinkedNode * getHead(); 
		LinkedNode * getTail(); 
		
		void setHead(LinkedNode* node);
		void setTail(LinkedNode* node);
		
		int getLength();
		virtual void printList();

		virtual void insertNode(LinkedNode * node, int data);
		void insertAfterLinkedNode(LinkedNode * node, int data);
		void insertBeforeLinkedNode(LinkedNode * node, int data);
		
	private:
		LinkedNode * head_;
		LinkedNode * tail_;
		
		int length = 0;
};   
#endif