// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

#ifndef HASHTABLE_CUCKOO_H
#define HASHTABLE_CUCKOO_H

#include "HashTable.h"
#include "HashEntry.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>

class HashTableCuckoo : public HashTable
{
	public:
	//-----*STRUCTORS-----
		HashTableCuckoo(int size);
		~HashTableCuckoo();
		
	//-----ACCESSOR METHODS-----
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
	
	//-----EQUATIONS-----
		//hash1 = key % size_
		//hash2 = (key / size_) % size_
		
	private:
		HashEntry * entry_; // Table I
		HashEntry * entry2_; // Table II
		int size_;
};
#endif