// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

#include "HashEntry.h"

HashEntry::HashEntry(int key, int value)
{
	key_ = key;
	value_ = value;
	status_ = EMPTY;	
}	

HashEntry::HashEntry()
{	
	status_ = EMPTY;
}	

HashEntry::~HashEntry()
{

}

//---------------SETTERS---------------
void HashEntry::setKey(int key)
{
	key_ = key;
}

void HashEntry::setValue(int value)
{
	value_ = value;
}

 void HashEntry::setStatus(Status status)
{
	 status_ = status;
}

//---------------GETTERS---------------		
int HashEntry::getKey()
{
	return key_;
}

int HashEntry::getValue(int key)
{
	return value_;
}

int HashEntry::getStatus()
{
	if(status_ == EMPTY)
	{	return 0;	}
	else if(status_ == OCCUPIED)
	{	return 1;	}
	else
	{	return 2;	}
		
}