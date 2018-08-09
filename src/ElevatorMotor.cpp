/*
  ElevatorMotor.cpp - Library for Elevator Motor interaction of Robot Braman.
  Created by Vadim Pitenko.
*/

#include "Arduino.h"
#include "ElevatorMotor.h"

ElevatorMotor::ElevatorMotor(int pin1, int pin2, int pin3, int pin4, int optPin) : BaseMotor(pin1, pin2, pin3, pin4, optPin)
{
	const int _EMsteps[32] = {
		1, 0, 0, 0,
		1, 1, 0, 0,
		0, 1, 0, 0,
		0, 1, 1, 0,
		0, 0, 1, 0,
		0, 0, 1, 1,
		0, 0, 0, 1,
		1, 0, 0, 1
	};
	
	for(int i=0; i<32; i++)
		_steps[i] = _EMsteps[i];
}

bool ElevatorMotor::isOptClosed()
{
	if(_optPinAnalog)
		return analogRead(_optPin) <= 0;
	else
		return digitalRead(_optPin) <= 0;
}
	
bool ElevatorMotor::renull()
{
	if(isOptClosed())
		moveTo(1000, false);
  
	int tryCnt = 5000;
	while(tryCnt > 0) 
	{
		moveTo(8, true);
		if(isOptClosed()) 
		{
			moveTo(200, true);
			//Serial.println("SM Set to NULL");
			return true;
		}
		tryCnt--;
	}

	//Serial.println("FAILED SM Set to NULL");
	return false;
}