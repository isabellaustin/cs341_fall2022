// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

#include "HashTableCuckoo.h"
#include <iostream>

//---------------*STRUCTORS---------------
HashTableCuckoo::HashTableCuckoo(int size) : HashTable()
{
	size_ = size;
	//TABLE 1
	if(size != 0)
	{
		entry_ = new HashEntry[size]; // array of entries
		for(int i=0; i++; i<size)
		{
			HashEntry newEntry;
			newEntry.HashEntry::setStatus(HashEntry::EMPTY);
			entry_[i] = newEntry;
		}
	}
	
	//TABLE 2
	if(size != 0)
	{
		entry2_ = new HashEntry[size]; // array of entries
		for(int i=0; i++; i<size)
		{
			HashEntry newEntry2;
			newEntry2.HashEntry::setStatus(HashEntry::EMPTY);
			entry2_[i] = newEntry2;
		}
	}
}

HashTableCuckoo::~HashTableCuckoo()
{
	delete [] entry_;
	delete [] entry2_;
}

//---------------ACCESSOR METHODS---------------
void HashTableCuckoo::insert(int key, int value)
{
	int hashVal = key % size_; //TABLE 1
	int hashVal2 = (key / size_) % size_; //TABLE 2
	int loop(0);
	placed_ = false;
	
	HashEntry newEntry(key, value);
	newEntry.HashEntry::setStatus(HashEntry::OCCUPIED);

	//no collisions
	while(!placed_ && loop<(2*size_))
	{
		placed_ = false;
		if(entry_[hashVal].getStatus() != 1) //1 is OCCUPIED
		{
			entry_[hashVal] = newEntry;
			placed_ = true;
		}
		else
		{
			//collisions
			
			HashEntry currEntry(entry_[hashVal].getKey(), entry_[hashVal].getValue(entry_[hashVal].getKey()));
			currEntry.HashEntry::setStatus(HashEntry::OCCUPIED);
			entry_[hashVal] = newEntry;
			newEntry = currEntry;
			
			key = newEntry.getKey();					
			hashVal = key % size_;						//added these two lines because it was placing the hash
			hashVal2 = (key / size_) % size_;			//value in the wrong spot, based on previous key
			
			
			if(entry2_[hashVal2].getStatus() != 1)
			{
				entry2_[hashVal2] = newEntry;
				placed_ = true;
			}
		}
		
		loop++;
	}
	
}

bool HashTableCuckoo::wasPlaced()
{
	return placed_;
}

int HashTableCuckoo::search(int key)
{
	int hashVal = key % size_; //TABLE 1
	int hashVal2 = (key / size_) % size_; //TABLE 2
	int val(0);
	
	if(entry_[hashVal].getKey() == key && entry_[hashVal].getStatus() == 1) //1 is OCCUPIED
	{
		val = entry_[hashVal].getValue(key);
		return val;
	}
	else if(entry2_[hashVal2].getKey() == key && entry2_[hashVal2].getStatus() == 1) //1 is OCCUPIED
	{
		val = entry2_[hashVal2].getValue(key);
		return val;
	}
	else
	{	return -1;	}
}

void HashTableCuckoo::remove(int key)
{
	for(int i=0; i<size_; i++)
	{
		if(entry_[i].getKey() == key && entry_[i].getStatus() == 1) //1 is OCCUPIED	
		{
			entry_[i].HashEntry::setKey(-1);
			entry_[i].HashEntry::setValue(-1);
			entry_[i].HashEntry::setStatus(HashEntry::REMOVED);	
		}
		else if(entry2_[i].getKey() == key && entry2_[i].getStatus() == 1) //1 is OCCUPIED	
		{
			entry2_[i].HashEntry::setKey(-1);
			entry2_[i].HashEntry::setValue(-1);
			entry2_[i].HashEntry::setStatus(HashEntry::REMOVED);
		}
	}
	
	std::cout << "Key " << key << " removed." << std::endl;	
}

void HashTableCuckoo::print()
{
	int count(0);
	//TABLE 1
	while(count<size_)
	{
//		int x(0);
		
		std::cout << "****************************" << std::endl;
		for(int i=count; i<size_; i++)
		{
			if(entry_[i].getStatus() == 1) //1 is OCCUPIED	
			{
				std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl;
			}
			else
			{
				std::cout << "[" << i << "]: " << std::endl;
			}
			count++;
//			x++;
			
//			if(x == 6)
//			{	break; }
		}
		std::cout << "****************************" << std::endl;
		std::cout << std::endl;
	}
	
	count = 0;
	
	//TABLE 2
	while(count<size_)
	{
	//	int x(0);
		
		std::cout << "****************************" << std::endl;
		for(int i=count; i<size_; i++)
		{
			if(entry2_[i].getStatus() == 1) //1 is OCCUPIED	
			{
				std::cout << "[" << i << "]: " << entry2_[i].getKey() << std::endl;
			}
			else
			{
				std::cout << "[" << i << "]: " << std::endl;
			}
			count++;
//			x++;
			
//			if(x == 6)
	//		{	break; }
		}
		std::cout << "****************************" << std::endl;
		std::cout << std::endl;
	}

}