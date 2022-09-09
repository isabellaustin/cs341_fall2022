// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include <string>



class Car
{
	public:
		Car();
		Car(std::string name, int speed, int control);
		~Car();
		
		//Accessor Methods
		void setName(std::string name);
		std::string getName();
		void setSpeed(int speed);
		int getSpeed();
		void setControl(int control);
		int getControl();
		void setLapNum(int lapNumber);
		int getLapNum();
		void printInfo();
		
	
	private:
		std::string name_;
		int speed_;
		int control_;
		int lapNumber_;
		int lstLap_ = 200;
};