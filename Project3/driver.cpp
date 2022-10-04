#include "bitarray.h"
#include "dictionary.h"
#include "set.h"

#include <vector>
#include <iostream>
#include <bitset>

int main()
{
	BitArray Bit(4);
	
	//std::cout << "Number of Bits: " << Bit.length() << std::endl;
	Bit.print();
	
	std::cout << Bit.get(14) << std::endl;

	
	return 0;
}