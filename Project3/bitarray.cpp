#include "bitarray.h"
#include <vector>
#include <bitset>
#include <iostream>

BitArray::BitArray(int size)
{
	BYTES = size;
	LENGTH = BYTES*BIT_IN_BYTE;
	data_ = new char[BYTES];
	
	for(int i=0; i<BYTES; i++)
	{	data_[i] = 100 + i;	}
}
 
BitArray::BitArray(const BitArray & array) : LENGTH(array.LENGTH)
{	
	for(int i =0; i<array.LENGTH; i++)
	{
		data_[i] = array.data_[i];
		std::cout << data_[i] << std::endl;
	}
}

/// Destructor
BitArray::~BitArray()
{
	delete [] data_;
}	
 
bool BitArray::get(int position) const
{
	int index = position/BIT_IN_BYTE;
	position = position%BIT_IN_BYTE;
	
	return((data_[index] & (1 << (8-position))) != 0);
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
	int index = position/BIT_IN_BYTE;
	position = position%BIT_IN_BYTE;
	
	data_[index] ^= (1 << (8-position));
	
	return 1;
}

bool BitArray::set(int position, int bit)
{
	int index = position/BIT_IN_BYTE;
	position = position%BIT_IN_BYTE;
	
	data_[index] |= (bit << (8-position));
	
	return 1;
}

// MULTIPLIES OF 8 NEED TO BE PUSHED INTO AN 'IF' STATEMENT
// FOR 'SET' AND 'FLIP' AND 'GET' FUNCTIONS
