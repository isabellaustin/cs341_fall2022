// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

//#include

#include "HashEntry.h"
#include "HashTableArray.h"
#include "HashTableCuckoo.h"
#include "HashTableChaining.h"
#include "HashTable.h"

#include <iostream>
#include <fstream>

int main()
{
	HashEntry HEntry;
	
	int key(0);
	int value(0);
	
	std::cout << std::endl;
	std::cout << "Welcome to Blue IV's Can of Who Hash!" << std::endl;
	
	int choice1(0);
	int size(0);
	int choice2(0);
	int searchKey(0);
	int removeKey(0);
	
	//----------------OPTIONS--------------------
	
	while(choice1 != 5)
	{	
		std::cout << std::endl;
		std::cout << "1) Linear Probing" << std::endl;
		std::cout << "2) Quadratic Probing" << std::endl;
		std::cout << "3) Separate Chaining" << std::endl;
		std::cout << "4) Cuckoo Hashing" << std::endl;
		std::cout << "5) Quit Program" << std::endl;
		
		std::cout << std::endl;
		std::cout << "Please enter your choice: ";
		std::cin >> choice1;
		std::cout << std::endl;
		
		if(choice1 == 5)
		{ break; }
		
		
		std::cout << "Please enter  the size of the Hash Table you wish to create: ";
		std::cin >> size;
		std::cout << std::endl;
		
		if(choice1 == 1 || choice1 == 2) //Linear Probing or Quadratic Probing; HTArray
		{
			HashTableArray HTArray(size, choice1);
			int count(0);
			//-------------------INSERTNG LIST OF DATA FROM DATA.TXT INTO HASH TABLE--------------------
			std::ifstream inputFile("data.txt");
			
			if(inputFile.is_open())
			{	
				while(!inputFile.eof())
				{
					inputFile >> key >> value;
					count++;
					
					if(count>size || size == 0) // added bc i found it was breaking it you entered 0
					{	
						std::cout << "Key Unpositioned: " << key << '\n' << std::endl;
						std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
						break;
					}
					else
					{
						HTArray.insert(key, value);
					}
					
				}
			}
			inputFile.close();
			
			while(count<=size && size != 0)
			{
				std::cout << std::endl;
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				
				std::cout << std::endl;
				std::cout << "Please enter your choice: ";
				std::cin >> choice2;
				std::cout << std::endl;
				
				while(choice2 != 4)
				{
					
					if(choice2 == 1)
					{
						std::cout << "Search (Please enter a Key): ";
						std::cin >> searchKey;
						std::cout << std::endl;
						
						if(!HTArray.search(searchKey) || HTArray.search(searchKey) == -1) //searchKey isn't in the table
						{	std::cout << "Invalid key! Key " << searchKey << " not found in table!" << std::endl; }
						else
						{ 
							std::cout << "Key: " << searchKey << "     Value: " << HTArray.search(searchKey) << std::endl; 
						}	
					}
					else if(choice2 == 2)
					{
						std::cout << "Remove (Please enter a Key): ";
						std::cin >> removeKey;
						std::cout << std::endl;
						
						if(!HTArray.search(removeKey) || HTArray.search(removeKey) == -1)
						{ std::cout << "Invalid key! Key " << removeKey << " not found in table!" << std::endl; }
						else
						{ 
							HTArray.remove(removeKey); 
						}
					}
					else if(choice2 == 3)
					{
						HTArray.print();
					}
					break;
				}
				
				if(choice2 == 4)
				{	break; }
			}
			//	HTArray.~HashTableArray(); 
		}
		else if(choice1 == 3) //Separate Chaining; HTChaining
		{
			HashTableChaining HTChaining(size);
			int count(0);
			
			//-------------------INSERTNG LIST OF DATA FROM DATA.TXT INTO HASH TABLE--------------------
			std::ifstream inputFile2("data.txt");
			
			if(inputFile2.is_open())
			{		
				while(!inputFile2.eof())
				{
					inputFile2 >> key >> value;
					
					if(size == 0)
					{	
						std::cout << "Key Unpositioned: " << key << '\n' << std::endl;
						std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
						break;
					}
					else
						HTChaining.insert(key, value);	
				}
			}
			inputFile2.close();
			
			while(size>0)
			{
				std::cout << std::endl;
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				
				std::cout << std::endl;
				std::cout << "Please enter your choice: ";
				std::cin >> choice2;
				std::cout << std::endl;
				
				while(choice2 != 4)
				{
					
					if(choice2 == 1)
					{
						std::cout << "Search (Please enter a Key): ";
						std::cin >> searchKey;
						std::cout << std::endl;
						
						if(HTChaining.search(searchKey) == -1) //searchKey isn't in the table
						{	std::cout << "Invalid key! Key " << searchKey << " not found in table!" << std::endl; }
						else
						{ 
							std::cout << "Key: " << searchKey << "     Value: " << HTChaining.search(searchKey) << std::endl; 
						}	
					}
					else if(choice2 == 2)
					{
						std::cout << "Remove (Please enter a Key): ";
						std::cin >> removeKey;
						std::cout << std::endl;
						
						if(HTChaining.search(removeKey) == -1)
						{ std::cout << "Invalid key! Key " << removeKey << " not found in table!" << std::endl; }
						else
						{ 
							HTChaining.remove(removeKey); 
						}
					}
					else if(choice2 == 3)
					{
						HTChaining.print();
					}
					break;
				}
				
				if(choice2 == 4)
				{	break; }
			} 
		}
		else if(choice1 == 4) //Cuckoo Hashing; HTCuckoo
		{
			HashTableCuckoo HTCuckoo(size);
			int count(0);
			
			//-------------------INSERTNG LIST OF DATA FROM DATA.TXT INTO HASH TABLE--------------------
			std::ifstream inputFile3("data1.txt");
			
			if(inputFile3.is_open())
			{		
				while(!inputFile3.eof())
				{
					inputFile3 >> key >> value;
					
					count++;
					if(count>(size*2) || size == 0)
					{	
						std::cout << "Key Unpositioned: " << key << '\n' << std::endl;
						std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
						break;
					}
					else
					{
						HTCuckoo.insert(key, value);		//added an accessor method so that we had a way to retrieve
						if(HTCuckoo.wasPlaced() == false)	//whether or not a key was successfully placed
						{
							std::cout << "Cycle Present - Rehash!" << std::endl;	
							std::cout << "Key Unpositioned: " << key << '\n' << std::endl;
							std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
							count = size*2+1;	// This is important so that it does not go into the next while loop
							break;
						}
					}	
				}
			}
			inputFile3.close();
			
			
			while(count<=size*2 && size != 0)
			{
				std::cout << std::endl;
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				
				std::cout << std::endl;
				std::cout << "Please enter your choice: ";
				std::cin >> choice2;
				std::cout << std::endl;
				
				while(choice2 != 4)
				{
					
					if(choice2 == 1)
					{
						std::cout << "Search (Please enter a Key): ";
						std::cin >> searchKey;
						std::cout << std::endl;
						
						if(HTCuckoo.search(searchKey) == -1) //searchKey isn't in the table
						{	std::cout << "Invalid key! Key " << searchKey << " not found in table!" << std::endl; }
						else
						{ 
							std::cout << "Key: " << searchKey << "     Value: " << HTCuckoo.search(searchKey) << std::endl; 
						}	
					}
					else if(choice2 == 2)
					{
						std::cout << "Remove (Please enter a Key): ";
						std::cin >> removeKey;
						std::cout << std::endl;
						
						if(HTCuckoo.search(removeKey) == -1)
						{ std::cout << "Invalid key! Key " << removeKey << " not found in table!" << std::endl; }
						else
						{ 
							HTCuckoo.remove(removeKey); 
						}
					}
					else if(choice2 == 3)
					{
						HTCuckoo.print();
					}
					break;
				}
				
				if(choice2 == 4)
				{	break; }
			}
		}
	}
	
	
	std::cout << "Thank you for using Blue IV's program - Goodbye!" << std::endl;
	 
}