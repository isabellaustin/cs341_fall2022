// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

#include "set.h"

// Dr. R: Let your Header Guard do its thing!
#include "bitarray.h"

//Constructor
Set::Set(int size) : data_(size)
{
	
}
                        
/// Destructor
Set::~Set()
{
	
}

void Set::initialize(char * word, int size)
{	
	data_.initialize(word, size);
}

int Set::getCardinality() const
{
	int cardinality = 0;
	int condition;
	
	for(int i=0; i<data_.length(); i++)
	{			
		condition = data_.get(i);
		
		if(condition == 1)
		{ 	cardinality++; }
	}
	
	return cardinality;
}
   
BitArray & Set::getData()
{
	return data_;
}	

bool Set::setUnion(Set & B)
{
	BitArray Union(data_.bytes());
	char c;
	
	if(data_.length() != (B.getData()).length()) // Checks if the BitArrays are the same length
	{ return 0;	}
	else
	{		
		for(int i=0; i<data_.bytes(); i++)
		{			
			c = data_.get8(i*8) | (B.getData()).get8(i*8);			
			Union.set8(c, i);
		}
		
		Union.print();
		return 1;
	}
}

bool Set::setIntersection(Set & B)
{
	BitArray Intersect(data_.bytes());
	char c;
	
	if(data_.length() != (B.getData()).length()) // Checks if the BitArrays are the same length
	{ return 0;	}
	else
	{		
		for(int i=0; i<data_.bytes(); i++)
		{			
			c = data_.get8(i*8) & (B.getData()).get8(i*8);			
			Intersect.set8(c, i);
		}
		
		Intersect.print();
		return 1;
	}
}
 