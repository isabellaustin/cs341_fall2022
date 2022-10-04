#include "bitarray.h"
          
//
// void print()
//
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


std::bitset<8> bits = data_[i];

data_(32)
[4]