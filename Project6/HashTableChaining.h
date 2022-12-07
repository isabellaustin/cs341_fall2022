// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

#ifndef HASHTABLE_CHAINING_H
#define HASHTABLE_CHAINING_H

#include "HashTable.h"
#include "HashEntry.h"
#include "DoublyLinkedList.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>

class HashTableChaining : public HashTable
{
	public:
	//-----*STRUCTORS-----
		HashTableChaining(int size);
		~HashTableChaining();

	//-----ACCESSOR METHODS-----
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		
	private:
		DoublyLinkedList * entry_;
		int size_;
};
#endif