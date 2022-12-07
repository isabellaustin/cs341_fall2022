// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

#ifndef HASH_ENTRY_H
#define HASH_ENTRY_H

#include <iostream>

// Defines the size of the HashEntry.
#define HashEntry_SIZE 256

class HashEntry 
{
	public:
		//-----*STRUCTORS-----
        HashEntry(int key, int value);                                        
		HashEntry(); 
		~HashEntry();    
		
		enum Status {EMPTY, OCCUPIED, REMOVED};
		
		//-----SETTERS-----
		void setStatus(Status status);
		void setKey(int key);
		void setValue(int value);
		
		//-----GETTERS-----
		int getKey();
		int getValue(int key);
		int getStatus();

	protected:
		int key_;
		int value_;
		Status status_;
}; 
#endif