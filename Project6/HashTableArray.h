// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

#ifndef HASHTABLE_ARRAY_H
#define HASHTABLE_ARRAY_H

#include "HashTable.h"
#include "HashEntry.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>

class HashTableArray : public HashTable
{
	public:
	//-----*STRUCTORS-----
		HashTableArray(int size, int method);
		~HashTableArray();
		
	//-----ACCESSOR METHODS-----
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		
		enum Status {EMPTY, OCCUPIED, REMOVED};
	
	private:
		HashEntry * entry_;
		int size_;
		int method_;
};
#endif