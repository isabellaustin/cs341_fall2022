#include "bitarray.h"
#include "dictionary.h"
#include "set.h"

#include <vector>
#include <iostream>
#include <bitset>

int main()
{
	BitArray V(24);
	
	std::cout << "Number of Bits: " << V.length() << std::endl;
	std::cout << V.bytes() << std::endl;
	
	V.print();

	
	return 0;
}