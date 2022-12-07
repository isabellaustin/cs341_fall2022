// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

#include "HashTableArray.h"
#include "HashEntry.h"
#include <iostream>

// Method 1: Linear Probing
// Method 2: Quadratic Probing

//---------------*STRUCTORS---------------
HashTableArray::HashTableArray(int size, int method) : HashTable(), method_(0), size_(0) //, entry_(NULL)
{
	size_ = size;
	if(size != 0)
	{
		entry_ = new HashEntry[size]; // array of entries
		for(int i=0; i++; i<size)
		{
			HashEntry newEntry;
			newEntry.HashEntry::setStatus(HashEntry::EMPTY);
			entry_[i] = newEntry;
		}
		method_ = method;
	}
}

HashTableArray::~HashTableArray()
{
	delete [] entry_;
}

//---------------ACCESSOR METHODS---------------
void HashTableArray::insert(int key, int value)
{
	int hashVal = key % size_;
	
	HashEntry newEntry(key, value);
	newEntry.HashEntry::setStatus(HashEntry::OCCUPIED);
	
//	std::cout << hashVal << std::endl;
//	std::cout << entry_[hashVal].getStatus() << std::endl;
	
	//no collisions
	if(entry_[hashVal].getStatus() != 1) //1 is OCCUPIED
	{
		entry_[hashVal] = newEntry;
	//	std::cout << entry_[hashVal].getKey() << std::endl;
	}
	else
	{
		//collisions
		for(int i=0; i<size_; i++)
		{
			int hashVal2(0); //new hash value
			
			if(method_ == 1) //Linear; hash(x) = hash(x) % size + n
			{
				hashVal2 = (hashVal+i) % size_;
			}
			else //Quadratic; hash(x) = hash(x) % size + n^2
			{
				hashVal2 = (hashVal+(i*i)) % size_;
			}
			
			if(entry_[hashVal2].getStatus() == 0) //0 is EMPTY
			{
				entry_[hashVal2] = newEntry;
				break;
			}
		}
	}
	//return;
}

int HashTableArray::search(int key)
{
	int hashVal = key % size_;
	int val(0);
	
	if(entry_[hashVal].getKey() == key && entry_[hashVal].getStatus() == 1) //1 is OCCUPIED
	{
		val = entry_[hashVal].getValue(key);
	}
	else
	{
		int start(-1);
		int count(0);
		
		while(entry_[hashVal].getKey() != key && start != hashVal && count < size_)
		{
			if(method_ == 1) //Linear
			{
				hashVal = (hashVal+1) % size_;
			}
			else //Quadratic
			{
				start = hashVal;
				hashVal = ((key % size_) + (count*count) % size_);
				
				if(start == hashVal)
				{
					count++;
					hashVal = (hashVal+(count*count)) % size_;
				}
			}
			
			if(entry_[hashVal].getKey() == key && entry_[hashVal].getStatus() == 1) //1 is OCCUPIED
			{
				val = entry_[hashVal].getValue(key);
				break;
			}
			count++;
		}
	}
	
	return val;
}

void HashTableArray::remove(int key)
{
	for(int i=0; i<size_; i++)
	{
		if(entry_[i].getKey() == key && entry_[i].getStatus() == 1) //1 is OCCUPIED	
		{
			entry_[i].HashEntry::setKey(NULL);
			entry_[i].HashEntry::setValue(NULL);
			entry_[i].HashEntry::setStatus(HashEntry::REMOVED);
		}
	}
	
	std::cout << "Key " << key << " removed." << std::endl;	
}

void HashTableArray::print()
{
	std::cout << "************************" << std::endl;
	
	for(int i=0; i<size_; i++)
	{
		if(entry_[i].getStatus() == HashEntry::OCCUPIED) //1 is OCCUPIED	
		{
			std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl;
		}
		else
		{
			std::cout << "[" << i << "]: " << std::endl;
		}
	}
	
	std::cout << "************************" << std::endl;
}