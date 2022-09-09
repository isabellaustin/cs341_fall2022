// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include "Car.h"
#include <iostream>

Car::Car()
{
	
}

Car::Car(std::string name, int speed, int control)
{
	name_ = name;
	speed_ = speed;
	control_ = control;
	lapNumber_ = 0;
}

Car::~Car()
{
	
}

	// Accessor Methods
	void Car::setName(std::string name)
	{
		name_ = name;
	}
	std::string Car::getName()
	{
		return name_;
	}
	void Car::setSpeed(int speed)
	{
		speed_ = speed;
	}
	int Car::getSpeed()
	{
		return speed_;
	}
	void Car::setControl(int control)
	{
		control_ = control;
	}
	int Car::getControl()
	{
		return control_;
	}
	void Car::setLapNum(int lapNumber)
	{
		if(lapNumber > lstLap_)
		{
			lapNumber_ = lstLap_;
		}
		else
			lapNumber_ = lapNumber;
	}
	int Car::getLapNum()
	{
		return lapNumber_;
	}	
	void Car::printInfo()
	{
		std::cout << name_ << ": " << lapNumber_ << std::endl;
	}