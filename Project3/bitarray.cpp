// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

#include "bitarray.h"

BitArray::BitArray(int size)
{
	BYTES = size;
	LENGTH = BYTES*BIT_IN_BYTE;
	data_ = new char[BYTES];
}
 
BitArray::BitArray(const BitArray & array)
{	
	LENGTH = array.LENGTH;
	BYTES = array.BYTES;
	data_ = new char[BYTES];
}

/// Destructor
BitArray::~BitArray()
{
	if(data_ != nullptr)
	{	delete [] data_;	}
}	
 
bool BitArray::get(int position) const
{
	int index = (position)/BIT_IN_BYTE;
	position = position%BIT_IN_BYTE;
	
	return((data_[index] & (1 << (7-position))) != 0);
}

void BitArray::print()
{	
	std::cout << "|";
	for (int i=0; i < BYTES; i++)
	{
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	std::cout << std::endl;
}

void BitArray::complement()
{
	for(int i=0; i<BYTES; i++)
	{
		data_[i] = ~data_[i];
	}
}

void BitArray::clear()
{
	for(int i=0; i<BYTES; i++)
	{
		data_[i] = 0;
	}
}

bool BitArray::flip(int position)
{
	int index = (position)/BIT_IN_BYTE;
	position = position%BIT_IN_BYTE;
	
	data_[index] ^= (1 << (7-position));
	
	return 1;
}

bool BitArray::set(int position, int bit)
{
	int index = (position)/BIT_IN_BYTE;
	position = position%BIT_IN_BYTE;

	if(bit == 1)
	{	data_[index] |= (1 << (7-position));	}
	else
	{	data_[index] &= ~(1 << (7-position));	}
	
	return 1;
}

char BitArray::get8(int position) const
{
	int index = (position)/BIT_IN_BYTE;
	
	return data_[index];
}

void BitArray::initialize(char * word, int size)
{
	// Dr. R: If we just create it pointing at the nullptr we don't 
	//	      need to delete it here. Don't forget to update the size
	//
	LENGTH = size*BIT_IN_BYTE;
	
	delete [] data_;
	data_ = new char[size];
	
	for(int i=0; i<size; i++)
	{
		data_[i] = word[i];
	}
}

void BitArray::set8(char c, int index)
{
	data_[index] = c;
}