// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

//separate chaining class - array of DLLs

#include "HashTableChaining.h"

#include <iostream>

//---------------*STRUCTORS---------------
HashTableChaining::HashTableChaining(int size) : HashTable()
{
	size_ = size;
	if(size != 0)
	{
		entry_ = new DoublyLinkedList[size]; // array of DoublyLinkedLists
		for(int i=0; i++; i<size)
		{
			DoublyLinkedList newList;
			entry_[i] = newList;
		}
	} 
}

HashTableChaining::~HashTableChaining()
{
	delete [] entry_;
}

//---------------ACCESSOR METHODS---------------
void HashTableChaining::insert(int key, int value)
{
	int hashVal = key % size_;
	
	if(entry_[hashVal].getHead() == nullptr)
	{
		LinkedNode * newNode = new LinkedNode(key, nullptr, nullptr);
		entry_[hashVal].setHead(newNode);
		entry_[hashVal].setTail(newNode);
	}
	else
	{
		//collisions	
		entry_[hashVal].insertNode(entry_[hashVal].getTail(), key);		
	}
}

int HashTableChaining::search(int key)
{
	int hashVal = key % size_;
	int val(0);
	int i(0);
	
	if(entry_[hashVal].getHead() != nullptr)
	{
		val = entry_[hashVal].find(key);
		if(val == -1)
			return -1;
		else
			return 1;
	}
	
	return -1;
	
}

void HashTableChaining::remove(int key)
{
	int hashVal = key % size_;
	
	entry_[hashVal].removeLinkedNode(key);
	
	std::cout << "Key " << key << " removed." << std::endl;
}

void HashTableChaining::print()
{
	//printList()
	
	std::cout << "****************************" << std::endl;
	
	for(int i=0; i<size_; i++)
	{
		if(entry_[i].getHead() != nullptr) //1 is OCCUPIED	
		{
			std::cout << "[" << i << "]: ";
			entry_[i].printList();
		}
		else
		{
			std::cout << "[" << i << "]: " << std::endl;
		}
	}
	
	std::cout << "****************************" << std::endl;
}