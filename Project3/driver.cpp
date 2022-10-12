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
#include <fstream>

int main()
{
	/*BitArray Bit(4);
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

//------------------------------------------------------------------------------
	
	Set A(4);
	A.initialize("Anna", 4);
	
	Set A2(4);
	A2.initialize("Anna", 4);
	
	Set B(4);
	B.initialize("Izzy", 4);
	
	(A.getData()).print();
	(B.getData()).print();
	
	std::cout << "\nCardinality: " << A.getCardinality() << std::endl;
	
	A.setUnion(B);
	std::cout << "\nSet Union (A U B): " << std::endl;
	(A.getData()).print();
	
	A2.setIntersection(B);
	std::cout << "\nSet Intersection (A X B): " << std::endl;
	(A2.getData()).print();

//------------------------------------------------------------------------------
	
	Dictionary Dict;
	Dict.initialize("test", 4);
	
	/*
	| 01110100 | 01100101 | 01110011 | 01110100 |
		 0			1			2		  3
		0-7		   8-15		  16-23	 	24-31*/
	
	
	std::cout << "Rank: " << Dict.rank(31, 1) << std::endl; 
	std::cout << "Rank Range (15-31): " << Dict.rank_range(15, 31) << std::endl;
	std::cout << "Select (5,1): " << Dict.select(5, 1) << std::endl; 
	//(select) his sample answer from the notes is different but this answer makes sense to me // AGREED -AS
	std::cout << "Select Range(0,15,2,1): " << Dict.select_range(0, 15, 2, 1) << std::endl;

	std::ofstream lookup;
	lookup.open("table.txt");
	Dict.printLookupTable(lookup);
	lookup.close();


	return 0;
}