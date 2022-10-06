// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

#include "bitarray.h"
#include "dictionary.h"
#include "set.h"

#include <vector>
#include <iostream>
#include <bitset>

int main()
{
	/*BitArray Bit2(4);
	BitArray Bit(Bit2);
	Bit.initialize("test", 4);
	Bit.print();
	
	std::cout << "\nThird Byte:" << std::endl;
	std::cout << Bit.get8(16) << std::endl;
	
	std::cout << "\n0th Bit Set: " << Bit.get(0) << std::endl;
	std::cout << "\n10th Bit Set: " << Bit.get(10) << std::endl;
	
	std::cout << "\nSetting 0th position to 1..." << std::endl;
	Bit.set(0, 1);
	Bit.print();
	
	std::cout << "\nSetting 10th position to 0..." << std::endl;
	Bit.set(10, 0);
	Bit.print();
	
	std::cout << "\nComplement:" << std::endl;
	Bit.complement();
	Bit.print();

	std::cout << "\nClear BitArray:" << std::endl;
	Bit.clear();
	Bit.print();*/
	
	Set A(4);
	A.initialize("test", 4);
	
	Set B(4);
	B.initialize("cool", 4);
	
	(A.getData()).print();
	(B.getData()).print();
	
	std::cout << "Cardinality: " << A.getCardinality() << std::endl;
	
	std::cout << "\nSet Union (A U B): " << A.setUnion(B) << std::endl;
	
	std::cout << "\nSet Intersection (A X B): " << A.setIntersection(B) << std::endl;
	
	return 0;
}